/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> a, b;
        while (headA) {
            a.push(headA);
            headA = headA->next;
        }
        while (headB) {
            b.push(headB);
            headB = headB->next;
        }
        if (a.empty() || b.empty()) return NULL;
        ListNode* ret = NULL;
        while (!a.empty() && !b.empty()) {
            if (a.top() == b.top()) ret = a.top();
            a.pop(), b.pop();
        }
        return ret;
    }
};