#ifndef __AUTO_LOCKER_HPP__
#define __AUTO_LOCKER_HPP__

#include "Locker.hpp"
using namespace HFC::Concurrent;

namespace HFC {
namespace Concurrent {

class HFC_API AutoLocker {

public:
	AutoLocker(Locker& locker) {
		m_pLocker = &locker;
		m_pLocker->lock();
	}

	virtual ~AutoLocker() {
		m_pLocker->unlock();
	}

protected:

	Locker* m_pLocker;
};

}
}

#endif
