#include <iostream>
#include <chrono>

int DoSomeLongRunningThing()
{
    int counter = 0;
    for (int i = 0; i < 9000; i++)
    {
        std::cout << " " << std::endl;
        counter += 1;
    }
    return counter;
}

int main(int argc, char** argv)
{
    // run through first function ("Hello World")
        // begin stopwatch
    auto _start = std::chrono::high_resolution_clock::now();
    std::cout << "Hello World" << std::endl;
        // end stopwatch
    auto _end = std::chrono::high_resolution_clock::now();

    // collect total time by getting the difference between the two time stamps 
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(_end - _start);

    // run through second function (DoSomeLongRunningThing)
        // begin stopwatch
    _start = std::chrono::high_resolution_clock::now();
    DoSomeLongRunningThing();
        // end stopwatch
    _end = std::chrono::high_resolution_clock::now();

    // collect total time by getting the difference between the two time stamps 
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start);
    
    // print results
    std::cout << "\t" << "First function time in milliseconds: " << duration1.count() << std::endl;

    std::cout << "\t" << "Second function time in milliseconds: " << duration2.count() << std::endl;
}