class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int INF = 2e7;  // ค่าสูงสุดแทนอนันต์ (ใหญ่กว่า x ที่เป็นไปได้)
        
        // รวบรวมสิ่งกีดขวางทั้งหมด (type 1 queries)
        // เพิ่มขอบเขตเริ่มต้น: 0 และ INF (ขอบเขตจำลอง)
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(INF);
        
        // เก็บสิ่งกีดขวางจากทุก type 1 query
        for (auto& query : queries) {
            if (query[0] == 1) {
                obstacles.insert(query[1]);
            }
        }
        
        // สร้าง "Holes" ที่มีความสำคัญ
        // เก็บเฉพาะ holes ที่่มีความสำคัญ
        // hole ที่มีขนาดใหญ่พอ และ start น้อยที่สุด
        
        map<int, int> minStartForSize;  // {ขนาดของ hole, ตำแหน่งเริ่มต้นที่น้อยที่สุด}
        set<int> dominantSizes;  // ชุดของขนาดที่่มีความสำคัญ (เรียงจากน้อยไปมาก)
        
        // เริ่มต้นด้วย hole ที่ใหญ่ที่สุด (จาก 0 ถึง INF)
        int lastObstacle = *prev(obstacles.end(), 2);  // ตำแหน่งก่อน INF
        minStartForSize[INF] = lastObstacle;
        dominantSizes.insert(INF);
        
        // สร้าง holes จากสิ่งกีดขวางทั้งหมด
        auto it = obstacles.begin();
        int leftBarrier = *it;  // 0
        ++it;
        
        while (it != obstacles.end()) {
            int rightBarrier = *it;
            int gapSize = rightBarrier - leftBarrier;
            
            // หา hole แรกที่มีขนาด >= gapSize นี้
            auto pos = dominantSizes.lower_bound(gapSize);
            int existingSize = *pos;
            
            // ถ้า start ของ gap นี้ น้อยกว่า start ของ hole ที่มีอยู่
            // แสดงว่า gap นี้ดีกว่า (เริ่มต้นซ้ายกว่า)
            if (minStartForSize[existingSize] > leftBarrier) {
                // ถ้าขนาดที่พบใหญ่กว่า gap ปัจจุบัน ให้เพิ่ม gap ปัจจุบันเข้าไป
                dominantSizes.insert(gapSize);
                
                minStartForSize[gapSize] = leftBarrier;
            }
            
            
            leftBarrier = rightBarrier;
            ++it;
        }
        
        // ประมวลผล queries แบบย้อนกลับ
        // เหตุผลที่ทำย้อนกลับ: การลบสิ่งกีดขวาง (type 1) กลายเป็นการเพิ่ม
        // ซึ่งง่ายกว่าการลบในโครงสร้างข้อมูล
        
        vector<bool> results;
        
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto& query = queries[i];
            
            // type 1 (ในมุมมองย้อนกลับ = ลบสิ่งกีดขวาง)
            if (query[0] == 1) {
                int x = query[1];  // ตำแหน่งที่จะลบสิ่งกีดขวาง
                
                // หาสิ่งกีดขวางทางซ้ายและขวา
                auto it = obstacles.find(x);
                int leftObstacle = *prev(it);
                int rightObstacle = *next(it);
                int newGapSize = rightObstacle - leftObstacle;
                
                // หา dominant hole ที่มีขนาด >= newGapSize
                auto pos = dominantSizes.lower_bound(newGapSize);
                int existingSize = *pos;
                
                // ถ้า start ของ gap ใหม่ น้อยกว่า start เดิม → ดีกว่า
                if (minStartForSize[existingSize] > leftObstacle) {
                    // ลบ holes ที่ถูก dominate
                    // เงื่อนไข: ขนาดเล็กกว่า แต่ start มากกว่า
                    while (pos != dominantSizes.begin()) {
                        auto prevPos = prev(pos);
                        int prevSize = *prevPos;
                        
                        if (minStartForSize[prevSize] > leftObstacle) {
                            // hole นี้ถูก dominate → ลบออก
                            minStartForSize.erase(prevSize);
                            dominantSizes.erase(prevPos);
                        } else {
                            break;
                        }
                    }
                    
                    // เพิ่ม hole ใหม่
                    minStartForSize[newGapSize] = leftObstacle;
                    if (*pos != newGapSize) {
                        dominantSizes.insert(newGapSize);
                    }
                }
                
                // ลบสิ่งกีดขวางออกจาก set
                obstacles.erase(x);
            } else {  // type 2 (ตรวจสอบว่าสามารถวางบล็อกได้หรือไม่)
                int x = query[1];   // ขอบเขตด้านขวา
                int sz = query[2];  // ขนาดบล็อกที่ต้องการวาง
                
                // หา dominant hole ที่มีขนาด >= sz
                auto pos = dominantSizes.lower_bound(sz);
                int holeSize = *pos;
                int holeStart = minStartForSize[holeSize];
                
                // ตรวจสอบ: วางบล็อกได้หรือไม่?
                // เงื่อนไข: start ของ hole อยู่ทางซ้ายของ x-sz (บล็อกจะไม่เกินขอบเขต x)
                bool canPlace = (holeStart <= x - sz);
                results.push_back(canPlace);
            }
        }
        
        // กลับลำดับผลลัพธ์ (เราประมวลผลย้อนกลับ)
        reverse(results.begin(), results.end());
        return results;
    }
};