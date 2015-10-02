#ifndef __TCP_SERVER_HPP__
#define __TCP_SERVER_HPP__

#include "../hfc_def.hpp"

#include "Connection.hpp"
#include "IConnectionManager.hpp"
using namespace HFC::Net;

#include "../IO/IIOProcessor.hpp"
using namespace HFC::IO;

#include <list>
using namespace std;

namespace HFC {
namespace Net {

class HFC_API TCPServer: public Socket, public IIOProcessor {

public:

	TCPServer();
	virtual ~TCPServer();

public:

	void onNewData(t_fd fd) {
		accept();
	}

	void onWritable(t_fd fd) {
	}

	void onError(t_fd fd) {
		stop();
	}

	void onClose(t_fd fd) {
	}

public:

	void setIP(const char* ip) {
		m_strIP = ip;
	}

	void setPort(const unsigned short port) {
		m_usPort = port;
	}

	void setDataReceiver(IIOProcessor& receiver) {
		m_pDataProcessor = &receiver;
	}

	void setConnectionManager(IConnectionManager& connectionManager) {
		m_pConnectionManager = &connectionManager;
	}

	void init();

	void start();

	void stop();

protected:

	void accept();

protected:

	IConnectionManager* m_pConnectionManager;

	IIOProcessor* m_pDataProcessor;

	String m_strIP;

	unsigned short m_usPort;

protected:

	class InnerConnectionManager: public IConnectionManager {

	public:

		InnerConnectionManager(TCPServer& outer) :
				m_pOuter(&outer) {
		}
	public:

		void onNewData(t_fd fd) {
			m_pOuter->m_pDataProcessor->onNewData(fd);
		}

		void onWritable(t_fd fd) {
			m_pOuter->m_pDataProcessor->onWritable(fd);
		}

		void onError(t_fd fd);

		void onClose(t_fd fd);

	public:

		void onNewConnection(const t_fd c);

		void onConnectionClose(const t_fd c) {
			//onClose函数会直接被EPoll调用，本函数不会被TCPServer调用。
		}

		void onConnectionError(const t_fd c) {
			//onError函数会直接被EPoll调用，本函数不会被TCPServer调用。
		}

	public:

		void closeAllConnection();

	protected:

		TCPServer* m_pOuter;

		typedef list<t_fd> ConnectionFDList;
		ConnectionFDList m_listFd;
	};

	InnerConnectionManager m_innerConnectionManager;

};

}
}

#endif
