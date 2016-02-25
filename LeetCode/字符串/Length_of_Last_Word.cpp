class Solution {
public:
    int lengthOfLastWord(string s) {
        while (!s.empty() && s.back() == ' ') s.pop_back();
        auto rItr = find(s.rbegin(), s.rend(), ' ');
        return distance(s.rbegin(), rItr);
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
    auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
    auto last = find_if_not(first, s.rend(), ::isalpha);
    return distance(first, last);
    }
};
