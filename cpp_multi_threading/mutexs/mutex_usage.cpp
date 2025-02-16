#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <list>
#include <mutex>
#include <algorithm>

using namespace std;

list<int> some_list;
mutex some_mutex;

// safeGuard unlock data whenever it gets out of the scope

void add_to_list(int new_value)
{
    lock_guard<mutex> guard(some_mutex);

    some_list.push_back(new_value);
}
bool list_contains(int values_to_find)
{
    lock_guard<mutex> guard(some_mutex);

    return find(some_list.begin(), some_list.end(), values_to_find) != some_list.end();
}

void addElements()
{
    // lock_guard<mutex> guard(some_mutex);

    for (int i = 0; i < 10; i++)
    {
        add_to_list(i);
        cout << "added:" << i << endl;
    }
}

void findElements()
{
    // lock_guard<mutex> guard(some_mutex);
    for (int i = 0; i < 10; i++)
    {
        cout << "looking for: " << i << " results: " << list_contains(i) << endl;
    }
}

int main(int argc, char const *argv[])
{
    thread add(addElements);
    thread search(findElements);

    add.join();
    search.join();

    return 0;
}