int strStr(char* haystack, char* needle) {
    int hay = strlen(haystack);
    int need =strlen(needle);
    if (hay<need){
        return -1;
    }

    for (int i=0; i <= hay-need; ++i){
        if (haystack[i]==needle[0]){
            int c = 1;
            for (int j=1; j<need; j++){
                if (needle[j]!=haystack[i+j]){
                    break;
                }
                c++;
            }
            if (c==need){
                return i;
            }
        }
    }
    return -1;
}