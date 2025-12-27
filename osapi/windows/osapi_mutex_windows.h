#ifndef OSAPI_MUTEX_WINDOWS_H
#define OSAPI_MUTEX_WINDOWS_H

namespace osapi {

class Mutex : public MutexInterface {
private:
    HANDLE mutexH;
public:
    Mutex() {
        mutexH = CreateMutex(0, false, 0);
    }
    virtual ~Mutex() {
        CloseHandle(mutexH);
    }
    virtual bool lock(unsigned int timeout) {
        if(!mutexH) return false;
        WaitForSingleObject(mutexH, timeout);

    }
    virtual void unlock() {
        ReleaseMutex(mutexH);
    }
};

} // namespace osapi

#endif // OSAPI_MUTEX_WINDOWS_H
