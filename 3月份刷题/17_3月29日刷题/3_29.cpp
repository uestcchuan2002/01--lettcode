#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

static int maxDepth = 0;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 求最大深度
int getDepth(TreeNode* cur) {
    if (cur == nullptr) return 0;
    int left = getDepth(cur->left);
    int right = getDepth(cur->right);
    maxDepth = max(left + right, maxDepth);
    return 1 + max(right, left);
}

// 求二叉树的直径
int diameterOfBinaryTree(TreeNode* root) {
    getDepth(root);
    return maxDepth;
}

// 二叉树的层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        ans.push_back(vec);
    }        
    return ans;
}

int main () {
    return 0;
}
