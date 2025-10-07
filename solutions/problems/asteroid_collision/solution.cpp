class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        
        for (int asteroid : asteroids) {
            // For positive asteroids or when stack is empty, just push
            if (stack.empty() || asteroid > 0) {
                stack.push_back(asteroid);
                continue;
            }
            
            // Handle negative asteroid (moving left)
            bool destroyed = false;
            while (!stack.empty() && stack.back() > 0) {
                if (stack.back() < -asteroid) {
                    // Current stack asteroid is smaller, pop it
                    stack.pop_back();
                } else if (stack.back() == -asteroid) {
                    // Both asteroids destroy each other
                    stack.pop_back();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid is smaller, destroy it
                    destroyed = true;
                    break;
                }
            }
            
            // If negative asteroid survived all collisions, push it
            if (!destroyed) {
                stack.push_back(asteroid);
            }
        }
        
        return stack;
    }
};