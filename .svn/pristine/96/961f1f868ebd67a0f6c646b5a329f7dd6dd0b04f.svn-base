#include "osapi.h"
#include <time.h>

namespace osapi {

unsigned int
getSystemTime()
{
    struct timespec ts;
    if (clock_gettime(CLOCK_BOOTTIME, &ts) < 0) {
        return 0;
	}
    return ts.tv_nsec / 1000000 + ts.tv_sec * 1000;
}

} // namespace osapi

