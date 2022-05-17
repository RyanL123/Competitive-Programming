/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* target) {
        if (root->val == target->val) return root;
        if (root->left == root->right && root->right == nullptr) return nullptr;
        TreeNode *left = nullptr, *right = nullptr;
        if (root->left != nullptr) left = dfs(root->left, target);
        if (root->right != nullptr) right = dfs(root->right, target);
        return left == nullptr ? right : left;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target);
    }
};