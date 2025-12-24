class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int total = 0;
        long long sum = 0;
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int mode = 0;
        int max_count = 0;
        
        // หา total ก่อน
        for (int c : count) total += c;
        
        int target1 = (total - 1) / 2;
        int target2 = total / 2;
        int cnt = 0;
        int median1 = -1, median2 = -1;
        
        // ลูปเดียวทั้งหมด
        for (int i = 0; i < 256; i++) {
            int c = count[i];
            if (c == 0) continue;
            
            // Min/Max
            if (i < min_val) min_val = i;
            if (i > max_val) max_val = i;
            
            // Sum
            sum += (long long)i * c;
            
            // Mode
            if (c > max_count) {
                max_count = c;
                mode = i;
            }
            
            // Median
            if (cnt <= target1 && cnt + c > target1) {
                median1 = i;
            }
            if (cnt <= target2 && cnt + c > target2) {
                median2 = i;
            }
            cnt += c;
        }
        
        double mean = (double)sum / total;
        double median = (total % 2 == 1) ? median2 : (median1 + median2) / 2.0;
        
        return {(double)min_val, (double)max_val, mean, median, (double)mode};
    }
};