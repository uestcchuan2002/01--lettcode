#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    for (int i = 1;; i++)
    {
        auto it = s.find(i);
        if (it != s.end())
        {
            continue;
        }
        return i;
    }
    return 1;
}

void setZero_H(vector<vector<int>> &matrix, int h)
{
    int len = matrix[0].size();
    for (int i = 0; i < len; i++)
    {
        matrix[h][i] = 0;
    }
}

void setZero_V(vector<vector<int>> &matrix, int h)
{
    int len = matrix.size();
    for (int i = 0; i < len; i++)
    {
        matrix[i][h] = 0;
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    unordered_map<int, vector<int>> m;
    int len_x = matrix[0].size();
    int len_y = matrix.size();
    int nums = 1;
    for (int i = 0; i < len_y; i++)
    {
        for (int j = 0; j < len_x; j++)
        {
            if (matrix[i][j] == 0)
            {
                m[nums].push_back(i);
                m[nums].push_back(j);
                nums++;
            }
        }
    }
    for (auto it : m)
    {
        int x = it.second[0];
        int y = it.second[1];
        setZero_H(matrix, x);
        setZero_V(matrix, y);
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    if (matrix.empty())
        return ans;
    int u = 0;
    int d = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    while (1)
    {
        for (int i = l; i <= r; i++)
        {
            ans.push_back(matrix[u][i]);
        }
        if (++u > d)
            break;
        for (int i = u; i <= d; i++)
        {
            ans.push_back(matrix[i][r]);
        }
        if (--r < l)
            break;
        for (int i = r; i >= l; i--)
        {
            ans.push_back(matrix[d][i]);
        }
        if (--d < u)
            break;
        for (int i = d; i >= u; i--)
        {
            ans.push_back(matrix[i][l]);
        }
        if (++l > r)
            break;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 0};
    cout << firstMissingPositive(nums) << endl;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}