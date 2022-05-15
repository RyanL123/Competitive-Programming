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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int deepest = 0, sum = 0;
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (lvl > deepest) {
                sum = node->val, deepest = lvl;
            } else if(deepest == lvl) sum += node->val;
            if (node->left != nullptr) q.push({node->left, lvl+1});
            if (node->right != nullptr) q.push({node->right, lvl+1});
        }
        return sum;
    }
};