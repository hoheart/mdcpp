#include "../../include/IO/EPoll.hpp"
using namespace HFC::IO;

#ifdef _LINUX
#include <sys/epoll.h>
#endif

#include "../../include/Util/OSErrorException.hpp"
using namespace HFC::Util;

#include "../../include/Concurrent/ThreadPool.hpp"
using namespace HFC::Concurrent;

#ifndef _WIN32
#include <unistd.h>
#include <fcntl.h>
#endif

const int EPoll::WAIT_EVENTS_SIZE = 1024;

EPoll::EPoll() :
		m_iEPollFd(-1), m_bStoped(false) {
	//Since Linux 2.6.8, the size argument is unused. 
	//( The kernel dynamically sizes the required data structures without needing this initial hint.)
	m_iEPollFd = epoll_create(1);
	if (m_iEPollFd <= 0) {
		throw OSErrorException("call epoll_create function error.");
	}
}

EPoll::~EPoll() {
	close(m_iEPollFd);
}

void EPoll::add(const int fd, const IIOProcessor& processor) {
	struct epoll_event ev = { 0 };
	ev.data.fd = fd;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLRDHUP | EPOLLHUP | EPOLLPRI | EPOLLET;
	ev.data.ptr = (void*) (&processor);

	int ret = epoll_ctl(m_iEPollFd, EPOLL_CTL_ADD, fd, &ev);
	if (0 != ret) {
		throw OSErrorException("call epoll_ctl for add error. ");
	}
}

void EPoll::del(int fd) {
	int ret = epoll_ctl(m_iEPollFd, EPOLL_CTL_DEL, fd, NULL);
	if (0 != ret) {
		throw OSErrorException("call epoll_ctl for delete error. ");
	}
}
/**
 * 启动一个线程任务去epoll_wait
 */
void EPoll::start() {
	while (!m_bStoped) {
		struct epoll_event events[WAIT_EVENTS_SIZE] = { 0 };
		int eventCount = epoll_wait(m_iEPollFd, events, WAIT_EVENTS_SIZE, -1);
		if (eventCount == -1) {
			throw OSErrorException("call epoll_wait error.");
		}

		for (int n = 0; n < eventCount; ++n) {
			IIOProcessor* pProcessor = (IIOProcessor*) (events[n].data.ptr);
			if (events[n].events & EPOLLIN) {
				pProcessor->onNewData(events[n].data.fd);
			} else if (events[n].events & EPOLLOUT) {
				pProcessor->onWritable(events[n].data.fd);
			} else if (events[n].events & EPOLLRDHUP
					|| events[n].events & EPOLLHUP) {
				pProcessor->onClose(events[n].data.fd);
			} else if (events[n].events & EPOLLERR) {
				pProcessor->onError(events[n].data.fd);
			}
		}
	}
}

void EPoll::stop() {
	m_bStoped = true;
}

