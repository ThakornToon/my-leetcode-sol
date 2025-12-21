/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
base 2
sum = a + b + carry
digit = sum % 2
new_carry = sum / 2

base -2
sum = a + b + carry
digit = ((sum % 2) + 2) % 2 // 0 or 1
new_carry = (digit - sum) / 2} // sum = digit + new_carry * (-2)

เราสามารถบอกได้ว่า ((sum % 2) + 2) % 2 = sum & 1 และ (digit - sum) / 2 = -(sum >> 1):

กรณี sum ≥ 0:
ถ้า sum คู่: digit = 0 → (0 - sum)/2 = -sum/2 = -(sum >> 1)
ถ้า sum คี่: digit = 1 → (1 - sum)/2 = -(sum-1)/2 = -(sum >> 1) 

กรณี sum = -1:
digit = 1 → (1 - (-1))/2 = 2/2 = 1
-(-1 >> 1) → -(-1) = 1 
*/

int* addNegabinary(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int i = arr1Size - 1;
    int j = arr2Size - 1;
    int carry = 0;
    
    int maxSize = (arr1Size > arr2Size ? arr1Size : arr2Size) + 2;
    int* result = (int*)malloc(maxSize * sizeof(int));
    int k = 0;
    
    while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        
        if (i >= 0) {
            sum += arr1[i];
            i--;
        }
        if (j >= 0) {
            sum += arr2[j];
            j--;
        }
        
        // In negabinary, digit can be 0 or 1
        // But during addition, we might get -1, 0, 1, 2
        if (sum >= 2) {
            // If sum is 2 or 3, we need to handle carry
            result[k++] = sum - 2;
            carry = -1;  // In negabinary, 2 becomes -1 carry
        } else if (sum >= 0) {
            result[k++] = sum;
            carry = 0;
        } else {  // sum == -1
            // -1 in negabinary is equivalent to 1 with carry 1
            result[k++] = 1;
            carry = 1;
        }
    }
    
    // Reverse the result array
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        int temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
    
    // Remove leading zeros
    int start = 0;
    while (start < k - 1 && result[start] == 0) {
        start++;
    }
    
    *returnSize = k - start;
    int* finalResult = (int*)malloc((*returnSize) * sizeof(int));
    for (int idx = 0; idx < *returnSize; idx++) {
        finalResult[idx] = result[start + idx];
    }
    
    free(result);
    return finalResult;
}