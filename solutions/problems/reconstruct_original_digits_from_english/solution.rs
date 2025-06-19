impl Solution {
    pub fn original_digits(s: String) -> String {
        let mut count = [0; 26];
        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }
        
        let mut nums = [0; 10];
        // ตัวเลขที่มีตัวอักษรเฉพาะ
        nums[0] = count[(b'z' - b'a') as usize]; // zero
        nums[2] = count[(b'w' - b'a') as usize]; // two
        nums[4] = count[(b'u' - b'a') as usize]; // four
        nums[6] = count[(b'x' - b'a') as usize]; // six
        nums[8] = count[(b'g' - b'a') as usize]; // eight
        
        // ตัวเลขที่ต้องหักลบ
        nums[3] = count[(b'h' - b'a') as usize] - nums[8]; // three (h อยู่ใน eight ด้วย)
        nums[5] = count[(b'f' - b'a') as usize] - nums[4]; // five (f อยู่ใน four ด้วย)
        nums[7] = count[(b's' - b'a') as usize] - nums[6]; // seven (s อยู่ใน six ด้วย)
        
        // ตัวเลขที่เหลือ
        nums[1] = count[(b'o' - b'a') as usize] - nums[0] - nums[2] - nums[4]; // one (o อยู่ใน zero, two, four)
        nums[9] = count[(b'i' - b'a') as usize] - nums[5] - nums[6] - nums[8]; // nine (i อยู่ใน five, six, eight)
        let mut result: Vec<u8> = Vec::new();
        for i in 0..10 {
            for _ in 0..nums[i] {
                result.push(b'0' + i as u8);
            }
        }
        String::from_utf8(result).unwrap()
    }
}