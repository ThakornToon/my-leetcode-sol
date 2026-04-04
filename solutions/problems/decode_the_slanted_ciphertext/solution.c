char* decodeCiphertext(char* encodedText, int rows) {
    int len = strlen(encodedText);
    int cols = len / rows;
    
    // สร้าง matrix 2D
    char** matrix = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = encodedText[i * cols + j];
        }
    }
    
    // จองพื้นที่สำหรับผลลัพธ์ (ขนาดไม่เกิน len)
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    
    // อ่านแนวทแยง
    for (int startCol = 0; startCol < cols; startCol++) {
        int r = 0, c = startCol;
        while (r < rows && c < cols) {
            result[idx++] = matrix[r][c];
            r++;
            c++;
        }
    }
    
    result[idx] = '\0';
    
    // ตัดช่องว่างท้าย
    while (idx > 0 && result[idx - 1] == ' ') {
        idx--;
    }
    result[idx] = '\0';
    
    // คืนหน่วยความจำ
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return result;
}