#笔记

1. Longest Palindromic Substring：动态规划和Manacher算法思想，不太熟练。
2. Length of Last Word：不太明白为什么`auto first = find_if(s.rbegin(), s.rend(), ::isalpha);`里第三个参数的`isalpha`函数要加上`::`？
3. String to Integer：对于`int`类型的溢出处理值得参考` if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) return isPositive ? INT_MAX : INT_MIN;
`
4. 在 STL 中，`下标访问[]`不检查边界，`at函数`才检查边界。