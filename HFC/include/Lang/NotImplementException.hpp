#ifndef __NOT_IMPLEMENT_EXCEPTION_HPP__
#define __NOT_IMPLEMENT_MEMORY_EXCEPTION_HPP__

#include "../hfc_def.hpp"

#include "../Lang/Exception.hpp"
using namespace HFC::Lang;

#include "../Error.hpp"
using namespace HFC;

namespace HFC {
namespace Lang {

class HFC_API NotImplementException: public Exception {

public:

	NotImplementException() {
		m_iErrno = NotImplement;
	}
};

}
}
#endif
