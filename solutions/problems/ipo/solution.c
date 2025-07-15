typedef struct {
    int capital;
    int profit;
} Project;

// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int compareProjects(const void* a, const void* b) {
    return ((Project*)a)->capital - ((Project*)b)->capital;
}

// Max heap implementation
typedef struct {
    int* data;
    int size;
} MaxHeap;

MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap* heap, int index) {
    while (index > 0 && heap->data[(index - 1) / 2] < heap->data[index]) {
        swap(&heap->data[(index - 1) / 2], &heap->data[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}

void push(MaxHeap* heap, int value) {
    heap->data[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

int pop(MaxHeap* heap) {
    // สลับโหนดแรก(อยู่บนสุด)กับโหนดสุดท้าย(อยู่ล่างสุด)
    int max = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return max;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project* projects = (Project*)malloc(profitsSize * sizeof(Project));
    for (int i = 0; i < profitsSize; i++) {
        projects[i].capital = capital[i];
        projects[i].profit = profits[i];
    }

    // เรียงตาม capital
    qsort(projects, profitsSize, sizeof(Project), compareProjects);

    MaxHeap* maxHeap = createHeap(profitsSize);
    int current = 0;

    for (int i = 0; i < k; i++) {
        // เพิ่มโครงการที่ทำได้ลงใน heap
        while (current < profitsSize && projects[current].capital <= w) {
            push(maxHeap, projects[current].profit);
            current++;
        }

        if (maxHeap->size == 0) break;

        // เลือกโครงการที่ให้กำไรสูงสุด
        w += pop(maxHeap);
    }

    free(projects);
    free(maxHeap->data);
    free(maxHeap);
    return w;
}