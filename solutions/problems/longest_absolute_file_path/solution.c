int lengthLongestPath(char* input) {
    int n = strlen(input);
    if (n == 0) return 0;

    // ความลึกสูงสุดไม่เกินจำนวนตัวอักษรทั้งหมด
    int* path_len = (int*)malloc(sizeof(int) * (n + 1));
    int max_len = 0;
    char* p = input;

    while (*p) {
        // นับความลึกจาก '\t'
        int depth = 0;
        while (*p == '\t') {
            depth++;
            p++;
        }

        // อ่านชื่อไฟล์หรือไดเรกทอรี
        int name_len = 0;
        bool is_file = false;
        while (*p && *p != '\n') {
            if (*p == '.') {
                is_file = true;
            }
            name_len++;
            p++;
        }

        // คำนวณความยาวเส้นทาง
        if (depth == 0) {
            path_len[depth] = name_len;
        } else {
            path_len[depth] = path_len[depth - 1] + 1 + name_len;
        }

        if (is_file) {
            if (path_len[depth] > max_len) {
                max_len = path_len[depth];
            }
        }

        // ข้ามตัวตัดบรรทัด '\n'
        if (*p == '\n') {
            p++;
        }
    }

    free(path_len);
    return max_len;
}