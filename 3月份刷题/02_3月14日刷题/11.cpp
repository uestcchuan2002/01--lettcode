#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
	int left = 0;
	int right = height.size() - 1;
	int ans = 0;
	while (left < right) {
		int temp = (right - left) * min(height[left], height[right]);
		ans = max(ans, temp);
		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}
	return ans;
}

int main() {
	vector<int> nums = {1,8,6,2,5,4,8,3,7};
	int ans = maxArea(nums);
	cout << "ans:" << ans << endl;
	return 0;
}

