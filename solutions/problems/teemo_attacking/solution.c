int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int count = 0;
    int start = 0;
    for (int i = 0; i < timeSeriesSize; i++) {
        start = (start >= timeSeries[i]) ? start : timeSeries[i];
        count += (timeSeries[i] + duration - start) > 0 ? (timeSeries[i] + duration - start) : 0;
        start = timeSeries[i] + duration;
    }
    return count;
}