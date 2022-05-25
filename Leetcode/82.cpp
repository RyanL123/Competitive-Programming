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
    ListNode* deleteDuplicates(ListNode* head) {
        bool seen[205];
        memset(seen, 0, sizeof(seen));
        ListNode *dummy = new ListNode(), *tail = dummy, *cur = head;
        while (cur) {
            if (!seen[cur->val+100]) {
                if (cur->next && cur->next->val == cur->val) {
                    seen[cur->val+100] = true;
                    cur = cur->next;
                    continue;
                }
                seen[cur->val+100] = true;
                tail->next = new ListNode(cur->val, nullptr);
                tail = tail->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};