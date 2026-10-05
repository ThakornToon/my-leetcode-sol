use std::cell::RefCell;

struct MyCalendar {
    bookings: RefCell<Vec<(i32, i32)>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendar {

    fn new() -> Self {
        MyCalendar {
            bookings: RefCell::new(Vec::new()),
        }
    }
    
    fn book(&self, start_time: i32, end_time: i32) -> bool {
        // ยืมข้อมูลมาแบบเปลี่ยนแปลงค่าได้ (Mutable borrow) ผ่าน RefCell
        let mut bookings = self.bookings.borrow_mut();
        
        for &(s, e) in bookings.iter() {
            if std::cmp::max(start_time, s) < std::cmp::min(end_time, e) {
                return false; // มีการทับซ้อน
            }
        }
        
        bookings.push((start_time, end_time));
        true
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * let obj = MyCalendar::new();
 * let ret_1: bool = obj.book(startTime, endTime);
 */