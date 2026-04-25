class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        map<int, map<string, int>> tableOrders;
        
        for (auto& order : orders) {
            int table = stoi(order[1]);
            string food = order[2];
            
            foods.insert(food);
            tableOrders[table][food]++;
        }
        
        vector<vector<string>> result;
        
        // Header row
        vector<string> header = {"Table"};
        header.insert(header.end(), foods.begin(), foods.end());
        result.push_back(header);
        
        // Data rows
        for (auto& [table, items] : tableOrders) {
            vector<string> row;
            row.push_back(to_string(table));
            
            for (const string& food : foods) {
                int count = items[food];
                row.push_back(to_string(count));
            }
            
            result.push_back(row);
        }
        
        return result;
    }
};