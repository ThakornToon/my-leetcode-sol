/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// โครงสร้างสำหรับเก็บร้านอาหาร
typedef struct {
    int id;
    int rating;
    int veganFriendly;
    int price;
    int distance;
} Restaurant;

// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int compare(const void* a, const void* b) {
    Restaurant* r1 = (Restaurant*)a;
    Restaurant* r2 = (Restaurant*)b;
    
    // เรียงตาม rating จากมากไปน้อย
    if (r1->rating != r2->rating) {
        return r2->rating - r1->rating;
    }
    // ถ้า rating เท่ากัน เรียงตาม id จากมากไปน้อย
    return r2->id - r1->id;
}

int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize) {
    // สร้าง array สำหรับร้านที่ผ่านการกรอง
    Restaurant* filtered = (Restaurant*)malloc(restaurantsSize * sizeof(Restaurant));
    int count = 0;
    
    for (int i = 0; i < restaurantsSize; i++) {
        int id = restaurants[i][0];
        int rating = restaurants[i][1];
        int vf = restaurants[i][2];
        int price = restaurants[i][3];
        int distance = restaurants[i][4];
        
        // ตรวจสอบเงื่อนไข
        if (veganFriendly == 1 && vf == 0) {
            continue;  // ต้องการ vegan-friendly แต่ร้านนี้ไม่ใช่
        }
        if (price > maxPrice) {
            continue;
        }
        if (distance > maxDistance) {
            continue;
        }
        
        // ผ่านเงื่อนไข
        filtered[count].id = id;
        filtered[count].rating = rating;
        filtered[count].veganFriendly = vf;
        filtered[count].price = price;
        filtered[count].distance = distance;
        count++;
    }
    
    // เรียงลำดับ
    qsort(filtered, count, sizeof(Restaurant), compare);
    
    // สร้างผลลัพธ์
    int* result = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        result[i] = filtered[i].id;
    }
    
    *returnSize = count;
    free(filtered);
    
    return result;
}