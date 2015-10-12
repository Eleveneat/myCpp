#1009. Mersenne Composite N

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

One of the world-wide cooperative computing tasks is the "Grand Internet Mersenne Prime Search" -- GIMPS -- striving to find ever-larger prime numbers by examining a particular category of such numbers.   
A Mersenne number is defined as a number of the form (2p–1), where p is a prime number -- a number divisible only by one and itself. (A number that can be divided by numbers other than itself and one are called "composite" numbers, and each of these can be uniquely represented by the prime numbers that can be multiplied together to generate the composite number — referred to as its prime factors.)   
Initially it looks as though the Mersenne numbers are all primes.   
Prime	Corresponding Mersenne Number  
2	4–1 = 3 -- prime  
3	8–1 = 7 -- prime  
5	32–1 = 31 -- prime  
7	128–1 = 127 -- prime  
If, however, we are having a "Grand Internet" search, that must not be the case.   
Where k is an input parameter, compute all the Mersenne composite numbers less than 2k -- where k <= 63 (that is, it will fit in a 64-bit signed integer on the computer). In Java, the "long" data type is a signed 64 bit integer. Under gcc and g++ (C and C++ in the programming contest environment), the "long long" data type is a signed 64 bit integer.  
##Input

Input is from file a. in. It contains a single number, without leading or trailing blanks, giving the value of k. As promised, k <= 63.

##Output

One line per Mersenne composite number giving first the prime factors (in increasing order) separate by asterisks, an equal sign, the Mersenne number itself, an equal sign, and then the explicit statement of the Mersenne number, as shown in the sample output. Use exactly this format. Note that all separating white space fields consist of one blank.

##Sample Input

31
##Sample Output

23 * 89 = 2047 = ( 2 ^ 11 ) - 1  
47 * 178481 = 8388607 = ( 2 ^ 23 ) - 1  
233 * 1103 * 2089 = 536870911 = ( 2 ^ 29 ) - 1