/*
arr = [1, 2, 3, 4]

เราต้องการหา OR ของทุก subarray:
[1], [1,2], [1,2,3], [1,2,3,4]
[2], [2,3], [2,3,4]
[3], [3,4]
[4]
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        vector<int> cur;
        
        for (int num : arr) {
            vector<int> next = {num};
            int last = num;
            
            for (int val : cur) {
                int new_val = val | num;
                if (new_val > last) {
                    next.push_back(new_val);
                    last = new_val;
                }
            }
            
            // เพิ่มเข้า result
            for (int val : next) {
                result.insert(val);
            }
            
            cur = next;
        }
        
        return result.size();
    }
};