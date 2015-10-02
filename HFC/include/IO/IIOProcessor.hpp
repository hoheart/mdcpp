#ifndef __I_IO_PROCESSOR_HPP__
#define __I_IO_PROCESSOR_HPP__

#include "../hfc_def.hpp"

namespace HFC {
namespace IO {

class HFC_API IIOProcessor {

public:

	virtual ~IIOProcessor() {
	}

public:

	virtual void onNewData(t_fd fd) = 0;

	virtual void onWritable(t_fd fd) = 0;

	virtual void onError(t_fd fd) = 0;

	virtual void onClose(t_fd fd) = 0;
};

}
}
#endif
