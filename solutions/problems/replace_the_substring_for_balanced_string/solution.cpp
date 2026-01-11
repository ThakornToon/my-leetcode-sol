class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int k = n / 4;
        
        int count[4] = {0};
        for (char c : s) {
            count[idx(c)]++;
        }
        
        if (count[0] == k && count[1] == k && count[2] == k && count[3] == k) {
            return 0;
        }
        
        int left = 0;
        int result = INT_MAX;
        int window[4] = {0};
        
        for (int right = 0; right < n; right++) {
            window[idx(s[right])]++;
            
            while (left <= right) {
                bool valid = true;
                for (int i = 0; i < 4; i++) {
                    if (count[i] - window[i] > k) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    result = min(result, right - left + 1);
                    window[idx(s[left])]--;
                    left++;
                } else {
                    break;
                }
            }
        }
        
        return result;
    }
private:
    int idx(char c) {
        switch(c) {
            case 'Q': return 0;
            case 'W': return 1;
            case 'E': return 2;
            case 'R': return 3;
        }
        return -1;
    }
};