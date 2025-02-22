class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        std::sort(s.begin(), s.end(), greater<char>());
        return s.substr(1, s.size() - 1) + '1';
    }
};