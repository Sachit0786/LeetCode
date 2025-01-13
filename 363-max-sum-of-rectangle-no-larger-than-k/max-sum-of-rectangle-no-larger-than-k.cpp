class Solution {
public:
    // Function to find the maximum subarray sum less than or equal to `k` without
    //using `lower_bound`
    int findMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int currentSum = 0;

        // A set to store prefix sums
        set<int> prefixSums;
        prefixSums.insert(0); 
        // Insert 0 to handle cases where currentSum == k

        for (int i = 0; i < n; ++i) {
            currentSum += nums[i]; 
            // Update the cumulative sum

            // Iterate through the set to find the 
            // smallest prefix sum >(currentSum - k)
            int closestSum = INT_MAX;
            for (int prefixSum : prefixSums) {
                if (prefixSum >= currentSum - k) {
                    closestSum = min(closestSum, prefixSum);
                }
            }

            // If a valid prefix sum is found, update the maximum sum
            if (closestSum != INT_MAX) {
                maxSum = max(maxSum, currentSum - closestSum);
            }

            // Insert the current cumulative sum into the set
            prefixSums.insert(currentSum);
        }

        return maxSum;
    }

    // Function to find the maximum sum of a submatrix with 
    // sum less than or equal to `k`
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSum = INT_MIN;

        // Fix two rows and calculate the column sums between them
        for (int startRow = 0; startRow < rows; ++startRow) {
            vector<int> columnSums(cols, 0); // Stores the cumulative column sums

            for (int endRow = startRow; endRow < rows; ++endRow) {
                // Update column sums for the current pair of rows
                for (int col = 0; col < cols; ++col) {
                    columnSums[col] += matrix[endRow][col];
                }

                // Find the maximum subarray sum in columnSums that is <= k
                int currentMax = findMaxSubarraySum(columnSums, k);

                // Update the global maximum sum
                maxSum = max(maxSum, currentMax);
            }
        }

        return maxSum;
    }
};
