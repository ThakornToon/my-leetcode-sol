

char * interpret(char * command){
    int n = strlen(command);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        if (command[i] == 'G') {
            result[idx++] = 'G';
        }
        else if (command[i] == '(') {
            if (command[i + 1] == ')') {
                result[idx++] = 'o';
                i += 1; // ข้าม ')'
            }
            else { // "(al"
                result[idx++] = 'a';
                result[idx++] = 'l';
                i += 3; // ข้าม "al)"
            }
        }
    }
    
    result[idx] = '\0';
    return result;
}