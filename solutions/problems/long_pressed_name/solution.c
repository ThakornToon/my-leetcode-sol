bool isLongPressedName(char* name, char* typed) {
    int nameLen = strlen(name);
    int typedLen = strlen(typed);
    
    // ถ้า typed สั้นกว่า name เป็นไปไม่ได้
    if (typedLen < nameLen) return false;
    
    int i = 0, j = 0;
    
    while (i < nameLen && j < typedLen) {
        // นับจำนวนตัวอักษรที่ติดกันใน name
        int nameCount = 0;
        char currentChar = name[i];
        while (i < nameLen && name[i] == currentChar) {
            nameCount++;
            i++;
        }
        
        // นับจำนวนตัวอักษรที่ติดกันใน typed
        int typedCount = 0;
        while (j < typedLen && typed[j] == currentChar) {
            typedCount++;
            j++;
        }
        
        // จำนวนใน typed ต้อง >= ใน name
        if (typedCount < nameCount) {
            return false;
        }
    }
    
    // ตรวจสอบว่าทั้ง name และ typed จบพร้อมกัน
    return i == nameLen && j == typedLen;
}