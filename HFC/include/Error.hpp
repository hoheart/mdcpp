#ifndef __ERROR_HPP__
#define __ERROR_HPP__

namespace HFC {

enum Error {
	OK,
	NotDigit,
	InvalidParameter,
	OutOfMemory,
	RepeatedCall,
	OSError,
	InvalidFile,
	NotImplement,
	Timeout,
	ServiceStoped
};
}

#endif
