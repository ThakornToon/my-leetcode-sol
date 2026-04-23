#define MAX_RESULT 100001

char* entityParser(char* text) {
    int n = strlen(text);
    char* result = (char*)malloc((MAX_RESULT) * sizeof(char));
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        if (text[i] == '&') {
            // ตรวจสอบ entity
            if (text[i+1] == 'q' && text[i+2] == 'u' && text[i+3] == 'o' && 
                text[i+4] == 't' && text[i+5] == ';') {
                result[idx++] = '"';
                i += 5;
            }
            else if (text[i+1] == 'a' && text[i+2] == 'p' && text[i+3] == 'o' && 
                     text[i+4] == 's' && text[i+5] == ';') {
                result[idx++] = '\'';
                i += 5;
            }
            else if (text[i+1] == 'a' && text[i+2] == 'm' && text[i+3] == 'p' && 
                     text[i+4] == ';') {
                result[idx++] = '&';
                i += 4;
            }
            else if (text[i+1] == 'g' && text[i+2] == 't' && text[i+3] == ';') {
                result[idx++] = '>';
                i += 3;
            }
            else if (text[i+1] == 'l' && text[i+2] == 't' && text[i+3] == ';') {
                result[idx++] = '<';
                i += 3;
            }
            else if (text[i+1] == 'f' && text[i+2] == 'r' && text[i+3] == 'a' && 
                     text[i+4] == 's' && text[i+5] == 'l' && text[i+6] == ';') {
                result[idx++] = '/';
                i += 6;
            }
            else {
                result[idx++] = text[i];
            }
        } else {
            result[idx++] = text[i];
        }
    }
    
    result[idx] = '\0';
    return result;
}