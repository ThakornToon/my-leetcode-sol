class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> res = {-1, -1};
        int countOne = 0;
        for (auto num : arr) {
            if (num == 1) {
                countOne++;
            } 
        }

        if (countOne == 0) {
            return {0, (int)arr.size() - 1};  // กรณีไม่มี 1
        }

        if (countOne % 3 != 0) {
            return res;
        }

        // แต่ละส่วนต้องมีเท่ากัน
        countOne /= 3;

        int i = -1;
        int j = -1;
        int k = arr.size() - 1;
        int extraZero = 0;

        // part 3
        int idx = k;
        for (; arr[idx] != 1; idx--) {
            extraZero++; // นับ 0 ที่ต้องลงท้าย
        } // idx หยุดที่ 1 ตัวสุดท้ายของ part 3
        
        int count = 0; // ไว้ใช้นับ(อเนกประสงค์)
        while (count != countOne && idx >= 0) {
            if (arr[idx] == 1) {
                count++;
            }
            idx--;
        } // idx หยุดที่หน้า 1 ตัวแรกของ part 3
        
        // part 2
        count = 0;
        j = idx;
        for (; arr[j] != 1; j--) {
            count++; // นับจำนวน 0 เพื่อแบ่ง
        } // j หยุดที่ 1 ตัวสุดท้ายใน part 2
        if (count < extraZero) {
            return res;
        }
        j += (extraZero + 1); // จุดแบ่ง part 2-3
        
        count = 0;
        while (count != countOne && idx >= 0) {
            if (arr[idx] == 1) {
                count++;
            }
            idx--;
        } // idx หยุดที่หน้า 1 ตัวแรกของ part 2

        // part 1
        count = 0;
        i = idx;
        for (; arr[i] != 1; i--) {
            count++; // นับจำนวน 0 เพื่อแบ่ง
        } // i หยุดที่ 1 ตัวสุดท้ายใน part 1
        if (count < extraZero) {
            return res;
        }
        i += extraZero; // จุดแบ่ง part 1-2

        // ตรงสอบคำตอบ
        count = 0;
        for (int l = 0; count != countOne; l++) {
            if (arr[i - l - extraZero] == arr[j - 1 - l - extraZero] && arr[j - 1 - l - extraZero] == arr[k - l -extraZero]) {
                if (arr[k - l -extraZero] == 1) {
                    count++;
                }
            } else {
                return res;
            }
        }
        res[0] = i;
        res[1] = j;
        return res;
    }
};