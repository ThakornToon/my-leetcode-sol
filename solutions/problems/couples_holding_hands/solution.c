int minSwapsCouples(int* row, int rowSize) {
    
    int n = rowSize;
    int* position = (int*)malloc(n * sizeof(int));
    
    // สร้าง mapping position[person] = index
    for (int i = 0; i < n; i++) {
        position[row[i]] = i;
    }
    
    int swaps = 0;
    for (int i = 0; i < n; i += 2) {
        int person = row[i];
        int partner = person ^ 1;  // คู่ของ person
        
        // ถ้าคนข้างๆ ไม่ใช่คู่ที่ถูกต้อง
        if (row[i + 1] != partner) {
            // หาตำแหน่งของ partner
            int partner_idx = position[partner];
            
            // สลับคนที่ i+1 กับ partner
            int temp = row[i + 1];
            row[i + 1] = row[partner_idx];
            row[partner_idx] = temp;
            
            // อัปเดต position
            position[row[partner_idx]] = partner_idx;
            position[row[i + 1]] = i + 1;
            
            swaps++;
        }
    }
    
    free(position);
    return swaps;
}