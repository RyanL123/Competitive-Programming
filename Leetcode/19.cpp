/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *a = head, *b = head;
        for (int i = 0; i < n; i++) b = b->next;
        if (b == nullptr) return head->next;
        while (b->next != nullptr) {
            b = b->next;
            a = a->next;
        }
        a->next = a->next->next;
        return head;
    } 
};