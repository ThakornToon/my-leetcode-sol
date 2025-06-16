class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {        
        set<long long> window; // จะมีการเรียงข้อมูลเอง
        
        for (int i = 0; i < nums.size(); ++i) {
            // ลบข้อมูลที่อยู่นอกหน้าต่าง
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }
            
            long long num = nums[i];
            // หาค่าที่ >= num - valueDiff
            auto it = window.lower_bound(num - valueDiff); // iterator ของ set
            
            // ตรวจสอบว่าค่าที่พบ <= num + valueDiff
            if (it != window.end() && *it <= num + valueDiff) {
                return true;
            }
            
            // เพิ่มค่าปัจจุบันเข้าไปในหน้าต่าง
            window.insert(num);
        }
        
        return false;
    }
};



/*
class Solution {
public:
    int lower_bound(const vector<long long>& nums, long long target) {
        int left = 0;
        int right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<long long> window_values; // เก็บเฉพาะค่า เราจะเรียงตามค่าของข้อมูล
        vector<int> window_indices; // เก็บดัชนี จะเก็บในตำแหน่งเดียวกับข้อมูลทำให้ดัชนีจะไม่เรียงและอาจมีข้อมูลเก่าอยู่
        for (int i = 0; i < nums.size(); ++i) {
            // ลบข้อมูลที่อยู่นอก window (i - index > k) 
            while (!window_indices.empty() && i - window_indices[0] > indexDiff) {
                window_values.erase(window_values.begin());
                window_indices.erase(window_indices.begin());
            }

            long long num = nums[i];
            long long lower = num - valueDiff;
            long long upper = num + valueDiff;

            // Binary search หาค่าที่ >= lower
            int pos = lower_bound(window_values, lower);

            // ตรวจสอบว่าค่าที่พบอยู่ในช่วง [lower, upper] หรือไม่
            while (pos < window_values.size()) {
                if (i - window_indices[pos] <= indexDiff && window_values[pos] <= upper) {
                    return true;
                }
                pos++;
            }

            // หาตำแหน่งที่จะแทรกเพื่อรักษาการเรียงลำดับ
            int insert_pos = lower_bound(window_values, num);

            // แทรกค่าและดัชนีในตำแหน่งที่เหมาะสม
            window_values.insert(window_values.begin() + insert_pos, num);
            window_indices.insert(window_indices.begin() + insert_pos, i);
        }

        return false;
    }
};
*/