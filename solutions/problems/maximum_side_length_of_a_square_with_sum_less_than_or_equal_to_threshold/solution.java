class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        
        // สร้าง 2D prefix sum array
        int[][] prefix = new int[m + 1][n + 1];
        
        // คำนวณ prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] 
                             + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        // Binary search บนขนาดด้าน
        int left = 1, right = Math.min(m, n);
        int answer = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            boolean found = false;
            
            // ตรวจสอบทุกสี่เหลี่ยมขนาด mid x mid
            for (int i = 0; i + mid <= m; i++) {
                for (int j = 0; j + mid <= n; j++) {
                    // คำนวณผลรวมสี่เหลี่ยม
                    int sum = prefix[i+mid][j+mid] - prefix[i][j+mid] 
                            - prefix[i+mid][j] + prefix[i][j];
                    
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            
            if (found) {
                answer = mid;
                left = mid + 1;  // ลองหาขนาดใหญ่กว่า
            } else {
                right = mid - 1;  // ลองหาขนาดเล็กลง
            }
        }
        
        return answer;
    }
}