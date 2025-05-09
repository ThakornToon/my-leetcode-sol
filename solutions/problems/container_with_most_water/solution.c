int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize-1;
    int vol = 0;
    if (heightSize < 2){
        return vol;
    }
    while(i<j){
        if (height[i] < height[j]){
            if (vol < height[i]*(j-i)){
                vol = height[i]*(j-i);
            }
            i+=1;
        }
        else{
            if (vol < height[j]*(j-i)){
                vol = height[j]*(j-i);
            }
            j-=1;
        }
    }
    return vol;
}