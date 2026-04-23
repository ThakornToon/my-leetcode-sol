class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result;
        vector<int> p(m);
        iota(p.begin(), p.end(), 1);  // p = [1,2,...,m]
        
        for (int x : queries) {
            // หาตำแหน่ง
            int pos = find(p.begin(), p.end(), x) - p.begin();
            result.push_back(pos);
            
            // ย้ายไปหน้าสุด
            p.erase(p.begin() + pos);
            p.insert(p.begin(), x);
        }
        
        return result;
    }
};