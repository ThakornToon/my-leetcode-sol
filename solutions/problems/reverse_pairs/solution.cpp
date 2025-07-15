class Solution {
private:
    int mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) return 0;  // เงื่อนไขฐาน
        
        int mid = start + (end - start) / 2;
        int count = 0;
        int j = mid + 1;
        count += mergeSort(nums, start, mid);
        count += mergeSort(nums, mid + 1, end);

        for (int i = start; i <= mid; i++) {
            while (j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp(end - start + 1);
        int i = start, k = 0;
        j = mid + 1;
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        // เก็บค่าที่เหลือจากส่วนซ้าย (ถ้ามี)
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        // เก็บค่าที่เหลือจากส่วนขวา (ถ้ามี)
        while (j <= end) {
            temp[k++] = nums[j++];
        }
        
        // คัดลอกค่าจาก temp กลับไปยัง nums
        for (int p = 0; p < k; p++) {
            nums[start + p] = temp[p];
        }
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};