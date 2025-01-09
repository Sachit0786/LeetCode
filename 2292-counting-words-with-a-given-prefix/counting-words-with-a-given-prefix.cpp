class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int count = 0;

        for(string &s : words){
            if(n>s.length())
                continue;
            if( pref+s.substr(n,s.length()-n) == s )
                count++;
        }
        return count;
    }
};