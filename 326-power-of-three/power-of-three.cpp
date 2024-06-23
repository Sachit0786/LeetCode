class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        while(n%3 == 0){
            n /= 3;
        }
        return n==1;  
    }
};

// also look the recursive and mathematical approach(1162261467) in the c++ solutions