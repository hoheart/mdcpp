#ifndef __EPOLL_HPP__
#define __EPOLL_HPP__

#ifndef _WIN32
#include <sys/epoll.h>
#endif

#include "../hfc_def.hpp"

#include "IIOProcessor.hpp"

namespace HFC {
namespace IO {

/**
 * 与linux的epoll一样，实现对多个（无限制）文件描述符进行可写可读等事件的监控。
 * 实现原理：构造函数向线程池中添加一个任务用于poll，当有事件发生后，重新向线程池中添加poll任务。
 * 之后，向线程池中添加处理事件的任务。
 */
class EPoll {

	const static int WAIT_EVENTS_SIZE;

protected:

	EPoll();

public:

	static EPoll* Instance() {
		static EPoll me;
		return &me;
	}

	virtual ~EPoll();

public:

	void add(const t_fd fd, const IIOProcessor& receiver);

	void del(const t_fd fd);

	void start();

	void stop();

protected:

	void setNonblocking(int fd);

protected:

	int m_iEPollFd;
	bool m_bStoped;

};
}
}

#endif
