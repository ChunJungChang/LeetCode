struct node_t {
    struct node_t *pre;
    struct node_t *next;
    int val;
};

typedef struct {
    struct node_t *head;
    struct node_t *mid;
    int size;
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder *medianFinder = NULL;
    
    medianFinder = (MedianFinder *)malloc(sizeof(MedianFinder));
    if (!medianFinder) {
        return NULL;
    }
    medianFinder->head = NULL;
    medianFinder->mid = NULL;
    medianFinder->size = 0;
    
    return medianFinder;
}

void dumpLinkedlist(MedianFinder* obj) {
    struct node_t *nodeTGT = NULL;
    nodeTGT = obj->head;
	while (nodeTGT) {
		printf("%d ", nodeTGT->val);
		nodeTGT = nodeTGT->next;
	}
	printf("\n");
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    struct node_t *node = NULL, *nodePre = NULL, *nodeTGT = NULL;
    
    /*
	printf("AddNum==================================================\n");
    */
	
    if (!obj) {
        return;
    }
    
    node = (struct node_t*)malloc(sizeof(struct node_t));
    if (!node) {
        return;
    }
    node->val = num;
    node->pre = NULL;
    node->next = NULL;
	
	if (!obj->head) { /* Insert the node to empty linked list */
        obj->head = node;
        obj->mid = node;
        obj->size++;
        
        /*
        dumpLinkedlist(obj);
        */
        
        return;
	} else if (node->val <= obj->head->val) { /* Insert the node to the beginning of linked list */
		nodeTGT = obj->head;
        nodeTGT->pre = node;
		node->next = nodeTGT;
        obj->head = node;
        obj->size++;
        
        if (obj->size % 2 == 0) {
            obj->mid = obj->mid->pre;
        }
        
        /*
        dumpLinkedlist(obj);
        */
        
        return;
	} else if (node->val <= obj->mid->val) { /* Insert the node to the first half of linked list */
        nodePre = nodeTGT = obj->head;
    } else {
        nodePre = nodeTGT = obj->mid; /* Insert the node to the last half of linked list */
    }
    
	while (nodeTGT && nodeTGT->val < node->val) {
		nodePre = nodeTGT;
		nodeTGT = nodeTGT->next;
	}
		
	if (!nodeTGT) { /* Insert the node to the end of linked list */
		nodePre->next = node;
        node->pre = nodePre;
	} else { /* Insert node at the middle of linked list */
		nodePre->next = node;
        node->pre = nodePre;
		node->next = nodeTGT;
        nodeTGT->pre = node;
	}
    
    obj->size++;
    
    if (obj->size % 2 == 0) {
        if(num <= obj->mid->val) {
            obj->mid = obj->mid->pre;
        }
    } else {
        if(num > obj->mid->val) {
            obj->mid = obj->mid->next;
        }
    }
	
    /*
	dumpLinkedlist(obj);
    */
	
    /*
	printf("============================================================\n");
    */
}

double medianFinderFindMedian(MedianFinder* obj) {
    double ret = 0;
    
    /*
	printf("FindMedian==================================================\n");
    */

    if (obj->size % 2 == 0) {
        ret = (obj->mid->val + obj->mid->next->val) / 2.0;
        /*
        printf("sizeIsNotOdd, obj->mid->val: %d, obj->mid->next->val: %d, ret: %1f\n", obj->mid->val, obj->mid->next->val, ret);
        */
    } else {
        ret = obj->mid->val;
        /*
        printf("sizeIsOdd, obj->mid->val: %d, ret: %1f\n", obj->mid->val, ret);
        */
    }
    
    /*
	printf("============================================================\n");
    */
   
    return ret;
}

void medianFinderFree(MedianFinder* obj) {
    struct node_t *nodeTGT = NULL, *nodeNext = NULL;
    
    nodeTGT = obj->head;
    while (nodeTGT) {
        if (nodeTGT) {
            nodeNext = nodeTGT->next;
        }

        if (nodeTGT) {
            free(nodeTGT);
        }
        
        nodeTGT = nodeNext;
    }
    
    if (obj) {
        free(obj);
    }
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
