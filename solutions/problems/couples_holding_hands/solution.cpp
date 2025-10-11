class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> position(n);
        for (int i = 0; i < n; i++) {
            position[row[i]] = i;
        }
        
        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int person = row[i];
            int partner = person ^ 1;
            
            if (row[i + 1] != partner) {
                int partner_idx = position[partner];
                // สลับ
                swap(row[i + 1], row[partner_idx]);
                // อัปเดต position
                position[row[partner_idx]] = partner_idx;
                position[row[i + 1]] = i + 1;
                swaps++;
            }
        }
        
        return swaps;
    }
};