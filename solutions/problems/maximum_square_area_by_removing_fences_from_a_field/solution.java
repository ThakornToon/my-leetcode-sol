class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        final int MOD = 1_000_000_007;
        
        // รวม fences ขอบ
        List<Integer> hPoints = new ArrayList<>();
        for (int fence : hFences) hPoints.add(fence);
        hPoints.add(1);
        hPoints.add(m);
        Collections.sort(hPoints);
        
        List<Integer> vPoints = new ArrayList<>();
        for (int fence : vFences) vPoints.add(fence);
        vPoints.add(1);
        vPoints.add(n);
        Collections.sort(vPoints);
        
        // สร้าง HashSet สำหรับ gaps แนวนอน
        Set<Integer> gaps = new HashSet<>();
        
        // คำนวณ gaps แนวนอน
        int hSize = hPoints.size();
        for (int i = 0; i < hSize; i++) {
            for (int j = i + 1; j < hSize; j++) {
                gaps.add(hPoints.get(j) - hPoints.get(i));
            }
        }
        
        // หา gap ที่ใหญ่ที่สุดที่เป็น common
        long maxSide = 0;
        int vSize = vPoints.size();
        
        for (int i = 0; i < vSize; i++) {
            for (int j = i + 1; j < vSize; j++) {
                int diff = vPoints.get(j) - vPoints.get(i);
                if (gaps.contains(diff)) {
                    maxSide = Math.max(maxSide, diff);
                }
            }
        }
        
        if (maxSide == 0) {
            return -1;
        }
        
        long area = (maxSide * maxSide) % MOD;
        return (int) area;

    }
}