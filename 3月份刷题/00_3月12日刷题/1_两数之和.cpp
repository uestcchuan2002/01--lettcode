#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m_map;
    for (int i = 0; i < nums.size(); i++) {
        auto it = m_map.find(target - nums[i]);
        if (it != m_map.end()) {
            return {it->second, i};
        }
        m_map[nums[i]] = i;
    }
    return {};
}

// 必须包含 main() 函数作为程序入口！
int main() {
    // 测试用例
    vector<int> nums = {1, 7, 11, 15};
    int target = 16;
    vector<int> res = twoSum(nums, target);
    
    // 输出结果
    cout << "两数之和的下标：" << res[0] << " " << res[1] << endl;
    return 0;
}