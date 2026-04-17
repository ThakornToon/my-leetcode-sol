#define MAX_SUM 9 * 4  // n ≤ 10^4, ตัวเลขมากสุด 4 หลัก => sum สูงสุด 36

// ฟังก์ชันหาผลรวมของ digits
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countLargestGroup(int n) {
    int freq[MAX_SUM + 1] = {0};
    int maxFreq = 0;
    
    // คำนวณ sum of digits สำหรับ 1..n และนับความถี่
    for (int i = 1; i <= n; i++) {
        int sum = digitSum(i);
        freq[sum]++;
        if (freq[sum] > maxFreq) {
            maxFreq = freq[sum];
        }
    }
    
    // นับจำนวนกลุ่มที่มีขนาดเท่ากับ maxFreq
    int count = 0;
    for (int i = 1; i <= MAX_SUM; i++) {
        if (freq[i] == maxFreq) {
            count++;
        }
    }
    
    return count;
}