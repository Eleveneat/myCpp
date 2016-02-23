class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (n--; n > 0; n--) {
            string newResult = "";
            int len = result.size();
            for (int i = 0; i < len; i++) {
                char digit = result[i];
                int count = 0;
                while (result[i] == digit) {
                    count++; i++;
                }
                char duplicateNum = '0' + count;
                newResult += duplicateNum;
                newResult += digit;
                i--;
            }
            result = newResult;
        }
        return result;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        while (--n)
            s = getNext(s);
        return s;
    }
    string getNext(const string &s) {
        stringstream ss;
        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }
};
