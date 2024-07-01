class Solution {
public:
    int findLUSlength(string a, string b) {
        int n = a.length();
        int m = b.length();

        if(a==b)
            return -1;
        else
            return max(n,m);    
    }
};