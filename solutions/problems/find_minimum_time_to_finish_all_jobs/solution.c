// ฟังก์ชันเปรียบเทียบสำหรับ qsort (มากไปน้อย)
int cmp_desc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

// DFS ตรวจสอบว่าสามารถแบ่งงานให้แต่ละคนทำงานไม่เกิน limit ได้หรือไม่
bool dfs(int* jobs, int n, int* workloads, int k, int limit, int idx) {
    if (idx == n) return true; // จัดสรรงานครบแล้ว
    
    int current_job = jobs[idx];
    
    for (int i = 0; i < k; i++) {
        // pruning: ถ้า workload[i] + current_job > limit ไม่สามารถใส่ได้
        if (workloads[i] + current_job > limit) continue;
        
        // pruning: ถ้าคนงาน i มี workload เท่ากับคนงาน i-1 และเราลองคนงาน i-1 ไปแล้ว ไม่ต้องลองซ้ำ
        if (i > 0 && workloads[i] == workloads[i-1]) continue;
        
        // เอางานนี้ให้คนที่ i หรือให้คนอื่นถัดไป
        workloads[i] += current_job;
        if (dfs(jobs, n, workloads, k, limit, idx + 1)) return true;
        workloads[i] -= current_job;
        
        // pruning : ถ้า workload[i] == 0 แสดงว่าใส่ job นี้ลงคนงานว่างคนแรกแล้วไม่สำเร็จ
        // การลองคนงานว่างคนอื่นก็จะไม่ได้ผล (เพราะงานนี้จะทำให้คนงานทุกคน workload > 0 เท่ากัน)
        if (workloads[i] == 0) return false;
    }
    
    return false;
}

bool canFinish(int* jobs, int n, int k, int limit) {
    int workloads[12] = {0}; // k <= 12 ตาม constraints
    return dfs(jobs, n, workloads, k, limit, 0);
}

int minimumTimeRequired(int* jobs, int jobsSize, int k) {
    // เรียงลำดับงานจากมากไปน้อย (improve pruning)
    qsort(jobs, jobsSize, sizeof(int), cmp_desc);
    
    int left = jobs[0]; // min ของค่ามากสุดคืองานที่ใหญ่ที่สุด
    int right = 0;
    for (int i = 0; i < jobsSize; i++) right += jobs[i];
    
    // binary search หา min ของ max working time
    while (left < right) {
        int mid = left + (right - left) / 2;
        // mid = max working time
        if (canFinish(jobs, jobsSize, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}