class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        // map ว่าแต่ละป้ายมีคะนไหนผ่านบ้าง
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }
        
        // BFS
        queue<int> q;
        vector<bool> visitedRoute(routes.size(), false); // บันทึกว่าเคยขึ้นคันไหนไปบ้าง
        
        // เริ่มจากทุกสายที่ผ่าน source
        for (int route : stopToRoutes[source]) {
            q.push(route);
            visitedRoute[route] = true; // บันทึกว่าเคยขึ้นคันไหนไปบ้าง
        }
        
        int buses = 1; // นับว่าขึ้นไปกี่คัน
        
        while (!q.empty()) {
            int size = q.size();
            // หาไปทีละ level
            for (int i = 0; i < size; i++) {
                int currRoute = q.front();
                q.pop();
                
                // ตรวจสอบทุกป้ายในสายนี้
                for (int stop : routes[currRoute]) {
                    if (stop == target) return buses;
                    
                    // ดูสายอื่นๆ ที่ผ่านป้ายนี้
                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visitedRoute[nextRoute]) {
                            visitedRoute[nextRoute] = true; // บันทึกว่าเคยขึ้นคันไหนไปบ้าง
                            q.push(nextRoute); // ลองลงแล้วไปขึ้นคันใหม่
                        }
                    }
                }
            }
            buses++;
        }
        
        return -1;
    }
};