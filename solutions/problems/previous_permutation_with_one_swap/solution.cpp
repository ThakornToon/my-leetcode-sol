class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        // หาตำแหน่งแรกที่ arr[i] > arr[i+1] เพื่อเปลี่ยน ไล่จากทางขวา 
        // 123 -> สลับไม่ได้, 221 -> 212
        int i;
        for (i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                break;
            }
        }
        
        // ถ้าไม่เจอถือว่าเป้นค่าน้อยสุดแล้ว
        if (i < 0) {
            return arr;
        }
        
        // มองทางขวาหาค่าน้อยกว่าที่มากที่สุดมาสลับ
        int j = i + 1;
        int maxIndex = j;
        int maxVal = arr[j];
        
        for (int k = j + 1; k < n; k++) {
            if (arr[k] < arr[i] && arr[k] > maxVal) {
                maxVal = arr[k];
                maxIndex = k;
            }
        }
        
        // สลับ arr[i] กับ arr[maxIndex]
        swap(arr[i], arr[maxIndex]);
        
        return arr;
    }
};