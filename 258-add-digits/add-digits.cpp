class Solution {
public:
    int sol(int num)
    {
        if(num/10 == 0)
            return num;

        int sum = 0;
        while(num)
        {
            sum += (num%10);
            num /= 10;
        }             
        num = sum;
        return sol(num);    
    }

    int addDigits(int num) {
        return sol(num);
    }
};