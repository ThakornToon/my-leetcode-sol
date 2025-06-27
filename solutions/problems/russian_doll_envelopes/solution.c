int compare(const void* a, const void* b) {
    int* envelopeA = *(int**)a;
    int* envelopeB = *(int**)b;
    
    if (envelopeA[0] == envelopeB[0]) {
        return envelopeB[1] - envelopeA[1]; // เรียง height จากมากไปน้อยเมื่อ width เท่ากัน
    }
    return envelopeA[0] - envelopeB[0]; // เรียง width จากน้อยไปมาก
}

// ฟังก์ชัน Binary Search แบบ lower_bound
int lower_bound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    qsort(envelopes, envelopesSize, sizeof(int*), compare);
    int* lis = (int*)malloc(envelopesSize * sizeof(int));
    int lisSize = 0;
    
    for (int i = 0; i < envelopesSize; i++) {
        int h = envelopes[i][1];
        int pos = lower_bound(lis, lisSize, h);
        
        if (pos == lisSize) {
            lis[lisSize++] = h;
        } else {
            lis[pos] = h;
        }
    }
    
    free(lis);
    return lisSize;
}

/*
ทำการเรียงตามความกว้างจากน้อยไปมากโดยถ้าหากมีความกว้างเท่ากันจากเรียงตามความสูงมากไปน้อย 
จากนั้นสร้างอาเรย์หนึ่งตัวเพื่อไว้เก็บความสูงซึ่งขนาดของอาเรย์จะเป็นคำตอบ 
เมื่อไล่ที่ละสมาชิกการตัดสินใจใส่ความสูงลงไปในอาเรย์ให้ใช้ binary search เพื่อลดเวลา หากไม่พบค่าที่มากกว่าให้เพิ่มค่านั้นลงไปแต่หากพบค่าที่มากกว่าให้แทนด้วยค่าใหม่ซึ่งอาจให้ผลลัพธ์ที่ดีกว่า

ตัวอย่างเมื่อเรียงแล้ว:
[[2,14], [2,5], [2,3], [5,4], [5,1], [6,7], [6,3], [7,5],[10,6]]
อาเรย์เก็บความสูงเมื่อวนลูปแต่ละรอบ:
[14] เลือก [2,14]
[5] เลือก [2,5]
[3] เลือก [2,3]
[3,4] เลือก [2,3], [5,4]
[1,4] เลือก [2,3], [5,4] หรือ [5,1], ... ซึ่งอาจได้ผลลัพธ์ที่ดีกว่า
[1,4,7] เลือก [2,3], [5,4], [6,7] หรือ [5,1], ... ซึ่งอาจให้ผลลัพธ์ที่ดีกว่า
[1,3,7] เลือก [2,3], [5,4], [6,7] หรือ [5,1], [6,3], ... ซึ่งอาจให้ผลลัพธ์ที่ดีกว่า
[1,3,5] เลือก [5,1], [6,3], [7,5]
[1,3,5,6] เลือก [5,1], [6,3], [7,5], [10,6]
การที่เราเรียงความสูงจากมากไปน้อยหากความกว้างเท่ากันทำให้จะไม่มีการเลือกความกว้างเท่ากันเช่น [2,3], [2,5] มาด้วยกัน
*/