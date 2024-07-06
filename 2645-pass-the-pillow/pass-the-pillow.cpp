class Solution {
public:
    int passThePillow(int n, int time) {
            int cycle = 2*(n - 1);
    int element = time % cycle;
    return element < n ? (element + 1) : (n - 1 - element % n);
    }
};