/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // 1. หา peak index
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peak = left;
        
        // 2. Binary search ในส่วนซ้าย (เพิ่มขึ้น)
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            
            if (val == target) {
                return mid;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 3. Binary search ในส่วนขวา (ลดลง)
        left = peak;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            
            if (val == target) {
                return mid;
            } else if (val > target) {
                left = mid + 1; // ลดลง ดังนั้นถ้า val > target ต้องไปขวา
            } else {
                right = mid - 1; // ลดลง ดังนั้นถ้า val < target ต้องไปซ้าย
            }
        }
        
        return -1; // ไม่พบ
    }
};