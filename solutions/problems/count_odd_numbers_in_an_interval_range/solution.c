

int countOdds(int low, int high){
    // จำนวนเลขคี่ในช่วง [0, high] = (high + 1) / 2
    // จำนวนเลขคี่ในช่วง [0, low-1] = low / 2
    // ดังนั้นจำนวนเลขคี่ในช่วง [low, high] = (high+1)/2 - low/2
    return (high + 1) / 2 - low / 2;
}