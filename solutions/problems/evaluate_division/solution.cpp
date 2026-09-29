class Solution {
private:
    // dfs จาก curr หาทางไป target
    double dfs(string& curr, string& target, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited) {
        if (curr == target) return 1.0;
        visited.insert(curr);

        // ลองไปทุกทาง
        for (auto& [next, weight] : adj[curr]) {
            // ห้าม loop
            if (visited.find(next) == visited.end()) {
                double sub = dfs(next, target, adj, visited);
                if (sub != -1.0) {
                    return sub * weight;
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // from -> {to, weight}
        unordered_map<string, vector<pair<string, double>>> adj;

        // สร้างกราฟสองทิศทางพร้อมค่าน้ำหนัก
        for (size_t i = 0; i < equations.size(); ++i) {
            string& u = equations[i][0];
            string& v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> results;
        for (auto& q : queries) {
            string& c = q[0];  
            string& d = q[1];  // target

            if (adj.find(c) == adj.end() || adj.find(d) == adj.end()) {
                results.push_back(-1.0);
            } else if (c == d) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(c, d, adj, visited));
            }
        }

        return results;
    }
};