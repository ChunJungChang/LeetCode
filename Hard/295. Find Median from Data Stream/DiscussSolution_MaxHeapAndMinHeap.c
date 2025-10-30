/**
 * https://stackoverflow.com/questions/22900388/why-in-a-heap-implemented-by-array-the-index-0-is-left-unused
 *                root at 0      root at 1
 * Left child     index*2+1      index*2
 * Right child    index*2+2      index*2+1
 * Parent         (index-1)/2    index/2
 */ 

struct maxHeap_t {
    int size;
    int *elms;
};

struct minHeap_t {
    int size;
    int *elms;
};

typedef struct {
    struct maxHeap_t *maxHeap;
    struct minHeap_t *minHeap;
} MedianFinder;

void maxInsert(struct maxHeap_t *maxHeap, int num) {
    int parent = 0, i = 0, j = 0;
    
    if (maxHeap->size == 0) {
        maxHeap->elms[0] = num;
        maxHeap->size = 1;
        
        return;
    }
    
    maxHeap->elms[maxHeap->size] = num;
    maxHeap->size += 1;
    for (i = maxHeap->size - 1; i > 0; i = parent) {
        parent = (i - 1) / 2; /* Parent */
        if (maxHeap->elms[parent] < num) {
            maxHeap->elms[i] = maxHeap->elms[parent];
        } else {
            break;
        }
    }
    maxHeap->elms[i] = num;
}

void maxDelete(struct maxHeap_t *maxHeap) {
    int lastNum = 0, child = 0, i = 0;
    
    lastNum = maxHeap->elms[maxHeap->size - 1];
    
    for (i = 0; i * 2 + 1 < maxHeap->size; i = child) {
        if (i * 2 + 2 < maxHeap->size) {
            child = maxHeap->elms[i * 2 + 1] > maxHeap->elms[i * 2 + 2] ? i * 2 + 1 : i * 2 + 2;
        } else {
            child = i * 2 + 1;
        }

        if (maxHeap->elms[child] > lastNum) {
            maxHeap->elms[i] = maxHeap->elms[child];
        } else {
            break;
        }
    }
    maxHeap->elms[i] = lastNum;
    
    maxHeap->size -= 1;
}

void minInsert(struct minHeap_t *minHeap, int num) {
    int parent = 0, i = 0;
    
    if (minHeap->size == 0) {
        minHeap->elms[0] = num;
        minHeap->size = 1;
        
        return;
    }
    
    minHeap->elms[minHeap->size] = num;
    minHeap->size += 1;
    for (i = minHeap->size - 1; i > 0; i = parent) {
        parent = (i - 1) / 2; /* Parent */
        if (minHeap->elms[parent] > num) {
            minHeap->elms[i] = minHeap->elms[parent];
        } else {
            break;
        }
    }
    minHeap->elms[i] = num;
}

void minDelete(struct minHeap_t *minHeap) {
    int lastNum = 0, child = 0, i = 0;
    
    lastNum = minHeap->elms[minHeap->size - 1];
    
    for (i = 0; i * 2 + 1 < minHeap->size; i = child) {
        if (i * 2 + 2 < minHeap->size) {
            child = minHeap->elms[i * 2 + 1] < minHeap->elms[i * 2 + 2] ? i * 2 + 1 : i * 2 + 2;
        } else {
            child = i * 2 + 1;
        }
        
        if (minHeap->elms[i] < lastNum) {
            minHeap->elms[i] = minHeap->elms[child];
        } else {
            break;
        }
    }
    minHeap->elms[i] = lastNum;
    
    minHeap->size -= 1;
}

MedianFinder* medianFinderCreate() {
    MedianFinder *medianFinder = NULL;
    
    medianFinder = (MedianFinder *)malloc(sizeof(MedianFinder));
    if (!medianFinder) {
        return NULL;
    }
    
    medianFinder->maxHeap = (struct maxHeap_t *)malloc(sizeof(struct maxHeap_t));
    medianFinder->maxHeap->size = 0;
    medianFinder->maxHeap->elms = (int*)malloc(sizeof(int) * 25000);
    
    medianFinder->minHeap = (struct minHeap_t *)malloc(sizeof(struct minHeap_t));
    medianFinder->minHeap->size = 0;
    medianFinder->minHeap->elms = (int*)malloc(sizeof(int) * 25000);
    
    return medianFinder;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    struct maxHeap_t *maxHeap = obj->maxHeap;
    struct minHeap_t *minHeap = obj->minHeap;
    int maxPop = 0, minPop = 0, i = 0;
    
    /*
    printf("medianFinderAddNum=========================\n");
    */
    
    if (maxHeap->size == 0) {
        maxInsert(maxHeap, num);
    } else if (num < maxHeap->elms[0]) {
        maxInsert(maxHeap, num);
    } else {
        minInsert(minHeap, num);
    }
    /*
    printf("Before\n");
    printf("maxHeap\n");
    for (i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->elms[i]);
    }
    printf("\n");
    printf("minHeap\n");
    for (i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->elms[i]);
    }
    printf("\n");
    */
    
    if (maxHeap->size - minHeap->size > 1) {
        maxPop = maxHeap->elms[0];
        maxDelete(maxHeap);
        minInsert(minHeap, maxPop);
    } else if (minHeap->size - maxHeap->size > 1) {
        minPop = minHeap->elms[0];
        minDelete(minHeap);
        maxInsert(maxHeap, minPop);
    }
    
    /*
    printf("After\n");
    printf("maxHeap\n");
    for (i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->elms[i]);
    }
    printf("\n");
    printf("minHeap\n");
    for (i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->elms[i]);
    }
    printf("\n");
    */
    
    /*
    printf("==============================\n");
    */
}

double medianFinderFindMedian(MedianFinder* obj) {
    struct maxHeap_t *maxHeap = obj->maxHeap;
    struct minHeap_t *minHeap = obj->minHeap;
    int size = maxHeap->size + minHeap->size;
    double ret = 0;
    
    /*
    printf("medianFinderFindMedian=========================\n");
    */
    
    if (size % 2 == 0) {
        ret = (maxHeap->elms[0] + minHeap->elms[0]) / 2.0;
    } else {
        if (maxHeap->size > minHeap->size)
            ret = maxHeap->elms[0];
        else
            ret = minHeap->elms[0];
    }
    
    /*
    printf("ret: %1f\n", ret);
    printf("==============================\n");
    */
   
    return ret;
}

void medianFinderFree(MedianFinder* obj) {
    if (obj) {
        if (obj->maxHeap) {
            if (obj->maxHeap->elms) {
                free(obj->maxHeap->elms);
            }
            free(obj->maxHeap);
        }
        if (obj->minHeap) {
            if (obj->minHeap->elms) {
                free(obj->minHeap->elms);
            }
            free(obj->minHeap);
        }
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
