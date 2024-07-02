class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        unordered_map<int,int> visited;
        for(int i=0; i<nums1.size(); i++){
            visited[nums1[i]]++;
        }
        for(auto& test : visited){
            cout<<test.first<<" "<<test.second<<"\n";
        }

        for(int i=0; i<nums2.size(); i++){
            if(visited.find(nums2[i])!=visited.end() && visited[nums2[i]]){
                ans.push_back(nums2[i]);
                visited[nums2[i]]--;
            }
        }

        return ans;
    }
};