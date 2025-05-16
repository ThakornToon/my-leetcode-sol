class Solution {
public:
    void recursion(vector<int> num, int index, vector<vector<int> > &res) {
        if (index == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int swp = index; swp < num.size(); swp++) {
            if (index != swp && num[index] == num[swp]) continue;
            swap(num[index], num[swp]);
            recursion(num, index+1, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};