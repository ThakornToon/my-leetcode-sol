class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int s : students) q.push(s);
        
        int i = 0;
        int attempts = 0;
        int n = students.size();
        
        while (!q.empty() && attempts < q.size()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                attempts = 0;
            } else {
                q.push(q.front());
                q.pop();
                attempts++;
            }
        }
        
        return q.size();
    }
};