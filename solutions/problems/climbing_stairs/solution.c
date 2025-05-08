int climbStairs(int n) {
    int v[3] = {1, 1, 1};
    while (n>=2){
        n--;
        v[2]=v[1]+v[0];
        v[0]=v[1];
        v[1]=v[2];
    }
    return v[2];
}