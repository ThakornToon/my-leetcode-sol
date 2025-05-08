class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length()<needle.length()){
            return -1;
        }

        for (int i=0; i <= haystack.length()-needle.length(); ++i){
            if (haystack[i]==needle[0]){
                int c = 1;
                for (int j=1; j<needle.length(); j++){
                    if (needle[j]!=haystack[i+j]){
                        break;
                    }
                    c++;
                }
                if (c==needle.length()){
                    return i;
                }
            }
        }
        return -1;
    }
};