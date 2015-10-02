#ifndef __I_CONNECTION_MANAGER_HPP__
#define __I_CONNECTION_MANAGER_HPP__

#include "../hfc_def.hpp"
using namespace HFC;

#include "../IO/IIOProcessor.hpp"
using namespace HFC::IO;

namespace HFC {
namespace Net {

class IConnectionManager: public IIOProcessor {

public:

	virtual ~IConnectionManager() {
	}

public:

	virtual void onNewConnection(const t_fd c) = 0;

	virtual void onConnectionClose(const t_fd c) = 0;

	virtual void onConnectionError(const t_fd c) = 0;
};

}
}

#endif
