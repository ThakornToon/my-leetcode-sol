class Solution {
private:
    int mergeAndCount(vector<long long>& sum, int left, int mid, int right, int lower, int upper) {
        int count = 0;
        int j = mid + 1, k = mid + 1;
        
        for (int i = left; i <= mid; i++) { // เช็คค่าโดยดูสมาชิกอาเรย์ทางซ้าย ไล่หาในอาเรย์ทางขวาเพื่อหาตำแหน่งที่อยู้ในขอบเขต(แต่ละอาเรย์เรียงมาแล้ว)
        //  เราต้องการหาคู่ (i,j) ที่ lower ≤ sum[j] - sum[i] ≤ upper คือ lower ≤ nums[i] + nums[i+1] + ... + nums[j-1] ≤ upper
            while (j <= right && sum[j] - sum[i] < lower) j++;
            while (k <= right && sum[k] - sum[i] <= upper) k++;
            count += k - j; // จำนวนระหว่างสมาชิกสองอาเรย์ที่วนจับได้
        }
        
        // Merge
        vector<long long> temp; // จะเรียงสองอาเรย์ที่เอามรวม น้อยไปมาก
        int p = left, q = mid + 1;
        while (p <= mid && q <= right) { // เรียงใส่ temp
            if (sum[p] <= sum[q]) {
                temp.push_back(sum[p++]);
            } else {
                temp.push_back(sum[q++]);
            }
        }
        while (p <= mid) temp.push_back(sum[p++]);
        while (q <= right) temp.push_back(sum[q++]);
        for (int i = 0; i < temp.size(); i++) sum[left + i] = temp[i]; // ก๊อป temp ใส่ใน sum
        
        return count;
    }

    int mergeSort(vector<long long>& sum, int left, int right, int lower, int upper) { //แบ่งคิดอาเรย์ย่อยก่อนแล้วนำมารวม
        if (left >= right) {
            return 0;
        } 
        int mid = left + (right - left) / 2;
        return mergeSort(sum, left, mid, lower, upper) +
            mergeSort(sum, mid + 1, right, lower, upper) +
            mergeAndCount(sum, left, mid, right, lower, upper);
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum;
        int numsSize = nums.size();
        sum.push_back(0);
        for (int i = 0; i < numsSize; i++) {
            sum.push_back(sum[i] + nums[i]);
        }
        return mergeSort(sum, 0, numsSize, lower, upper);
    }
};