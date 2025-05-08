int lengthOfLastWord(char* s) {
    int count = 0;
    for (int i=strlen(s)-1; i>=0; i--){
        if (s[i]==' '){
            if (count!=0){
                return count;
            }
            continue;
        }
        else{
            count+=1;
        }
    }
    return count;
}