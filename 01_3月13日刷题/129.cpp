#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_set<int> m_set(nums.begin(), nums.end());
	int longest = 0;
	for (auto &i : nums) {
		if (m_set.find(i - 1) == m_set.end()) {
			int currentNum = i;
			int currentLong = 1;
			while (m_set.find(currentNum + 1) != m_set.end()) {
				currentLong++;
				currentNum++;
			}

			longest = max(longest, currentLong);
			if (longest > m_set.size() /2) {
				break;
			}
			
		}
	}
	return longest;
}

int main() {
 	vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
	int ans = 0;
	ans = longestConsecutive(nums);
	cout << "ans:" << ans << endl;
    return 0;
}