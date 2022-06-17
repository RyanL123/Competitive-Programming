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
    // dfs return 0 if leaf
    // 1 if parent of leaf
    // 2 if it's covered without a camera on the node
    int res = 0;
    int dfs(TreeNode* root) {
        if (!root) return 2; // null node, consider covered
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) { // parent of leaf
            res++;
            return 1;
        }
        // if either side is covered, return 2 as node is covered
        // neither side has camera, so this node is not covered and can be considered a leaf
        return left == 1 || right == 1 ? 2 : 0;
    }
    int minCameraCover(TreeNode* root) {
        // dfs at root = 0 -> children of root do not have camera, must place one at root
        return (dfs(root) == 0 ? 1 : 0) + res;
    }
};