class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        for (int i = 3; i < distance.size(); i++) {
            // กรณี 1: เส้นที่ i ตัดกับเส้นที่ i-3
            if (distance[i] >= distance[i-2] && distance[i-1] <= distance[i-3]) {
                return true;
            }
            
            // กรณี 2: เส้นที่ i ตัดกับเส้นที่ i-4 (เมื่อ i >= 4)
            if (i >= 4 && distance[i-1] == distance[i-3] && distance[i] + distance[i-4] >= distance[i-2]) {
                return true;
            }
            
            // กรณี 3: เส้นที่ i ตัดกับเส้นที่ i-5 (เมื่อ i >= 5)
            if (i >= 5 && distance[i-2] >= distance[i-4] && 
                distance[i-3] >= distance[i-1] && 
                distance[i-1] + distance[i-5] >= distance[i-3] && 
                distance[i] + distance[i-4] >= distance[i-2]) {
                return true;
            }
        }
        return false;
    }
};