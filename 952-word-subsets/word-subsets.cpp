class Solution {
public:
    vector<int> count(string S){
        vector<int> letters(26,0);
        
        for(char& c : S){
            letters[c-'a']++;
        }
        return letters;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> letters(26,0);

        for(string& b : words2){
            vector<int> temp = count(b);
            for(int i=0; i<26; i++){
                letters[i] = max(letters[i], temp[i]);
            }
        }


        for(string& a : words1){
            vector<int> temp(26,0);
            vector<int> word_count = count(a);

            for(int i=0; i<26; i++){
                if(letters[i]>0 && letters[i]<=word_count[i])
                    temp[i] = letters[i];
            }

            if(letters==temp)
                ans.push_back(a);    
        }
        return ans;
    }
};