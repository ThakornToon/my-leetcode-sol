class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // เก็บ frequency ของ word masks ที่มี ≤ 7 bits
        unordered_map<int, int> freq;
        
        for (const string& w : words) {
            int mask = 0;
            for (char c : w) {
                mask |= 1 << (c - 'a');
            }
            // Optimization: เก็บเฉพาะ mask ที่มี ≤ 7 bits
            // เพราะ puzzle มีแค่ 7 ตัวอักษรต่างกัน
            if (__builtin_popcount(mask) <= 7) {
                freq[mask]++;
            }
        }
        
        vector<int> result;
        result.reserve(puzzles.size());
        
        for (const string& p : puzzles) {
            int first = 1 << (p[0] - 'a');
            int mask = 0;
            
            // สร้าง mask สำหรับ puzzle
            for (char c : p) {
                mask |= 1 << (c - 'a');
            }
            
            int count = 0;
            
            // Optimization: ตรวจสอบเฉพาะ subsets ที่มี first character
            // โดยเริ่มจาก mask ที่ไม่มี first character ก่อน
            int subset = mask;
            
            while (true) {
                // ตรวจสอบเฉพาะ subset ที่มี first character
                if (subset & first) {
                    auto it = freq.find(subset);
                    if (it != freq.end()) {
                        count += it->second;
                    }
                }
                
                if (subset == 0) break;
                subset = (subset - 1) & mask;
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};