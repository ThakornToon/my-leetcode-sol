/*
1. ต้องจ่ายให้ทุกคนตาม อัตราส่วนเงินเดือนต่อประสิทธิภาพที่เท่ากัน = r = W / Q
2. แต่ละคนต้องได้อย่างน้อยเงินเดือนขั้นต่ำที่ตัวเองต้องการ

COST i = Qi * r

เรียงตาม r จากน้อยไปมาก
ใช้ max-heap หาคน k-1 คนก่อนหน้าที่มี quality น้อยที่สุด + ตัวคนที่กำหนด r อีก 1
ทุกครั้งที่มีคนใหม่ ลองให้เขาเป็นคนกำหนด r

ถ้าคนที่ r สูงอยู่ในทีม เราต้องใช้ r ของเขาเลยต้องให้คนที่ r สูงเป็นคนกำหนด(คนล่าสุดที่พิจารณา)
*/
#include <float.h>
typedef struct {
    double ratio;
    int quality;
} Worker;

// สำหรับ sorting workers ตาม ratio น้อยไปมาก
int compareWorkers(const void* a, const void* b) {
    Worker* wa = (Worker*)a;
    Worker* wb = (Worker*)b;
    if (wa->ratio < wb->ratio) return -1;
    if (wa->ratio > wb->ratio) return 1;
    return 0;
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k) {
    int n = qualitySize;
    
    // สร้าง workers
    Worker* workers = (Worker*)malloc(n * sizeof(Worker));
    for (int i = 0; i < n; i++) {
        workers[i].ratio = (double)wage[i] / quality[i];
        workers[i].quality = quality[i];
    }
    // ratio น้อยไปมาก
    qsort(workers, n, sizeof(Worker), compareWorkers);
    
    // สร้าง array สำหรับเก็บ quality ของคนที่เลือก
    int* selected = (int*)malloc(k * sizeof(int));
    double minCost = DBL_MAX;
    
    // สำหรับแต่ละคนงาน i
    for (int i = 0; i < n; i++) {
        // ใส่ quality ปัจจุบันในตำแหน่งที่เหมาะสม (insertion sort style)
        int currentQ = workers[i].quality;
        int pos = 0;
        
        // หาตำแหน่งที่จะใส่ (เรียงจากน้อยไปมาก)
        while (pos < k - 1 && pos < i && currentQ > selected[pos]) {
            pos++;
        }
        
        // เลื่อน elements ไปทางขวา
        for (int j = k - 1; j > pos && j > 0; j--) {
            if (j - 1 < i) {
                selected[j] = selected[j - 1];
            }
        }
        
        // ใส่ค่าใหม่
        if (pos < k) {
            selected[pos] = currentQ;
        }
        
        // คำนวณ total quality ของคน k คนแรก (ถ้ามี)
        if (i >= k - 1) {
            int totalQuality = 0;
            // บวก quality ของคน k คนสุดท้ายใน selected
            for (int j = 0; j < k; j++) {
                totalQuality += selected[j];
            }
            
            double cost = workers[i].ratio * totalQuality;
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }
    
    free(workers);
    free(selected);
    return minCost;
}