class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        
        // สร้างและเรียงงานตามเวลาสิ้นสุด
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(jobs, (a, b) -> Integer.compare(a.end, b.end));
        
        // DP array
        int[] dp = new int[n];
        dp[0] = jobs[0].profit;
        
        for (int i = 1; i < n; i++) {
            // ตัวเลือก 1: ไม่ทำงานนี้
            int profitExcluding = dp[i - 1];
            
            // ตัวเลือก 2: ทำงานนี้
            int profitIncluding = jobs[i].profit;
            
            // Binary search หางานที่สิ้นสุดก่อนงานนี้เริ่ม
            int j = binarySearch(jobs, i, jobs[i].start);
            if (j != -1) {
                profitIncluding += dp[j];
            }
            
            // เลือกค่าสูงสุด
            dp[i] = Math.max(profitExcluding, profitIncluding);
        }
        
        return dp[n - 1];
    }
    
    // Binary search หางานที่สิ้นสุดก่อน target
    private int binarySearch(Job[] jobs, int index, int target) {
        int left = 0, right = index - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid].end <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    // Inner class สำหรับเก็บข้อมูลงาน
    class Job {
        int start, end, profit;
        
        Job(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }
}