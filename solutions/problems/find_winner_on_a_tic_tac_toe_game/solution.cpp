class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int diag1 = 0, diag2 = 0;
        
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            int val = (i % 2 == 0) ? 1 : -1;  // A = +1, B = -1
            
            rows[row] += val;
            cols[col] += val;
            
            if (row == col) diag1 += val;
            if (row + col == 2) diag2 += val;
            
            // ตรวจสอบการชนะ
            if (abs(rows[row]) == 3 || abs(cols[col]) == 3 || abs(diag1) == 3 || abs(diag2) == 3) {
                return (i % 2 == 0) ? "A" : "B";
            }
        }
        
        return (moves.size() == 9) ? "Draw" : "Pending";

    }
};