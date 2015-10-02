#include "../../include/Concurrent/Locker.hpp"
using namespace HFC::Concurrent;
	
#include "../../include/Util/OSErrorException.hpp"
using namespace HFC::Util;

Locker::Locker() {

#ifdef _WIN32

	InitializeCriticalSection( &mMutex );

#else

	if (0 != pthread_mutex_init(&mMutex, NULL)) {
		throw OSErrorException( "pthread_mutex_init error." );
	}

#endif

}

Locker::~Locker() {

#ifdef _WIN32

	DeleteCriticalSection( &mMutex );

#else

	if (0 != pthread_mutex_destroy(&mMutex)) {
		throw OSErrorException("pthread_mutex_destroy error.");
	}

#endif

}

void Locker::lock() {

#ifdef _WIN32

	EnterCriticalSection( &mMutex );

#else

	if (0 != pthread_mutex_lock(&mMutex)) {
		throw OSErrorException( "pthread_mutex_lock error." );
	}

#endif

}

void Locker::unlock() {

#ifdef _WIN32

	LeaveCriticalSection( &mMutex );

#else

	if (0 != pthread_mutex_unlock(&mMutex)) {
		throw OSErrorException( "pthread_mutex_unlock error." );
	}

#endif

}
