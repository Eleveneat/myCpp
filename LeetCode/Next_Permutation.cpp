// 超时
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; i++)
            s[i] += i + 1;
        
        for (int i = 0; i < k - 1; i++) {
            next_permutation(s.begin(), s.end());
        }
        
        return s;
    }
};

// 超时again，不过貌似比上面快一点
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; i++)
            s[i] += i + 1;
        
        for (int i = 0; i < k - 1; i++) {
            next_permutation(s.begin(), s.end());
        }
        
        return s;
    }
    
    template<typename t>
    bool next_permutation(t first, t last) {
        if (first == last) return false;
        
        auto rFirst = reverse_iterator<t>(last);
        auto rLast = reverse_iterator<t>(first);
        
        auto pivot = next(rFirst);
        
        while (pivot != rLast && *pivot > *(pivot - 1))
            pivot++;
        
        if (pivot == rLast) {
            reverse(first, last);
            return false;
        }
        
        auto change = find_if(rFirst, pivot, bind1st(less<int>(), *pivot));
        
        swap(*change, *pivot);
        reverse(rFirst, pivot);
        
        return true;
    }
};
