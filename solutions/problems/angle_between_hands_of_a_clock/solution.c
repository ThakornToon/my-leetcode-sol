double angleClock(int hour, int minutes) {
    // คำนวณมุมของเข็มนาที (360° / 60 = 6° ต่อนาที)
    double minuteAngle = minutes * 6.0;
    
    // คำนวณมุมของเข็มชั่วโมง
    // 30° ต่อชั่วโมง + 0.5° ต่อนาที
    double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
    
    // หาความแตกต่าง
    double diff = fabs(hourAngle - minuteAngle);
    
    // เลือกมุมที่เล็กกว่า (diff หรือ 360-diff)
    if (diff > 180) {
        diff = 360 - diff;
    }
    
    return diff;
}