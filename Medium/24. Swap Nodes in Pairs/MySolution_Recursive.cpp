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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tmp1 = NULL, *tmp2 = NULL, *res = NULL;

        if (!head || !head->next) {
            return head;
        }

        tmp1 = head->next;
        tmp2 = head->next->next;
        tmp1->next = head;
        res = swapPairs(tmp2);
        head->next = res;

        return tmp1;
    }
};
