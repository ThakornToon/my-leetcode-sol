class Solution {
private:
    const int MOD = 1e9 + 7;
    
public:
    int maxProfit(vector<int>& inventory, int orders) {
        // เรียงลำดับจากมากไปน้อย
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0); // sentinel
        
        long long profit = 0;
        long long remaining = orders;
        int n = inventory.size();
        
        for (int i = 0; i < n - 1; i++) {
            long long current = inventory[i];  // ขอบบน
            long long next = inventory[i + 1];  // ขอบล่าง
            long long diff = current - next;  // ผลต่างจำนวน
            long long count = i + 1;  // จำนวนสีที่มีค่าเท่ากับ current
            
            // จำนวนลูกบอลที่สามารถขายได้ในช่วงระดับตัวเลข (next, current] ตั้งแต่ index 0 ถึง i
            long long canSell = diff * count;
            
            if (canSell <= remaining) {
                // ขายทั้งหมดในช่วง (next, current] จากสูตร a + (a+1) + ... + b = (b-a)(a+1+b)/2
                // ผลรวม = count * (next+1 + current) * diff / 2 = จำนวนชุด * ผลรวมช่วง
                long long total = count * (next + 1 + current) * diff / 2;
                profit = (profit + total) % MOD;
                remaining -= canSell;
            } else {
                // ขายบางส่วนในช่วงนี้
                long long fullRows = remaining / count;  // ต้องการตัวเลข (next, current] กี่แถว
                long long remainder = remaining % count;  // เศษที่เหลือ
                
                // fullRows แถวเต็ม (ขายเต็มทุกสี)
                // ผลรวมเลขคณิตจาก current ลงไปถึง current-fullRows+1 = [current, current-fullRows+1]
                long long total = count * (current + (current - fullRows + 1)) * fullRows / 2;
                profit = (profit + total) % MOD;
                
                // remainder ของแถวที่เหลือ
                profit = (profit + remainder * (current - fullRows)) % MOD;
                break;
            }
        }
        
        return (int)profit;
    }
};