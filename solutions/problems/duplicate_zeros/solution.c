void duplicateZeros(int* arr, int arrSize) {
    int zeros = 0;
    int n = arrSize;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeros++;
        }
    }
    
    if (zeros == 0 || zeros == n) return;
    
    int i = n - 1;
    int j = n + zeros - 1;  
    
    while (i >= 0 && j >= 0) {
        if (j < n) {
            arr[j] = arr[i];
        }
        
        if (arr[i] == 0) {
            j--;
            if (j < n) {
                arr[j] = 0;
            }
        }
        
        i--;
        j--;
    }
}