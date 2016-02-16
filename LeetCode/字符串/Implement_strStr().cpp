class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        int haystackLen = haystack.length(), needleLen = needle.length();
        for (int i = 0; i < haystackLen; ++i) {
            if (haystack[i] == needle[0] && i + needleLen <= haystackLen) {
                int index = i;
                for (int j = 0; j < needleLen; j++) {
                    if (haystack[i + j] != needle[j]) {
                        index = -1;
                        break;
                    }
                }
                if (index != -1)
                    return index;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        const int N = haystack.size() - needle.size() + 1;
        for (int i = 0; i < N; ++i) {
            int j = i;
            int k = 0;
            while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if (k == needle.size()) return i;
        }
        return -1;
    }
};
