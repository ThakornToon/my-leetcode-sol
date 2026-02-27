class Solution {
    public int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int num = n;
        
        while (num > 0) {
            int digit = num % 10;
            product *= digit;
            sum += digit;
            num /= 10;
        }
        
        return product - sum;
    }
}