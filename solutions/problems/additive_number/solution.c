#define MAX_SEQ_LEN 35

bool backtrack(const char* num, int start, long long* store, int size) {
    if (start == strlen(num)) {
        return size > 2;
    }

    long long curr = 0;
    for (int i = start; i < strlen(num); i++) {
        // ตรวจสอบ overflow
        if (curr > LLONG_MAX / 10) {
            break;
        }
        curr = curr * 10 + (num[i] - '0');

        if (size >= 2) {
            long long sum = store[size-1] + store[size-2];
            if (sum == curr) {
                store[size] = curr;
                if (backtrack(num, i + 1, store, size + 1)) {
                    return true;
                }
            } else if (sum < curr) {
                break;
            }
        } else {
            store[size] = curr;
            if (backtrack(num, i + 1, store, size + 1)) {
                return true;
            }
        }

        // ตรวจสอบ leading zero
        if (i == start && num[i] == '0') {
            break;
        }
    }
    return false;
}

bool isAdditiveNumber(char* num) {
    long long store[MAX_SEQ_LEN];
    return backtrack(num, 0, store, 0);
}