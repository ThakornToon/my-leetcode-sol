bool isValid(char* s) {
    int index = -1;
    char store[strlen(s)/2+1];
    for (int i=0; i<strlen(s); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            index++;
            if (index>strlen(s)/2){
                return false;
            }
            store[index] = s[i];
            
        }
        else{
            if (index==-1){
                return false;
            }
            if ( (s[i] == ')' && store[index] != '(') || 
                 (s[i] == '}' && store[index] != '{') || 
                 (s[i] == ']' && store[index] != '[') ) {
                return false;
            }
            index--;
        }
    }
    printf("%d", index);
    return index<0;
}