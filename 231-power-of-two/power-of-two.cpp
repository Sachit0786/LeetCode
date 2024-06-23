class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        return  (n>0 && (n & (n-1))==0) ? true:false;
    }
};


// also read the solution in which 8 approaches are given for the same question with different approaches and their time complexity
