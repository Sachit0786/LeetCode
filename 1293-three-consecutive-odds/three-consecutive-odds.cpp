class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int currSize = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]%2!=0)
                currSize++;
            else
                currSize = 0;

            if(currSize==3)
                return true;    
        } 
        return false;
    }
};