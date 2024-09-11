class Solution {
public:
    int countSetBits(int n)
    {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        return countSetBits(ans);
    }
};