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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            n++;
        }
        cur = head;
        int i = 0;
        while (cur != nullptr) {
            if (i == n/2) return cur;
            cur = cur->next;
            i++;
        }
        return NULL;
    }
};