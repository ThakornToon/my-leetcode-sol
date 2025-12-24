/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

int findInMountainArray(int target, MountainArray* mountainArr) {
	int n = length(mountainArr);
    
    // 1. หา peak
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) { // ลาดขึ้น
            left = mid + 1;
        } else { // ลาดลง
            right = mid;
        }
    }
    int peak = left;
    
    // 2. Binary search ซ้าย (เพิ่มขึ้น)
    left = 0;
    right = peak;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int val = get(mountainArr, mid);
        
        if (val == target) {
            return mid;
        } else if (val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // 3. Binary search ขวา (ลดลง)
    left = peak;
    right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int val = get(mountainArr, mid);
        
        if (val == target) {
            return mid;
        } else if (val > target) {
            // ลดลง: ถ้าปัจจุบัน > target ต้องไปขวา
            left = mid + 1;
        } else {
            // ลดลง: ถ้าปัจจุบัน < target ต้องไปซ้าย
            right = mid - 1;
        }
    }
    
    return -1;
}