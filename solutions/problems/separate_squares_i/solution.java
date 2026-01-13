class Solution {
    public double separateSquares(int[][] squares) {
        double maxY = Double.MIN_VALUE;
        double minY = Double.MAX_VALUE;
        
        // หาค่า y ต่ำสุดและสูงสุด
        for (int[] square : squares) {
            int y = square[1];
            double side = square[2];
            double top = y + side;
            
            maxY = Math.max(maxY, top);
            minY = Math.min(minY, y);
        }
        
        // Binary Search
        double epsilon = 1e-5;
        
        while (maxY - minY > epsilon) {
            double midY = minY + (maxY - minY) / 2.0;
            double upArea = 0.0;    // พื้นที่เหนือเส้น
            double downArea = 0.0;  // พื้นที่ใต้เส้น
            
            for (int[] square : squares) {
                int y = square[1];
                double side = square[2];
                double squareTop = y + side;
                
                if (midY >= squareTop) {
                    // ทั้งสี่เหลี่ยมอยู่ใต้เส้น
                    downArea += (side * side);
                } else if (midY <= y) {
                    // ทั้งสี่เหลี่ยมอยู่เหนือเส้น
                    upArea += (side * side);
                } else {
                    // เส้นตัดผ่านสี่เหลี่ยม
                    double heightBelow = midY - y;
                    double heightAbove = squareTop - midY;
                    
                    downArea += (heightBelow * side);
                    upArea += (heightAbove * side);
                }
            }
            
            double diff = upArea - downArea;
            
            if (Math.abs(diff) < epsilon) {
                // พื้นที่เท่ากัน (ใน tolerance)
                maxY = midY;  // พยายามหา y ที่น้อยกว่า
            } else if (diff > 0) {
                // พื้นที่บนมากกว่า → ยกเส้นขึ้น
                minY = midY;
            } else {
                // พื้นที่ล่างมากกว่า → ลดเส้นลง
                maxY = midY;
            }
        }
        
        return minY;
    }
}