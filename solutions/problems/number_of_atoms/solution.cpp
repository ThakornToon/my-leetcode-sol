class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        map<string, int> counts = parseFormula(formula, i);
        
        string result;
        for (auto& [atom, count] : counts) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }
        
        return result;
    }

private:
    map<string, int> parseFormula(const string& formula, int& i) {
        map<string, int> counts;
        int n = formula.size();
        
        while (i < n && formula[i] != ')') {
            if (formula[i] == '(') {
                i++; // Skip '('
                map<string, int> subCounts = parseFormula(formula, i);
                i++; // Skip ')'
                
                int multiplier = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    multiplier = multiplier * 10 + (formula[i] - '0');
                    i++;
                }
                if (multiplier == 0) multiplier = 1;
                for (auto& [atom, count] : subCounts) {
                    counts[atom] += count * multiplier;
                }
            } else {
                string atom;
                atom += formula[i++]; // First character must be uppercase
                
                while (i < formula.size() && islower(formula[i])) {
                    atom += formula[i++];
                }

                int count = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                counts[atom] += (count == 0 ? 1 : count);
            }
        }
        
        return counts;
    }
};