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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
            return (l1 != NULL) ? l1 : l2;
        
        ListNode *head = NULL, *now = NULL;
        if (l1->val < l2->val) {
            head = now = l1;
            l1 = l1->next;
        }
        else {
            head = now = l2;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                now->next = l1;
                l1 = l1->next;
            }
            else {
                now->next = l2;
                l2 = l2->next;
            }
            now = now->next;
        }
        now->next = (l1 == NULL) ? l2 : l1;
        
        return head;
    }
};
