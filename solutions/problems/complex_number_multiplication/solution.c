char* complexNumberMultiply(char* num1, char* num2) {
    int a, b, c, d;
    
    // Parse first complex number
    sscanf(num1, "%d+%di", &a, &b);
    
    // Parse second complex number
    sscanf(num2, "%d+%di", &c, &d);
    
    // Calculate result
    int real = a * c - b * d;
    int imag = a * d + b * c;
    
    // Allocate memory for result string
    char* result = (char*)malloc(20 * sizeof(char));
    snprintf(result, 20, "%d+%di", real, imag);
    
    return result;
}