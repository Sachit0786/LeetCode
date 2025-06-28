class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: Store each element with its index
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({i, nums[i]});
        }

        // Step 2: Sort by value in descending order to get largest values first
        sort(indexedNums.begin(), indexedNums.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });

        // Step 3: Pick the first k elements (which have the largest values)
        vector<pair<int, int>> topK(indexedNums.begin(), indexedNums.begin() + k);

        // Step 4: Sort these k elements by their original index to keep order
        sort(topK.begin(), topK.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });

        // Step 5: Collect the values into result
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(topK[i].second);
        }

        return result;
    }
};