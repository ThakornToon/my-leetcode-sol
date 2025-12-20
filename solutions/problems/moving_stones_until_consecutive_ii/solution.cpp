/*
หินอยู่ในช่วง [start, end] ถ้าเราหยิบหินฝั่งใดฝั่งหนึ่งจะต้องหยิบหินนั้นไปวางระหว่างหินช่วงใหม่ [start, new_end] หรือ [new_start, end] 
เช่น
5, 8, 9, 16 เลือก 16 ไปวางในช่องว่างระหว่าง [5,9] ได้ แต่หากต้องการ moves ที่มากที่สุดในครั้งแรกเราต้องเลือกขยับโดยเสียช่องว่างให้น้อยที่สุดจากนั้นในครั้งต่อๆไปให้ผลัดกันขยับหินไปช่องว่างที่ใกล้ที่สุด 5,8,9,16->8,9,10,16 (เสียช่องว่างไปสามช่องเนื่องจากกฎที่บังคับ)->9,10,11,16->10,11,12,16->11,12,13,16->...->13,14,15,16 ในทางกลับกันหากต้องการ moves ที่น้อยที่สุดเราต้องจองพื้นที่ขนาด n ตามจำนวนหินโดยที่มีหินอยู่ในช่วงนั้นมากที่สุด(จะได้ไม่ต้องย้าย) ซึ่งจากนั้นเราแค่นำหินที่ไม่อยู่ในช่วงย้ายมาโดยใช้การ move หนึ่งครั้งต่อหนึ่งก้อน อย่าลืมคิดกรณีที่หินมีอยู่ n-1 ก้อนติดกัน เช่น 8,9,10,16->9,10,12,16->9,10,11,12 
*/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        
        // Maximum moves
        int total_empty = (stones[n-1] - stones[0] + 1) - n;
        int left_gap = stones[1] - stones[0] - 1;
        int right_gap = stones[n-1] - stones[n-2] - 1;
        int max_moves = total_empty - min(left_gap, right_gap);
        
        // Minimum moves using sliding window
        int min_moves = n;
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            // Expand window to include as many stones as possible within length n
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) {
                j++;
            }
            
            int stones_in_window = j - i + 1;
            
            // Special case: n-1 stones in window of size n-1
            if (stones_in_window == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                min_moves = min(min_moves, 2);
            } else {
                min_moves = min(min_moves, n - stones_in_window);
            }
        }
        
        return {min_moves, max_moves};
    }
};