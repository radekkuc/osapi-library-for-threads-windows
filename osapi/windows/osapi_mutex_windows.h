#ifndef OSAPI_MUTEX_WINDOWS_H
#define OSAPI_MUTEX_WINDOWS_H

namespace osapi {

class Mutex : public MutexInterface {
private:
    HANDLE mutexH;
    bool locked = false;
    DWORD id;
public:
    Mutex() {
        mutexH = CreateMutex(0, false, 0);
        id = 0;
    }

    virtual ~Mutex() {
        CloseHandle(mutexH);
    }

    virtual bool lock(unsigned int timeout) {
        if(!mutexH) return false;
        if(locked && (GetCurrentThreadId() == id)) return false;
        if(WaitForSingleObject(mutexH, timeout) == WAIT_OBJECT_0) {
            locked = true;
            id = GetCurrentThreadId();
            return true;
        } 
        return false;
    }

    virtual void unlock() {
        if(!locked || (GetCurrentThreadId() != id)) return;
        ReleaseMutex(mutexH);
        locked = false;
    }
};

} // namespace osapi

#endif // OSAPI_MUTEX_WINDOWS_H
