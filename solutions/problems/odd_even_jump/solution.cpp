class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_higher(n, -1), next_lower(n, -1);
        
        // สร้าง monotonic stack
        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        
        // เรียงตามค่า จากน้อยไปมาก
        sort(indices.begin(), indices.end(), 
             [&](int i, int j) { 
                 return arr[i] == arr[j] ? i < j : arr[i] < arr[j]; 
             });
        
        // หา next higher
        vector<int> stack;
        for (int i : indices) {
            while (!stack.empty() && stack.back() < i) {
                next_higher[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        // เรียงตามค่า จากมากไปน้อย
        sort(indices.begin(), indices.end(), 
             [&](int i, int j) { 
                 return arr[i] == arr[j] ? i < j : arr[i] > arr[j]; 
             });
        
        // หา next lower
        stack.clear();
        for (int i : indices) {
            while (!stack.empty() && stack.back() < i) {
                next_lower[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        // DP
        vector<int> odd(n, 0), even(n, 0);
        odd[n-1] = even[n-1] = 1;
        
        int result = 1;
        for (int i = n-2; i >= 0; i--) {
            if (next_higher[i] != -1) {
                odd[i] = even[next_higher[i]];
            }
            if (next_lower[i] != -1) {
                even[i] = odd[next_lower[i]];
            }
            if (odd[i]) result++;
        }
        
        return result;
    }
};