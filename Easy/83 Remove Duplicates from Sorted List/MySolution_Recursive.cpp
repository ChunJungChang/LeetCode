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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp;
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        tmp = deleteDuplicates(head->next);
        
        if (head->val == tmp->val) {
            return tmp;
        } else {
            head->next = tmp;
            return head;
        }
    }
};
