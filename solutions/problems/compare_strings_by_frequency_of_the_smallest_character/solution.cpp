class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // คำนวณ f สำหรับ words และเก็บใน array ที่นับความถี่
        // f(s) ≤ 10 เพราะ string ยาวไม่เกิน 10
        vector<int> freqCount(11, 0);  // index 1-10
        
        for (const string& word : words) {
            int f = calculateF(word);
            freqCount[f]++;
        }
        
        // สร้าง prefix sum จากหลังมาหน้า
        // suffixSum[i] = จำนวนคำที่มี f ≥ i
        vector<int> suffixSum(12, 0);  // ขนาด 12 เพื่อให้ suffixSum[11]=0
        for (int i = 10; i >= 1; i--) {
            suffixSum[i] = suffixSum[i + 1] + freqCount[i];
        }
        
        vector<int> result;
        for (const string& query : queries) {
            int queryF = calculateF(query);
            // ต้องการจำนวนคำที่มี f > queryF
            result.push_back(suffixSum[queryF + 1]);
        }
        
        return result;
    }

private:
    int calculateF(const string& s) {
        char smallest = 'z';
        int count = 0;
        
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                count++;
            }
        }
        
        return count;
    }
};