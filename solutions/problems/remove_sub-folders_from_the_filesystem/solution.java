class Solution {
    public List<String> removeSubfolders(String[] folder) {
        // เรียงโฟลเดอร์ตามพาธ
        Arrays.sort(folder);
        
        List<String> result = new ArrayList<>();
        result.add(folder[0]);
        
        for (int i = 1; i < folder.length; i++) {
            String lastFolder = result.get(result.size() - 1);
            String currentFolder = folder[i];
            
            // ตรวจสอบว่า currentFolder เป็น sub-folder ของ lastFolder หรือไม่
            // ต้องเพิ่ม "/" ต่อท้ายเพื่อป้องกันกรณีเช่น "/a" และ "/ab"
            String prefix = lastFolder + "/";
            
            if (!currentFolder.startsWith(prefix)) {
                result.add(currentFolder);
            }
        }
        
        return result;
    }
}