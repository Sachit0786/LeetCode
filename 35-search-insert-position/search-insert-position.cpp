class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int si = 0, ei = nums.size()-1;
        int mid = 0;
        while(si<=ei)
        {
            mid = si + (ei - si)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) si = mid+1;
            else ei = mid-1;
        }
        return si;
    }
};