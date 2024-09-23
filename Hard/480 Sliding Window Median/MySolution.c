/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * https://stackoverflow.com/questions/22900388/why-in-a-heap-implemented-by-array-the-index-0-is-left-unused
 *                root at 0      root at 1
 * Left child     index*2+1      index*2
 * Right child    index*2+2      index*2+1
 * Parent         (index-1)/2    index/2
 */ 

struct heap_t {
    int size;
    int *elms;
};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapifyUp(struct heap_t *maxHeap, int idx) {
    int parent = (idx - 1) / 2;

    while (idx > 0 && idx < maxHeap->size &&
           maxHeap->elms[idx] > maxHeap->elms[parent]) {
        swap(&maxHeap->elms[idx], &maxHeap->elms[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}

void maxHeapifyDown(struct heap_t *maxHeap, int idx)
{
    int largest = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (leftChild < maxHeap->size && maxHeap->elms[leftChild] > maxHeap->elms[largest]) {
        largest = leftChild;
    }

    if (rightChild < maxHeap->size && maxHeap->elms[rightChild] > maxHeap->elms[largest]) {
        largest = rightChild;
    }

    if (largest != idx) {
        swap(&maxHeap->elms[idx], &maxHeap->elms[largest]);
        maxHeapifyDown(maxHeap, largest);
    }
}

void maxInsert(struct heap_t *maxHeap, int num) {
    int parent = 0, i = 0;
    
    if (maxHeap->size == 0) {
        maxHeap->elms[0] = num;
        maxHeap->size = 1;
        
        return;
    }

    maxHeap->size += 1;
    i = maxHeap->size - 1;
    maxHeap->elms[i] = num;
    
    while (i != 0) {
        parent = (i - 1) / 2;
        if (maxHeap->elms[i] > maxHeap->elms[parent]) {
            swap(&maxHeap->elms[i], &maxHeap->elms[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int extractMax(struct heap_t *maxHeap)
{
    int root = INT_MIN;

    if (maxHeap->size <= 0) {

    } else if (maxHeap->size == 1) {
        root = maxHeap->elms[0];
        maxHeap->size -= 1;
    } else {
        root = maxHeap->elms[0];
        swap(&maxHeap->elms[0], &maxHeap->elms[maxHeap->size - 1]);
        maxHeap->size -= 1;
        maxHeapifyDown(maxHeap, 0);
    } 

    return root;
}

void maxDeleteTarget(struct heap_t *maxHeap, int num) {
    int i = INT_MAX;
    
    for (i = 0; i < maxHeap->size; i++) {
        if (maxHeap->elms[i] == num) {
            break;
        }
    }
    swap(&maxHeap->elms[i], &maxHeap->elms[maxHeap->size - 1]);
    maxHeap->size -= 1;
	
    if (i < maxHeap->size) {
        maxHeapifyUp(maxHeap, i);
        maxHeapifyDown(maxHeap, i);
    }
}

void minHeapifyUp(struct heap_t *minHeap, int idx) {
    int parent = (idx - 1) / 2;

    while (idx > 0 && idx < minHeap->size &&
           minHeap->elms[idx] < minHeap->elms[parent]) {
        swap(&minHeap->elms[idx], &minHeap->elms[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}

void minHeapifyDown(struct heap_t *minHeap, int idx)
{
    int smallest = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (leftChild < minHeap->size && minHeap->elms[leftChild] < minHeap->elms[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < minHeap->size && minHeap->elms[rightChild] < minHeap->elms[smallest]) {
        smallest = rightChild;
    }

    if (smallest != idx) {
        swap(&minHeap->elms[idx], &minHeap->elms[smallest]);
        minHeapifyDown(minHeap, smallest);
    }
}

void minInsert(struct heap_t *minHeap, int num) {
    int parent = 0, i = 0;
    
    if (minHeap->size == 0) {
        minHeap->elms[0] = num;
        minHeap->size = 1;
        
        return;
    }

    minHeap->size += 1;
    i = minHeap->size - 1;
    minHeap->elms[i] = num;
    
    while (i != 0) {
        parent = (i - 1) / 2;
        if (minHeap->elms[i] < minHeap->elms[parent]) {
            swap(&minHeap->elms[i], &minHeap->elms[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int extractMin(struct heap_t *minHeap)
{
    int root = INT_MAX;

    if (minHeap->size <= 0) {

    } else if (minHeap->size == 1) {
        root = minHeap->elms[0];
        minHeap->size -= 1;
    } else {
        root = minHeap->elms[0];
        swap(&minHeap->elms[0], &minHeap->elms[minHeap->size - 1]);
        minHeap->size -= 1;
        minHeapifyDown(minHeap, 0);
    }

    return root;
}

void minDeleteTarget(struct heap_t *minHeap, int num) {
    int i = INT_MAX;
    
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->elms[i] == num) {
            break;
        }
    }
    swap(&minHeap->elms[i], &minHeap->elms[minHeap->size - 1]);
    minHeap->size -= 1;
	
    if (i < minHeap->size) {
        minHeapifyUp(minHeap, i);
        minHeapifyDown(minHeap, i);
    }
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    struct heap_t *maxHeap = NULL, *minHeap = NULL;;
    double *ret = NULL;
    int maxPop = 0, minPop = 0, rmTarget = 0, i = 0, j = 0;

    *returnSize = numsSize - k + 1;
    ret = (double*)calloc(*returnSize, sizeof(double));

    maxHeap = (struct heap_t *)malloc(sizeof(struct heap_t));
    maxHeap->size = 0;
    maxHeap->elms = (int*)malloc(sizeof(int) * numsSize);

    minHeap = (struct heap_t *)malloc(sizeof(struct heap_t));
    minHeap->size = 0;
    minHeap->elms = (int*)malloc(sizeof(int) * numsSize);

    for (i = 0; i < numsSize; i++) {
        if (maxHeap->size == 0 || nums[i] <= maxHeap->elms[0]) {
            maxInsert(maxHeap, nums[i]);
        } else {
            minInsert(minHeap, nums[i]);
        }

        if (maxHeap->size > minHeap->size + 1) {
            maxPop = extractMax(maxHeap);
            minInsert(minHeap, maxPop);
        } else if (maxHeap->size < minHeap->size) {
            minPop = extractMin(minHeap);
            maxInsert(maxHeap, minPop);
        }


        j = i - k + 1;
        if (j >= 0) {
            if (maxHeap->size == minHeap->size) {
                /* runtime error: signed integer overflow: 2147483647 + 2147483647 cannot be represented in type 'int' [solution.c] */
                ret[j] = ((long)maxHeap->elms[0] + (long)minHeap->elms[0]) / 2.0;
            } else {
                ret[j] = maxHeap->elms[0];
            }
            
            rmTarget = nums[j];
            if (rmTarget <= maxHeap->elms[0]) {
                maxDeleteTarget(maxHeap, rmTarget);
            } else {
                minDeleteTarget(minHeap, rmTarget);
            }

            if (maxHeap->size > minHeap->size + 1) {
                maxPop = extractMax(maxHeap);
                minInsert(minHeap, maxPop);
            } else if (maxHeap->size < minHeap->size) {
                minPop = extractMin(minHeap);
                maxInsert(maxHeap, minPop);
            }
        }
    }

    if (maxHeap) {
        if (maxHeap->elms) {
            free(maxHeap->elms);
            maxHeap->elms = NULL;
        }
        free(maxHeap);
        maxHeap = NULL;
    }
    if (minHeap) {
        if (minHeap->elms) {
            free(minHeap->elms);
            minHeap->elms = NULL;
        }
        free(minHeap);
        minHeap = NULL;
    }

    return ret;
}
