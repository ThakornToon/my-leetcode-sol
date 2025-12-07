
int atMostNGivenDigitSet(char** digits, int digitsSize, int n) {
    // แปลง n เป็น string
    char n_str[20];
    sprintf(n_str, "%d", n);
    int k = strlen(n_str);
    
    // แปลง digits เป็นตัวเลขและเรียงลำดับ
    int* digit_vals = (int*)malloc(digitsSize * sizeof(int));
    for (int i = 0; i < digitsSize; i++) {
        digit_vals[i] = digits[i][0] - '0';
    }
    
    // Sort digits (bubble sort)
    for (int i = 0; i < digitsSize; i++) {
        for (int j = i + 1; j < digitsSize; j++) {
            if (digit_vals[i] > digit_vals[j]) {
                int temp = digit_vals[i];
                digit_vals[i] = digit_vals[j];
                digit_vals[j] = temp;
            }
        }
    }
    
    int result = 0;
    
    // กรณี 1: หลักน้อยกว่า k
    for (int len = 1; len < k; len++) {
        result += (int)pow(digitsSize, len);
    }
    
    // กรณี 2: หลักเท่ากับ k
    for (int i = 0; i < k; i++) {
        int current_digit = n_str[i] - '0';
        
        // นับ digit ที่น้อยกว่า current_digit
        int less_count = 0;
        for (int j = 0; j < digitsSize; j++) {
            if (digit_vals[j] < current_digit) {
                less_count++;
            } else {
                break;
            }
        }
        
        result += less_count * (int)pow(digitsSize, k - i - 1);
        
        // ตรวจสอบว่ามี digit เท่ากับ current_digit หรือไม่
        int has_equal = 0;
        for (int j = 0; j < digitsSize; j++) {
            if (digit_vals[j] == current_digit) {
                has_equal = 1;
                break;
            }
        }
        
        if (!has_equal) {
            free(digit_vals);
            return result;
        }
        
        // ถ้าเป็นหลักสุดท้าย
        if (i == k - 1) {
            result += 1;
        }
    }
    
    free(digit_vals);
    return result;
}