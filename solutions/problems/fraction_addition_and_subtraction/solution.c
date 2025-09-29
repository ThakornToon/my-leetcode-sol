int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* fractionAddition(char* expression) {
    int numerator = 0, denominator = 1;
    int i = 0, n = strlen(expression);
    
    while (i < n) {
        // อ่านเครื่องหมาย
        int sign = 1;
        if (expression[i] == '+' || expression[i] == '-') {
            if (expression[i] == '-') sign = -1;
            i++;
        }
        
        // อ่านตัวเศษ
        int num = 0;
        while (i < n && isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
            i++;
        }
        num *= sign;
        
        // ข้ามเครื่องหมาย /
        i++;
        
        // อ่านตัวส่วน
        int den = 0;
        while (i < n && isdigit(expression[i])) {
            den = den * 10 + (expression[i] - '0');
            i++;
        }
        
        // บวกเศษส่วน
        numerator = numerator * den + num * denominator;
        denominator *= den;
        
        // ทำให้เป็นเศษส่วนอย่างต่ำ
        int gcd_val = gcd(abs(numerator), denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }
    
    // แปลงผลลัพธ์เป็น string
    char* result = (char*)malloc(20 * sizeof(char));
    sprintf(result, "%d/%d", numerator, denominator);
    return result;
}