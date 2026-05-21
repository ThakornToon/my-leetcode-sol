class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // เรียงตาม unitsPerBox จากมากไปน้อย
        sort(boxTypes.begin(), boxTypes.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             }
        );
        
        int totalUnits = 0;
        int remaining = truckSize;
        
        for (auto& box : boxTypes) {
            int boxes = box[0];
            int units = box[1];
            
            int take = min(boxes, remaining);
            totalUnits += take * units;
            remaining -= take;
            
            if (remaining == 0) break;
        }
        
        return totalUnits;
    }
};