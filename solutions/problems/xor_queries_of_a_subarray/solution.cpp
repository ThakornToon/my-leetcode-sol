// x XOR x = 0 (ตัวเลขเดียวกัน XOR กันได้ 0)
// x XOR 0 = x (XOR กับ 0 ได้ตัวเดิม)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        
        // คำนวณ prefix XOR
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        // คำนวณผลลัพธ์สำหรับแต่ละ query
        vector<int> result;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            result.push_back(prefix[right + 1] ^ prefix[left]);
        }
        
        return result;
    }
};