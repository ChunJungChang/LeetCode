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
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp = NULL;
        
        if (head == NULL || head->next == NULL)
            return head;
        if (head->next->next == NULL) {
            tmp = head->next;
            tmp->next = head;
            head->next = NULL;
            return tmp;
        }
        else {
            tmp = reverseList(head->next);
            ListNode *last = head;
            while (last->next != NULL)
                last = last->next;
            last->next = head;
            head->next = NULL;
            return tmp;
        }
    }
};
