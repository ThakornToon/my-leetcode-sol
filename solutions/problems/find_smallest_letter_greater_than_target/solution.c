char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0, right = lettersSize - 1;
    
    // Wrap around case
    if (target >= letters[right]) {
        return letters[0];
    }
    
    // Binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (letters[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return letters[left];
}