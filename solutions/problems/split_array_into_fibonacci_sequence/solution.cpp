class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> result;
        backtrack(num, 0, result);
        return result;
    }
    
private:
    bool backtrack(const string& num, int start, vector<int>& sequence) {
        if (start == num.size() && sequence.size() >= 3) {
            return true;
        }
        
        string currentStr = "";
        for (int i = start; i < num.size(); i++) {
            // No leading zero except for single zero
            if (num[start] == '0' && i > start) break;
            
            currentStr += num[i];
            long long current = stoll(currentStr);
            
            // Check 32-bit integer range
            if (current > INT_MAX) break;
            
            int n = sequence.size();
            if (n >= 2) {
                long long sum = (long long)sequence[n-1] + sequence[n-2];
                if (current < sum) continue;
                if (current > sum) break;  // No need to check longer numbers
            }
            
            sequence.push_back((int)current);
            if (backtrack(num, i + 1, sequence)) {
                return true;
            }
            sequence.pop_back();
        }
        
        return false;
    }
};