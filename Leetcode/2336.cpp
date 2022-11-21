class SmallestInfiniteSet {
public:
    map<int, bool> mp;
    SmallestInfiniteSet() {

    }

    int popSmallest() {
        int ret = 1;
        for (auto x : mp) {
            if (x.first == ret) {
                ++ret;
            } else {
                break;
            }
        }
        mp[ret] = true;
        return ret;
    }

    void addBack(int num) {
        if (mp.count(num)) {
            mp.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */