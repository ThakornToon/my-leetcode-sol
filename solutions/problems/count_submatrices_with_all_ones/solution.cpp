class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> height(n, 0);
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            // อัปเดตความสูงของ histogram
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            // นับจำนวน submatrix ที่มีแถวล่างสุดเป็นแถว i
            // ใช้ monotonic stack
            stack<int> st;
            vector<int> sum(n, 0);
            
            for (int j = 0; j < n; j++) {
                while (!st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }
                
                if (st.empty()) {
                    sum[j] = height[j] * (j + 1);
                } else {
                    int prevIndex = st.top();
                    sum[j] = sum[prevIndex] + height[j] * (j - prevIndex);
                }
                
                st.push(j);
                result += sum[j];
            }
        }
        
        return result;
    }
};