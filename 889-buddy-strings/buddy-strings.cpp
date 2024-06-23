class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        if(s==goal)
        {
            unordered_map<char,int> u;
            for(auto x:s)
                u[x]++;
            for(auto i:u)
            {
                if(i.second>1)
                    return true;
            }    
            return false;
        }
        
        int fi = -1; 
        int si = -1;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != goal[i])
            {
                if(fi == -1)
                    fi = i;
                else if(si == -1)
                    si = i;
                else
                    return false;        
            }
        }
        if((fi != -1) && (si != -1))
        {
            if((s[fi] == goal[si]) && (s[si] == goal[fi]))
                return true;
            else
                return false;    
        }
        return false;
    }
};