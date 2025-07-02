#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
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
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 2, 1};
    int result = majorityElement(nums);
    cout << "Majority Element: " << result << endl;
    return 0;
}
