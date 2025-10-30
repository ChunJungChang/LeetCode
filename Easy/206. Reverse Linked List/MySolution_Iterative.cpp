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
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *node_ptr_1 = head;
        ListNode *node_ptr_2 = head->next;
        ListNode *node_ptr_3 = head->next->next;
        
        node_ptr_1->next = NULL;
        while (node_ptr_3 != NULL) {
            node_ptr_2->next = node_ptr_1;
            node_ptr_1 = node_ptr_2;
            node_ptr_2 = node_ptr_3;
            node_ptr_3 = node_ptr_3->next;
        }
        node_ptr_2->next = node_ptr_1;
        
        return node_ptr_2;
    }
};
