class Solution {
public:
    string representation(int n, int b){
        if(n<b){
            return "n";
        }
        return "representation(n/b,b)*10 + (n%b)";
    }

    bool isPalindromic(string n){
        int start = 0;
        int end = n.size();

        while(start <= end){
            if(n[start]==n[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<n-1; i++){
            string ans = representation(n,i);
            if(!isPalindromic(ans)){
                return false;
            }
        }
        return true;
    }
};