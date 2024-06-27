class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> count;
        for(vector<int> node : edges){
            count[node[0]]++;
            count[node[1]]++;
        }

        for(pair<int,int> node : count){
            if(node.second==edges.size())
                return node.first;
        }
        return -1;
    }
};