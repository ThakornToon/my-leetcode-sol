class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int score = 0;
        int maxScore = 0;
        int left = 0;
        int right = tokens.size() - 1;
        
        while (left <= right) {
            // ถ้ามี power พอให้เล่น face-up
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
                maxScore = max(maxScore, score);
            }
            // ถ้าเล่น face-up ไม่ได้ แต่มี score และยังมี token เหลือ
            else if (score > 0 && left < right) {
                power += tokens[right];
                score--;
                right--;
            }
            // ไม่สามารถเล่นได้อีก
            else {
                break;
            }
        }
        
        return maxScore;
    }
};