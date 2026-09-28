class MedianFinder {
private:
    std::priority_queue<int> small;  // ครึ่งซ้าย Max-heap มากไปน้อย
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // ครึ่งขวา Min-heap น้อยไปมาก

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // ดันเข้า max-heap ก่อน แล้วย้ายตัวมากสุดไปให้ min-heap
        small.push(num);
        large.push(small.top());
        small.pop();

        // รักษาสมดุลขนาด (small ต้องมีขนาดเท่ากับหรือมากกว่า large 1 ตัว)
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */