class Solution {
public:
    //If a sorted array is rotated then in that case the total number of inversion is always
    //less than 1, thus contributing to idea of this approach, because starting form that pair
    //if we rotate the further elements we get the required sorted array.
    bool check(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        if (n <= 1) return true;  // An empty or single-element array is always sorted

        int inversionCount = 0;  // Counter to track the number of inversions

        // Loop through the array to count inversions
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {  // Check if the current element is smaller than the 
                                            //previous one
                ++inversionCount;  // Increment inversion count
            }
        }

        // Check the circular rotation condition (last element compared to first element)
        if (nums[0] < nums[n - 1]) {
            ++inversionCount;
        }

        // The array can be sorted by at most one rotation if there is at most one inversion
        return inversionCount <= 1;
    }
};
