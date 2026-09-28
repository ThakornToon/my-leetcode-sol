class MyQueue {
private:
    std::stack<int> back;
    std::stack<int> front;

    // ย้ายข้อมูลจาก back ไป front เมื่อ front ว่าง
    void adjust() {
        if (front.empty()) {
            while (!back.empty()) {
                front.push(back.top());
                back.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        back.push(x);
    }

    int pop() {
        adjust();
        int val = front.top();
        front.pop();
        return val;
    }

    int peek() {
        adjust();
        return front.top();
    }

    bool empty() {
        return back.empty() && front.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */