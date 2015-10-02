#ifndef __TIMEOUT_EXCEPTION_HPP__
#define __TIMEOUT_EXCEPTION_HPP__

#include "../hfc_def.hpp"
using namespace HFC;

#include "../Lang/Exception.hpp"
using namespace HFC::Lang;

#include "../Error.hpp"

namespace HFC {
namespace Concurrent {

class HFC_API TimeoutException: public Exception {

public:

	TimeoutException() {
		m_iErrno = Timeout;
	}
};

}
}
#endif
