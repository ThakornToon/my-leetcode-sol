int romanToInt(char* s) {
    int v[strlen(s)+1];
    int sum=0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='I'){
            v[i]=1;
        }
        else if(s[i]=='V'){
            v[i]=5;
        }
        else if(s[i]=='X'){
            v[i]=10;
        }
        else if(s[i]=='L'){
            v[i]=50;
        }
        else if(s[i]=='C'){
            v[i]=100;
        }
        else if(s[i]=='D'){
            v[i]=500;
        }
        else if(s[i]=='M'){
            v[i]=1000;
        }
    }
    v[strlen(s)]=0;
    for(int i=0; i < strlen(s); i++){
        if(v[i]>=v[i+1]){
            sum=sum+v[i];
        }
        else{
            sum=sum-v[i];
        }
    }
    return sum;
}