#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include "./generator.hpp"

using namespace std;
/**
 * use a ref to remove copying time overhead
 * no change on gen, so it's safe
 */
void ProducerTask(Generator &gen, atomic<bool> &is_running){

    const auto targetInterval = chrono::duration<double, milli>(1000.0 / gen.rate());
    while(is_running){
        auto startTime = chrono::high_resolution_clock::now();

        int data = gen.generate();

        cout << data << " generated" << '\n';

        auto endTime = chrono::high_resolution_clock::now();
        auto elapsedTime = endTime - startTime;
        if(elapsedTime < targetInterval){
            this_thread::sleep_for(targetInterval - elapsedTime);
        }
    }
} 


int main(int argc,[[maybe_unused]] char **argv){
    // this is just test
    int duration = 30;
    Generator gen(100, 60);
    
    cout << "Enter the duration you want the program to run for in seconds: ";
    cin >> duration;

    // we shall pass time in the args
    /**
    init gen, consumer, analyser
    create a thread that runs generate 60times a second
    consumer reads from some shared memory whenever it can, non-stop
    copies data to private buffer
    analyser uses it for any task
     */

    atomic<bool> is_running(true);

    thread producerThread(ProducerTask, ref(gen), ref(is_running));
    
    this_thread::sleep_for(chrono::seconds(duration));

    cout << "Halting Producer thread...\n";
    
    is_running = false;

    cout << "Producer Thread halted successfully!\n";


    
    producerThread.join();
    return 0;
}