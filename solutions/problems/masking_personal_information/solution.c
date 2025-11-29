char* maskEmail(char* s) {
    // Convert to lowercase and process
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
    
    char* at_pos = strchr(s, '@');
    *at_pos = '\0'; // Split string
    char* local_name = s;
    char* domain_name = at_pos + 1;
    
    // Create masked email
    char* result = malloc(100 * sizeof(char));
    sprintf(result, "%c*****%c@%s", local_name[0], local_name[strlen(local_name)-1], domain_name);
    
    return result;
}

char* maskPhone(char* s) {
    // Extract digits
    char digits[20] = {0};
    int digit_count = 0;
    
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            digits[digit_count++] = s[i];
        }
    }
    digits[digit_count] = '\0';
    
    // Get last 4 digits
    char last_four[5] = {0};
    strcpy(last_four, digits + digit_count - 4);
    
    char* result = malloc(20 * sizeof(char));
    
    if (digit_count == 10) {
        sprintf(result, "***-***-%s", last_four);
    } else {
        int country_code_len = digit_count - 10;
        char stars[5] = {0};
        for (int i = 0; i < country_code_len; i++) {
            stars[i] = '*';
        }
        sprintf(result, "+%s-***-***-%s", stars, last_four);
    }
    
    return result;
}

char* maskPII(char* s) {
    // Check if it's email
    if (strchr(s, '@') != NULL) {
        return maskEmail(s);
    } else {
        return maskPhone(s);
    }
}