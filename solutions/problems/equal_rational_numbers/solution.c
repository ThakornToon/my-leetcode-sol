double parseToDouble(char* s) {
    int len = strlen(s);
    double result = 0.0;
    
    int i = 0;
    // Integer part
    while (i < len && s[i] != '.') {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    
    // Non-repeating decimal part
    double non_repeating_value = 0.0;
    int non_repeating_len = 0;
    
    if (i < len && s[i] == '.') {
        i++;
        while (i < len && s[i] != '(') {
            non_repeating_value = non_repeating_value * 10 + (s[i] - '0');
            non_repeating_len++;
            i++;
        }
        result += non_repeating_value / pow(10, non_repeating_len);
    }
    
    // Repeating part
    if (i < len && s[i] == '(') {
        i++;
        double repeating = 0.0;
        int repeat_len = 0;
        int start = i;
        
        while (i < len && s[i] != ')') {
            repeating = repeating * 10 + (s[i] - '0');
            repeat_len++;
            i++;
        }
        
        // แปลง repeating part เป็นเศษส่วน
        // 0.5(25) = 0.525252... แบ่งเป็น: 0.5 + 0.025252...
        // 0.025252... = 25/990 ไม่ใช่ 25/99 เพราะส่วนซ้ำเริ่มต้นที่ตำแหน่งที่ 2
        if (repeat_len > 0) {
            double repeating_fraction = (double)repeating / (pow(10, repeat_len) - 1);
            // ปรับ scale ตามตำแหน่ง
            repeating_fraction /= pow(10, non_repeating_len);
            result += repeating_fraction;
        }
    }
    
    return result;
}

bool isRationalEqual(char* s, char* t) {
    double d1 = parseToDouble(s);
    double d2 = parseToDouble(t);
    // ใช้ epsilon เพื่อเปรียบเทียบ floating point
    return fabs(d1 - d2) < 1e-12;
}