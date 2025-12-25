#ifndef OSAPI_THREAD_WINDOWS_H
#define OSAPI_THREAD_WINDOWS_H

#include "windows.h"
#include <stdlib.h>
#include "windows_proc_info.h"

namespace osapi {

/** Thread interface implementation for Windows. */
class Thread : public ThreadInterface {
    private:
    const char* name;
    int priority;
    unsigned int stackSize;
    Joinable joinable;
    HANDLE handle;
    ThreadState state;

    static DWORD entry_function(void* arg) {
        Thread* thread = static_cast<Thread*>(arg);
        if(thread) {
            thread->job();
        }
        thread->state = INACTIVE;

        return 0;
    }

    public:
        Thread(int priority, unsigned int stackSize, Joinable joinable, const char* name = "unnamed") :   
        name(name), priority(priority), stackSize(stackSize), joinable(joinable), handle(nullptr)  {
            
            
        }
        
        virtual ~Thread() { 
            if(handle) {
                // joinable means that we can wait for this thread, if something is not joinable then we do not have permission
                // for waiting even if thread is in FINISHED state
                if(joinable == JOINABLE) {
                    WaitForSingleObject(handle, INFINITE);
                }
                CloseHandle(handle);
                handle = nullptr;
                
            }
        }

        virtual bool run() {
            if(handle != nullptr) {
                return false;
            }

            handle = CreateThread(nullptr, stackSize, Thread::entry_function, this, 0, nullptr);
            if(handle) {
                state = RUNNING;
                SetThreadPriority(handle, priority);
                return true;
            }
            return false;
        }
        
        virtual bool isRunning() {
            if(!handle) return false;
            return state == RUNNING;
        }

        virtual bool join(unsigned int timeout) {
            if(joinable == JOINABLE && handle) {
                if(WaitForSingleObject(handle, timeout) == WAIT_OBJECT_0) {
                    state = INACTIVE;
                    return true;
                }
            }
            return false;
        }

        virtual bool isJoinable() {
            if(!handle) return false;
            return joinable == JOINABLE;
        }

        virtual bool suspend() {
            if(state != SUSPENDED && handle) {
                if(SuspendThread(handle) == ((DWORD) - 1)) return false;
                state = SUSPENDED;
                return true;
            }
            return false;
        }

        virtual bool resume() {
            if(state == SUSPENDED && handle) {
                if(ResumeThread(handle) == (DWORD) - 1) return false;
                state = RUNNING;
                return true; 
            }
            return false;
        }

        virtual bool setPriority(int priority) {
            this->priority = priority;
            SetThreadPriority(handle, priority);
            return true;
        }

        virtual int getPriority() {
            return priority;
        }
        
        virtual const char* getName() {
            return name;
        }

        /** Gets the current state of the thread
         *  @return current state of the thread
         */
        virtual ThreadState getState() {
            // TODO
            return UNKNOWN;
        }

        /** Gets the total size of the stack assigned for this thread
         *  @return total stack size in number of bytes
         */
        virtual unsigned int getTotalStackSize() {
            // TODO
            return 0;
        }

        /** Gets the size of the used stack for this thread
         *  @return number of bytes used on the stack
         */
        virtual unsigned int getUsedStackSize() {
            // TODO
            return 0;
        }

    protected:
        virtual void sleep(unsigned int time) {
            // Consider setting BLOCKED state 
            Sleep(time);
        }
};

} // namespace osapi

#endif // OSAPI_THREAD_WINDOWS_H
