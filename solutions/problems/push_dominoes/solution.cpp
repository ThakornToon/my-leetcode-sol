class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0;
        
        while (i < n) {
            if (dominoes[i] == '.') {
                int j = i;
                // Find the segment of '.' between two forces
                while (j < n && dominoes[j] == '.') {
                    j += 1;
                }
                
                int left_force = (i > 0) ? dominoes[i - 1] : '.';
                int right_force = (j < n) ? dominoes[j] : '.';
                
                // Apply forces to the segment
                if (left_force == 'R' && right_force == 'L') {
                    // Balanced: meet in the middle
                    int left = i;
                    int right = j - 1;
                    while (left < right) {
                        dominoes[left] = 'R';
                        dominoes[right] = 'L';
                        left += 1;
                        right -= 1;
                    }
                } else if (left_force == 'R') {
                    // Push all to right
                    for (int k = i; k < j; k++) {
                        dominoes[k] = 'R';
                    }
                } else if (right_force == 'L') {
                    // Push all to left  
                    for (int k = i; k < j; k++) {
                        dominoes[k] = 'L';
                    }
                }
                // else: no force, remain '.'
                
                i = j;
            } else {
                i += 1;
            }
        }
        return dominoes;
    }
};