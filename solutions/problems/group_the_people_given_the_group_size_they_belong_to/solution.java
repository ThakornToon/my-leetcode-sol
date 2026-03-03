class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> result = new ArrayList<>();
        // ใช้ HashMap<Integer, List<Integer>>: size -> list of people
        Map<Integer, List<Integer>> groups = new HashMap<>();
        
        for (int i = 0; i < groupSizes.length; i++) {
            int size = groupSizes[i];
            
            // ถ้ายังไม่มี list สำหรับ size นี้ ให้สร้างใหม่
            groups.putIfAbsent(size, new ArrayList<>());
            
            // เพิ่มคนเข้า groups ตามขนาด
            groups.get(size).add(i);
            
            // ถ้ามีคนครบตามขนาดกลุ่มแล้ว
            if (groups.get(size).size() == size) {
                result.add(new ArrayList<>(groups.get(size)));
                groups.get(size).clear();  // รีเซ็ตสำหรับกลุ่มถัดไป
            }
        }
        
        return result;
    }
}