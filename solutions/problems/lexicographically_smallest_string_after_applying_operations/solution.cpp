class Solution {
private:
    string addOperation(string s, int a) {
        for (int i = 1; i < s.length(); i += 2) {
            int digit = s[i] - '0';
            digit = (digit + a) % 10;
            s[i] = digit + '0';
        }
        return s;
    }
    
    string rotateOperation(string s, int b) {
        int n = s.length();
        b %= n;
        return s.substr(n - b) + s.substr(0, n - b);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        string smallest = s;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // ทดลอง add
            string addResult = addOperation(curr, a);
            if (visited.find(addResult) == visited.end()) {
                visited.insert(addResult);
                q.push(addResult);
                if (addResult < smallest) smallest = addResult;
            }
            
            // ทดลอง rotate
            string rotateResult = rotateOperation(curr, b);
            if (visited.find(rotateResult) == visited.end()) {
                visited.insert(rotateResult);
                q.push(rotateResult);
                if (rotateResult < smallest) smallest = rotateResult;
            }
        }
        
        return smallest;
    }
};