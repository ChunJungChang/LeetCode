/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = NULL, *slow = NULL;
    bool ret = false;
    
    if (!head || !head->next || !head->next) {
        return ret;
    }
    
    fast = head->next->next;
    slow = head->next;
    while (fast && slow) {
        if (fast == slow) {
            ret = true;
            break;
        }
        if (!fast->next || !fast->next->next) {
            break;
        } else {
            fast = fast->next->next;
        }
        if (!slow->next) {
            break;
        } else {
            slow = slow->next;
        }
    }
    
    return ret;
}
