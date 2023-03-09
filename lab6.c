#include <stdio.h>

long long signed_min(int bitwidth) {
    long long tmp = 1;
    for (int i = 0; i < bitwidth / 2; i++) {
        tmp = tmp << 2;
    }
    long long neg = tmp / 2 * -1;
    return neg;
}

long long signed_max(int bitwidth) {
    long long tmp = 1;
    for (int i = 0; i < bitwidth / 2; i++) {
        tmp = tmp << 2;
    }
    long long pos = tmp / 2 - 1;
    return pos;
}

long long sat_add(long long operand1, long long operand2, int bitwidth) {
    int tmp = 2;
    for (int i = 1; i < bitwidth; i++) {
        tmp = tmp * 2;
    }
    tmp = tmp - 1;
    int ttt = tmp/2;
    int c = 0;

    while (operand2 != 0) {
        c = (((operand1 & operand2) & tmp) << 1);
        operand1 = operand1 ^ operand2;
        operand2 = c;
    }
//    while (operand2 != 0) {
//        c = (((operand1 & operand2) & 0xff) << 1);
//        operand1 = operand1 ^ operand2;
//        operand2 = c;
//    }

    return operand1 & (tmp/2);
}

long long sat_sub(long long operand1, long long operand2, int bitwidth) {
    int neg1 = 0;
    int neg2 = 0;
    int tmp = 2;
    int c = 0;

    for (int i = 1; i < bitwidth; i++) {
        tmp = tmp * 2;
    }
    int tmp2 = tmp - 1;

//    if (operand1 < 0 && operand2 > 0) {
//        neg1 = tmp + operand1;
//        neg2 = operand2;
//        while (neg2 != 0) {
//            c = (((neg1 & neg2) & tmp2) << 1);
//            neg1 = neg1 ^ neg2;
//            neg2 = c;
//        }
//        return neg1 - tmp;
//    } else if (operand1 > 0 && operand2 < 0) {
//        neg1 = operand1;
//        neg2 = tmp + operand2;
//        while (neg2 != 0) {
//            c = (((neg1 & neg2) & tmp2) << 1);
//            neg1 = neg1 ^ neg2;
//            neg2 = c;
//        }
//        return neg1 - tmp;
//    } else if (operand1 < 0 && operand2 < 0) {
//        neg1 = tmp + operand1;
//        neg2 = tmp + operand2;
//        while (neg2 != 0) {
//            c = (((neg1 & neg2) & tmp2) << 1);
//            neg1 = neg1 ^ neg2;
//            neg2 = c;
//        }
//        return neg1 - tmp*2;
//    }

    neg1 = tmp + operand1;
    neg2 = tmp + operand2;
    while (neg2 != 0) {
        c = (((neg1 & neg2) & tmp2) << 1);
        neg1 = neg1 ^ neg2;
        neg2 = c;
    }
    return neg1 - tmp * 2;

}


int main() {
    long long a = signed_min(8);
    long long b = signed_max(8);
    int c = sat_add(125, 5, 8);
    int d = sat_sub(125, -22, 8);

    printf("min: %d\t0x%016llx\n", a, a);
    printf("max: %d\t0x%016llx\n", b, b);
    printf("%d\n", c);
    printf("%d\n", d);

}