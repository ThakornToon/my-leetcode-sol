class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            // ถ้าสามารถใส่คนหนัก+คนเบาได้ด้วยกัน
            if (people[left] + people[right] <= limit) {
                left++;   // คนเบาขึ้นเรือ
                right--;  // คนหนักขึ้นเรือ
            } else {
                // ใส่คนหนักคนเดียว
                right--;
            }
            boats++;
        }
        
        return boats;
    }
};