#ifndef __SERVICE_STOPED_EXCEPTION_HPP__
#define __SERVICE_STOPED_EXCEPTION_HPP__

#include "../Lang/Exception.hpp"
using namespace HFC;

#include "../Error.hpp"

namespace HFC {
namespace Util {

class HFC_API ServiceStopedException: public Exception {

public:

	ServiceStopedException() {
		m_iErrno = ServiceStoped;
	}
};
}
}
#endif
