class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        int n = colsum.length;
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>(Collections.nCopies(n, 0)));
        result.add(new ArrayList<>(Collections.nCopies(n, 0)));
        
        int up = upper;
        int low = lower;
        
        // 1. ใส่ colsum=2 ก่อน
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                result.get(0).set(i, 1);
                result.get(1).set(i, 1);
                up--;
                low--;
            }
        }
        
        // 2. ใส่ colsum=1
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                if (up > 0) {
                    result.get(0).set(i, 1);
                    up--;
                } else if (low > 0) {
                    result.get(1).set(i, 1);
                    low--;
                } else {
                    return new ArrayList<>();  // ล้มเหลว
                }
            }
        }
        
        // 3. ตรวจสอบ
        if (up != 0 || low != 0) {
            return new ArrayList<>();
        }
        
        return result;
    }
}