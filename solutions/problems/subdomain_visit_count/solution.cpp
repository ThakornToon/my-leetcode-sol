class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainCount;
        
        for (const string& cpdomain : cpdomains) {
            // Split count and domain
            size_t spacePos = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, spacePos));
            string domain = cpdomain.substr(spacePos + 1);
            
            // Process all subdomains
            domainCount[domain] += count;
            size_t dotPos = domain.find('.');
            
            while (dotPos != string::npos) {
                domain = domain.substr(dotPos + 1);
                domainCount[domain] += count;
                dotPos = domain.find('.');
            }
        }
        
        // Convert to result format
        vector<string> result;
        for (const auto& [domain, count] : domainCount) {
            result.push_back(to_string(count) + " " + domain);
        }
        
        return result;
    }
};