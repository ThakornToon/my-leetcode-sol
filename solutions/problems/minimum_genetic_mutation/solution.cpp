class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (bank_set.find(endGene) == bank_set.end()) {
            return -1;
        }

        unordered_set<string> visited;
        queue<pair<string, int>> q;

        q.push({startGene, 0});
        visited.insert(startGene);

        char gene_chars[4] = {'A', 'C', 'G', 'T'};

        // BFS
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == endGene) {
                return steps;
            }

            string next = curr;
            for (int i = 0; i < 8; ++i) {
                char original = next[i];
                for (char ch : gene_chars) {
                    if (ch == original) continue;
                    next[i] = ch;

                    if (bank_set.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
                next[i] = original;
            }
        }

        return -1;
    }
};