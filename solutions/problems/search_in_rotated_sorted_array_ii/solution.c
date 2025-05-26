bool search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
        
    while (left <= right) {
        int mid = (left + right) / 2;
            
        if (nums[mid] == target) {
            return true;
        }
            
        if (nums[mid] == nums[left]) { //ถ้าเท่ากันเราจะไม่สามารถระบุได้ว่าฝั่งซ้ายหรือขวาที่เรียงลำดับกันเลยต้องเลื่อน(เสมือนตัดตัวซ้ำ) 11101 10111 / 123(1)111 111(1)123 111(1)231 311(1)112
            left++;
            continue;
        }
            
        if (nums[left] <= nums[mid]) {  //ซ้ายเรียงไหม
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        } 
        else { //ขวาเรียง
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
    }
    return false;
}