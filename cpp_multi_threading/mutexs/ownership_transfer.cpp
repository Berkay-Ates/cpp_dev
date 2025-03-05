#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

unique_lock<mutex> get_lock()
{
    extern mutex some_mutex;
    unique_lock<mutex> lk(some_mutex);
    // perpare data
    return lk;
}

void process_data()
{
    unique_lock<mutex> lk(get_lock());
    // do_something();
}

extern mutex the_mutex;
void get_and_process_data()
{
    unique_lock<mutex> my_lock(the_mutex);
    // some_class data_to_ptocess=get_next_data_chunk();
    my_lock.unlock();
    // result_type result = process(data_to_process);
    my_lock.lock();
    // write_reult(data_to_process,result);
}

int main(int argc, char const *argv[])
{

    return 0;
}