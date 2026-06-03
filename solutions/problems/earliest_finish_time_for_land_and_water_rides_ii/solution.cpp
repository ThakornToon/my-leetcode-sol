class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // สร้าง vector ของ water rides {startTime, duration}
        vector<pair<int, int>> waterRides;
        for (int j = 0; j < m; j++) {
            waterRides.push_back({waterStartTime[j], waterDuration[j]});
        }
        
        // เรียงตาม startTime
        sort(waterRides.begin(), waterRides.end());
        
        // สร้าง prefixMinDuration: สำหรับ rides ที่ start <= finishLand
        // เลือก duration ที่น้อยที่สุด
        vector<int> prefixMinDur(m);
        prefixMinDur[0] = waterRides[0].second;
        for (int j = 1; j < m; j++) {
            prefixMinDur[j] = min(prefixMinDur[j-1], waterRides[j].second);
        }
        
        // สร้าง suffixMinFinish: สำหรับ rides ที่ start > finishLand
        // finishTime = startTime + duration
        vector<int> suffixMinFinish(m);
        suffixMinFinish[m-1] = waterRides[m-1].first + waterRides[m-1].second;
        for (int j = m-2; j >= 0; j--) {
            int finish = waterRides[j].first + waterRides[j].second;
            suffixMinFinish[j] = min(suffixMinFinish[j+1], finish);
        }
        
        int earliest = INT_MAX;
        
        // กรณีที่ 1: Land ก่อน Water
        for (int i = 0; i < n; i++) {
            int landFinish = landStartTime[i] + landDuration[i];
            
            // Binary search หาตำแหน่งสุดท้ายที่ waterStartTime <= landFinish
            int left = 0, right = m - 1;
            int lastIdx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (waterRides[mid].first <= landFinish) {
                    lastIdx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // กลุ่ม A: start <= landFinish (ใช้ prefixMinDur)
            if (lastIdx != -1) {
                int finishTime = landFinish + prefixMinDur[lastIdx];
                earliest = min(earliest, finishTime);
            }
            
            // กลุ่ม B: start > landFinish (ใช้ suffixMinFinish)
            if (lastIdx + 1 < m) {
                int finishTime = suffixMinFinish[lastIdx + 1];
                earliest = min(earliest, finishTime);
            }
        }
        
        // กรณีที่ 2: Water ก่อน Land (ทำแบบเดียวกัน)
        vector<pair<int, int>> landRides;
        for (int i = 0; i < n; i++) {
            landRides.push_back({landStartTime[i], landDuration[i]});
        }
        
        sort(landRides.begin(), landRides.end());
        
        vector<int> prefixMinDurLand(n);
        prefixMinDurLand[0] = landRides[0].second;
        for (int i = 1; i < n; i++) {
            prefixMinDurLand[i] = min(prefixMinDurLand[i-1], landRides[i].second);
        }
        
        vector<int> suffixMinFinishLand(n);
        suffixMinFinishLand[n-1] = landRides[n-1].first + landRides[n-1].second;
        for (int i = n-2; i >= 0; i--) {
            int finish = landRides[i].first + landRides[i].second;
            suffixMinFinishLand[i] = min(suffixMinFinishLand[i+1], finish);
        }
        
        for (int j = 0; j < m; j++) {
            int waterFinish = waterStartTime[j] + waterDuration[j];
            
            int left = 0, right = n - 1;
            int lastIdx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (landRides[mid].first <= waterFinish) {
                    lastIdx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if (lastIdx != -1) {
                int finishTime = waterFinish + prefixMinDurLand[lastIdx];
                earliest = min(earliest, finishTime);
            }
            
            if (lastIdx + 1 < n) {
                int finishTime = suffixMinFinishLand[lastIdx + 1];
                earliest = min(earliest, finishTime);
            }
        }
        
        return earliest;
    }
};