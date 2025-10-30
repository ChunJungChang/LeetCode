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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *fir = head;
        ListNode *sec = head->next;
        ListNode *res = head->next->next;
        
        sec->next = fir;
        fir->next = swapPairs(res);
        
        return sec;
    }
};
