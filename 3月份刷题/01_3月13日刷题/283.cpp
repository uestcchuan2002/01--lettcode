#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int left = 0;
	int right = 0;
	while (right < nums.size()) {
		if (nums[right] != 0) {
			swap(nums[right], nums[left]);
			left++;
		}
		right++;
	}
}

int main() {
	vector<int> nums = {0, 1, 0, 3, 12, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] <<" ";
	}
	cout << endl;
	return 0;
}
