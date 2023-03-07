class Solution {
public:
    int splitNum(int num) {
        vector<int> vec;
        while (num) {
            vec.push_back(num % 10);
            num /= 10;
        }
        sort(vec.begin(), vec.end());
        int a = 0, b = 0;
        for (int i = 0; i < vec.size(); i++) {
            i & 1 ? a =  a * 10 + vec[i] : b = b * 10 + vec[i];
        }
        return a + b;
    }
};