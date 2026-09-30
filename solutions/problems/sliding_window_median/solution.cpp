class DualMulSet {
private:
    multiset<long long> small, large;
    int k;

    void balance() {
        // รักษาขนาดของ small ให้เป็น (k + 1) / 2 เสมอ
        // small ขนาดมากกว่า large ไม่เกิน 1
        while (small.size() < (k + 1) / 2 && !large.empty()) {
            auto it = large.begin();
            small.insert(*it);
            large.erase(it);
        }
        while (small.size() > (k + 1) / 2) {
            auto it = std::prev(small.end());
            large.insert(*it);
            small.erase(it);
        }
    }

public:
    DualMulSet(int _k) : k(_k) {}

    void insert(long long x) {
        if (small.empty() || x <= *small.rbegin()) {
            small.insert(x);
        } else {
            large.insert(x);
        }
        balance();
    }

    void erase(long long x) {
        // ใช้ ms.find() เพื่อลบเพียง 1 instance
        auto it = small.find(x);
        if (it != small.end()) {
            small.erase(it);
        } else {
            it = large.find(x);
            if (it != large.end()) {
                large.erase(it);
            }
        }
        balance();
    }

    double getMedian() {
        if (k % 2 == 1) {
            return *small.rbegin();
        }
        return (*small.rbegin() + *large.begin()) / 2.0;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DualMulSet dms(k);
        for (int i = 0; i < k; ++i) {
            dms.insert(nums[i]);
        }

        vector<double> result = {dms.getMedian()};
        for (int i = k; i < nums.size(); ++i) {
            dms.insert(nums[i]);
            dms.erase(nums[i - k]);
            result.push_back(dms.getMedian());
        }

        return result;
    }
};