#ifndef OSAPI_MUTEX_FREERTOS_H
#define OSAPI_MUTEX_FREERTOS_H

#include "osapi_mutex_interface.h"

namespace osapi {

/** Mutex implementation for FreeRTOS. */
class Mutex : public MutexInterface
{
    public:
        /** Constructor */
        Mutex() {
            // TODO
        }

        /** Destructor */
        virtual ~Mutex() {
            // TODO
        }

        /** Locks the mutex.
         *  @param[in] timeout maximum number of milliseconds to wait for mutex
         *  @retval true if the mutex was successfully locked
         *  @retval false if the mutex could not be locked within the timeout
         */
        virtual bool lock(unsigned int timeout) override {
            // TODO
            return false;
        }

        /** Unlocks the mutex */
        virtual void unlock() override {
            // TODO
        }
};

} // namespace osapi

#endif // OSAPI_MUTEX_FREERTOS_H
