#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    //--->>>4
    // Approch-4 optimal ....Bayer Moore's AlgoT.C - O(N),S.C-O(1)
    int el = 0;  // candidate
    int cnt = 0; // count
    // for find majority element (>n/2 times)
    for (int i = 0; i < nums.size(); i++)
    {
        // es loop se mere ko majority vala element milega
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    // for varification process
    int cnt1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el)
            cnt1++;
    }
    if (cnt1 > nums.size() / 2)
    {
        return el;
    }
    return 0;

    /*
     //-->>3
     Hashing mathoda T.C-(N) S.C - O(N)
        unordered_map<int , int> freq ;


        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(auto it:freq){
            if(it.second>nums.size()/2){
                return it.first;
            }
        }
        return 0;
    */

    /*
        //-->2
        // by sorting... T.C - 0(nlogn) s.c - O(1)
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;
        if(nums[mid]==nums[mid+1]) {
            return nums[mid];
        }
        return 0;
    */

    /*
        //-->>1 Bruth force approch T.C-O(N^2) , S.C-O(1)
       // 2-loop chla do and count find krke nums.size()/2 se compaire krvado
       for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
            if(count > nums.size() / 2) {
                return nums[i];
            }
        }
        return -1; // Return -1 if no majority element found
    */
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 2, 2};
    int result = majorityElement(nums);
    cout << "Majority Element: " << result << endl;
    return 0;
}
