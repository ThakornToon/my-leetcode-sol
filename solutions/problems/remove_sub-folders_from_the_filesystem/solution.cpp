class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        result.push_back(folder[0]);
        
        for (int i = 1; i < folder.size(); i++) {
            string current = folder[i];
            string last = result.back();
            
            // Create the prefix to check
            string prefix = last + "/";
            
            // Check if current not starts with prefix
            if (current.compare(0, prefix.size(), prefix) != 0) {
                result.push_back(current);
            }
        }
        
        return result;
    }
};