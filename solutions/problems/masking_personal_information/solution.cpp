class Solution {
public:
    string maskPII(string s) {
        if (isEmail(s)) {
            return maskEmail(s);
        } else {
            return maskPhone(s);
        }
    }

private:
    bool isEmail(const string& s) {
        return s.find('@') != string::npos;
    }
    
    string maskEmail(string s) {
        string result;
        size_t at_pos = s.find('@');
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string local_name = s.substr(0, at_pos);
        string domain_name = s.substr(at_pos + 1);
        
        result = local_name[0] + string("*****") + local_name[at_pos - 1] + "@" + domain_name;
        return result;
    }
    
    string maskPhone(const string& s) {
        string digits;
        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            }
        }
        
        int n = digits.length();
        string last_four = digits.substr(n - 4);
        
        if (n == 10) {
            return "***-***-" + last_four;
        } else {
            string country_code = string(n - 10, '*');
            return "+" + country_code + "-***-***-" + last_four;
        }
    }
};