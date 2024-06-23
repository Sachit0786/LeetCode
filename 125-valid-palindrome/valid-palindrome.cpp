class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()<=1)
        return true;

        int si = 0, ei = s.length()-1;
        while(si < ei)
        {
            while(si < ei && !isalnum(s[si]))
            si++;

            while(si < ei && !isalnum(s[ei]))
            ei--;

            if(si < ei && tolower(s[si]) != tolower(s[ei]))
            return false;

            si++;
            ei--;
        }
        return true;
    }
};