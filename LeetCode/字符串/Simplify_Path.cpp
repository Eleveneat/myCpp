class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        size_t len = path.size();
        path += "/";
        for (int i = 0; i < len; i++) {
            if (path[i] == '/') continue;
            int j = path.find('/', i);
            string str = path.substr(i, j - i);
            i = j;
            if (str == "..") {
                if (!s.empty()) s.pop();
            } else if (str == ".") {
                NULL;
            } else {
                str = "/" + str;
                s.push(str);
            }
        }
        if (s.empty()) return "/";
        string result("");
        while (!s.empty()) {
            result = s.top() + result;
            s.pop();
        }
        return result;
    }
};
