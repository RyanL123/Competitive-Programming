/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            Node* n = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (!q.empty()) {
                if (q.front().second == lvl) {
                    n->next = q.front().first;
                }
                else {
                    n->next = NULL;
                }
            }
            if (n && n->left) q.push({n->left, lvl+1});
            if (n && n->right) q.push({n->right, lvl+1});
        }
        return root;
    }
};