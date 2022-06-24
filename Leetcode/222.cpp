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
    int dfsL(TreeNode* root) {
        if (!root) return 0;
        return dfsL(root->left)+1;
    }
    int dfsR(TreeNode* root) {
        if (!root) return 0;
        return dfsR(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = -1, rh = -1;
        lh = dfsL(root);
        rh = dfsR(root);
        if (lh == rh) return (1<<lh)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};  