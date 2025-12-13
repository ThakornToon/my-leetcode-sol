class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string result = "";
        int maxTime = -1;
        
        // ทดสอบทุก combination
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                for (int k = 0; k < 4; k++) {
                    if (k == i || k == j) continue;
                    int l = 6 - i - j - k; // เพราะ 0+1+2+3 = 6
                    
                    int hours = arr[i] * 10 + arr[j];
                    int minutes = arr[k] * 10 + arr[l];
                    
                    if (hours < 24 && minutes < 60) {
                        int total = hours * 60 + minutes;
                        if (total > maxTime) {
                            maxTime = total;
                            result = to_string(arr[i]) + to_string(arr[j]) + ":" +
                                     to_string(arr[k]) + to_string(arr[l]);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};