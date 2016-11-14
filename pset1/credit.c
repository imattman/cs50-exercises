#include <stdio.h>
#include <cs50.h>

// function prototype declarations
int is_valid(long long cc_num);
int sum_digits(int number);
int first_n_digits(int n, long long number);
int is_amex(long long cc_num);
int is_mc(long long cc_num);
int is_visa(long long cc_num);


int main(void) {
    printf("Number: ");
    long long cc_num = GetLongLong();
    
    if (!is_valid(cc_num))
    {
        printf("INVALID");
    }
    else if (is_amex(cc_num))
    {
        printf("AMEX");
    }
    else if (is_mc(cc_num))
    {
        printf("MASTERCARD");
    }
    else if (is_visa(cc_num))
    {
        printf("VISA");
    }
    else
    {
        printf("UNKNOWN");
    }
    
    printf("\n");
}

int is_valid(long long cc_num) {
    int luhn_sum = 0;
    
    long long remaining = cc_num; // remaining most-significant-digits

    // consume digits in reverse by repeatedly removing and processing the least significant digit
    for (int i = 0; remaining > 0; i++) {
        int digit = remaining % 10;

        // luhn digit multiplier of 2 for every other digit starting with second LSD
        int mult = 1;
        if (i % 2 == 1) {
            mult = 2; 
        }
        
        luhn_sum += sum_digits(digit * mult);
        remaining = remaining / 10;
    }

    return (luhn_sum % 10) == 0; // valid if last digit of sum is 0
}

int sum_digits(int n) {
    int sum = 0;
    int remaining = n;
    
    while (remaining > 0) {
        sum += remaining % 10;
        remaining = remaining / 10;
    }

    return sum;
}

int first_n_digits(int n, long long number) {
    // compute limit as power of 10 -- could use math libs for this
    int limit = 1; 
    for (int i = 0; i < n; i++) {
        limit = limit * 10;
    }

    long long msd = number; // most significant digits
    while (msd > limit) {
        msd = msd / 10;
    }

    // only need a couple of digits so it's safe to cast without data loss    
    return (int) msd; 
}

int is_amex(long long cc_num) {
    int pre = first_n_digits(2, cc_num);
    
    return (pre == 34) || 
           (pre == 37);
}

int is_mc(long long cc_num) {
    int pre = first_n_digits(2, cc_num);
    
    return (pre == 51) || 
           (pre == 52) ||
           (pre == 53) ||
           (pre == 54) ||
           (pre == 55);
}

int is_visa(long long cc_num) {
    int pre = first_n_digits(1, cc_num);
    
    return (pre == 4);
}
