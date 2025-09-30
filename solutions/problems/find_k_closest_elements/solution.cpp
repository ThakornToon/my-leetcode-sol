class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        
        while (left < right) {
            // ตำแหน่งเริ่มต้น
            int mid = left + (right - left) / 2;
            // เปรียบเทียบ สองช่วงที่อาจเป็นคำตอบ:
        //  ช่วง A: เริ่มที่ mid → arr[mid] ถึง arr[mid + k - 1]
        //ช่วง B: เริ่มที่ mid + 1 → arr[mid + 1] ถึง arr[mid + k]
        //ทั้งสองช่วงมี k-1 ตัวที่ซ้อนกัน ต่างกันแค่ตัวแรกและตัวสุดท้าย
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};