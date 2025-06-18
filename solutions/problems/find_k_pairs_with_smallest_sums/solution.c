/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    int sum;
    Pair pair;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPQ(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(HeapNode* a, HeapNode* b) { // สลับข้อมูลสองโหนด
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) { // ทำงานตอน push เรียงน้อยไปมาก
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->data[parent].sum >= pq->data[index].sum) { 
            break;
        }
        swap(&pq->data[parent], &pq->data[index]);
        index = parent;
    }
}

void heapifyDown(PriorityQueue* pq, int index) { // ทำงานตอน pop 
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        
        if (left < pq->size && pq->data[left].sum > pq->data[largest].sum)
            largest = left;
        if (right < pq->size && pq->data[right].sum > pq->data[largest].sum)
            largest = right;
        
        if (largest == index) {
            break;
        }
        swap(&pq->data[index], &pq->data[largest]);
        index = largest;
    }
}

void push(PriorityQueue* pq, int sum, Pair pair) {
    if (pq->size == pq->capacity) return;
    
    pq->data[pq->size].sum = sum;
    pq->data[pq->size].pair = pair;
    heapifyUp(pq, pq->size);
    pq->size++;
}

HeapNode pop(PriorityQueue* pq) {
    HeapNode result = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];
    heapifyDown(pq, 0);
    return result;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    PriorityQueue* pq = createPQ(k);

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            int sum = nums1[i] + nums2[j];
            if (pq->size < k) { 
                push(pq, sum, (Pair){nums1[i], nums2[j]}); // เติมโหนดแล้วเรียง
            } else if (sum < pq->data[0].sum) {
                pop(pq); // เอาโหนดที่มากสุดออก
                push(pq, sum, (Pair){nums1[i], nums2[j]}); // เติมโหนดแล้วเรียง
            } else {
                break;
            }
        }
    }
    
    *returnSize = pq->size;
    *returnColumnSizes = (int*)malloc((*returnSize) * (sizeof(int)));
    int** res = (int**)malloc((*returnSize) * sizeof(int*));
    
    for (int i = 0; i < *returnSize; i++) {
        HeapNode node = pop(pq); // จะเหลือแต่ข้อมูลที่จะเอามาตอบ
        res[i] = (int*)malloc(2 * sizeof(int));
        res[i][0] = node.pair.first;
        res[i][1] = node.pair.second;
        (*returnColumnSizes)[i] = 2;
    }
    
    free(pq->data);
    free(pq);
    return res;
}

/* TLE
typedef struct {
    int num1;
    int num2;
} Pair;

int comparePairs(const void* a, const void* b) {
    Pair* pairA = (Pair*)a;
    Pair* pairB = (Pair*)b;
    return (pairA->num1 + pairA->num2) - (pairB->num1 + pairB->num2);
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int totalPairs = nums1Size * nums2Size;
    Pair* allPairs = (Pair*)malloc(totalPairs * sizeof(Pair));
    
    int index = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            allPairs[index].num1 = nums1[i];
            allPairs[index].num2 = nums2[j];
            index++;
        }
    }
    
    qsort(allPairs, totalPairs, sizeof(Pair), comparePairs);
    
    *returnSize = k;
    int** result = (int**)malloc((*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < *returnSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = allPairs[i].num1;
        result[i][1] = allPairs[i].num2;
        (*returnColumnSizes)[i] = 2;
    }
    
    free(allPairs);
    return result;
}
*/