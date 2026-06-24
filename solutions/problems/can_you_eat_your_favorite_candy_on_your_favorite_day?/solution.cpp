class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<bool> result;
        result.reserve(queries.size());
        
        // Prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + candiesCount[i];
        }
        
        for (auto& query : queries) {
            int favoriteType = query[0];
            int favoriteDay = query[1];
            int dailyCap = query[2];
            
            // จำนวนลูกอมทั้งหมดก่อน favoriteType
            long long candiesBefore = prefix[favoriteType];
            
            // จำนวนลูกอมทั้งหมดรวม favoriteType
            long long candiesUpTo = prefix[favoriteType + 1];
            
            // วันแรกสุดที่กิน favoriteType ได้ = หลังจากกิน candiesBefore หมด
            // กินวันละ dailyCap ชิ้น ใช้เวลา candiesBefore / dailyCap วัน
            long long earliestDay = candiesBefore / dailyCap;
            
            // วันสุดท้ายที่กิน favoriteType ได้ = ก่อนที่ candiesUpTo จะหมด
            // ถ้ากินวันละ 1 ชิ้น จะใช้เวลา candiesUpTo - 1 วัน (0-indexed)
            long long latestDay = candiesUpTo - 1;
            
            // ตรวจสอบว่า favoriteDay อยู่ในช่วงหรือไม่
            bool possible = (favoriteDay >= earliestDay && favoriteDay <= latestDay);
            result.push_back(possible);
        }
        
        return result;
    }
};