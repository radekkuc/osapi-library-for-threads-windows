#ifndef OSAPI_RECURSIVE_MUTEX_WINDOWS_H
#define OSAPI_RECURSIVE_MUTEX_WINDOWS_H

namespace osapi {

class RecursiveMutex : public MutexInterface {
private:
    HANDLE mutexH;
public:
    RecursiveMutex() {
        mutexH = CreateMutex(0, false, 0);
    }
    virtual ~RecursiveMutex() {
        CloseHandle(mutexH);
    }
    virtual bool lock(unsigned int timeout) {
        if(!mutexH) return false;
        if(WaitForSingleObject(mutexH, timeout) == WAIT_OBJECT_0) {
            return true;
        }
        return false;
    }
    virtual void unlock() {
        if(!mutexH) return;
        ReleaseMutex(mutexH);
    }
};

} // namespace osapi

#endif // OSAPI_RECURSIVE_MUTEX_WINDOWS_H
