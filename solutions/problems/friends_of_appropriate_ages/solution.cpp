class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> freq(121, 0);
        
        // นับความถี่
        for (int age : ages) {
            freq[age]++;
        }
        
        // สร้าง prefix sum
        vector<int> prefix(121, 0);
        prefix[0] = freq[0];
        for (int i = 1; i <= 120; i++) {
            prefix[i] = prefix[i-1] + freq[i];
        }
        
        int requests = 0;
        
        for (int ageA = 15; ageA <= 120; ageA++) {  // เริ่มที่ 15 เพราะอายุน้อยกว่าไม่สามารถส่งได้
            if (freq[ageA] == 0) continue;
            
            // ขอบเขตล่าง: ageB > ageA/2 + 7
            int lower = ageA / 2 + 7;
            // ขอบเขตบน: ageB <= ageA
            
            // จำนวนคนใน range [lower+1, ageA]
            int count = prefix[ageA] - prefix[lower];
            
            if (count > 0) {
                // คนอายุ ageA ส่งให้คนใน range นี้ได้
                requests += freq[ageA] * count;
                
                // ลบกรณีส่งให้ตัวเอง (ถ้า ageA อยู่ใน range)
                if (ageA > lower) {
                    requests -= freq[ageA];
                }
            }
        }
        
        return requests;
    }
};