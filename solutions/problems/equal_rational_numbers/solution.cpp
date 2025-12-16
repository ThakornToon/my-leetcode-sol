class Solution {
public:
    bool isRationalEqual(string s, string t) {
        double d1 = parseToDouble(s);
        double d2 = parseToDouble(t);
        return abs(d1 - d2) < 1e-12;
    }
private:
    double parseToDouble(const string& s) {
        int len = s.length();
        double result = 0.0;
        
        int i = 0;
        // Integer part
        while (i < len && s[i] != '.') {
            result = result * 10 + (s[i] - '0');
            i++;
        }
        
        // Non-repeating decimal part
        double non_repeating_value = 0.0;
        int non_repeating_len = 0;
        
        if (i < len && s[i] == '.') {
            i++;
            while (i < len && s[i] != '(') {
                non_repeating_value = non_repeating_value * 10 + (s[i] - '0');
                non_repeating_len++;
                i++;
            }
            result += non_repeating_value / pow(10, non_repeating_len);
        }
        
        // Repeating part
        if (i < len && s[i] == '(') {
            i++;
            double repeating = 0.0;
            int repeat_len = 0;
            
            while (i < len && s[i] != ')') {
                repeating = repeating * 10 + (s[i] - '0');
                repeat_len++;
                i++;
            }
            
            if (repeat_len > 0) {
                // Convert repeating part to fraction
                // Example: 0.(25) = 25/99
                // But for 0.5(25), we need to scale it: 0.5 + 0.025252... = 0.5 + 25/990
                double repeating_fraction = repeating / (pow(10, repeat_len) - 1);
                // Scale according to position
                repeating_fraction /= pow(10, non_repeating_len);
                result += repeating_fraction;
            }
        }
        
        return result;
    }
};