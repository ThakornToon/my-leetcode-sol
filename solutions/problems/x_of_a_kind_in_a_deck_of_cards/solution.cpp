class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // เก็บความถี่ของไพ่แต่ละใบ
        unordered_map<int, int> freq;
        for (int card : deck) {
            freq[card]++;
        }
        
        // หา GCD ของความถี่ทั้งหมด
        int g = 0;
        for (auto& pair : freq) {
            if (g == 0) {
                g = pair.second;
            } else {
                g = gcd(g, pair.second);
            }
        }
        
        return g >= 2;
    }
private:
    // ฟังก์ชันหา GCD (ตัวหารร่วมมาก)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};