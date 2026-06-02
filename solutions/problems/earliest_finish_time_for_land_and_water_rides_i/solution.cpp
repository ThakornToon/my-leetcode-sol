class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliest = INT_MAX;
        
        // ลองทุกคู่ของ land ride และ water ride
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                
                // กรณีที่ 1: Land ก่อน Water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(waterStartTime[j], landFinish);
                int finishTime1 = waterStart + waterDuration[j];
                
                // กรณีที่ 2: Water ก่อน Land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(landStartTime[i], waterFinish);
                int finishTime2 = landStart + landDuration[i];
                
                // เก็บค่าที่น้อยที่สุดของคู่นี้
                earliest = min(earliest, min(finishTime1, finishTime2));
            }
        }
        
        return earliest;
    }
};