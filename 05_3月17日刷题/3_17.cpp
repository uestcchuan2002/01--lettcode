#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

bool isCover(int cnt_s[], int cnt_t[]) {
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cnt_s[i] < cnt_t[i]) {
			return false;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt_s[i] < cnt_t[i]) {
			return false;
		}
	}
	return true;
}

string minWindow(string s, string t) {
	int cnt_s[128];
	int cnt_t[128];
    memset(cnt_s, 0, sizeof(cnt_s));
    memset(cnt_t, 0, sizeof(cnt_t));
	for (char c : t) {
		cnt_t[c]++;
	}

	int s_len = s.size();
	int ans_left = -1;
	int ans_right = s_len;
	int left = 0;
	for (int right = 0; right < s_len; right++) {
		cnt_s[s[right]]++;
		while (isCover(cnt_s, cnt_t)) {
			if (right - left < ans_right - ans_left) {
				ans_left = left;
				ans_right = right;
			}
			cnt_s[s[left]]--;
			left++;
		}
	}
	return ans_left < 0 ? "" : s.substr(ans_left, (ans_right - ans_left + 1));
}

	
int main() {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << minWindow(s, t) << endl;
	return 0;
}
