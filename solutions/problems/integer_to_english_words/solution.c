void append(char* result, const char* word) {
    if (strlen(result) > 0 && strlen(word) > 0) {
        strcat(result, " ");
    }
    strcat(result, word);
}

void ones(int num, char* result) {
    const char* words[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    append(result, words[num]);
}

void tens(int num, char* result) {
    const char* words[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    append(result, words[num]);
}

void teens(int num, char* result) {
    const char* words[] = {
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    append(result, words[num]);
}

void convert(int num, char* result) {
    int hundred = num / 100; //เลขในหลักร้อย
    int ten_unit = num % 100; //เศษหาร 100
    int ten = ten_unit / 10; //เลขในหลักสิบ
    int one = ten_unit % 10; //เลขในหลัหน่วย
    //341 เราจะเอามาต่อท้ายที่ละหลัก สามร้อย สี่สิบ หนึ่ง
    if (hundred > 0) {
        ones(hundred, result);
        append(result, "Hundred");
    }

    if (ten_unit >= 10 && ten_unit < 20) { //ลงท้ายด้วย teen
        teens(ten_unit - 10, result);
    } else {
        if (ten > 0) tens(ten, result);
        if (one > 0) ones(one, result);
    }
}

char* numberToWords(int num) {
    if (num == 0) return strdup("Zero");

    const char* levels[] = {"", "Thousand", "Million", "Billion"};
    char* result = (char*)malloc(1024 * sizeof(char));
    result[0] = '\0';

    //เป็นการไล่จากตัวเลขท้ายมาหน้า
    int part, i = 0;
    while (num > 0) {
        part = num % 1000; //หาเศษจาการหารด้วย 1000
        if (part > 0) { //ถ้ามีเศษ
            char temp[256] = "";
            convert(part, temp); //แปลงตัวเลขจากเศษเป็นประโยค
            if (strlen(levels[i]) != 0) { //0-999 ตอนแรกจะยังไม่มีหน่วยนำ พอ 1000++ ต้องใส่หน่วยนำเช่น 521,000
                append(temp, levels[i]);
            }

            if (strlen(result) != 0) { //ถ้าเริ่มสร้างประโยคไปแล้ว
                char temp_result[1024] = "";
                //เอา ประโยคใหม่่ + ' ' + ประโยคเดิม
                strcpy(temp_result, temp); 
                strcat(temp_result, " ");
                strcat(temp_result, result);

                strcpy(result, temp_result);
            } else { //ถ้ายังไม่ได้สร้างประโยคมาก่อน
                strcpy(result, temp);
            }
        }
        num /= 1000; 
        i++;
    }
    return result;
}