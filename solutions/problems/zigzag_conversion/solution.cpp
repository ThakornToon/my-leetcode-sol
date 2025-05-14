class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) {
            return s;
        }
        string ans;
        vector<string> table(numRows);  //คล้าย array 2D 
        
        for(int index=0, size=s.size(); index<size;){  
            for(int j=0; j<numRows && index<size;  j++, index++){
                table[j] += s[index];    
            }
            for(int j=numRows - 2;j && index<size; j--, index++){
                table[j] += s[index];  
            }   
        }
        for(int j=0;j<numRows; j++){
            ans += table[j];
        }                       
        return ans;
    }
};