typedef long long ll;

ll getBucketId(ll num, ll bucketSize) {
    return (num >= 0) ? num / bucketSize : ((num + 1) / bucketSize) - 1;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff) {
    int mapSize = numsSize * 2;  // อาจใช้ค่าที่ใหญ่กว่านี้
    ll* map = (ll*)malloc(sizeof(ll) * mapSize);
    bool* used = calloc(mapSize, sizeof(bool)); // บ่งชี้ว่า bucket นั้นมีการใช้งานหรือไม่
    for (int i = 0; i < mapSize; i++) used[i] = false;

    ll bucketSize = (ll)valueDiff + 1;

    for (int i = 0; i < numsSize; i++) {
        ll num = (ll)nums[i];
        ll bucketId = getBucketId(num, bucketSize);
        int key = (bucketId % mapSize + mapSize) % mapSize; // แปลง bucketId ให้เป็น index ใน array ของ Hash Map รับประกันว่าได้ค่า index ที่เป็นบวกเสมอ แม้ bucketId จะเป็นลบ

        // Check current bucket ถ้า key นั้นมีอยู่แล้วใน bucket เดียวกันแปลว่าช่วงค่าเดียวกันตอบได้เลย
        if (used[key] && getBucketId(map[key], bucketSize) == bucketId) {
            return true;
        }

        // Check neighbors ว่ามี key ไหมแล้วดูว่าช่วงค่าตรงไหม
        for (int diff = -1; diff <= 1; diff += 2) {
            ll neighborId = bucketId + diff;
            int neighborKey = (neighborId % mapSize + mapSize) % mapSize;
            if (used[neighborKey] && llabs(map[neighborKey] - num) <= valueDiff) {
                return true;
            }
        }

        // Insert current number
        map[key] = num;
        used[key] = true;

        // Remove old value outside the sliding window
        if (i >= indexDiff) {
            ll oldNum = (ll)nums[i - indexDiff];
            ll oldBucketId = getBucketId(oldNum, bucketSize);
            int oldKey = (oldBucketId % mapSize + mapSize) % mapSize;
            used[oldKey] = false;
        }
    }

    free(map);
    free(used);
    return false;
}