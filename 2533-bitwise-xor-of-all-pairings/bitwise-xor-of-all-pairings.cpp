class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0 && nums2.size()%2==0)
            return 0;
        else if(nums1.size()%2==1 && nums2.size()%2==0){
            int ans = 0;
            for(int& a : nums2)
                ans ^= a;
            return ans;
        }
        else if(nums1.size()%2==0 && nums2.size()%2==1){
            int ans = 0;
            for(int& a : nums1)
                ans ^= a;
            return ans;
        }
        else{
            int ans = 0;
            for(int& a : nums1)
                ans ^= a;
            for(int& a : nums2)
                ans ^= a;    
            return ans;
        }
    }
};