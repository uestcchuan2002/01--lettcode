#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int len = temperatures.size();
    stack<int> st;
    vector<int> ans(len);
    for (int i = 0; i < len; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int j = st.top();
            st.pop();
            ans[j] = i - j;
        }
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            int j = st.top();
            st.pop();
            int w = i - st.top() - 1;
            ans = max(ans, w * heights[j]);
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    return 0;
}