char* solveEquation(char* equation) {
    int fristConst = 0;
    int secConst = 0;
    int fristX = 0;
    int secX = 0;

    int sign = 1;
    int left = 1;
    int n = strlen(equation);
    int i = 0;
    while (i < n) {
        int num = 0;
        int hasNum = 0;
        while (i < n && equation[i] >= '0' && equation[i] <= '9') {
            num = num * 10 + (equation[i] - '0');
            i++;
            hasNum = 1;
        }

        if (equation[i] == 'x') {
            if (!hasNum) {
                num = 1;
            }

            if (left) {
                fristX += (num * sign);
            } else {
                secX += (num * sign);
            }
            i++;
            if (equation[i] == '-') {
                sign = -1;
            } else {
                sign = 1;
                if (equation[i] == '=') {
                    left = 0;
                }
            }
            i++;
        } else if (equation[i] == '-') {
            if (left) {
                fristConst += (num * sign);
            } else {
                secConst += (num * sign);
            }
            sign = -1;
            i++;
        } else {
            if (left) {
                fristConst += (num * sign);
            } else {
                secConst += (num * sign);
            }

            sign = 1;
            if (equation[i] == '=') {
                left = 0;
            }
            i++;
        }
    }

    fristX -= secX;
    secConst -= fristConst; 
    char* res = (char*)malloc(19 * sizeof(char));
    if (fristX == 0 && secConst == 0) {
        strcpy(res, "Infinite solutions");
    } else if (fristX == 0) {
        strcpy(res, "No solution");
    } else {
        secConst /= fristX;
        sprintf(res, "x=%d", secConst);
    }
    return res;
}