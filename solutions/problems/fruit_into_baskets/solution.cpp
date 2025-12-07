class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0, max_len = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;
            
            // ถ้ามีมากกว่า 2 ประเภท
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};