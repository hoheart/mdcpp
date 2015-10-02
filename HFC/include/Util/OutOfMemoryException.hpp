#ifndef __OUT_OF_MEMORY_EXCEPTION_HPP__
#define __OUT_OF_MEMORY_EXCEPTION_HPP__

#include "../Lang/Exception.hpp"
using namespace HFC;

#include "../Error.hpp"

namespace HFC {
namespace Util {

class HFC_API OutOfMemoryException: public Exception {

public:

	OutOfMemoryException() {
		m_iErrno = OutOfMemory;
	}
};

}
}
#endif
