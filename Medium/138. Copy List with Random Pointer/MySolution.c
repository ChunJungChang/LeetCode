/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	struct Node *cur = NULL, *cur_find_random = NULL,
                *copied_head = NULL, *copied_cur = NULL, *copied_last = NULL, *copied_new = NULL, *copied_find_random = NULL,
                *trace = NULL;
    bool is_loop = false;
    
    if (!head) {
        return copied_head;
    }
    cur = head;
    
    while (cur) {       
        /* Create new node */
        copied_new = malloc(sizeof(struct Node));
        copied_new->val = cur->val;
        if (cur == head) {
            copied_head = copied_new;
            copied_last = copied_head;
        } else {
            copied_last->next = copied_new;
            copied_last = copied_last->next;
        }
        
        /* Only focus on the node which is in a loop */
        is_loop = false;
        trace = cur->random;
        do {
            if (!trace) {
                is_loop = false;
                break;
            } else if (trace == cur) {
                is_loop = true;
                break;
            } else {
                trace = trace->next;
            }
        } while (trace);
        if (is_loop) {
            cur_find_random = head;
            copied_find_random = copied_head;
            
            while (cur_find_random != cur->random) {
                cur_find_random = cur_find_random->next;
                copied_find_random = copied_find_random->next;
            }
            copied_new->random = copied_find_random;
        } else {
            copied_new->random = NULL;
        }
        
        cur = cur->next;
    }
    copied_last->next = NULL;
    
    /* Fixed the random pointer of nodes which is in copied list is NULL */
    cur = head;
    copied_cur = copied_head;
    while (cur) {
        if (cur->random && !copied_cur->random) {
            cur_find_random = cur;
            copied_find_random = copied_cur;
            while (cur_find_random != cur->random) {
                cur_find_random = cur_find_random->next;
                copied_find_random = copied_find_random->next;
            }
            copied_cur->random = copied_find_random;
        }
        cur = cur->next;
        copied_cur = copied_cur->next;
    }
    
    /* Debug */
    /*
    trace = copied_head;
    while (trace) {
        printf("trace->val: %d\n", trace->val);
        if (trace->random) {
            printf("trace->random->val: %d\n", trace->random->val);
        }
        trace = trace->next;
        printf("\n");
    }
    */
    
    return copied_head;
}
