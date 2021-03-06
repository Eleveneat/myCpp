
class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
            INVALID,//0
            SPACE,//1
            SIGN,//2
            DIGIT,//3
            DOT,//4
            EXPONENT,//5
            NUM_INPUTS//6
        };
        const int transitionTable[][NUM_INPUTS] = {
            -1, 0, 3, 1, 2, -1,
            -1, 8, -1, 1, 4, 5,
            -1, -1, -1, 4, -1, -1,
            -1, -1, -1, 1, 2, -1,
            -1, 8, -1, 4, -1, 5,
            -1, -1, 6, 7, -1, -1,
            -1, -1, -1, 7, -1, -1,
            -1, 8, -1, 7, -1, -1,
            -1, 8, -1, -1, -1, -1,
        };
        int state = 0;
        for (auto ch : s) {
            InputType inputType = INVALID;
            if (isspace(ch))
                inputType = SPACE;
            else if (ch == '+' || ch == '-')
                inputType = SIGN;
            else if (isdigit(ch))
                inputType = DIGIT;
            else if (ch == '.')
                inputType = DOT;
            else if (ch == 'e' || ch == 'E')
                inputType = EXPONENT;
            state = transitionTable[state][inputType];
            if (state == -1) return false;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};


class Solution {
public:
    bool isNumber(string s) {
        return isNumber(s.c_str());
    }
private:
    bool isNumber(char const *s) {
        char* endptr;
        strtod(s, &endptr);
        
        if (endptr == s) return false;
        
        for (; *endptr; ++endptr)
            if (!isspace(*endptr)) return false;
        
        return true;
    }
};
