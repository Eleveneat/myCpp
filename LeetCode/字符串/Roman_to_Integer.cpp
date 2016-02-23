class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        const size_t len = s.size();
        int result = 0;
        for(size_t cur = 0, next = 1; next < len; cur++, next++) {
            if (m[s[cur]] < m[s[next]])
                result -= m[s[cur]];
            else
                result += m[s[cur]];
        }
        result += len == 0 ? 0 : m[s.back()];
        return result;
    }
};
