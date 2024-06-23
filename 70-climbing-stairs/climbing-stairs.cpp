class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
        return 1;

        int t1 = 1, t2 = 1;
        int fibo = 0;
        for(int i=2; i<=n; i++)
        {
            fibo = t1+t2;
            t1 = t2;
            t2 = fibo;
        }
        return fibo;
    }
};