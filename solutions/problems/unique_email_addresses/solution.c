#define MAX_EMAIL_LENGTH 100
#define MAX_EMAILS 100

// ลบทุก '.' ใน local name
// ลบทุกอย่างหลัง '+' ใน local name
void normalizeEmail(const char* email, char* result) {
    int i = 0, j = 0;
    bool inLocal = true;
    bool seenPlus = false;
    
    while (email[i] != '\0') {
        char c = email[i];
        
        if (inLocal) {
            if (c == '@') {
                // ถึง domain part
                inLocal = false;
                result[j++] = c;
            } else if (c == '+') {
                // พบ + ใน local name
                seenPlus = true;
            } else if (c == '.') {
                // ข้าม . ใน local name
                // do nothing
            } else if (!seenPlus) {
                // เพิ่มตัวอักษรถ้ายังไม่พบ +
                result[j++] = c;
            }
        } else {
            // domain part - คัดลอกตามเดิม
            result[j++] = c;
        }
        
        i++;
    }
    
    result[j] = '\0'; // null terminator
}

int numUniqueEmails(char** emails, int emailsSize) {    
    // สร้าง array สำหรับเก็บ normalized emails
    char** normalized = (char**)malloc(emailsSize * sizeof(char*));
    for (int i = 0; i < emailsSize; i++) {
        normalized[i] = (char*)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        normalizeEmail(emails[i], normalized[i]);
    }
    
    // นับ unique emails
    int uniqueCount = 0;
    
    for (int i = 0; i < emailsSize; i++) {
        bool isUnique = true;
        
        // ตรวจสอบว่ามี email นี้แล้วหรือยัง
        for (int j = 0; j < i; j++) {
            if (strcmp(normalized[i], normalized[j]) == 0) {
                isUnique = false;
                break;
            }
        }
        
        if (isUnique) {
            uniqueCount++;
        }
    }
    
    // คืน memory
    for (int i = 0; i < emailsSize; i++) {
        free(normalized[i]);
    }
    free(normalized);
    
    return uniqueCount;
}