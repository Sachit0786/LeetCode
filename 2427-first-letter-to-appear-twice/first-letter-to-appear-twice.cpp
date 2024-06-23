class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> count(26,0);
        int n = s.length();
        char ans = 'a';

        for(int i=0; i<n; i++)
        {
            count[s[i]-'a']++;
            int j;
            for(j=0; j<26; j++)
            {
                if(count[j]==2)
                break;
            }
            if(j<26)
            {
                ans += j;
                break;
            }
        }
        return ans;
    }
};