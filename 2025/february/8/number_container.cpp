#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm> // For std::remove
#include <functional>

using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // For std::lower_bound and std::remove

class NumberContainers
{
    std::map<int, std::vector<int>> values; // Stores sorted lists of indices for each number
    std::map<int, int> valuesMap;           // Stores the current number assigned to each index

    void insertSorted(std::vector<int> &vec, int value)
    {
        auto pos = std::lower_bound(vec.begin(), vec.end(), value);
        vec.insert(pos, value);
    }

public:
    NumberContainers() {}

    void change(int index, int number)
    {
        // If the index already has a number, remove it from the old number's list
        if (valuesMap.count(index))
        {
            int oldNumber = valuesMap[index];
            if (oldNumber != number)
            {
                // Remove the index from the old number's vector
                auto &oldVec = values[oldNumber];
                oldVec.erase(std::remove(oldVec.begin(), oldVec.end(), index), oldVec.end());

                // If the old number's vector becomes empty, erase it
                if (oldVec.empty())
                {
                    values.erase(oldNumber);
                }
            }
            else
            {
                return; // If the number is the same, no need to change anything
            }
        }

        // Insert the new index into the correct sorted position for the new number
        insertSorted(values[number], index);
        valuesMap[index] = number;
    }

    int find(int number)
    {
        auto it = values.find(number);
        if (it != values.end() && !it->second.empty())
        {
            return it->second[0]; // Return the smallest index for this number
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{

    NumberContainers *obj = new NumberContainers();
    obj->change(2, 10);
    int param_2 = obj->find(10);

    cout << param_2 << endl;

    return 0;
}