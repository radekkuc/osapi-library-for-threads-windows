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
        thread->state = READY;
        return 0;
    }

    public:

        /** Thread constructor.
         *  @param[in] priority thread priority
         *  @param[in] stackSize thread stack size in bytes
         *  @param[in] isJoinable decides if the thread supports join operation or not
         *  @param[in] name optional thread name
         */
        Thread(int priority, unsigned int stackSize, Joinable joinable, const char* name = "unnamed") :   
        name(name), handle(nullptr) {
            
            
        }
        
        /** Virtual destructor required to properly destroy derived class objects. */
        virtual ~Thread() { 
            
        }
        
        /** Runs the thread.
         *  @retval true if the thread was started successfully,
         *  @retval false if the thread was not started successfully, or the thread was already running
         */
        virtual bool run() {
            if(handle != nullptr) {
                return false;
            }

            handle = CreateThread(nullptr, stackSize, Thread::entry_function, this, 0, nullptr);
            if(handle) {
                state = RUNNING;
                return true;
            }
            return false;
        }
        
        /** Checks if the thread is running.
         *  @retval true if the thread is running
         *  @retval false if the thread is not running
         */
        virtual bool isRunning() {
            // TODO
            return false;
        }

        /** Waits for the thread to finish executing, with a given timeout.
         *  @param timeout[in] number of milliseconds to wait for the thread to finish executing
         *  @retval true if the thread was successfully joined in the given time
         *  @retval false if the thread was not joined within the given time or the thread is not joinable at all
         */
        virtual bool join(unsigned int timeout) {
            // TODO
            return false;
        }

        /** Checks, if the thread is joinable.
         *  @retval true if the thread is joinable
         *  @retval false if the thread is not joinable
         */
        virtual bool isJoinable() {
            // TODO
            return false;
        }

        /** Suspends thread execution.
         *  @retval true if the thread was suspended successfully
         *  @retval false if the thread was not suspended for some reason
         */
        virtual bool suspend() {
            // TODO
            return false;
        }

        /** Resumes thread execution.
         *  @retval true if the thread was resumed successfully
         *  @retval false if the thread was not resumed for some reason
         */
        virtual bool resume() {
            // TODO
            return false;
        }

        /** Sets thread priority
         *  @param[in] priority new thread priority
         *  @retval true if the priority for the thread was set successfully
         *  @retval false if the priority for the thread was not set successfully for some reason
         */
        virtual bool setPriority(int priority) {
            // TODO
            return false;
        }

        /** Gets the thread priority
         *  @return current thread priority
         */
        virtual int getPriority() {
            // TODO
            return 0;
        }
        
        /** Gets thread name
         *  @return name of the thread
         */
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

        /** Delays thread execution for a given time.
         *  @param time[in] number of milliseconds to delay thread execution
         */
        virtual void sleep(unsigned int time) {
            // TODO
        }
};

} // namespace osapi

#endif // OSAPI_THREAD_WINDOWS_H
