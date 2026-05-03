class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> countMap;   // frequency of prefix XOR
        unordered_map<int, int> sumMap;     // sum of indices for each prefix XOR
        int prefix = 0;
        int result = 0;
        
        countMap[0] = 1;
        sumMap[0] = 0;
        
        for (int i = 0; i < n; i++) {
            prefix ^= arr[i];
            
            // สำหรับ prefix ที่เท่ากันก่อนหน้านี้
            // contribution = count * i - sum_of_indices
            if (countMap.count(prefix)) {
                result += countMap[prefix] * i - sumMap[prefix];
            }
            
            countMap[prefix]++;
            sumMap[prefix] += (i + 1);
        }
        
        return result;
    }
};