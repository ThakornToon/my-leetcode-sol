class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> seen(nums.begin(), nums.end());
        
        // สร้าง combinations ทั้งหมด
        for (int i = 0; i < (1 << n); i++) {
            // แปลงเลขจำนวนเต็ม i เป็น binary string ความยาว 16 บิต
            // เอาเฉพาะ n ตัวสุดท้ายจาก string ความยาว 16
            string candidate = bitset<16>(i).to_string().substr(16 - n);
            if (seen.find(candidate) == seen.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};