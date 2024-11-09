class Solution {
public:
    long minEnd(int n, int x) {
        long a = x;
        while (--n > 0)  // we will run the loop till n-1
            a = (a + 1) | x; // each time we will add '1' to 'a' and 'or' with 'x'
        
        return a;
    }
};
