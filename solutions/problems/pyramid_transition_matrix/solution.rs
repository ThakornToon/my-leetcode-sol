use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn pyramid_transition(bottom: String, allowed: Vec<String>) -> bool {
        // สร้าง HashMap สำหรับเก็บกฎการเปลี่ยน
        // key: คู่ตัวอักษร (เช่น "AB"), value: ลิสต์ตัวอักษรที่วางบนได้ (เช่น ['C', 'D'])
        let mut transitions: HashMap<String, Vec<char>> = HashMap::new();
        
        // สร้าง HashSet สำหรับเก็บแถวที่สร้างไม่ได้ (Memoization)
        let mut failed_rows: HashSet<String> = HashSet::new();
        
        // เติมข้อมูลกฎการเปลี่ยนจาก allowed
        for rule in allowed {
            let key = rule[0..2].to_string();          // ตัวซ้าย+ขวา เช่น "AB"
            let value = rule.chars().nth(2).unwrap();  // ตัวบน เช่น 'C'
            transitions.entry(key).or_insert(Vec::new()).push(value);
        }
        
        // ฟังก์ชันสำหรับสร้างแถวถัดไปทีละตำแหน่ง
        fn row_backtrack(
            base: &str,            // แถวปัจจุบัน
            i: usize,              // ตำแหน่งปัจจุบันในแถว
            next: &mut String,     // แถวถัดไปที่กำลังสร้าง
            transitions: &HashMap<String, Vec<char>>,
            failed_rows: &mut HashSet<String>,
        ) -> bool {
            // ฐาน: สร้างแถวถัดไปเสร็จแล้ว (ได้ความยาว base.len()-1)
            if i == base.len() - 1 {
                return level_backtrack(next, transitions, failed_rows);
            }
            
            // ดึงคู่ตัวอักษรจากตำแหน่ง i ถึง i+1
            let key = &base[i..i + 2];
            
            // ถ้ามีกฎสำหรับคู่นี้
            if let Some(possible_tops) = transitions.get(key) {
                // ลองทุกตัวอักษรที่สามารถวางบนคู่นี้ได้
                for &top_char in possible_tops {
                    next.push(top_char);  // ลองใส่ตัวอักษร
                    
                    // สร้างตำแหน่งต่อไปในแถว
                    if row_backtrack(base, i + 1, next, transitions, failed_rows) {
                        return true;  // สำเร็จ → หยุดทันที
                    }
                    
                    next.pop();  // Backtrack: ลบตัวอักษรออก
                }
            }
            
            false  // ทุกทางเลือกลองแล้วไม่ได้ผล
        }
        
        // ฟังก์ชันหลักสำหรับตรวจสอบแต่ละระดับของพีระมิด
        fn level_backtrack(
            base: &str,            // แถวปัจจุบัน
            transitions: &HashMap<String, Vec<char>>,
            failed_rows: &mut HashSet<String>,
        ) -> bool {
            // ฐาน: ถึงยอดพีระมิดแล้ว (เหลือตัวเดียว)
            if base.len() == 1 {
                return true;
            }
            
            // Memoization: ถ้ารู้แล้วว่าแถวนี้สร้างไม่ได้ → return false ทันที
            if failed_rows.contains(base) {
                return false;
            }
            
            // สร้างแถวถัดไปทั้งหมดที่เป็นไปได้
            let mut next_row = String::new();
            let success = row_backtrack(base, 0, &mut next_row, transitions, failed_rows);
            
            // Memoization: ถ้าสร้างไม่ได้เลย → เก็บไว้ใน failed_rows
            if !success {
                failed_rows.insert(base.to_string());
            }
            
            success
        }
        
        // เริ่มการสร้างพีระมิดจากแถวล่างสุด
        level_backtrack(&bottom, &transitions, &mut failed_rows)
    }
}