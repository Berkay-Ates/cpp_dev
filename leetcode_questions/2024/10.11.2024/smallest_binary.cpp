#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int length = INT_MAX; // En küçük uzunluğu başlangıçta büyük bir değerle başlat
        int orPosition = 0;   // Alt dizinin bitişi
        int orResult = 0;     // OR işlemi sonucu
        int i = 0;

        while (i < (int)nums.size())
        {
            orPosition = i;
            orResult = 0;

            // İç döngü, orResult en az k'ya eşit olduğunda çalışmaya devam eder
            while (orPosition < (int)nums.size() && orResult < k)
            {
                orResult = orResult | nums[orPosition]; // OR işlemi
                orPosition++;                           // Yeni bir eleman ekle
            }

            // Eğer orResult k'ya eşit veya büyükse, alt dizi uzunluğunu kontrol et
            if (orResult >= k)
            {
                length = min(length, max(orPosition - i, 1)); // En küçük alt dizi uzunluğunu güncelle
            }

            i++;
        }

        // Eğer geçerli bir alt dizi bulunmuşsa, uzunluğu döndür, yoksa -1 döndür
        return length == INT_MAX ? -1 : length;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 1, 8};
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {1, 2, 32, 21};

    Solution sol;

    // Test örnekleri
    cout << sol.minimumSubarrayLength(nums1, 3) << endl;  // 2
    cout << sol.minimumSubarrayLength(nums2, 10) << endl; // 2
    cout << sol.minimumSubarrayLength(nums3, 0) << endl;  // 1
    cout << sol.minimumSubarrayLength(nums4, 55) << endl; // 1

    return 0;
}
