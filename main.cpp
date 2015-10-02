#include <LogReceiver/include/LogReceiver.hpp>
using namespace Framework::Logger;

int main(int argc, char* argv[]) {
	LogReceiver* pReceiver = LogReceiver::Instance();
	pReceiver->setIP("*");
	pReceiver->setPort(9000);
	pReceiver->start();
	pReceiver->stop();

	return 0;
}
