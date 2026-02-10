class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int maxLen = 0;
        
        // Precompute parity
        boolean[] isEven = new boolean[n];
        for (int i = 0; i < n; i++) {
            isEven[i] = nums[i] % 2 == 0;
        }
        
        for (int i = 0; i < n; i++) {
            Set<Integer> evenSet = new HashSet<>();
            Set<Integer> oddSet = new HashSet<>();
            
            for (int j = i; j < n; j++) {
                if (isEven[j]) {
                    evenSet.add(nums[j]);
                } else {
                    oddSet.add(nums[j]);
                }
                
                if (evenSet.size() == oddSet.size()) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
                
                // Early exit if remaining can't beat maxLen
                if (n - i <= maxLen) {
                    break;
                }
            }
        }
        
        return maxLen;
    }
}