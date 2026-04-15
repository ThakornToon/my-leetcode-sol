class Solution {
    public int[] closestDivisors(int num) {
        int[] result = new int[2];
        int minDiff = Integer.MAX_VALUE;
        
        // ลองทั้ง num+1 และ num+2
        for (int n : new int[]{num + 1, num + 2}) {
            int sqrtN = (int)Math.sqrt(n);
            
            // หาตัวประกอบที่ใกล้ sqrt มากที่สุด
            for (int a = sqrtN; a >= 1; a--) {
                if (n % a == 0) {
                    int b = n / a;
                    int diff = b - a;
                    
                    if (diff < minDiff) {
                        minDiff = diff;
                        result[0] = a;
                        result[1] = b;
                    }
                    break;  // เจอแล้วหยุด
                }
            }
        }
        
        return result;
    }
}