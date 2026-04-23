class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // max-heap: (count, char)
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result;
        
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            
            // ตรวจสอบว่าซ้ำ 2 ตัวสุดท้ายหรือไม่
            if (result.size() >= 2 && result.back() == ch1 && 
                result[result.size() - 2] == ch1) {
                // ต้องใช้ตัวที่สอง
                if (pq.empty()) break;
                
                auto [cnt2, ch2] = pq.top();
                pq.pop();
                
                result += ch2;
                cnt2--;
                
                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            } else {
                result += ch1;
                cnt1--;
                if (cnt1 > 0) pq.push({cnt1, ch1});
            }
        }
        
        return result;
    }
};