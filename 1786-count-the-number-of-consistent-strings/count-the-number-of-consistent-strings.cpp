class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allow;
        int count=0;
        bool flag = false;
        for(char& letter : allowed){
            allow.insert(letter);
        }
        for(string& word : words){
            flag = false;
            for(char& letter : word){
                if(!(allow.count(letter))){
                    flag = true;
                    break;
                }
            }
            if(flag==true){
                continue;
            }
            count++;
        }
        return count;
    }
};