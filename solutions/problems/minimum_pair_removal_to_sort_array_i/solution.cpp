class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        
        // ตรวจสอบว่า non-decreasing อยู่แล้วหรือไม่
        bool isNonDecreasing = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                isNonDecreasing = false;
                break;
            }
        }
        if (isNonDecreasing) return 0;
        
        // Min-heap: store (sum, left_index)
        // เราต้องเก็บ right_value ด้วยเพราะเมื่อรวมแล้วเราต้องรู้ค่าขวาสำหรับการสร้างคู่ใหม่
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        // คำนวณผลรวมเริ่มต้นของทุกคู่
        for (int i = 0; i < n - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            pq.push({sum, i});  // ใช้ i เป็น left_index
        }
        
        int operations = 0;
        
        // Simulation
        while (!pq.empty()) {
            // ดึงคู่ที่มี sum ต่ำสุด (ซ้ายสุดถ้า sum เท่ากัน เพราะ priority_queue sort โดยอัตโนมัติ)
            auto [current_sum, left_idx] = pq.top();
            pq.pop();
            
            // ดำเนินการ merge
            int new_value = current_sum;
            
            // เก็บค่าก่อน merge สำหรับการอัปเดต
            int old_left = nums[left_idx];
            int old_right = nums[left_idx + 1];
            
            // แทนที่คู่ด้วยผลรวม
            nums[left_idx] = new_value;
            nums.erase(nums.begin() + left_idx + 1);
            
            operations++;
            
            // ตรวจสอบว่าเป็น non-decreasing หรือยัง
            bool valid = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    valid = false;
                    break;
                }
            }
            if (valid) break;
            
            // อัปเดต heap: ลบคู่ที่เกี่ยวข้องกับตำแหน่งที่เปลี่ยนไป
            // แต่ละครั้งที่ merge จะส่งผลต่อ 2-3 คู่:
            // 1. คู่ที่ left_idx-1 และ left_idx (ถ้า left_idx > 0)
            // 2. คู่ที่ left_idx และ left_idx+1 (ถ้า left_idx < nums.size()-1)
            
            // วิธีง่ายกว่า: สร้าง heap ใหม่ (ในทางปฏิบัติควรอัปเดตแบบ lazy)
            // แต่เพื่อความง่ายในตัวอย่างนี้ เราจะสร้างใหม่
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> new_pq;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                new_pq.push({sum, i});
            }
            pq = new_pq;
        }
        
        return operations;
    }
};