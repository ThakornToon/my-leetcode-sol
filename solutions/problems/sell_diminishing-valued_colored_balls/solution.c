#define MOD 1000000007

long long sumRange(long long x, long long y) {
    return (x + y) * (x - y + 1) / 2;
}

// นับจำนวนลูกบอลที่มีค่า >= target
long long countBalls(int* inventory, int size, int target) {
    long long count = 0;
    for (int i = 0; i < size; i++) {
        if (inventory[i] >= target) {
            count += inventory[i] - target + 1;
        }
    }
    return count;
}

// คำนวณมูลค่ารวมของลูกบอลที่มีค่า >= target
long long sumBalls(int* inventory, int size, int target) {
    long long total = 0;
    for (int i = 0; i < size; i++) {
        if (inventory[i] >= target) {
            total += sumRange(inventory[i], target);
        }
    }
    return total;
}

int maxProfit(int* inventory, int inventorySize, int orders) {
    // หาค่าสูงสุด
    int maxVal = 0;
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i] > maxVal) maxVal = inventory[i];
    }
    
    int left = 0, right = maxVal;
    
    // Binary Search หา threshold
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (countBalls(inventory, inventorySize, mid) >= orders) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    int threshold = left;
    
    // คำนวณมูลค่าจากลูกบอลที่มีค่า > threshold
    long long profit = sumBalls(inventory, inventorySize, threshold + 1) % MOD;
    long long used = countBalls(inventory, inventorySize, threshold + 1);
    
    // ขายลูกบอลที่มีค่า = threshold บางส่วน (เศษที่เหลือ)
    long long remaining = orders - used;
    profit = (profit + remaining * threshold) % MOD;
    
    return (int)profit;
}