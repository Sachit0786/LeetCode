class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        else if(s1==s2)
            return true;    
        
        int first_idx = -1, second_idx = -1;

        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                if(first_idx==-1){
                    first_idx = i;
                }
                else if(second_idx==-1){
                    second_idx = i;
                }
                else{
                    return false;
                }
            }
        }
        if(first_idx!=-1 && second_idx!=-1){
            if(s1[first_idx]==s2[second_idx] && s2[first_idx]==s1[second_idx])
                return true;
            else
                return false;
        }   
        return false; 
    }
};