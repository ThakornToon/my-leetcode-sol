#include <float.h>

typedef struct {
    double x, y;
} Point;

// ฟังก์ชันคำนวณระยะทาง^2
double dist_sq(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// ฟังก์ชันตรวจสอบว่า 4 จุดเป็นสี่เหลี่ยม
int isRectangle(Point p1, Point p2, Point p3, Point p4) {
    // จุดกึ่งกลางของเส้นทแยงมุมทั้งสองควรตรงกัน
    double mid1_x = (p1.x + p3.x) / 2.0;
    double mid1_y = (p1.y + p3.y) / 2.0;
    double mid2_x = (p2.x + p4.x) / 2.0;
    double mid2_y = (p2.y + p4.y) / 2.0;
    
    if (fabs(mid1_x - mid2_x) > 1e-9 || fabs(mid1_y - mid2_y) > 1e-9) {
        return 0;
    }
    
    // ความยาวของเส้นทแยงมุมทั้งสองควรเท่ากัน
    double diag1 = dist_sq(p1, p3);
    double diag2 = dist_sq(p2, p4);
    
    if (fabs(diag1 - diag2) > 1e-9) {
        return 0;
    }
    
    return 1;
}

// คำนวณพื้นที่สี่เหลี่ยมจากจุด 4 จุด
double area(Point p1, Point p2, Point p3, Point p4) {
    // จุดต้องเรียงตามลำดับต่อเนื่อง (p1→p2→p3→p4→p1)
    double sum1 = p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p1.y;
    double sum2 = p1.y * p2.x + p2.y * p3.x + p3.y * p4.x + p4.y * p1.x;
    return fabs(sum1 - sum2) / 2.0;
}

double minAreaFreeRect(int** points, int pointsSize, int* pointsColSize) {
    double min_area = DBL_MAX;
    
    // ลองทุกชุดจุด 4 จุด
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                for (int l = k + 1; l < pointsSize; l++) {
                    Point p1 = {points[i][0], points[i][1]};
                    Point p2 = {points[j][0], points[j][1]};
                    Point p3 = {points[k][0], points[k][1]};
                    Point p4 = {points[l][0], points[l][1]};
                    
                    // ตรวจสอบทุกการเรียงสับเปลี่ยนของจุด 4 จุด
                    // สำหรับสี่เหลี่ยม เส้นทแยงมุมคือ (p1,p3) และ (p2,p4)
                    if (isRectangle(p1, p2, p3, p4)) {
                        double a = area(p1, p2, p3, p4);
                        if (a < min_area && a > 1e-9) {
                            min_area = a;
                        }
                    }
                    
                    if (isRectangle(p1, p2, p4, p3)) {
                        double a = area(p1, p2, p4, p3);
                        if (a < min_area && a > 1e-9) {
                            min_area = a;
                        }
                    }
                    
                    if (isRectangle(p1, p3, p2, p4)) {
                        double a = area(p1, p3, p2, p4);
                        if (a < min_area && a > 1e-9) {
                            min_area = a;
                        }
                    }
                }
            }
        }
    }
    
    return (min_area == DBL_MAX) ? 0 : min_area;
}