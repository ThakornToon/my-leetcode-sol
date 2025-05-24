class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int idx = 0;
        while (idx<n) {
            int start = idx;
            int curr_line = 0; //count all space and character
            int sum_of_ch = 0; //count only character
            bool last_line = false;
            while (idx<n && curr_line + words[idx].length() <= maxWidth) {
                curr_line += words[idx].length() + 1;
                sum_of_ch += words[idx].length();
                idx++;
                if (idx==n) {
                    last_line = true;
                }
            }
            int extra;
            int space;
            curr_line = idx - start; //change this variable to store number of word instead
            if (last_line || curr_line == 1) {
                extra=0;
                space = maxWidth - sum_of_ch;
            }
            else {
                extra = (maxWidth - sum_of_ch) % (curr_line - 1);
                space = (maxWidth - sum_of_ch) / (curr_line - 1);
            }
            string line = "";
            if (last_line) {
                for (; start<idx; start++) {
                    line+=words[start];
                    if (start == idx-1) {
                        break;
                    }
                    line+=' ';
                    space--;
                }
                line+=string(space, ' ');
            }
            else {
                for (; start<idx; start++) {
                    line+=words[start];
                    if (start == idx-1 && curr_line != 1) {
                        break;
                    }
                    line+=string(space, ' ');
                    if (extra>0) {
                        line+=' ';
                        extra--;
                    }
                }
            }
            ans.push_back(line);
        }
        return ans;
    }
};
