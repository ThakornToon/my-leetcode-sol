class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);;
        int n = nums.size();
        double avg = sum / n;

        // ตรวจสอบว่าเป็นไปได้ทางคณิตศาสตร์
        // sumA / k = sumB / (n-k) = sum / n
        // เทียบเท่ากับ sumA = k * sum / n
        // k * sum ต้องหารด้วย n ลงตัว
        bool possible = false;
        for (int k = 1; k <= n/2; k++) {
            if (k * sum % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        // set ของค่าที่เป็นไปได้เมื่อเลือก count ตัวในช่วงทางซ้าย
        int leftSize = n / 2;
        vector<unordered_set<int>> leftSums(leftSize + 1);
        leftSums[0].insert(0);
        for (int i = 0; i < leftSize; i++) {
            for (int count = i; count >= 0; count--) { // ดู set ทั้งหมดที่มี
                for (int sum : leftSums[count]) { // วนทีละตัวใน set ก่อนหน้าแล้วเพิ่มตัวที่ i ลงไป
                    leftSums[count + 1].insert(sum + nums[i]);
                }
            }
        }

        // set ของค่าที่เป็นไปได้เมื่อเลือก count ตัวในช่วงทางซ้าย
        int rightSize = n - leftSize;
        vector<unordered_set<int>> rightSums(rightSize + 1);
        rightSums[0].insert(0);
        for (int i = 0; i < rightSize; i++) {
            for (int count = i; count >= 0; count--) { // ดู set ทั้งหมดที่มี
                for (int sum : rightSums[count]) { // วนทีละตัวใน set ก่อนหน้าแล้วเพิ่มตัวที่ i ลงไป
                    rightSums[count + 1].insert(sum + nums[leftSize + i]);
                }
            }
        }

        // ดูทุกความเป็นไปได้เมื่อเลือกมา k ตัว
        for (int k = 1; k <= n/2; k++) {
            if (k * sum % n != 0) continue;
            
            int targetSum = k * sum / n; // sum ที่ต้องการ
            
            // จับคู่ซ้ายกับขวา
            for (int leftK = max(0, k - rightSize); leftK <= min(k, leftSize); leftK++) {
                int rightK = k - leftK;
                
                for (int leftSum : leftSums[leftK]) {
                    int neededRightSum = targetSum - leftSum;
                    
                    // rightK == 0 หมายถึง neededRightSum == 0
                    // และ rightSums[0] มีแค่ {0} อยู่แล้ว
                    if (rightSums[rightK].count(neededRightSum)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};