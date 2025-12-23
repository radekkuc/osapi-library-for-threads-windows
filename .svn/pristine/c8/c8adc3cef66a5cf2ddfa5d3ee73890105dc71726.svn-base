// 
// 
// TODO: replace this with your own implementation !!!
// 
// This is just a mock
//
//

#ifndef OSAPI_MORTAL_THREAD_H
#define OSAPI_MORTAL_THREAD_H
 
namespace osapi {

class MortalThread
{
    public:
        MortalThread(int priority, unsigned int stackSize) { ; }
        virtual ~MortalThread() { ; }
        void kill() { ; }        
                bool run() { return false; }
                bool join(unsigned int timeout) { return false; }
                void sleep(unsigned int time) { ; }
    protected:
        virtual void begin() { ; }
        virtual void loop() = 0;
        virtual void end() { ; }
};

} // namespace osapi
 
#endif // OSAPI_MORTAL_THREAD_H