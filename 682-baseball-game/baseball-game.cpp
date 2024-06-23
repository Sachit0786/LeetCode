class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        vector<int> vect;
        int size = 0;
        int n = operations.size();
        for(int i=0; i<n; i++)
        {
            if(size>0 && operations[i] == "C")
            {
                vect.pop_back();
                size--;
            }
            else if(size>0 && operations[i] == "D")
            {
                vect.push_back(0);
                vect[size] = 2*vect[size-1];
                size++;
            }
            else if(size>1 && operations[i] == "+") 
            {
                vect.push_back(0);
                vect[size] = vect[size-1] + vect[size-2];
                size++;
            }   
            else
            {
                vect.push_back(stoi(operations[i]));
                size++;
            }      
        }

        for(int i=0; i<size; i++)
        {
            ans += vect[i];
        }
        
        return ans;
    }
};