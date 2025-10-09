class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        
        // Suffix count และ suffix pairs
        vector<int> rightCount(10, 0);
        vector<vector<int>> rightPairs(10, vector<int>(10, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            int d = s[i] - '0';
            // อัพเดท rightPairs: ทุกตัวเลขที่อยู่ก่อน d (ใน suffix) จะสร้างคู่กับ d
            for (int x = 0; x < 10; x++) {
                rightPairs[x][d] += rightCount[x]; // d x
            }
            rightCount[d]++;
        }
        
        // Prefix count และ prefix pairs
        vector<int> leftCount(10, 0);
        vector<vector<int>> leftPairs(10, vector<int>(10, 0));
        long long ans = 0;
        
        for (int k = 0; k < n; k++) {
            // ให้ d เป็น center
            int d = s[k] - '0';
            
            // ลบ d ออกจาก rightCount และ rightPairs
            rightCount[d]--;
            for (int x = 0; x < 10; x++) {
                rightPairs[x][d] -= rightCount[x];
            }
            
            // นับผลรวมจาก leftPairs และ rightPairs
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    ans = (ans + (long long)leftPairs[x][y] * rightPairs[x][y]) % MOD; // x d center dx
                }
            }
            
            // อัพเดท leftPairs: เพิ่มคู่ใหม่ระหว่าง d กับทุกตัวใน leftCount
            for (int x = 0; x < 10; x++) {
                leftPairs[x][d] += leftCount[x]; // x d
            }
            leftCount[d]++;
        }
        
        return ans;
    }
};