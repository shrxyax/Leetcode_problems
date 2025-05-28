class Solution {
public:
    int divide(int a1, int b1) 
    {
        
        if (b1 == 0) return INT_MAX; // Division by zero protection
        
        //only case where dividing two int can cause overflow
        if (a1 == INT_MIN && b1 == -1) return INT_MAX; // Overflow case

        // Convert to long long to handle abs(INT_MIN)
        long long a = abs((long long)a1);
        long long b = abs((long long)b1);

        bool sign = (a1 > 0 && b1 < 0) || (a1 < 0 && b1 > 0);

        long long quotient = 0;
        int i = 0;

        //quotient adds the greatest bit of the quotient(2^2 + 2^1 + 2^0)
        while (a >= b) {
            while ((b << i) <= a) {
                i++;
            }
            quotient += 1LL << (i - 1);
            a -= b << (i - 1);
            i = 0;
        }

        // Apply sign
        if (sign) quotient = -quotient;

        // Clamp result within 32-bit signed int range
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
