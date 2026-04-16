class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        if (reservedSeats.length == 0) {
            return n * 2;
        }
        
        // sort reserved seats
        Arrays.sort(reservedSeats, (a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
        
        int total = 0;
        int i = 0;
        int lastRow = 0;
        
        while (i < reservedSeats.length) {
            int currentRow = reservedSeats[i][0];
            
            // แถวที่ไม่มี reservation ก่อนถึงแถวนี้
            total += (currentRow - lastRow - 1) * 2;
            lastRow = currentRow;
            
            // เก็บที่นั่งที่ถูกจองในแถวนี้
            boolean[] reserved = new boolean[11];  // index 1-10
            
            while (i < reservedSeats.length && reservedSeats[i][0] == currentRow) {
                reserved[reservedSeats[i][1]] = true;
                i++;
            }
            
            // ตรวจสอบรูปแบบ
            boolean left = !reserved[2] && !reserved[3] && !reserved[4] && !reserved[5];
            boolean middle = !reserved[4] && !reserved[5] && !reserved[6] && !reserved[7];
            boolean right = !reserved[6] && !reserved[7] && !reserved[8] && !reserved[9];
            
            if (left && right) {
                total += 2;
            } else if (left || middle || right) {
                total += 1;
            }
        }
        
        // แถวหลังแถวสุดท้ายที่มี reservation
        total += (n - lastRow) * 2;
        
        return total;
    }
}