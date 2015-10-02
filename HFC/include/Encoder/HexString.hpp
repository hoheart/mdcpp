#ifndef __HEX_STRING_HPP__
#define __HEX_STRING_HPP__

#include "../hfc_def.hpp"

#include "../Lang/String.hpp"
using namespace HFC::Lang;

namespace HFC {
namespace Encoder {

/**
 * 用php-5.3.13的base函数改写。
 */
class HFC_API HexString {

public:

	HexString() {
	}
	virtual ~HexString() {
	}

public:

	static String Encode(const String& str);

	static String Decode(const String& str);

};

}
}

#endif
