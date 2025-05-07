class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        int min = 0;
        for (string& check : strs){
            if (check.size()==0){
                return "";
            }
            else if (check.size()==1){
                min=1;
            }
        }

        for (int i=1; i<strs.size(); i++){
            int index = 0;
            while (index<strs[0].size() && index<strs[i].size()){
                if (strs[0][index]==strs[i][index]){
                    count++;
                }
                else{
                    if (count<min || min==0){
                        min = count;
                        break;
                    }
                }
                index++;
            }
            if (count==0){
                return "";
            }
            if (count>0 && min==0){
                min=count;
            }
            count=0;
            index=0;
        }
        if (min!=0){
            return strs[0].substr(0, min);
        }
        return "";
    }
};