#include "../../include/Crypto/Md5.hpp"
using namespace HFC::Crypto;

#include <openssl/md5.h>

Md5::Md5() {
}

Md5::~Md5() {
}

String Md5::Encrypt(const String::t_char* szSrc , const int iLen ) {
	unsigned char md[16] = { 0 };

	MD5((const unsigned char*) szSrc, iLen, md);

	String s( (const String::t_char*)md , sizeof(md));

	return s;
}
