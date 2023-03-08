#include <stdio.h>

long long signed_min(int bitwidth){
    //2^8 =256
    // -128 ~ 127
    long long tmp=1;
    for(int i=0;i<bitwidth/2;i++){
        tmp=tmp<<2;
    }
//    long long pos = tmp/2-1;
    long long neg = tmp/2 *-1;
    return neg;
}
long long signed_max(int bitwidth){
    long long tmp=1;
    for(int i=0;i<bitwidth/2;i++){
        tmp=tmp<<2;
    }
    long long pos = tmp/2-1;
//    long long neg = tmp/2 *-1;
    return pos;
}
long long sat_add(long long operand1, long long operand2, int bitwidth){
//    long long tmp=1;
//    for(int i=0;i<bitwidth;i++){
//        tmp=(operand1|operand2);
//    }
//    return tmp;
    int c = 0;
//        long long tmp=1;
//    for(int i=0;i<bitwidth;i++){
//        c = ((operand1 & operand2) <<1) ;
//        operand1 = operand1 ^ operand2;
//        operand2 = c;
//        }
//    return tmp;

    while(operand2 != 0){
        c = (((operand1 & operand2) & 0xff)<<1) ;
        operand1 = operand1 ^ operand2;
        operand2 = c;
    }

    return operand1;
}
long long sat_sub(long long operand1, long long operand2, int bitwidth){

}

//long long tr(int bitwidth){
//
//}

int main() {
//    long long signed_min(int bitwidth);
    long long a = signed_min(8);
//    long long signed_max(int bitwidth);
    long long b = signed_max(8);
//    long long sat_add(long long operand1, long long operand2, int bitwidth);
    int c = sat_add(125, 5, 8);
    long long sat_sub(long long operand1, long long operand2, int bitwidth);
//    long long tr(8);

    printf("min: %d\t0x%016llx\n", a, a);
    printf("max: %d\t0x%016llx\n", b, b);
    printf("%d", c);

}