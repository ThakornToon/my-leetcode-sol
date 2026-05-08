double average(int* salary, int salarySize) {
    int sum = 0;
    int min = INT_MAX, max = INT_MIN;
    
    for (int i = 0; i < salarySize; i++) {
        sum += salary[i];
        if (salary[i] < min) min = salary[i];
        if (salary[i] > max) max = salary[i];
    }
    
    return (double)(sum - min - max) / (salarySize - 2);
}