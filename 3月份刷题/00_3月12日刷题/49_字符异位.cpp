#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    // 采用引用的方式：避免拷贝字符串
    for (string &s : strs) {
        string s_old = s;
        sort(s_old.begin(), s_old.end());
        m[s_old].push_back(s);
    }

    vector<vector<string>> ans;
    ans.reserve(m.size());
    for (auto& pair : m) {
        vector<string>& value = pair.second;
        ans.push_back(value);
    }
    return ans;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (const auto& group : ans) {
        for (const auto& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
