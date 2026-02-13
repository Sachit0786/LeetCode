int reverse(int x){
    int32_t reverse = 0;
    while(x!=0){
        short int digit = x%10;

        // Check overflow before multiplying
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10) {
            return 0;   // overflow case
        }

        reverse = reverse*10 + digit;
        x /= 10;
    }
    return reverse;
}