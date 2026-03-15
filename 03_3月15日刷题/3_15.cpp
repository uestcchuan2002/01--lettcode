#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		int len = s.size();
		int left = 0;
		unordered_map<char, int> m;
		for (int right = 0; right < len; right++) {
			m[s[right]]++;
			while (m[s[right]] > 1) {
				m[s[left]]--;
				left++;
			}
			ans = max(ans, right - left + 1);
		}
		return ans;
	}

	vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
		int p_len = p.size();
		int cnt[26] = {};
		for (char c : p) {
			cnt[c - 'a']++;
		}

		int left = 0;
		for (int right = 0; right < s.size(); right++) {
			int c = s[right] - 'a';
			cnt[c]--;
			while (cnt[c] < 0) {
				cnt[s[left] - 'a']++;
				left++;
			}
			if (right - left + 1 == p_len) {
				ans.push_back(left);
			}
		}
		return ans;
    }

	int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
		vector<int> a(nums.size() + 1);
		for (int i = 0; i < nums.size(); i++) {
			a[i + 1] = a[i] + nums[i];
		}

		unordered_map<int, int> m;
		for (int i : a) {
			auto it = m.find(i - k);
			if (it != m.end()) {
				ans += it->second;
			}
			m[i]++;
		}
		return ans;
    }
};

int main() {
	string s = "abcabcbb";	//≤‚ ‘1
	string s1 = "cbaebabacd", p1 = "abc";
	vector<int> nums = {1, 1, 1};
	int k = 2;
	Solution test;
	cout << "≤‚ ‘1: " << test.lengthOfLongestSubstring(s) << endl;

	cout << "≤‚ ‘2: " << test.findAnagrams(s1, p1).size() << endl;

	cout << "≤‚ ‘3: " << test.subarraySum(nums, k) << endl;
	
	return 0;
}


