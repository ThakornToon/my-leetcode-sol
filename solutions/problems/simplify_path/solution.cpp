class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        int i = 0 ;
        int n = path.size();
        while (i < n){
            string temp = "";
            while (i < n && path[i] == '/') i++;
            while (i < n && path[i] != '/') temp += path[i++];
            if (temp == " " || temp  == ".")continue;
            if (temp == ".."){
                if (!st.empty()) st.pop();
                continue;
            }
            if (temp!="") st.push(temp);
        }
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans == "")return "/";
        return ans;
    }
};