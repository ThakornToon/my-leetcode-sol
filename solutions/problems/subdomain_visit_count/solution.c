/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_DOMAINS 1000
#define MAX_LENGTH 100

char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
    // ใช้ array ธรรมดาเก็บ domain กับ count
    char domains[MAX_DOMAINS][MAX_LENGTH] = {0};
    int counts[MAX_DOMAINS] = {0};
    int domainCount = 0;
    
    for (int i = 0; i < cpdomainsSize; i++) {
        // แยก count กับ domain
        char* cp = cpdomains[i];
        int count = atoi(cp);
        
        // ข้ามไปหาช่องว่าง
        while (*cp != ' ') cp++;
        cp++; // ข้ามช่องว่าง
        
        char domain[MAX_LENGTH];
        strcpy(domain, cp);
        
        // ประมวลผลทุก subdomain
        char* sub = domain;
        while (1) {
            // หา domain นี้ใน array
            int found = -1;
            for (int j = 0; j < domainCount; j++) {
                if (strcmp(domains[j], sub) == 0) {
                    found = j;
                    break;
                }
            }
            
            if (found == -1) {
                // ใหม่ - เพิ่มเข้าไป
                strcpy(domains[domainCount], sub);
                counts[domainCount] = count;
                domainCount++;
            } else {
                // มีอยู่แล้ว - บวก count
                counts[found] += count;
            }
            
            // หา dot ต่อไป
            char* dot = strchr(sub, '.');
            if (dot == NULL) break;
            sub = dot + 1; // ข้าม dot
        }
    }
    
    // สร้างผลลัพธ์
    char** result = malloc(domainCount * sizeof(char*));
    for (int i = 0; i < domainCount; i++) {
        result[i] = malloc(MAX_LENGTH); // พอสำหรับ "count domain"
        sprintf(result[i], "%d %s", counts[i], domains[i]);
    }
    
    *returnSize = domainCount;
    return result;

}