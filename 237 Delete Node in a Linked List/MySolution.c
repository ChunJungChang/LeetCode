/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    if (node->next->next == NULL) {
        node->next = NULL;
    } else {
        deleteNode(node->next);
    }
}
