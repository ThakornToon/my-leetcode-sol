/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* maxSeq(int* nums, int n, int numsSize) {
    int* result = (int*)malloc(n * sizeof(int));
    int idx = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        int max_num = -1;
        int max_pos = -1;

        // หาตัวเลขที่มากที่สุดในส่วนที่เหลือ โดยให้เหลือตัวเลขพอสำหรับเลือกในขั้นตอนต่อไป
        for (int j = start; j <= numsSize - (n - i); j++) {
            if (nums[j] > max_num) {
                max_num = nums[j];
                max_pos = j;
            }
        }

        result[idx++] = max_num;
        start = max_pos + 1;
    }

    return result;
}

bool isGreater(int* n1, int n1Size, int i, int* n2, int n2Size, int j) {
    while (i < n1Size && j < n2Size) {
        if (n1[i] > n2[j]) {
            return true;
        }
        else if (n1[i] < n2[j]) {
            return false;
        }
        i++;
        j++;
    }
    return (n1Size - i) > (n2Size - j);
}

int* merge(int* n1, int n1Size, int* n2, int n2Size) {
    int* merge = (int*)malloc((n1Size + n2Size) * sizeof(int));
    int idx = 0;
    int i = 0, j = 0;
    while (i < n1Size || j < n2Size) {
        if (isGreater(n1, n1Size, i, n2, n2Size, j)) {
            merge[idx++] = n1[i++];
        } else {
            merge[idx++] = n2[j++];
        }
    }
    return merge;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int* ans = (int*)calloc(k, sizeof(int));
    *returnSize = k;
    for (int i = 0; i <= k; i++) {
        if (i > nums1Size || k - i > nums2Size) {
            continue;
        }
        // sub-sequence from n1=i, from n2=k-i
        int* s1 = maxSeq(nums1, i, nums1Size);
        int* s2 = maxSeq(nums2, k - i, nums2Size);

        int* temp = merge(s1, i, s2, k - i);
        
        if (isGreater(temp, k, 0, ans, k, 0)) {
            memcpy(ans, temp, sizeof(int) * k);
        }
        free(s1);
        free(s2);
        free(temp);
    }
    return ans;
}