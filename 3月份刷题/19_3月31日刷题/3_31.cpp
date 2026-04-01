#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* build(vector<int>& preorder, vector<int>& inorder) {
    if (inorder.size() == 0) return nullptr;

    int rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);

    int delimiterIndex = 0;
    for (delimiterIndex; delimiterIndex < inorder.size(); delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue)   break;
    }

    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

    preorder.erase(preorder.begin());
    vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
    vector<int> rightPreorder(preorder.begin() + leftInorder.size(), preorder.end());

    root->left = build(leftPreorder, leftInorder);
    root->right = build(rightPreorder, rightInorder);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
    return build(preorder, inorder);
}

unordered_map<long long, int> prefixSum;
int target;
int Sum(TreeNode* root, long long curSum) {
    if (root == nullptr) return 0;

    int cnt = 0;
    curSum += root->val;

    if (prefixSum.find(curSum - target) != prefixSum.end()) {
        cnt += prefixSum[curSum - target];
    }
    prefixSum[curSum]++;

    cnt += Sum(root->left, curSum);
    cnt += Sum(root->right, curSum);

    prefixSum[curSum]--;

    return cnt;
}

int pathSum(TreeNode* root, int targetSum) {
    target = targetSum;
    prefixSum[0] = 1;
    return Sum(root, 0);        
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr && right == nullptr) return nullptr;
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    return root;    
}
 
int maxSum(TreeNode* root, int &val) {
    if (root == nullptr) return 0;
    int left = maxSum(root->left, val);
    int right = maxSum(root->right, val);
    int not_ret = root->val + max(0, left) + max(0, right);
    int ret = root->val + max(0, max(left, right));
    val = max (val, max(not_ret, ret));
    return ret;
}

int maxPathSum(TreeNode* root) {
    int val = INT_MIN;
    maxSum(root, val);
    return val;        
}

int main() {

    return 0;
}