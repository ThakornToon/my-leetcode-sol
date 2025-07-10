// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand10() {
    while (1){
        int num = (rand7() - 1) * 7 + rand7(); // ได้เลข 1-49 ความน่าจะเป็นเท่ากัน
        if (num <= 40) {
            return num % 10 + 1;
        }
    }
}
/*
(rand7() - 1) ให้ค่า 0-6
(rand7() - 1) * 7 ให้ค่า 0, 7, 14, ..., 42
บวกด้วย rand7() ที่ให้ค่า 1-7
ดังนั้นผลลัพธ์สุดท้ายจะครอบคลุมทุกค่าใน 1-49 อย่างสม่ำเสมอ
*/