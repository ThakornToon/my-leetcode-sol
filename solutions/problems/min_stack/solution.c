typedef struct {
    int val;
    int min;
} Element;

typedef struct {
    // ไว้เก็บค่า val และหา min จากทั้งหมด
    Element* data; 
    int top;  
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 1024;
    obj->data = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top + 1 >= obj->capacity) {
        // worse case O(n), average O(1)
        obj->capacity *= 2;
        obj->data = (Element*)realloc(obj->data, sizeof(Element) * obj->capacity);
    }
    
    obj->top++;
    obj->data[obj->top].val = val;
    
    // กำหนดค่า min ของตำแหน่งปัจจุบัน
    if (obj->top == 0) {
        obj->data[obj->top].min = val;
    } else {
        int prev_min = obj->data[obj->top - 1].min;
        obj->data[obj->top].min = (val < prev_min) ? val : prev_min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/