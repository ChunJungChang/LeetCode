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
        ListNode *rest = head->next->next;
        ListNode *bef = sec;
        head = sec;
        
        bef->next = fir;
        fir->next = rest;
        if (rest == NULL)
            return head;
        bef = fir;

        while (rest != NULL && rest->next != NULL) {
            fir = rest;
            sec = rest->next;
            rest = rest->next->next;
            bef->next = sec;
            bef = sec;
            bef->next = fir;
            bef = fir;
        }
        
        bef->next = rest;
        return head;
    }
};
