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

class MortalThread : public Thread {
    private:
    bool killSignal = false;
    public:
        MortalThread(int priority, unsigned int stackSize) : Thread(priority, stackSize, JOINABLE) {}
        virtual ~MortalThread() {}

        void kill() {  
            killSignal = true;
        }
        
        void job() override {
            begin();
            while(!killSignal) {
                loop();
            }
            end();
        }

    protected:
        virtual void begin() { ; }
        virtual void loop() = 0;
        virtual void end() { ; }
};

} // namespace osapi
 
#endif // OSAPI_MORTAL_THREAD_H