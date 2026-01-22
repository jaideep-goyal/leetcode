class Solution {
public:
    int sumd(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }
        return sum;
    }
    int prodd(int n) {
        int product = 1;
        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            n /= 10;
        }
        return product;
    }
    bool checkDivisibility(int n) {
        if(n% (prodd(n)+sumd(n))==0){
            return true;
        }
        return false;
    }
};