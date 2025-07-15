/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int* result = (int*)malloc(nums1Size * sizeof(int));
    int* stack = (int*)malloc(nums2Size * sizeof(int));

    int next[10000];
    int top = -1;

    for(int i = 0; i < 10000; i++){
        next[i] = -1;
    }

    for(int i = 0; i < nums2Size; i++){

        while(top >=0 && nums2[i] > stack[top]){
            next[stack[top--]] = nums2[i];
        }

        stack[++top] = nums2[i];
    }


    for(int i = 0; i < nums1Size; i++){
        result[i] = next[nums1[i]];
    }

    *returnSize = nums1Size;
    return result;
}