class Solution {

    private Map<Integer, Integer> memo = new HashMap<>();
    
    public int minDays(int n) {
        if (n <= 1) return n;
        
        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        int result = n;

        /*
        การลดทีละ 1 หลายครั้งสามารถ "กระโดด" ไปที่ n/2 หรือ n/3 ได้โดยตรง
        result = Math.min(result, 1 + minDays(n - 1));
        */
        
        // ลดไปที่ค่าที่หาร 2 หรือ 3 ลงตัวโดยตรง
        int toEven = 1 + minDays(n / 2) + (n % 2);
        int toThree = 1 + minDays(n / 3) + (n % 3);
        result = Math.min(result, Math.min(toEven, toThree));
        
        memo.put(n, result);
        return result;
    }
}