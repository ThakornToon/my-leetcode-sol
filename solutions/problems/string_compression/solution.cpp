class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        int count = 0;
        char prev = chars[0];
        chars.push_back('\0');
        int len = chars.size();
        while (read < len) {
            if (chars[read] == prev) {
                count += 1;
            } else {
                chars[write++] = prev;
                if (count > 1) {
                    int left = write;
                    while (count > 0) {
                        chars[write++] = '0' + count % 10;
                        count /= 10;
                    }
                    int right = write - 1;
                    while (left < right) {
                        char temp = chars[left];
                        chars[left++] = chars[right];
                        chars[right--] = temp;
                    }
                }

                prev = chars[read];
                count = 1;
            }
            read++;
        }
        return write;
    }
};