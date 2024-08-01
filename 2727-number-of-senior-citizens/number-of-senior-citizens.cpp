class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto element : details){
            if((element[11]-'0')*10 + (element[12]-'0')>60)
                count++;
        }
        return count;
    }
};