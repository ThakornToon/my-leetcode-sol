class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        if (k >= n - 1) {
            // หาค่าสูงสุดใน array
            int maxVal = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] > maxVal) {
                    maxVal = arr[i];
                }
            }
            return maxVal;
        }

        deque<int> dq(arr.begin(), arr.end());
        
        int winner = dq.front();
        dq.pop_front();
        int winCount = 0;
        
        while (winCount < k) {
            int challenger = dq.front();
            dq.pop_front();
            
            if (winner > challenger) {
                winCount++;
                dq.push_back(challenger);  // ตัวแพ้ไปต่อท้าย
            } else {
                dq.push_back(winner);       // ตัวแพ้ไปต่อท้าย
                winner = challenger;
                winCount = 1;
            }
            
            if (winCount == k) {
                return winner;
            }
        }
        
        return winner;
    }
};