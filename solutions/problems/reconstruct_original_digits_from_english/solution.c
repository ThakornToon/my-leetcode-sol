char* originalDigits(char* s) {
    int count[26] = {0};
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
    }
    
    int nums[10] = {0};
    nums[0] = count['z' - 'a'];
    nums[2] = count['w' - 'a'];
    nums[4] = count['u' - 'a'];
    nums[6] = count['x' - 'a'];
    nums[8] = count['g' - 'a'];
    
    nums[3] = count['h' - 'a'] - nums[8];
    nums[5] = count['f' - 'a'] - nums[4];
    nums[7] = count['s' - 'a'] - nums[6];
    
    nums[1] = count['o' - 'a'] - nums[0] - nums[2] - nums[4];
    nums[9] = count['i' - 'a'] - nums[5] - nums[6] - nums[8];
    
    // คำนวณความยาวผลลัพธ์
    int len = 0;
    for (int i = 0; i < 10; i++) {
        len += nums[i];
    }
    
    char* result = (char*)malloc(len + 1);
    int pos = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < nums[i]; j++) {
            result[pos++] = '0' + i;
        }
    }
    result[pos] = '\0';
    
    return result;
}