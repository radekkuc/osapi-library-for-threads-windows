#ifndef OSAPI_RECURSIVE_MUTEX_WINDOWS_H
#define OSAPI_RECURSIVE_MUTEX_WINDOWS_H

namespace osapi {

class RecursiveMutex : public MutexInterface
{
public:
    RecursiveMutex() {
        // TODO
    }
    virtual ~RecursiveMutex() {
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

#endif // OSAPI_RECURSIVE_MUTEX_WINDOWS_H
