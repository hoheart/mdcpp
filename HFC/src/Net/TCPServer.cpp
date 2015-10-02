#include "../../include/Net/TCPServer.hpp"
using namespace HFC::Net;

#include "../../include/Util/OSErrorException.hpp"
using namespace HFC::Util;

#include "../../include/IO/EPoll.hpp"
using namespace HFC::IO;

TCPServer::TCPServer() :
		m_pConnectionManager(NULL), m_pDataProcessor(NULL), m_usPort(0), m_innerConnectionManager(
				*this) {
}

TCPServer::~TCPServer() {
}

void TCPServer::init() {
	create(Tcp, m_strIP, m_usPort);
}

void TCPServer::start() {
	if (0 != ::listen(m_sock, 0)) {
		throw OSErrorException("can't listen.");
	}

	EPoll* pPoll = EPoll::Instance();
	pPoll->add(m_sock, *this);

	pPoll->start();
}

void TCPServer::stop() {
	EPoll* pPoll = EPoll::Instance();
	pPoll->add(m_sock, *this);

	pPoll->del(m_sock);

	m_innerConnectionManager.closeAllConnection();
}

void TCPServer::accept() {
	sockaddr_in addr = { 0 };
	int iClientAddrLen = sizeof(addr);
#ifdef _WIN32
	Socket::OSSocket clientSock = ::accept(m_sock, (sockaddr*) &addr,
			&iClientAddrLen);
#else
	Socket::OSSocket clientSock = ::accept(m_sock, (sockaddr*) &addr,
			(socklen_t*) &iClientAddrLen);
#endif

	if (Socket::InvalidSocket == clientSock) {
		throw OSErrorException("accept invalid client socket.");
	}

	Socket::SetNonblocking(clientSock);

	if ( NULL != m_pConnectionManager) {
		m_pConnectionManager->onNewConnection(clientSock);
	}

	m_innerConnectionManager.onNewConnection(clientSock);

	EPoll* pPoll = EPoll::Instance();
	pPoll->add(clientSock, m_innerConnectionManager);
}

void TCPServer::InnerConnectionManager::onError(t_fd fd) {
	EPoll* pPoll = EPoll::Instance();
	pPoll->del(fd);

	if ( NULL != m_pOuter->m_pConnectionManager) {
		m_pOuter->m_pConnectionManager->onError(fd);
	}
}

void TCPServer::InnerConnectionManager::onClose(t_fd fd) {
	EPoll* pPoll = EPoll::Instance();
	pPoll->del(fd);

	if ( NULL != m_pOuter->m_pConnectionManager) {
		m_pOuter->m_pConnectionManager->onClose(fd);
	}
}

void TCPServer::InnerConnectionManager::onNewConnection(t_fd fd) {
	m_listFd.push_back(fd);
}

void TCPServer::InnerConnectionManager::closeAllConnection() {
	ConnectionFDList::iterator i;
	for (i = m_listFd.begin(); i != m_listFd.end(); ++i) {
		Connection c;
		c.attach(*i);

		c.close();
	}

	m_listFd.clear();
}

