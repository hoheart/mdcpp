#ifndef __LOG_RECEIVER_HPP__
#define __LOG_RECEIVER_HPP__

#include <IO/IIOProcessor.hpp>
using namespace HFC::IO;

#include <Net/TCPServer.hpp>
using namespace HFC::Net;

#include <hfc_def.hpp>
using namespace HFC;

#include <map>
using namespace std;

namespace Framework {
namespace Logger {

class HFC_API LogReceiver: public IIOProcessor {

protected:

	LogReceiver();

public:

	static LogReceiver* Instance() {
		static LogReceiver me;
		return &me;
	}

	virtual ~LogReceiver() {
	}

public:

	void onNewData(t_fd fd) {
		recevLog(fd);
	}

	void onWritable(t_fd fd) {

	}

	void onError(t_fd fd) {

	}

	void onClose(t_fd fd) {
	}

public:

	void setIP(const char* ip) {
		m_server.setIP(ip);
	}

	void setPort(const unsigned short port) {
		m_server.setPort(port);
	}

	void start();

	void stop();

protected:

	void recevLog(t_fd fd);

protected:

	TCPServer m_server;

};

}
}

#endif
