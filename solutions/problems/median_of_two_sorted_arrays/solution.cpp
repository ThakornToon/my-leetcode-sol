class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ให้ nums1 เป็นอาเรย์ที่สั้นกว่าเสมอ เพื่อลดขอบเขตการค้นหา Binary Search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;
        
        while (low <= high) {
            // แบ่งสมาชิกให้ได้ median พอดีจำนวน (x+y+1)/2 ตัว
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            // ฝั่งซ้าย: รวมสมาชิกจาก nums1 (จำนวน partitionX ตัว) และจาก nums2 (จำนวน partitionY ตัว)
            // ฝั่งขวา: สมาชิกที่เหลือของทั้งสองอาเรย์
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            // เราต้องการให้สมาชิกทุกตัวในฝั่งซ้ายทั้งหมด ต้องมีค่าน้อยกว่าหรือเท่ากับสมาชิกทุกตัวในฝั่งขวา เพื่อให้เวลานำมารวมกันแล้วเรียงลำดับจะได้ค่าที่ถูกต้อง
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // แบ่งถูกต้องแล้ว คำนวณค่ามัธยฐาน
                if ((x + y) % 2 == 0) {
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } 
            // ตัวเลขที่อยู่ฝั่งซ้ายของ nums1 (maxLeftX) ดันมีค่า มากกว่า 
            // ตัวเลขที่อยู่ฝั่งขวาของ nums2 (minRightY) แปลว่า
            //เราเผลอหยิบตัวเลขจาก nums1 มาไว้ฝั่งซ้าย "มากเกินไป" ทำให้ตัวเลขที่ควรจะไปอยู่ฝั่งขวา (เพราะมันมีค่าเยอะ) ถูกลากมาอยู่ฝั่งซ้ายผิดที่
            else if (maxLeftX > minRightY) {
                // ขยับพาร์ทิชันใน nums1 ไปทางซ้าย
                high = partitionX - 1;
            } else {
                // ขยับพาร์ทิชันใน nums1 ไปทางขวา
                low = partitionX + 1;
            }
        }
        
        return 0.0;
    }
};