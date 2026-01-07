/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define BOARD_SIZE 8

int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes) {
    // สร้าง board และเซตทุกค่าเป็น false
    bool board[BOARD_SIZE][BOARD_SIZE] = {false};
    
    // เก็บตำแหน่ง queens ใน board
    for (int i = 0; i < queensSize; i++) {
        int row = queens[i][0];
        int col = queens[i][1];
        board[row][col] = true;
    }
    
    // กำหนดทิศทางทั้ง 8
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };
    
    // buffer สำหรับเก็บผลลัพธ์ (สูงสุด 8 queens)
    int result[8][2];
    int resultCount = 0;
    
    int kingRow = king[0];
    int kingCol = king[1];
    
    // สำรวจแต่ละทิศทาง
    for (int d = 0; d < 8; d++) {
        int row = kingRow + directions[d][0];
        int col = kingCol + directions[d][1];
        
        // เดินไปตามทิศทางจนกว่าจะออกนอกกระดาน
        while (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if (board[row][col]) {
                // พบ queen ในทิศทางนี้
                result[resultCount][0] = row;
                result[resultCount][1] = col;
                resultCount++;
                break;  // หยุดค้นหาในทิศทางนี้
            }
            
            // เดินต่อไปในทิศทางเดิม
            row += directions[d][0];
            col += directions[d][1];
        }
    }
    
    // จัดสรรหน่วยความจำสำหรับผลลัพธ์
    int** returnArray = (int**)malloc(resultCount * sizeof(int*));
    *returnColumnSizes = (int*)malloc(resultCount * sizeof(int));
    *returnSize = resultCount;
    
    for (int i = 0; i < resultCount; i++) {
        returnArray[i] = (int*)malloc(2 * sizeof(int));
        returnArray[i][0] = result[i][0];
        returnArray[i][1] = result[i][1];
        (*returnColumnSizes)[i] = 2;
    }
    
    return returnArray;
}