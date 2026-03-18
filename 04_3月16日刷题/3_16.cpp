#include <iostream>
#include <unordered_map> 
#include <vector>
#include <deque>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int ans = 0;
	int len = nums.size();
	unordered_map<int, int> m;
	int curSum = 0;
	m[0]++;
	for (int i = 0; i < len; i++) {
		curSum += nums[i];
		if (m.find(curSum - k) != m.end()) {
			ans += m[curSum - k];
		}
		m[curSum]++;
	}
	return ans;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> ans(n - k + 1);
	deque<int> q;

	for (int i = 0; i < n; i++) {
		while (!q.empty() && nums[q.back()] <= nums[i]) {
			q.pop_back();
		}
		q.push_back(i);

		int left = i - k + 1;
		if (left > q.front()) {
			q.pop_front();
		}

		if (left >= 0) {
			ans[left] = nums[q.front()];
		}
	}
	return ans;
}

int main() {
	vector<int> nums = {1, 1, 1};
	int k = 2;
	cout << subarraySum(nums, k) << endl;
    vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    vector<int> result = maxSlidingWindow(nums1, k1);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
	return 0;
}

