#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream iss(sentence);
        string word;
        int i = 0;

        while (iss >> word)
        {
            // Kelimenin başlangıcı prefix ile eşleşiyor mu kontrol et
            if (word.rfind(searchWord, 0) == 0)
            { // rfind(prefix, 0) -> Başlangıçta kontrol eder
                std::cout << word << " prefix ile uyusuyor." << std::endl;
                return ++i;
            }
            else
            {
                std::cout << word << " prefix ile uyusmuyor." << std::endl;
            }
            i++;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    string case1 = "i love eating burger";
    string search1 = "burg";

    string case2 = "this problem is an easy problem";
    string search2 = "pro";

    string case3 = "i am tired";
    string search3 = "you";

    cout << "case1: " << sol.isPrefixOfWord(case1, search1) << endl;
    cout << "case2: " << sol.isPrefixOfWord(case2, search2) << endl;
    cout << "case3: " << sol.isPrefixOfWord(case3, search3) << endl;

    return 0;
}