#ifndef __INVALID_FILE_EXCEPTION_HPP__
#define __INVALID_FILE_EXCEPTION_HPP__

#include "../Lang/Exception.hpp"
using namespace HFC::Lang;

#include "../Error.hpp"
using namespace HFC;

namespace HFC {
namespace IO {

/**
 * 文件不存在或文件格式不正确。
 */
class HFC_API InvalidFileException: public Exception {

public:

	InvalidFileException() {
		m_iErrno = InvalidFile;
	}
};

}
}
#endif
