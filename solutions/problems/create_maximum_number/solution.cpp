class Solution {
private:
    vector<int> maxSeq(vector<int>& nums, int n) {
        vector<int> result;
        int size = nums.size();
        int start = 0;
        
        for (int i = 0; i < n; i++) {
            int max_num = -1;
            int max_pos = -1;
            
            // หาตัวเลขที่มากที่สุดในส่วนที่เหลือ โดยให้เหลือตัวเลขพอสำหรับเลือกในขั้นตอนต่อไป
            for (int j = start; j <= size - (n - i); j++) {
                if (nums[j] > max_num) {
                    max_num = nums[j];
                    max_pos = j;
                }
            }
            
            result.push_back(max_num);
            start = max_pos + 1;
        }
        
        return result;
    }

    bool isGreater(vector<int>& n1, int i, vector<int>& n2, int j) {
        while (i < n1.size() && j < n2.size()) {
            if (n1[i] > n2[j]) {
                return true;
            }
            else if (n1[i] < n2[j]) {
                return false;
            }
            i++;
            j++;
        }
        return (n1.size() - i) > (n2.size() - j);
    }

    vector<int> merge(vector<int> n1, vector<int> n2) {
        vector<int> merge;
        int i = 0, j = 0;
        while (i < n1.size() || j < n2.size()) {
            if (isGreater(n1, i, n2, j)) {
                merge.push_back(n1[i++]);
            } else {
                merge.push_back(n2[j++]);
            }
        }
        return merge;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, -1);
        vector<int> temp;
        for (int i = 0; i <= k; i++) {
            if (i > nums1.size() || k - i > nums2.size()) {
                continue;
            }
            // sub-sequence from n1=i, from n2=k-i
            vector<int> s1 = maxSeq(nums1, i);
            vector<int> s2 = maxSeq(nums2, k - i);

            temp = merge(s1, s2);
            
            if (isGreater(temp, 0, ans, 0)){
                ans = temp;
            }
        }
        return ans;
    }
};