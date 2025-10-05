#define MAX_FORMULA_LEN 2000
#define MAX_ATOM_LEN 15

typedef struct {
    char name[MAX_ATOM_LEN];
    int count;
} Atom;

Atom atoms[100];
int atomCount = 0;

// ฟังก์ชันคูณสูตรด้วยตัวคูณ
void multiplyFormula(char* formula, int multiplier) {
    if (multiplier == 1) return;
    
    char temp[MAX_FORMULA_LEN] = {0};
    int pos = 0;
    int i = 0;
    
    while (formula[i]) {
        // Copy atom name (uppercase + lowercase)
        if (isupper(formula[i])) {
            temp[pos++] = formula[i++];
            while (islower(formula[i])) {
                temp[pos++] = formula[i++];
            }
            
            // Read and multiply number
            int num = 0;
            while (isdigit(formula[i])) {
                num = num * 10 + (formula[i] - '0');
                i++;
            }
            
            if (num == 0) num = 1;
            num *= multiplier;
            
            // Write multiplied number
            if (num > 1) {
                char numStr[10];
                sprintf(numStr, "%d", num);
                strcpy(temp + pos, numStr);
                pos += strlen(numStr);
            }
        } else {
            temp[pos++] = formula[i++];
        }
    }
    temp[pos] = '\0';
    strcpy(formula, temp);
}

// ฟังก์ชัน expand วงเล็บทั้งหมด
void expandParentheses(char* formula) {
    char temp[MAX_FORMULA_LEN];
    int changed;
    
    do {
        changed = 0;
        strcpy(temp, formula);
        int tempPos = 0;
        int i = 0;
        
        while (temp[i]) {
            if (temp[i] == '(') {
                // Find matching ')'
                int depth = 1;
                int j = i + 1;
                while (temp[j] && depth > 0) {
                    if (temp[j] == '(') depth++;
                    else if (temp[j] == ')') depth--;
                    j++;
                }
                
                if (depth == 0) {
                    // Extract content inside parentheses
                    char inner[MAX_FORMULA_LEN] = {0};
                    strncpy(inner, temp + i + 1, j - i - 2);
                    
                    // Parse multiplier after ')'
                    int multiplier = 0;
                    int k = j;
                    while (isdigit(temp[k])) {
                        multiplier = multiplier * 10 + (temp[k] - '0');
                        k++;
                    }
                    if (multiplier == 0) multiplier = 1;
                    
                    // Multiply the inner formula
                    multiplyFormula(inner, multiplier);
                    
                    // Copy expanded content
                    strcpy(formula + tempPos, inner);
                    tempPos += strlen(inner);
                    
                    i = k;
                    changed = 1;
                } else {
                    formula[tempPos++] = temp[i++];
                }
            } else {
                formula[tempPos++] = temp[i++];
            }
        }
        formula[tempPos] = '\0';
    } while (changed);
}

void addAtom(char* name, int count) {
    for (int i = 0; i < atomCount; i++) {
        if (strcmp(atoms[i].name, name) == 0) {
            atoms[i].count += count;
            return;
        }
    }
    strcpy(atoms[atomCount].name, name);
    atoms[atomCount].count = count;
    atomCount++;
}

int cmp(const void* a, const void* b) {
    return strcmp(((Atom*)a)->name, ((Atom*)b)->name);
}

// นับ atoms จากสูตรที่ expand แล้ว
void countAtomsFromFormula(char* formula) {
    int i = 0;
    while (formula[i]) {
        if (isupper(formula[i])) {
            char atom[MAX_ATOM_LEN] = {0};
            int count = 0;
            
            atom[0] = formula[i++];
            int j = 1;
            
            while (islower(formula[i])) {
                atom[j++] = formula[i++];
            }
            atom[j] = '\0';
            
            while (isdigit(formula[i])) {
                count = count * 10 + (formula[i] - '0');
                i++;
            }
            if (count == 0) count = 1;
            
            addAtom(atom, count);
        } else {
            i++;
        }
    }
}

char* countOfAtoms(char* formula) {
    atomCount = 0;
    // printf("Formula: %s\n", formula); 
    
    // Expand all parentheses first
    char expanded[MAX_FORMULA_LEN];
    strcpy(expanded, formula);
    expandParentheses(expanded);
    
    // printf("Expanded: %s\n", expanded); 
    
    // Count atoms from expanded formula
    countAtomsFromFormula(expanded);
    
    // Sort and build result
    qsort(atoms, atomCount, sizeof(Atom), cmp);
    
    char* result = (char*)malloc(1000 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < atomCount; i++) {
        strcat(result, atoms[i].name);
        if (atoms[i].count > 1) {
            char num[10];
            sprintf(num, "%d", atoms[i].count);
            strcat(result, num);
        }
    }
    
    return result;
}