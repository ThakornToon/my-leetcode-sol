class Solution {
private:
    std::vector<std::string> split(string& s, char delim) {
        vector<std::string> tokens;
        string token = "";
        for (char c : s) {
            if (c == delim) {
                tokens.push_back(token);
                token.clear();
            } else {
                token += c;
            }
        }
        tokens.push_back(token);
        return tokens;
    }

    bool isValidIPv4(string& ip) {
        vector<string> parts = split(ip, '.');
        if (parts.size() != 4) return false;

        for (string& part : parts) {
            if (part.empty() || part.size() > 3) return false;
            // ห้ามมี leading zero
            if (part.size() > 1 && part[0] == '0') return false;

            int val = 0;
            for (char c : part) {
                if (!isdigit(c)) return false;
                val = val * 10 + (c - '0');
            }
            if (val > 255) return false;
        }
        return true;
    }

    bool isValidIPv6(string& ip) {
        vector<string> parts = split(ip, ':');
        if (parts.size() != 8) return false;

        for (string& part : parts) {
            if (part.empty() || part.size() > 4) return false;
            for (char c : part) {
                if (!isxdigit(c)) return false;
            }
        }
        return true;
    }

public:
    string validIPAddress(string queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};