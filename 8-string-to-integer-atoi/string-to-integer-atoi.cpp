class Solution {
public:
    int myAtoi(string s) {
        if(s.empty())
        {
            return 0;
        }
        int length = s.length();
        int sign = 1;
        int i = 0;

        while(i<length && s[i]==' ')
        {
            i++;
        }

        if(i==length)
        {
            return 0;
        }

        if(s[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }

        long int ans = 0;

        while(s[i]>='0' && s[i]<='9')
        {
            ans *= 10;
            if(ans>=INT_MAX || ans<=INT_MIN)
            {
                break;
            }
            ans = ans + (s[i]-'0');
            i++;
        }
        ans *= sign;

        if(ans<=INT_MIN)
        return INT_MIN;
        
        if(ans>=INT_MAX)
        return INT_MAX;

        return ans;
    }
};