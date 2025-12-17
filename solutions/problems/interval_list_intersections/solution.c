/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc((firstListSize + secondListSize) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((firstListSize + secondListSize) * sizeof(int));
    
    int i = 0, j = 0;
    int count = 0;
    
    while (i < firstListSize && j < secondListSize) {
        // หาค่าเริ่มต้นและสิ้นสุดของ intersection
        int start = firstList[i][0] > secondList[j][0] ? firstList[i][0] : secondList[j][0];
        int end = firstList[i][1] < secondList[j][1] ? firstList[i][1] : secondList[j][1];
        
        // ตรวจสอบว่ามี intersection หรือไม่
        if (start <= end) {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = start;
            result[count][1] = end;
            (*returnColumnSizes)[count] = 2;
            count++;
        }
        
        // เลื่อน pointer ของ interval ที่สิ้นสุดก่อน
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    
    *returnSize = count;
    return result;
}