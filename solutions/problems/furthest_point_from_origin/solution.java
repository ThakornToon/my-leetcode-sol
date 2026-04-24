class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int L = 0, R = 0, any = 0;
        
        for (int i = 0; i < moves.length(); i++) {
            char c = moves.charAt(i);
            switch (c) {
                case 'L': L++; break;
                case 'R': R++; break;
                default: any++; break;
            }
        }
        
        return Math.abs(L - R) + any;
    }
}