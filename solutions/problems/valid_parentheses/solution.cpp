class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        for (char c:s){
            if (c == '(' || c == '{' || c == '['){
                vec.push_back(c);
            }
            else{
                if (vec.empty()){
                    return false;
                }
                char top = vec.back();
                vec.pop_back();
                if ( (c == ')' && top != '(') || 
                     (c == '}' && top != '{') || 
                     (c == ']' && top != '[') ) {
                    return false;
                }
            }
        }
        return vec.empty();
    }
};