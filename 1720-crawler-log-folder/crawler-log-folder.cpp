class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(int i=0; i<logs.size(); i++)
        {
            if(count == 0 && logs[i] == "../");
            //if we are in the main folder then remain in the same folder if 
            //we are calling for parent folder 

            //if count id=s greater than 0
            else
            {
                if(logs[i] == "../") count--;//move back to the parent folder
                else if(logs[i] == "./") ;//remain in the same folder 
                else count++;//move to the child folder
            }
        }
        
        return count;
    }
};