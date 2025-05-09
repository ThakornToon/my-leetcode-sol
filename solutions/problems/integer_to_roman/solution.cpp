class Solution {
public:
    string intToRoman(int num) {
        string s;
        while (num!=0){
            if (num >= 1000){
                s.push_back('M');
                num-=1000;
            }
            else if (num >= 500){
                if (num >= 900){
                    s.append("CM");
                    num-=900;
                    continue;
                }
                s.push_back('D');
                num-=500;
            }
            else if (num >= 100){
                if (num >= 400){
                    s.append("CD");
                    num-=400;
                    continue;
                }
                s.push_back('C');
                num-=100;
            }
            else if (num >= 50){
                if (num >= 90){
                    s.append("XC");
                    num-=90;
                    continue;
                }
                s.push_back('L');
                num-=50;
            }
            else if (num >= 10){
                if (num >= 40){
                    s.append("XL");
                    num-=40;
                    continue;
                }
                s.push_back('X');
                num-=10;
            }
            else if (num >= 5){
                if (num >= 9){
                    s.append("IX");
                    num-=9;
                    continue;
                }
                s.push_back('V');
                num-=5;
            }
            else if (num >= 1){
                if (num == 4){
                    s.append("IV");
                    num-=4;
                    continue;
                }
                s.push_back('I');
                num-=1;
            }
        }
        return s;
    }
};