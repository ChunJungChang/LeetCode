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

void maxHeapify(struct heap_t *maxHeap, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < maxHeap->size && maxHeap->elms[leftChild] > maxHeap->elms[largest]) {
        largest = leftChild;
    }

    if (rightChild < maxHeap->size && maxHeap->elms[rightChild] > maxHeap->elms[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(&maxHeap->elms[i], &maxHeap->elms[largest]);
        maxHeapify(maxHeap, largest);
    }
}

void maxInsert(struct heap_t *maxHeap, int num) {
    int i = 0;
   
    maxHeap->size++;
    i = maxHeap->size - 1;
    maxHeap->elms[i] = num;

    while (i != 0 && maxHeap->elms[(i - 1) / 2] < maxHeap->elms[i]) {
        swap(&maxHeap->elms[i], &maxHeap->elms[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct heap_t *maxHeap)
{
    int root = INT_MIN;

    if (maxHeap->size <= 0) {
        return root;
    }
    if (maxHeap->size == 1) {
        root = maxHeap->elms[0];
        maxHeap->size--;
        return root;
    }

    root = maxHeap->elms[0];
    maxHeap->elms[0] = maxHeap->elms[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);

    return root;
}

void maxDeleteTarget(struct heap_t *maxHeap, int num) {
    int lastNum = 0, i = 0;
    
    lastNum = maxHeap->elms[maxHeap->size - 1];
    
    for (i = 0; i < maxHeap->size; i++) {
        if (maxHeap->elms[i] == num) {
            break;
        }
    }
    maxHeap->elms[i] = lastNum;
    
    maxHeap->size -= 1;
	
    maxHeapify(maxHeap, i);
}

void minHeapify(struct heap_t *minHeap, int i)
{
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < minHeap->size && minHeap->elms[leftChild] < minHeap->elms[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < minHeap->size && minHeap->elms[rightChild] < minHeap->elms[smallest]) {
        smallest = rightChild;
    }

    if (smallest != i) {
        swap(&minHeap->elms[i], &minHeap->elms[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void minInsert(struct heap_t *minHeap, int num) {
    int i = 0;
   
    minHeap->size++;
    i = minHeap->size - 1;
    minHeap->elms[i] = num;

    while (i != 0 && minHeap->elms[(i - 1) / 2] > minHeap->elms[i]) {
        swap(&minHeap->elms[i], &minHeap->elms[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(struct heap_t *minHeap)
{
    int root = INT_MAX;

    if (minHeap->size <= 0) {
        return root;
    }
    if (minHeap->size == 1) {
        root = minHeap->elms[0];
        minHeap->size--;
        return root;
    }

    root = minHeap->elms[0];
    minHeap->elms[0] = minHeap->elms[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void minDeleteTarget(struct heap_t *minHeap, int num) {
    int lastNum = 0, i = 0;
    
    lastNum = minHeap->elms[minHeap->size - 1];
    
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->elms[i] == num) {
            break;
        }
    }
    minHeap->elms[i] = lastNum;
    
    minHeap->size -= 1;
	
    minHeapify(minHeap, i);
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
