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
        int cnt = 0;
        ListNode* cur = head;

        if (!head) {
            return cur;
        }

        while (cur) {
            cnt++;
            cur = cur->next;
        }

        cnt = cnt / 2 + 1 - 1; /* The first of index is 1, thus, minors 1. */
        cur = head;
        while (cnt != 0) {
            cur = cur->next;
            cnt--;
        }

        return cur;
    }
};
