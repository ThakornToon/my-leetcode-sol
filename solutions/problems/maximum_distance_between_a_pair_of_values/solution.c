int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int maxDist = 0;
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            maxDist = (j - i > maxDist) ? j - i : maxDist;
            j++;  // ลองขยาย j ไปเรื่อยๆ
        } else {
            i++;  // nums1[i] มากเกินไป ต้องเพิ่ม i
        }
    }
    
    return maxDist;
}