#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return;
        int firstNumIndex = -1;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                firstNumIndex = i;
                break;
            }
        }
        if (firstNumIndex != -1) {
            int secondNumIndex = -1;
            for (int i = len - 1; i > firstNumIndex; i--) {
                if (nums[i] > nums[firstNumIndex]) {
                    secondNumIndex = i;
                    break;
                }
            }
            swap(nums[firstNumIndex], nums[secondNumIndex]);
        }
        reverse(nums.begin() + firstNumIndex + 1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 3, 4, 1};
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}