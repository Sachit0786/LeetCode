class Solution {
public:
    // Function to check if a given `mid` can be the maximum sum for k subarrays
    int check(int mid, vector<int>& nums, int k) {
        int curr = 0; // Current sum of the ongoing subarray
        int cnt = 0;  // Number of subarrays formed
        
        for (int i = 0; i < nums.size(); i++) {
            if (curr >= nums[i]) {
                // If the current subarray can accommodate nums[i], include it
                curr -= nums[i];
            } else {
                // Otherwise, start a new subarray
                cnt++;
                curr = mid - nums[i];
            }
            // If the number of subarrays exceeds k, it's not a valid solution
            if (cnt > k) return 0;
        }
        return (cnt <= k); // Return 1 if the division is possible, else 0
    }

    // Function to find the minimum largest sum among k subarrays
    int splitArray(vector<int>& nums, int k) {
        int lo = 0; // Minimum possible largest sum (largest element in nums)
        int hi = 0; // Maximum possible largest sum (sum of all elements)
        
        for (auto i : nums) {
            lo = max(lo, i); // Update lo to the max element
            hi += i;         // Calculate the total sum of the array
        }

        int ans = 0; // Variable to store the answer

        // Binary search to find the minimum largest sum
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // Middle value as a candidate largest sum
            if (check(mid, nums, k)) {
                // If `mid` is valid, it might be the answer; try smaller values
                ans = mid;
                hi = mid - 1;
            } else {
                // If `mid` is not valid, try larger values
                lo = mid + 1;
            }
        }

        return ans; // Return the minimum largest sum
    }
};