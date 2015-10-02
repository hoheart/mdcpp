#include "../include/LogReceiver.hpp"
using namespace Framework::Logger;

#include <Net/Connection.hpp>
using namespace HFC::Net;

#include <stdio.h>

LogReceiver::LogReceiver() {

}

void LogReceiver::start() {
	m_server.setDataReceiver(*this);
	m_server.start();
}

void LogReceiver::stop() {
	m_server.stop();
}

void LogReceiver::recevLog(t_fd fd) {
	while (true) {
		Connection c;
		c.attach(fd);

		char buf[1024] = { 0 };
		int len = c.recv(buf, 1023);

		printf("received data:%s", buf);
	}
}
