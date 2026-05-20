class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // A, B เป็นการสลับลำดับ 1 ถึง n หาจำนวนตัวเลขที่ปรากฏใน prefix A[0..i] และ B[0..i] พร้อมกัน

        int n = A.size();
        vector<int> result(n);
        vector<int> count(n + 1, 0); // count array (1-indexed)
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            // เพิ่ม A[i]
            count[A[i]]++;
            if (count[A[i]] == 2) {
                common++;
            }
            
            // เพิ่ม B[i]
            count[B[i]]++;
            if (count[B[i]] == 2) {
                common++;
            }
            
            result[i] = common;
        }
        
        return result;
    }
};