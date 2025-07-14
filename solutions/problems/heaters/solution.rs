impl Solution {
    pub fn find_radius(houses: Vec<i32>, heaters: Vec<i32>) -> i32 {
        let mut houses = houses;
        let mut heaters = heaters;
        houses.sort();
        heaters.sort();
        
        let mut radius = 0;
        let mut i = 0;
        
        for &house in &houses {
            while i < heaters.len() - 1 && (heaters[i+1] - house).abs() <= (heaters[i] - house).abs() { // หาเครื่องทำน้ำร้อนที่ใกล้ที่สุดสำหรับแต่ละบ้าน
                i += 1;
            }
            radius = radius.max((heaters[i] - house).abs()); // หารัศมีจากเครื่องทำน้ำร้อนไปยังบ้านที่ไกลที่สุดที่มีระยะห่างใกล้กว่าเครื่องทำน้ำร้อนอื่น
        }
        
        radius
    }
}