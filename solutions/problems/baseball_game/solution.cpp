class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        
        for (const string& op : operations) {
            if (op == "+") {
                // บวกสองคะแนนล่าสุด
                int top1 = scores.top(); scores.pop();
                int top2 = scores.top();
                scores.push(top1);
                scores.push(top1 + top2);
            }
            else if (op == "D") {
                // คูณสองคะแนนล่าสุด
                scores.push(scores.top() * 2);
            }
            else if (op == "C") {
                // ลบคะแนนล่าสุด
                scores.pop();
            }
            else {
                // จำนวนเต็ม
                scores.push(stoi(op));
            }
        }
        
        // คำนวณผลรวม
        int sum = 0;
        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }
        
        return sum;
    }
};