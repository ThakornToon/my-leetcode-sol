class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new ArrayList<>();
        
        // วิธีที่ 1: สร้างโดยตรง
        for (int start = 1; start <= 9; start++) {
            int num = start;
            
            for (int next = start + 1; next <= 9; next++) {
                num = num * 10 + next;
                
                if (num >= low && num <= high) {
                    result.add(num);
                }
            }
        }
        
        Collections.sort(result);
        return result;
    }
}