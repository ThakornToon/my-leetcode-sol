bool isNumber(char* s) {
    bool isdot = false, nums = false, ise = false;
    for(int i=0; s[i]!='\0'; i++){
        if(isdigit(s[i])) {
            nums = true;
        }
        else if(s[i] == '+' || s[i] == '-') {
            if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) {
                return false;
            }
        }
        else if(s[i] == 'e' || s[i] == 'E') {
            if(ise || !nums) {
            return false;
            }
            ise = true;
            nums = false;
        }
        else if(s[i] == '.') {
            if(isdot || ise) {
                return false;
            }
            isdot = true;
        }
        else {
                return false;
        }
    }        
    return nums;
}