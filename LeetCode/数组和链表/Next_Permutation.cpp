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

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; i++)
            s[i] += i + 1;
        
        return kth_permutation(s, k);
    }
    
private:
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++)
            result *= i;
        return result;
    }
    
    template<typename Sequence>
    Sequence kth_permutation(const Sequence &seq, int k) {
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;
        
        int base = factorial(n - 1);
        k--;
        
        for (int i = n - 1; i > 0; k %= base, base /= i, i--) {
            auto a = next(S.begin(), k / base);
            result.push_back(*a);
            S.erase(a);
        }
        
        result.push_back(S[0]);
        return result;
    }
};
