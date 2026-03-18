#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size();)
    {
        int first = intervals[i][0];
        int second = intervals[i][1];
        int j = i + 1;
        while (j < intervals.size() && second >= intervals[j][0])
        {
            second = max(second, intervals[j][1]);
            j++;
        }
        ans.push_back({first, second});
        i = j;
    }
    return ans;
}

int maxSubArray(vector<int>& nums) {
	int n = nums.size();
    vector<int> pre_sum(n + 1, 0);
    pre_sum[0] = 0;
       
    int min_pre = INT_MAX;
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    for (int i = 0; i < n; i++) {
    	pre_sum[i + 1] = pre_sum[i] + nums[i];
    }

    int maxSub = INT_MIN;
    for (int i = 0; i < n + 1; i++) {
    	maxSub = max(maxSub, pre_sum[i] - min_pre);
        min_pre = min(min_pre, pre_sum[i]);
    }
    return maxSub;
}


int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = maxSubArray(nums);
    cout << "Maximum subarray sum: " << max_sum << endl;            
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = merge(intervals);
    cout << "Merged intervals: ";
    for (const auto &interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }   
    cout << endl;
    return 0;
}


