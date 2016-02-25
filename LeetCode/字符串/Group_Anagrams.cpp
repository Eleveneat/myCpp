class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        for (auto str : strs) {
            string anagram = str;
            sort(anagram.begin(), anagram.end());
            m[anagram].push_back(str);
        }
        for (auto itr = m.begin(); itr != m.end(); itr++)
            sort(itr->second.begin(), itr->second.end());
        vector<vector<string>> result;
        for (auto itr = m.begin(); itr != m.end(); itr++)
            result.push_back(itr->second);
        return result;
    }
};
