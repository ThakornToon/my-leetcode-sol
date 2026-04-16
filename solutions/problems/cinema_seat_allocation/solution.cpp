class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        
        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reserved[row].insert(col);
        }
        
        int total = 0;
        
        for (auto& [row, seats] : reserved) {
            int count = 0;
            
            bool left = !seats.count(2) && !seats.count(3) && 
                        !seats.count(4) && !seats.count(5);
            bool middle = !seats.count(4) && !seats.count(5) && 
                          !seats.count(6) && !seats.count(7);
            bool right = !seats.count(6) && !seats.count(7) && 
                         !seats.count(8) && !seats.count(9);
            
            if (left && right) {
                count = 2;
            } else if (left || middle || right) {
                count = 1;
            }
            
            total += count;
        }
        
        total += (n - reserved.size()) * 2;
        
        return total;
    }
};