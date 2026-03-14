#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		int left = i + 1;
		int right = len - 1;
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		while (left < right) {
			if (nums[i] + nums[left] + nums[right] > 0) {
				right--;
			} else if (nums[i] + nums[left] + nums[right] < 0) {
				left++;
			} else {
				ans.push_back({nums[i], nums[left], nums[right]});
				while (left < right && nums[left] == nums[left + 1])
					left++;
				while (left < right && nums[right] == nums[right - 1]) 
					right--;
				left++;
				right--;
			}
		}
	}
	return ans;
}


int main() {
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> ans = threeSum(nums);
	for (auto &i : ans) {
		cout << "{" ;
		for (auto &j : i) {
			cout << j << " ";
		}
		cout << "}" << endl;
	}
	return 0;
}


