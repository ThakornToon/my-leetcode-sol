class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        vector<int> v;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='I'){
                v.push_back(1);
            }
            else if(s[i]=='V'){
                v.push_back(5);
            }
            else if(s[i]=='X'){
                v.push_back(10);
            }
            else if(s[i]=='L'){
                v.push_back(50);
            }
            else if(s[i]=='C'){
                v.push_back(100);
            }
            else if(s[i]=='D'){
                v.push_back(500);
            }
            else if(s[i]=='M'){
                v.push_back(1000);
            }
        }
        v.push_back(0);
        for(int i=0; i < v.size()-1; i++){
            if(v[i]>=v[i+1]){
                sum=sum+v[i];
            }
            else{
                sum=sum-v[i];
            }
        }
        return sum;
    }
};