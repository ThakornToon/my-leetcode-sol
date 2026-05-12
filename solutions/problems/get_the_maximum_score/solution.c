#define MOD 1000000007
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long result = 0;
    long long sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            sum1 += nums1[i];
            i++;
        } else if (nums1[i] > nums2[j]) {
            sum2 += nums2[j];
            j++;
        } else {
            // เจอค่าที่เท่ากัน
            result += MAX(sum1, sum2) + nums1[i];
            result %= MOD;
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }
    
    // เก็บผลรวมที่เหลือ
    while (i < nums1Size) {
        sum1 += nums1[i];
        i++;
    }
    while (j < nums2Size) {
        sum2 += nums2[j];
        j++;
    }
    
    // เพิ่มผลรวมสุดท้าย
    result += MAX(sum1, sum2);
    result %= MOD;
    
    return (int)result;
}