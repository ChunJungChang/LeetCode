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
        head = head->next;
        
        // swap the first and second node
        fir->next = res;
        sec->next = fir;
        
        while (res != NULL && res->next != NULL) {
            ListNode *pre = fir;
            fir = res;
            sec = res->next;
            res = res->next->next;
            
            fir->next = res;
            sec->next = fir;
            pre->next = sec;
            
            if (res == NULL || res->next == NULL)
                break;
        }
        
        return head;
    }
};
