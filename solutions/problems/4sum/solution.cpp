class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size<4){
            return vv;
        }
        
        for (int i=0; i<size-3; i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            if (target / 4 < nums[i]) {
                break;
            }
            for (int j=i+1; j<size-2; j++){
                if (j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int l = j+1;
                int r = size-1;
                while (l<r){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if (sum>INT_MAX){
                        r-=1;
                    }
                    else if (sum<INT_MIN){
                        l+=1;
                    }
                    else{
                        if (sum<target){
                            l+=1;
                        }
                        else if (sum>target){
                            r-=1;
                        }
                        else{
                            vv.push_back({nums[i], nums[j], nums[l], nums[r]});
                            l+=1;
                            while (nums[l]==nums[l-1] && l<r){
                                l+=1;
                            }
                        }
                    }
                }
            }
            
        }
        return vv;
    }
};