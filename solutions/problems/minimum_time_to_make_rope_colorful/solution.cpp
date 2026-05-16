class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.length();
        int i = 0;
        
        while (i < n) {
            char currentColor = colors[i];
            int groupMax = neededTime[i];
            int groupSum = neededTime[i];
            int groupSize = 1;
            
            // หาทุกตัวที่สีเดียวกันติดกัน
            int j = i + 1;
            while (j < n && colors[j] == currentColor) {
                groupSum += neededTime[j];
                groupMax = max(groupMax, neededTime[j]);
                groupSize++;
                j++;
            }
            
            // ต้องเอาออกทั้งหมดยกเว้นอันที่มีเวลามากที่สุด
            totalTime += (groupSum - groupMax);
            
            // ข้ามไปที่กลุ่มถัดไป
            i = j;
        }
        
        return totalTime;

    }
};