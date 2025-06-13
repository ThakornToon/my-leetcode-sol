class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers; 
        int fact = 1; 
        for(int i=1; i<n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";

        //to align with 0 index based
        k = k-1; //1234 มี 24 แบบ แบ่งช่วง 0-5, 6-11, 12-17, 18-23 ว่าตัวแรกจะเป็นอะไร 1,2,3,4 ...และตัวถัดไปเรื่อยๆ สมมติต้องการแบบสุดท้ายถ้าใช้ 24/24 จะได้ตัวแรกคือ 2 แทนทีจะเป็น 4
        while(1){
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size()==0){
                break;
            }

            //to get next iteration k, fact
            k = k%fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};