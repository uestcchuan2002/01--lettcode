#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 合并区间
        // 1.记录最远的字符下标
        int last[26];
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    string s = "ababcbacadefegdehijhklij";
    vector<int> v = so.partitionLabels(s);
    for (int i : v) {
        cout << i;
    }
    cout << endl;
    return 0;
}

