class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int temp = strs[0].length();
        for(int j=0; j<strs.size()-1; j++)
        {
            int i=0;
            while(i<temp)
            {
                if(strs[j][i] == strs[j+1][i])
                i++;

                else
                break;
            }
            temp = i;
            if(temp<1)
                return ans;
        }
        ans  = ans + strs[0].substr(0,temp);
        return ans;
    }
};