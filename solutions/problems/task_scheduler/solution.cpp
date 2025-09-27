class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        
        // นับความถี่ของแต่ละ task
        for (char task : tasks) {
            count[task - 'A']++;
        }
        
        // เรียงลำดับความถี่จากมากไปน้อย
        sort(count.rbegin(), count.rend());
        
        // หาจำนวน task ที่มีความถี่สูงสุด
        int max_count = count[0];
        int num_max = 1;
        
        for (int i = 1; i < 26; i++) {
            if (count[i] == max_count) {
                num_max++;
            } else {
                break;
            }
        }
        
        // คำนวณเวลาขั้นต่ำ
        int min_time = (max_count - 1) * (n + 1) + num_max;
        
        return max(min_time, (int)tasks.size());
    }
};