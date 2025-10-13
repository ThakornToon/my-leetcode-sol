/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    double left = 0.0, right = 1.0;
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // ตัวแปรสำหรับเก็บคำตอบ
    int numerator = 0, denominator = 0;
    
    while (left <= right) {
        double mid = (left + right) / 2.0;
        
        // นับจำนวน fraction ที่ <= mid และหา fraction ที่ใหญ่ที่สุดในกลุ่มนั้น
        int count = 0;
        int i = 0;
        double max_fraction = 0.0;
        int current_num = 0, current_den = 0;
        
        for (int j = 1; j < arrSize; j++) {
            while (i < j && (double)arr[i] / arr[j] <= mid) {
                double fraction = (double)arr[i] / arr[j];
                if (fraction > max_fraction) {
                    max_fraction = fraction;
                    current_num = arr[i];
                    current_den = arr[j];
                }
                i++;
            }
            count += i;
        }
        
        if (count == k) {
            numerator = current_num;
            denominator = current_den;
            break;
        } else if (count < k) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    result[0] = numerator;
    result[1] = denominator;
    return result;
}