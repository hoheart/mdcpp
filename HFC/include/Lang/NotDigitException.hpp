#ifndef __NOT_DIGIT_EXCEPTION_HPP__
#define __NOT_DIGIT_EXCEPTION_HPP__

#include "../hfc_def.hpp"
#include "../Lang/Exception.hpp"
using namespace HFC;

#include "../Error.hpp"

namespace HFC {
namespace Lang {

class HFC_API NotDigitException: public Exception {

public:

	NotDigitException() {
		m_iErrno = NotDigit;
	}
};

}
}
#endif
