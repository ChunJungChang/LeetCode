/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *ret = NULL, *cur = NULL;
    
    if (!l1 || !l2) {
        return l1 ? l1 : l2;
    }
    
    while (l1 && l2) {
        if (!ret) { /* For head */
            if (l1->val <= l2->val) {
                ret = l1;
                l1 = l1->next;
            } else {
                ret = l2;
                l2 = l2->next;
            }
            cur = ret;
        } else {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
    }
    
    cur->next = l1 ? l1 : l2;
    
    return ret;
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *end = NULL, *mid = NULL, *pre = NULL,
                    *l1 = NULL, *l2 = NULL, *ret = NULL;
    
    if (!head || !head->next)
        return head;
    
    pre = mid = end = head;
    while (end && end->next) {
        end = end->next->next; /* two steps */
        pre = mid;
        mid = mid->next; /* one step */
    }
    pre->next = NULL;
    
    l1 = sortList(head);
    l2 = sortList(mid);
    
    ret = mergeTwoLists(l1, l2);
    
    return ret;
}
