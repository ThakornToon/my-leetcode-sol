class Solution {
public:
    string largestMerge(string word1, string word2) {
        string result;
        result.reserve(word1.length() + word2.length());
        
        int i = 0, j = 0;
        int len1 = word1.length();
        int len2 = word2.length();
        
        while (i < len1 && j < len2) {
            // ถ้าตัวอักษรต่างกัน ให้เลือกตัวที่ใหญ่กว่า
            if (word1[i] != word2[j]) {
                if (word1[i] > word2[j]) {
                    result += word1[i++];
                } else {
                    result += word2[j++];
                }
                continue;
            }
            
            // ตัวอักษรเท่ากัน ต้องเปรียบเทียบ suffix
            int p = i, q = j;
            
            // หาความยาวของ prefix ที่เหมือนกัน (รวมตัวอักษรที่เท่ากันทั้งหมด)
            while (p < len1 && q < len2 && word1[p] == word2[q]) {
                p++;
                q++;
            }
            
            // กรณีหนึ่งในสองสตริงหมด
            if (p == len1 || q == len2) {
                if (p == len1) {
                    // word1 หมด → เลือกจาก word2
                    result += word2[j++];
                } else {
                    // word2 หมด → เลือกจาก word1
                    result += word1[i++];
                }
                continue;
            }
            
            // เปรียบเทียบตัวอักษรที่ต่างกัน
            if (word1[p] > word2[q]) {
                // word1 มี suffix ใหญ่กว่า → เลือกจาก word1
                result += word1[i++];
            } else {
                // word2 มี suffix ใหญ่กว่า → เลือกจาก word2
                result += word2[j++];
            }
        }
        
        // เพิ่มส่วนที่เหลือ
        if (i < len1) result.append(word1, i, len1 - i);
        if (j < len2) result.append(word2, j, len2 - j);
        
        return result;
    }
};