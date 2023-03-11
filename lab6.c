#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


long long signed_min(int bitwidth) {
    return LLONG_MIN >> (64 - bitwidth);
}

long long signed_max(int bitwidth) {
    return LLONG_MAX >> (64 - bitwidth);
}

long long sat_add(long long operand1, long long operand2, int bitwidth) {
    long long max_val = signed_max(bitwidth);
    long long min_val = signed_min(bitwidth);
    long long result = operand1 + operand2;
    int sign_bit = (result >> (bitwidth - 1)) & 0x01;
    int negative_bit = (result >> (bitwidth)) & 0x01;

    if (sign_bit == 1 && negative_bit == 0) {
        return max_val;
    } else if (negative_bit == 1 && sign_bit == 0) {
        return min_val;
    } else {
        return result;
    }
}


long long sat_sub(long long operand1, long long operand2, int bitwidth) {
    long long max_val = signed_max(bitwidth);
    long long min_val = signed_min(bitwidth);
    long long result = operand1 - operand2;

    int sign_bit = (result >> (bitwidth - 1)) & 0x01;
    int negative_bit = (result >> (bitwidth)) & 0x01;
    if (sign_bit == 1 && negative_bit == 0) {
        return max_val;
    } else if (negative_bit == 1 && sign_bit == 0) {
        return min_val;
    } else {
        return result;
    }

}


int main(int argc, char **argv) {
    int bit = atoi(argv[1]);
    if (argc == 2) {
        printf("%d-bit signed integer range\n", bit);
        printf("min: %lld\t0x%016llx\n", signed_min(bit), signed_min(bit));
        printf("max: %lld\t0x%016llx", signed_max(bit), signed_max(bit));
    } else {
        long long op1 = atoi(argv[2]);
        long long op2 = atoi(argv[3]);
        if (atoi(argv[4]) == 0) {
            printf("%s + %s = %lld", argv[2], argv[3], sat_add(op1, op2, bit));
        } else {
            printf("%s - %s = %lld", argv[2], argv[3], sat_sub(op1, op2, bit));
        }
    }
    return 0;
}