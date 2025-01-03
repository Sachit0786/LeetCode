class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> forwardSum(n-1);
        vector<long long> backwardSum(n-1);
        long long sum = 0;
        int count = 0;

        for(int i=0; i<n; i++)
            sum += nums[i];

        for(int i=0; i<n-1; i++){
            if(i==0)
                forwardSum[i] = nums[i];
            else    
                forwardSum[i] = forwardSum[i-1] + nums[i];

            backwardSum[i] = sum - forwardSum[i];

            if(forwardSum[i] >= backwardSum[i])
                count++;    
        }

        return count;    
    }
};