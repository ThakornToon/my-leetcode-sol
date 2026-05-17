class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        
        for (const string& log : logs) {
            if (log == "../") {
                // กลับไป folder แม่
                if (depth > 0) {
                    depth--;
                }
            }
            else if (log == "./") {
                // อยู่ folder เดิม - ไม่ต้องทำอะไร
                continue;
            }
            else {
                // เข้า folder ใหม่
                depth++;
            }
        }
        
        return depth;
    }
};