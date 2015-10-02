#ifndef __INVALID_PARAMETER_EXCEPTION_HPP__
#define __INVALID_PARAMETER_EXCEPTION_HPP__

#include "../Lang/Exception.hpp"
using namespace HFC;

#include "../Error.hpp"

namespace HFC {
namespace Lang {

class InvalidParameterException: public Exception {

public:

	InvalidParameterException() {
		m_iErrno = InvalidParameter;
	}
};

}
}
#endif
