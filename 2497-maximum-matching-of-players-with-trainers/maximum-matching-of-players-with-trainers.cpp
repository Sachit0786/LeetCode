class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int playersIndex = 0;
        int trainersIndex = 0;
        while(playersIndex<players.size() && trainersIndex<trainers.size()){
            if(players[playersIndex]<=trainers[trainersIndex])
                playersIndex++;
            trainersIndex++;    
        }
        return playersIndex;
    }
};