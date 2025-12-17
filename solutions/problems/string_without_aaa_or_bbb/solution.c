

char * strWithout3a3b(int a, int b){
    char* result = (char*)malloc((a + b + 1) * sizeof(char));
    int index = 0;
    
    while (a > 0 || b > 0) {
        if (a > b) {
            // วาง "aab" ถ้ายังมี a มากกว่า b
            if (a > 0) { result[index++] = 'a'; a--; }
            if (a > 0) { result[index++] = 'a'; a--; }
            if (b > 0) { result[index++] = 'b'; b--; }
        } else if (b > a) {
            // วาง "bba" ถ้ายังมี b มากกว่า a
            if (b > 0) { result[index++] = 'b'; b--; }
            if (b > 0) { result[index++] = 'b'; b--; }
            if (a > 0) { result[index++] = 'a'; a--; }
        } else {
            // a == b, สลับกันไป
            if (a > 0) { result[index++] = 'a'; a--; }
            if (b > 0) { result[index++] = 'b'; b--; }
        }
    }
    
    result[index] = '\0';
    return result;
}