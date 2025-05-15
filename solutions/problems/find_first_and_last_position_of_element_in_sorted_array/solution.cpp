class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid;
        int f=-1, l=-1;
        if(nums.size()==0) return {-1, -1};
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
            return {-1,-1};
        }
        int old_mid=mid, old_end=end;
        end=mid;
        while(start<=end){ //หาขอบล่าง
            mid=start-(start-end)/2;
            if(nums[start]==target){
                f=start;
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
                l=end;
                break;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]==target){
                l=mid;
                start=mid+1;
            }
        }

        return {f, l};
    }
};