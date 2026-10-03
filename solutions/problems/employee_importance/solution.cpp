/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    unordered_map<int, Employee*> empMap;

    int dfs(int id) {
        Employee* emp = empMap[id];
        int total = emp->importance;
        for (int subId : emp->subordinates) {
            total += dfs(subId);
        }
        return total;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto emp : employees) {
            empMap[emp->id] = emp;
        }
        return dfs(id);
    }
};