/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *res=(int*)malloc(sizeof(int)*2);
    res[0] = -1;
    res[1] = -1;
    *returnSize = 2;
    if(numsSize==0) {
        return res;
    }
    int start=0, end=numsSize-1, mid;
    while(start<=end){ //binary search
        mid=start-(start-end)/2;
        if(nums[mid]==target){
            break;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(nums[mid]!=target){
        return res;
    }
    int old_mid=mid, old_end=end;
    end=mid;
    while(start<=end){ //หาขอบล่าง
        mid=start-(start-end)/2;
        if(nums[start]==target){
            res[0]=start;
            break;
        }
        else if(nums[mid]==target){
            end=mid;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
    }
    end=old_end; start=mid;
    while(start<=end){ //หาขอบบน
        mid=start-(start-end)/2;
        if(nums[end]==target){
            res[1]=end;
            break;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]==target){
            res[1]=mid;
            start=mid+1;
        }
    }

    return res;
}