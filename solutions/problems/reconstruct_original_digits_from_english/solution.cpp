class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        vector<int> nums(10, 0);
        // ตรวจสอบตัวเลขที่มีตัวอักษรเฉพาะ
        nums[0] = count['z' - 'a']; // zero มี z เฉพาะ
        nums[2] = count['w' - 'a']; // two มี w เฉพาะ
        nums[4] = count['u' - 'a']; // four มี u เฉพาะ
        nums[6] = count['x' - 'a']; // six มี x เฉพาะ
        nums[8] = count['g' - 'a']; // eight มี g เฉพาะ
        
        // ตัวเลขที่หาจากตัวอักษรอื่นหลังจากหักตัวที่รู้แล้ว
        nums[3] = count['h' - 'a'] - nums[8]; // three มี h (eight ก็มี h)
        nums[5] = count['f' - 'a'] - nums[4]; // five มี f (four ก็มี f)
        nums[7] = count['s' - 'a'] - nums[6]; // seven มี s (six ก็มี s)
        
        // ตัวเลขที่เหลือ
        nums[1] = count['o' - 'a'] - nums[0] - nums[2] - nums[4]; // one มี o (zero, two, four ก็มี o)
        nums[9] = count['i' - 'a'] - nums[5] - nums[6] - nums[8]; // nine มี i (five, six, eight ก็มี i)
        
        string result;
        for (int i = 0; i < 10; ++i) {
            result += string(nums[i], '0' + i);
        }
        return result;
    }
};