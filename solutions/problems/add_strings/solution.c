char* addStrings(char* num1, char* num2) {
    int l1 = strlen(num1), l2 = strlen(num2);
    int size, carry = 0;
    size = (l1 > l2) ? l1 : l2;
    size++;
    char* result = (char*)malloc((size+1) * sizeof(char));
    result[size]='\0';
    size--;
    l1--;
    l2--;
    while (l1 >= 0 || l2 >= 0 || carry){
        int sum = carry;
        if (l1 >= 0) {
            sum += num1[l1--] - '0';
        }
        if (l2 >= 0) {
            sum += num2[l2--] - '0';
        }
        result[size--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (size == 0) { // คัวหน้าสุดเป็น 0
        // คำนวณความยาวใหม่
        int new_len = strlen(result);
        char* start;
        start = &result[1];
        // สร้างสตริงใหม่โดยไม่ต้องมีเลข 0 นำหน้า
        char* trimmed_result = (char*)malloc((new_len) * sizeof(char));
        strcpy(trimmed_result, start);
        free(result);
        return trimmed_result;

    }

    return result;
}