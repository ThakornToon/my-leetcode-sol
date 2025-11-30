/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool backtrack(const char* num, int start, int* sequence, int seq_size, 
               int** result, int* return_size, int* result_capacity) {
    
    // If we've processed entire string and have at least 3 numbers, success!
    if (start == strlen(num)) {
        if (seq_size >= 3) {
            // Allocate result array
            *result = (int*)malloc(seq_size * sizeof(int));
            
            // Copy sequence to result
            memcpy(*result, sequence, seq_size * sizeof(int));
            *return_size = seq_size;
            return true;
        }
        return false;
    }
    
    long long current = 0;
    
    for (int i = start; i < strlen(num); i++) {
        // Check for leading zero (except single zero)
        if (num[start] == '0' && i > start) {
            break;
        }
        
        // Build current number digit by digit
        current = current * 10 + (num[i] - '0');
        
        // Check 32-bit integer range
        if (current > INT_MAX) {
            break;
        }
        
        int current_int = (int)current;
        
        // Check Fibonacci property if we have at least 2 numbers
        if (seq_size >= 2) {
            long long sum = (long long)sequence[seq_size - 1] + sequence[seq_size - 2];
            
            if (current_int < sum) {
                continue;  // Try longer number
            }
            if (current_int > sum) {
                break;     // No need to check longer numbers
            }
            // current_int == sum, proceed
        }
        
        // Add current number to sequence
        sequence[seq_size] = current_int;
        
        // Recursively try next position
        if (backtrack(num, i + 1, sequence, seq_size + 1, result, return_size, result_capacity)) {
            return true;
        }
        
        // Backtrack - no need to explicitly pop since we overwrite in next iteration
    }
    
    return false;
}

int* splitIntoFibonacci(char* num, int* returnSize) {
    int n = strlen(num);
    // Temporary sequence for backtracking
    int* sequence = (int*)malloc(n * sizeof(int));
    if (sequence == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = NULL;
    int result_capacity = 0;
    *returnSize = 0;
    
    // Start backtracking from position 0 with empty sequence
    if (backtrack(num, 0, sequence, 0, &result, returnSize, &result_capacity)) {
        free(sequence);
        return result;
    }
    
    free(sequence);
    *returnSize = 0;
    return NULL;
}
