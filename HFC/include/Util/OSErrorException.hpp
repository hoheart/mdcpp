#ifndef __OS_ERROR_EXCEPTION_HPP__
#define __OS_ERROR_EXCEPTION_HPP__

#include "../Lang/Exception.hpp"
using namespace HFC::Lang;

#include "../Error.hpp"

namespace HFC {
namespace Util {

/**
 * 操作系统错误，调用操作系统API是出错。
 */
class OSErrorException: public Exception {

public:

	OSErrorException(const String& errstr) {
		m_iErrno = OSError;
		m_strErrstr = errstr;
	}
};

}
}
#endif
