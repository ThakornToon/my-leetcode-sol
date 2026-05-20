int binarySearch(int* res, int size, int target) {
    int l = 0, r = size - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (res[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

void computeLIS(int* nums, int n, int* lis) {
    int* tails = (int*)malloc(n * sizeof(int));
    int len = 0;
    
    for (int i = 0; i < n; i++) {
        if (len == 0 || tails[len - 1] < nums[i]) {
            tails[len++] = nums[i];
            lis[i] = len;
        } else {
            int pos = binarySearch(tails, len, nums[i]);
            tails[pos] = nums[i];
            lis[i] = pos + 1; // length of LIS ending at i
        }
    }
    
    free(tails);
}

void computeLDS(int* nums, int n, int* lds) {
    int* tails = (int*)malloc(n * sizeof(int));
    int len = 0;
    
    // คำนวณ LDS = LIS ของ array ที่กลับด้านแล้วสลับเครื่องหมาย
    for (int i = n - 1; i >= 0; i--) {
        if (len == 0 || tails[len - 1] < nums[i]) {
            tails[len++] = nums[i];
            lds[i] = len;
        } else {
            int pos = binarySearch(tails, len, nums[i]);
            tails[pos] = nums[i];
            lds[i] = pos + 1;
        }
    }
    
    free(tails);
}

int minimumMountainRemovals(int* nums, int numsSize) {
    int* lis = (int*)malloc(numsSize * sizeof(int));
    int* lds = (int*)malloc(numsSize * sizeof(int));
    
    computeLIS(nums, numsSize, lis);
    computeLDS(nums, numsSize, lds);
    
    int maxMountainLen = 0;

    // เมื่อ i เป็น mountain ขวาเพิ่ม ซ้ายลด
    for (int i = 1; i < numsSize - 1; i++) {
        if (lis[i] > 1 && lds[i] > 1) {
            int len = lis[i] + lds[i] - 1;
            if (len > maxMountainLen) {
                maxMountainLen = len;
            }
        }
    }
    
    free(lis);
    free(lds);
    
    return numsSize - maxMountainLen;
}