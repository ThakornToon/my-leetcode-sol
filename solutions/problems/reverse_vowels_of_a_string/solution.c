bool isVowel(char a) {
    a = tolower(a);
    if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
        return true;
    }
    else{
        return false;
    }   
}

char* reverseVowels(char* s) {
    int start = 0;
    int end = strlen(s) - 1;

    while (start < end) {
        while (start < end && !isVowel(s[start])) {
            start++;
        }
        while (start < end && !isVowel(s[end])) {
            end--;
        }
        
        // Swap vowels
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
    return s;
}