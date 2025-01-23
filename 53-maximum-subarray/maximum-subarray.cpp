class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maximum = INT_MIN;
        int curr_maximum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            curr_maximum = max(nums[i],sum);   
            if(sum<nums[i])
                sum = nums[i];
            maximum = max(curr_maximum,maximum);
        }
        return maximum;
    }
};