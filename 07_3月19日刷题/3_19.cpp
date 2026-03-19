#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    // k有可能大于n
    k = k % n;
    if (k == 0)
        return;
    vector<int> temp(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            nums[i] = temp[n - k + i];
        }
        else
        {
            nums[i] = temp[i - k];
        }
    }
    return;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    vector<int> pre(n + 1, 1);
    vector<int> suf(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] * nums[i];
        suf[i + 1] = suf[i] * nums[n - 1 - i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp = pre[i] * suf[n - 1 - i];
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }   
    cout << endl;
    vector<int> ans = productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}