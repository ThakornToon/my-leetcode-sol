typedef struct {
    int start;
    int end;
    int profit;
} Job;

// เรียงตาม end
int compareJobs(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->end - jobB->end;
}

// Binary search หางานที่สิ้นสุดก่อนเวลาที่กำหนด
int binarySearch(Job jobs[], int right, int target) {
    int left = 0;
    int result = -1;  // ถ้าไม่เจองานที่สิ้นสุดก่อน target
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (jobs[mid].end <= target) {
            result = mid;
            left = mid + 1;  // ลองหาต่อทางขวา
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
    int n = startTimeSize;
    
    // สร้างอาร์เรย์ของ Job
    Job* jobs = (Job*)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }
    
    // จัดเรียงงานตามเวลาสิ้นสุด
    qsort(jobs, n, sizeof(Job), compareJobs);
    
    // dp[i] = กำไรมากสุดเมื่อพิจารณางานถึงตำแหน่งที่ i
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = jobs[0].profit;  // งานแรก
    
    for (int i = 1; i < n; i++) {
        // ตัวเลือก 1: ไม่ทำงานนี้
        int profitExcluding = dp[i-1];
        
        // ตัวเลือก 2: ทำงานนี้
        int profitIncluding = jobs[i].profit;
        
        // หางานที่ใกล้ที่สุดที่สิ้นสุดก่อนงานนี้เริ่ม
        int j = binarySearch(jobs, i - 1, jobs[i].start);
        if (j != -1) {
            profitIncluding += dp[j];
        }
        
        // เลือกค่าสูงสุด
        dp[i] = (profitExcluding > profitIncluding) ? 
                profitExcluding : profitIncluding;
    }
    
    int result = dp[n-1];
    
    // คืนหน่วยความจำ
    free(jobs);
    free(dp);
    
    return result;
}