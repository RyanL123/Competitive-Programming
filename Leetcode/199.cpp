/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height[100];
    void helper(TreeNode* rt, vector<int> &ret, int d) {
        if (!rt) return;
        if (height[d] == 0x3f3f3f3f) {
            ret.push_back(rt->val);
        }
        height[d] = rt->val;
        if (rt->right) helper(rt->right, ret, d+1);
        if (rt->left) helper(rt->left, ret, d+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        memset(height, 0x3f, sizeof(height));
        vector<int> ret;
        helper(root, ret, 0);
        return ret;
    }
};