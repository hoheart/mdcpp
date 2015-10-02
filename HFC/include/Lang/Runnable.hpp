#ifndef __IRUNNABLE_HPP__
#define __IRUNNABLE_HPP__

#include "../hfc_def.hpp"

namespace HFC {
namespace Lang {

class HFC_API IRunnable {

public:

	virtual ~IRunnable() {
	}

public:

	virtual void run(void* pParam = NULL) = 0;
};

}
}

#endif
