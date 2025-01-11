class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.length()==1) return 1;
        
        int n = s.length();
        int start = 0;
        int end = 1;
        int max_length = 1;
        
        vector<int> location(256,-1);
        location[s[0]] = 0;
        
        while(end < n){
            if(location[s[end]]!=-1)
                if(location[s[end]]>=start)
                    start = location[s[end]]+1;
            location[s[end]] = end;
            int curr_length = end-start+1;
            max_length = max(max_length,curr_length);
            end++;    
        }
        return max_length;
    }
};