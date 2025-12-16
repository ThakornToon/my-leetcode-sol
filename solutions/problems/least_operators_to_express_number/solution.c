int leastOpsExpressTarget(int x, int target) {
    // target = ax^0 + bx^1 + cx^2 + ... = (...cba)3
    // สปส อยู่ในช่วง [0, x-1] หรือเป็นค่าลบ

    // แปลง target เป็นฐาน x
    int digits[32]; // เก็บค่า สปส
    int len = 0;
    
    while (target > 0) {
        digits[len++] = target % x;
        target /= x;
    }
    
    // สปส จะเป็น a (ไม่มีการให้) หรือ x - a (มีการให้) 4*5^3 = (5 - 1)*5^3 = 5^4 - 5^3
    // dp[i][0] = ไม่มีการยืมจากหลักก่อนหน้า
    // dp[i][1] = มีการให้หลักถัดไป
    int dp[32][2];
    
    // คำนวณค่าสำหรับหลักแรก
    int i = 0;
    int digit = digits[i];

    // ค่าใช้จ่ายสำหรับหลัก i โดยไม่มีการให้
    // i = 0: x/x + x/x + ... ใช้ 2*digit - 1 operations
    int cost_no_borrow = digit * 2 - 1;
  
    // ค่าใช้จ่ายสำหรับหลัก i โดยมีการให้ ax^i = x^(i+1) - (x-a)x^i
    // ใช้ (x - digits[i]) ตัว
    int cost_borrow = (x - digit) * 2 - 1;
    
    dp[i][0] = cost_no_borrow;
    dp[i][1] = cost_borrow;
    
    // คำนวณจากหลักสูงไปต่ำ
    for (i = 1; i <= len; i++) {
        digit = digits[i];

        // กรณีหลักปัจจุบันไม่มีการให้หลักถัดไป

        // 1. ต่อจาก dp[i-1][0] (กรณีไม่มีการให้มา)
        int cost_no_borrow1 = dp[i-1][0] + i * digit;
        // i > 0: ต้องสร้าง x^i ก่อน (ใช้ i operations) แล้วคูณด้วย digit (ทำทั้งหมด digit ครั้ง)

        // 2. ต่อจาก dp[i-1][1] (กรณีมีการให้มา)
        int cost_no_borrow2 = dp[i-1][1] + i * (digit + 1);
        
        dp[i][0] = (cost_no_borrow1 < cost_no_borrow2) ? cost_no_borrow1 : cost_no_borrow2;
        
        // กรณีมีการยืมจากหลัก i (ให้หลัก i+1)
        // หลัก i+1 เพิ่มขึ้น 1 หลัก i เป็น x - digits[i]
        
        // 1. ต่อจาก dp[i-1][0] 
        int borrow_cost1 = dp[i-1][0] + i * (x - digit);
        
        // 2. ต่อจาก dp[i-1][1] 
        int borrow_cost2 = dp[i-1][1] + i * (x - (digit + 1));
        
        dp[i][1] = (borrow_cost1 < borrow_cost2) ? borrow_cost1 : borrow_cost2;
    }
    
    return (dp[len][0] < dp[len][1] ? dp[len][0] : dp[len][1]);
}