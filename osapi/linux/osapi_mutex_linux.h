#ifndef OSAPI_MUTEX_LINUX_H
#define OSAPI_MUTEX_LINUX_H

namespace osapi {

class Mutex : public MutexInterface
{
public:
	Mutex() {
		// TODO
	}
	virtual ~Mutex() {
		// TODO
	}
	virtual bool lock(unsigned int timeout) {
		// TODO
		return false;
	}
	virtual void unlock() {
		// TODO
	}
};

} // namespace osapi

#endif // OSAPI_MUTEX_LINUX_H
