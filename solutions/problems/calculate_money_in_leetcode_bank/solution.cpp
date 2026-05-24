class Solution {
public:
    int totalMoney(int n) {
        // แต่ละสัปดาห์มี 7 วัน สัปดาห์ที่ i (เริ่มที่ 0) มีค่าเริ่มต้น = i+1 บาท
        // รวมเงินในสัปดาห์ที่ i = 7*(i+1) + (0+1+...+6) = 7*(i+1) + 21
        // รวมเงินเต็มสัปดาห์: 7 × weeks×(weeks+1)/2 + 21×weeks = weeks * 28 + 7 * (0+1+...+(weeks-1)) + 21 * weeks แล้วจากนั้นบวกเศษวัน
        
        // เศษวันคือวันที่เหลือหลังจากมี weeks สัปดาห์เต็ม (7 วันต่อสัปดาห์)
        // เศษวันมี remaining วัน (1 ≤ remaining ≤ 6)
        // วันที่ 1 ของเศษ: เริ่มที่ weeks + 1 (เพราะสัปดาห์ถัดไปเริ่มที่ weeks+1)
        // วันที่ 2 ของเศษ: weeks + 2
        // วันที่ remaining ของเศษ: weeks + remaining
        // เงินในเศษวัน = (weeks + 1) + (weeks + 2) + ... + (weeks + remaining) = remaining × [(weeks + 1) + (weeks + remaining)] / 2 = remaining × (2×weeks + 1 + remaining) / 2
        
        int weeks = n / 7;
        int remaining = n % 7;
        
        int total = 7 * weeks*(weeks+1)/2 + 21*weeks;
        total += (2 * weeks + 1 + remaining) * remaining / 2;
        
        return total;
    }
};