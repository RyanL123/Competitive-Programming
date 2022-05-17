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
    void dfs(Node* (&id)[5000], Node* root, int cur) {
        if (!root) return;
        id[cur] = root;
        if (root->left) dfs(id, root->left, cur*2);
        if (root->right) dfs(id, root->right, cur*2+1);
    }
    Node* connect(Node* root) {
        Node* id[5000];
        memset(id, 0, sizeof(id));
        dfs(id, root, 1);
        int i = 1;
        while (id[i]) {
            id[i]->next = id[i+1];
            i++;
        }
        int j = 1;
        i = 1;
        while (i < 5000 && id[i]) {
            id[i]->next = NULL;
            i += 1<<(j++);
        }
        return root;
    }
};