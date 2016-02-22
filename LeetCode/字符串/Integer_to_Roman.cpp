class Solution {
public:
    string intToRoman(int num) {
        const string table[4][10] = {
            "0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
            "0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
            "0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
            "0", "M", "MM", "MMM"
        };
        int one = num % 10; num /= 10;
        int ten = num % 10; num /= 10;
        int hundred = num % 10; num /= 10;
        int thousand = num % 10;
        string result = "";
        result += table[3][thousand] == "0" ? "" : table[3][thousand];
        result += table[2][hundred] == "0" ? "" : table[2][hundred];
        result += table[1][ten] == "0" ? "" : table[1][ten];
        result += table[0][one] == "0" ? "" : table[0][one];
        return result;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string roman;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / radix[i];
            num %= radix[i];
            for (; count > 0; --count) roman += symbol[i];
        }
        return roman;
    }
};
