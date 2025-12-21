/*
base 2
sum = a + b + carry
digit = sum % 2
new_carry = sum / 2

base -2
sum = a + b + carry
digit = ((sum % 2) + 2) % 2 // 0 or 1
new_carry = (digit - sum) / 2} // sum = digit + new_carry * (-2)
*/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            
            if (i >= 0) {
                sum += arr1[i];
                i--;
            }
            if (j >= 0) {
                sum += arr2[j];
                j--;
            }
            
            // ใช้สูตรทางคณิตศาสตร์
            int digit = ((sum % 2) + 2) % 2;  // รับประกันได้ 0 หรือ 1
            int new_carry = (digit - sum) / 2;
            
            result.push_back(digit);
            carry = new_carry;
        }
        
        // กลับลำดับและลบ leading zeros
        reverse(result.begin(), result.end());
        
        // ลบเลข 0 นำหน้า (แต่ต้องเหลืออย่างน้อย 1 หลัก)
        while (result.size() > 1 && result[0] == 0) {
            result.erase(result.begin());
        }
        
        return result;
    }
};