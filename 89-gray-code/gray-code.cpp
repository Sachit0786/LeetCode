class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> grey;
        // "num = pow(2,n)" is same as "num = 1 << n"
        for(int i=0; i<(1<<n); i++){
            grey.push_back(i ^ (i>>1));
        }
        return grey;
    }
};