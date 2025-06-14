int mergeAndCount(long long* sum, int left, int mid, int right, int lower, int upper) {
    int count = 0;
    int j = mid + 1, k = mid + 1;
    
    for (int i = left; i <= mid; i++) { // เช็คค่าโดยดูสมาชิกอาเรย์ทางซ้าย ไล่หาในอาเรย์ทางขวาเพื่อหาตำแหน่งที่อยู้ในขอบเขต(แต่ละอาเรย์เรียงมาแล้ว)
    //  เราต้องการหาคู่ (i,j) ที่ lower ≤ sum[j] - sum[i] ≤ upper คือ lower ≤ nums[i] + nums[i+1] + ... + nums[j-1] ≤ upper
        while (j <= right && sum[j] - sum[i] < lower) j++;
        while (k <= right && sum[k] - sum[i] <= upper) k++;
        count += k - j; // จำนวนระหว่างสมาชิกสองอาเรย์ที่วนจับได้
    }
    
    // Merge
    long long* temp = malloc((right - left + 1) * sizeof(long long)); // จะเรียงสองอาเรย์ที่เอามรวม น้อยไปมาก
    int p = left, q = mid + 1, idx = 0;
    while (p <= mid && q <= right) { // เรียงใส่ temp
        temp[idx++] = (sum[p] <= sum[q]) ? sum[p++] : sum[q++];
    }
    while (p <= mid) temp[idx++] = sum[p++];
    while (q <= right) temp[idx++] = sum[q++];
    for (int i = 0; i < idx; i++) sum[left + i] = temp[i]; // ก๊อปใส่ temp ใน sum
    
    free(temp);
    return count;
}

int mergeSort(long long* sum, int left, int right, int lower, int upper) { //แบ่งคิดอาเรย์ย่อยก่อนแล้วนำมารวม
    if (left >= right) {
        return 0;
    } 
    int mid = left + (right - left) / 2;
    return mergeSort(sum, left, mid, lower, upper) +
           mergeSort(sum, mid + 1, right, lower, upper) +
           mergeAndCount(sum, left, mid, right, lower, upper);
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long long* sum = (long long*)malloc((numsSize + 1) * sizeof(long long));
    sum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sum[i + 1] = sum[i] + nums[i]; // sum[i + 1] จะเก็บค่าสมาชิกใน nums ตั้งแต่ index 0 ถึง i
    }
    int count = mergeSort(sum, 0, numsSize, lower, upper);
    free(sum);
    return count;
}

/*
int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        long long curr_sum = 0;
        for (int j = i; j < numsSize; j++) {
            curr_sum += nums[j];
            if (curr_sum >= lower && curr_sum <= upper) {
                count++;
            }
        }
    }
    return count;
}
*/