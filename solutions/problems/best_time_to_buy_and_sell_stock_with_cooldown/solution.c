int max(int a, int b) {
    return (a >= b) ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int buy = INT_MIN;
    int sell = 0;
    int prev_sell = 0; 
    int prev_buy;
    for (int i = 0; i < pricesSize; i++) {
        prev_buy = buy; 
        buy = max(prev_sell - prices[i], prev_buy); // ถือหุ้นค้างจากเมื่อวาน หรือ ซื้อหุ้นวันนี้ (มาจากสถานะที่ ready แล้ว = prev_sell)
        prev_sell = sell; // ค่า sell ของเมื่อวานจะเก็บใน prev_sell ทำให้ในวันพรุ่งนี้จะเป็นค่าที่ ready (ซื้อหุ้นต่อได้ในวันพรุ่งนี้)
        sell = max(prev_buy + prices[i], sell); // ขายหุ้นที่ถืออยู่จากเมื่อวาน หรือ ไม่ทำอะไรเลย(คงสถานะขายไว้จากวันก่อน)
    }
    return sell;
}