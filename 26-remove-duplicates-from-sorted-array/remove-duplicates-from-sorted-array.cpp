class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int end = 1;

        while(end < nums.size()){
            while(end < nums.size() && nums[end-1]==nums[end]){
                end++;
            }
            if(end < nums.size())
                nums[++start] = nums[end];
            end++;class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1,i=0,j=0;
        vector<int>ans;
        ans.push_back(nums[0]);
        while(i<nums.size() && j<nums.size()){
            if(nums[i]==nums[j]) {
                j++;
            }else{
                cnt++;
                ans.push_back(nums[j]);
                i=j;
                
                       }
        }
        nums=ans;

        return cnt;
    }
};
        }
        return start+1;
    }
};