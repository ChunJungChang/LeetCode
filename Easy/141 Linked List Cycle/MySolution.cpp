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
    bool hasCycle(ListNode *head) {
        ListNode *nodeT, *nodeR;
        
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return false;

        nodeT = head->next;
        nodeR = head->next->next;

        while (nodeT != nodeR) {
            if (nodeT->next == NULL || nodeR->next == NULL || nodeR->next->next == NULL) {
                return false;
            }
            nodeT = nodeT->next;
            nodeR = nodeR->next->next;
        }
        return true;
    }
};
