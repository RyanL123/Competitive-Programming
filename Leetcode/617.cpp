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
    void dfs(TreeNode* root1, TreeNode* root2) {
        TreeNode *l1, *l2, *r1, *r2;
        root1->val += root2->val;
        l1 = root1->left, l2 = root2->left, r1 = root1->right, r2 = root2->right;
        if (!l1 && l2) root1->left = root2->left;
        else if (l1 && l2) {
            dfs(root1->left, root2->left);
        }
        if (!r1 && r2) root1->right = root2->right;
        else if (r1 && r2) {
            dfs(root1->right, root2->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        dfs(root1, root2);
        return root1;
    }
};