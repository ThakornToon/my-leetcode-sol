class Solution {
public:
    double angleClock(int hour, int minutes) {
        // คำนวณมุมของเข็มนาที
        double minuteAngle = minutes * 6.0;
        
        // คำนวณมุมของเข็มชั่วโมง
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        // หาความแตกต่าง
        double diff = abs(hourAngle - minuteAngle);
        
        // เลือกมุมที่เล็กกว่า
        return min(diff, 360.0 - diff);
    }
};