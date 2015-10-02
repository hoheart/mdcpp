#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include "../hfc_def.hpp"
using namespace HFC;

#include "../Lang/String.hpp"
using namespace HFC::Lang;

namespace HFC {
namespace Lang {

class HFC_API Exception {

public:

	int m_iErrno;
	String m_strErrstr;

public:

	Exception() :
			m_iErrno(0) {
	}

	Exception(const int errno) {
		m_iErrno = errno;
	}

	Exception(const String& errstr) :
			m_iErrno(0) {
		m_strErrstr = errstr;
	}

	Exception(const int errno, const String& errstr) {
		m_iErrno = errno;
		m_strErrstr = errstr;
	}
};
}
}
#endif
