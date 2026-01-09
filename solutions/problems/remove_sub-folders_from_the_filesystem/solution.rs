impl Solution {
    pub fn remove_subfolders(folder: Vec<String>) -> Vec<String> {
        // เรียงโฟลเดอร์ตามพาธ
        let mut sorted_folders = folder.clone();
        sorted_folders.sort();
        
        let mut result: Vec<String> = Vec::new();
        result.push(sorted_folders[0].clone());
        
        for i in 1..sorted_folders.len() {
            let current = &sorted_folders[i];
            let last = result.last().unwrap();
            
            // ตรวจสอบว่า current เป็น sub-folder ของ last หรือไม่
            // ต้องเพิ่ม "/" ต่อท้ายเพื่อป้องกันกรณีเช่น "/a" และ "/ab"
            if !current.starts_with(&format!("{}/", last)) {
                result.push(current.clone());
            }
        }
        
        result
    }
}