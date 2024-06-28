class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long result = 0;
        vector<int> cities(n);
        for(vector<int> road : roads){
            cities[road[0]]++;
            cities[road[1]]++;
        }
        sort(cities.begin(),cities.end());
        int temp = n;
        for(int i=n-1; i>=0; i--){
            result += (long long)cities[i]*temp;
            temp--;
        }
        return result;
    }
};