class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = (n+m)*mean;

        for(int i=0; i<m; i++){
            sum -= rolls[i];
        }

        if(sum<n || n*6<sum){
            return {};
        }

        else{
            int distributeMean = sum / n;
            int mod = sum % n; //remaining elements magnitude
            // Distribute the remaining mod elements in nElements array.
            vector<int> ans(n, distributeMean);
            for (int i = 0; i < mod; i++) {
                ans[i]++;
                // as we are adding only 1 each time so the numbers will never get > 6
            }
            return ans;
        }
    }
};