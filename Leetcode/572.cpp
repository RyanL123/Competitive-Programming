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
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (root && subRoot) {
            if (root->val == subRoot->val) {
                return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
            }
            else return false;
        }
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ret = false;
        ret |= isSame(root, subRoot);
        if (root) {
            ret |= isSubtree(root->left, subRoot);
            ret |= isSubtree(root->right, subRoot);
        }
        return ret;
    }
};