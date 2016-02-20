class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        int aLen = a.length(), bLen = b.length();
        if (aLen > bLen) return addBinary(b, a);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result = "";
        int carry = 0;
        for (int i = 0; i < aLen; i++) {
            int digit = carry + (a[i] - '0') + (b[i] - '0');
            carry = digit / 2;
            result.push_back('0' + digit % 2);
        }
        for (int i = aLen; i < bLen; i++) {
            int digit = carry + (b[i] - '0');
            carry = digit / 2;
            result.push_back('0' + digit % 2);
        }
        if (carry > 0)
            result.push_back('1');
        while (result.back() == '0' && result.length() > 1) result.pop_back();
        reverse(result.begin(), result.end());
        return result;
    }
};

// 按道理要判断前面是否有多余的0吧？
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        const size_t n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (size_t i = 0; i < n; i++){
            const int ai = i < a.size() ? a[i] - '0' : 0;
            const int bi = i < b.size() ? b[i] - '0' : 0;
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};
