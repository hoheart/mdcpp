#ifndef __REPEATED_CALL_EXCEPTION_HPP__
#define __REPEATED_CALL_EXCEPTION_HPP__

#include "../Lang/Exception.hpp"
using namespace HFC::Lang;

#include "../Error.hpp"
using namespace HFC;

namespace HFC {
namespace Lang {

class HFC_API RepeatedCallException: public Exception {

public:

	RepeatedCallException() {
		m_iErrno = RepeatedCall;
	}
};
}
}
#endif
