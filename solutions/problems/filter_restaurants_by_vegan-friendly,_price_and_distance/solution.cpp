class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> filtered;  // (rating, id)
        
        for (auto& r : restaurants) {
            int id = r[0];
            int rating = r[1];
            int vf = r[2];
            int price = r[3];
            int distance = r[4];
            
            // ตรวจสอบเงื่อนไข
            if (veganFriendly == 1 && vf == 0) continue;
            if (price > maxPrice) continue;
            if (distance > maxDistance) continue;
            
            filtered.push_back({rating, id});
        }
        
        // เรียงลำดับ: rating desc, id desc
        sort(filtered.begin(), filtered.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first > b.first;  // rating desc
            return a.second > b.second;  // id desc
        });
        
        vector<int> result;
        for (auto& p : filtered) {
            result.push_back(p.second);
        }
        
        return result;
    }
};