#include <stdio.h>
#include <stdbool.h>

// bit operation in C language
// mask type
#define OPC_BITWISE_AND  0x00
#define OPC_BITWISE_OR   0x01
#define OPC_BITWISE_XOR  0x02
// specified bit type
#define OPC_BITWISE_SHF  0x03
#define OPC_BITWISE_SET  0x04
#define OPC_BITWISE_CLR  0x05 
#define OPC_BITWISE_TGL  0x06
#define OPC_BITWISE_CHK  0x07
#define OPC_BITWISE_UPD  0x08
// self-handling type
#define OPC_BITWISE_NOT  0x09
#define OPC_BITWISE_RVS  0x0A
#define OPC_SWP_ODD_EVN  0x0B
#define OPC_CHK_POW_TWO  0x0C
// count type
#define OPC_CNT_BRI_KNH  0x0D
#define OPC_CNT_HAMMING  0x0E

#define BITWISE_AND(num, mask)       ((num) & (mask))
#define BITWISE_OR(num, mask)        ((num) | (mask))
#define BITWISE_XOR(num, mask)       ((num) ^ (mask))

#define BITWISE_L_SHF(num, shift)    ((num) << (shift))
#define BITWISE_R_SHF(num, shift)    ((num) >> (shift))
#define BITWISE_SET(num, bit)        ((num) | (1 << (bit)))
#define BITWISE_CLR(num, bit)        ((num) & ~(1 << (bit)))
#define BITWISE_TGL(num, bit)        ((num) ^ (1 << (bit)))
#define BITWISE_CHK(num, bit)        (((num) >> (bit)) & 1)
#define BITWISE_UPD(num, bit, value) (((num) & ~(1 << (bit))) | ((value) << (bit)))

#define BITWISE_NOT(num)             (~(num))
#define BITWISE_RVS(num)             reverse_bits(num)
#define SWP_ODD_EVN(num)             swap_odd_even_bits(num)
#define CHK_POW_TWO(num)             ((num) && !((num) & ((num) - 1)))

// reverse bits of a number
unsigned int reverse_bits(unsigned long long num) {
    unsigned int reversed = 0;
    while (num) {
        reversed <<= 1;
        reversed |= num & 1;
        num >>= 1;
    }
    return reversed;
}

// reverse bits of a number by swapping nibbles
unsigned long long reverse_bits_by_swapping_nibbles(unsigned long long num) {
    unsigned long long patterns_1[] = {0x5555555555555555,
                                       0x3333333333333333,
                                       0x0F0F0F0F0F0F0F0F,
                                       0x00FF00FF00FF00FF,
                                       0x0000FFFF0000FFFF,
                                       0x00000000FFFFFFFF};
    unsigned long long patterns_2[] = {0xAAAAAAAAAAAAAAAA,
                                       0xCCCCCCCCCCCCCCCC,
                                       0xF0F0F0F0F0F0F0F0,
                                       0xFF00FF00FF00FF00,
                                       0xFFFF0000FFFF0000,
                                       0xFFFFFFFF00000000};
    for(int i = 0; i < 6; i++) {
        num = (num & patterns_1[i]) << (1 << i) | (num & patterns_2[i]) >> (1 << i);
    }
}

// swap odd and even bits
unsigned int swap_odd_even_bits(unsigned long long num) {
    return ((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1);
}

// count number of set bits
unsigned int count_set_bits(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// count number of set bits using Brian Kernighan's algorithm
unsigned int count_set_bits_brian_kernighan(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        num &= num - 1;
        count++;
    }
    return count;
}

// count number of set bits using hamming weight
// It uses 24 arithmetic operations
// Ref: https://zh.wikipedia.org/zh-tw/%E6%B1%89%E6%98%8E%E6%9D%83%E9%87%8D
unsigned long long pop_count_1(unsigned long long num) {
    unsigned long long fixed_patterns[6] = {0x5555555555555555, 
                                            0x3333333333333333,
                                            0x0F0F0F0F0F0F0F0F,
                                            0x00FF00FF00FF00FF,
                                            0x0000FFFF0000FFFF,
                                            0x00000000FFFFFFFF};

    for(int i = 0; i < 6; i++) {
        num = (num & fixed_patterns[i]) + ((num >> (1<<i)) & fixed_patterns[i]);
    }
    return num;
}

// count number of set bits using hamming weight
// It uses 17 arithmetic operations, implementation on machines with slow multiplication.
unsigned long long pop_count_2(unsigned long long num) {
    unsigned long long fixed_patterns[3] = {0x5555555555555555, 
                                            0x3333333333333333,
                                            0x0F0F0F0F0F0F0F0F};
    num -= (num >> 1) & fixed_patterns[0];             //put count of each 2 bits into those 2 bits
    num = (num & fixed_patterns[1]) + ((num >> 2) & fixed_patterns[1]); //put count of each 4 bits into those 4 bits 
    num = (num + (num >> 4)) & fixed_patterns[2];        //put count of each 8 bits into those 8 bits 
    num += num >>  8;  //put count of each 16 bits into their lowest 8 bits
    num += num >> 16;  //put count of each 32 bits into their lowest 8 bits
    num += num >> 32;  //put count of each 64 bits into their lowest 8 bits
    return num & 0xff;
}

// count number of set bits using hamming weight
// It uses 12 arithmetic operations, implementation on machines with fast multiplication.
unsigned long long pop_count_3(unsigned long long num) {
    unsigned long long fixed_patterns[4] = {0x5555555555555555, 
                                            0x3333333333333333,
                                            0x0F0F0F0F0F0F0F0F,
                                            0x0101010101010101};
    num -= (num >> 1) & fixed_patterns[0];             //put count of each 2 bits into those 2 bits
    num = (num & fixed_patterns[1]) + ((num >> 2) & fixed_patterns[1]); //put count of each 4 bits into those 4 bits 
    num = (num + (num >> 4)) & fixed_patterns[2];        //put count of each 8 bits into those 8 bits 
    return (num * fixed_patterns[3])>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}

int main() {
    int specified_bit = 64;
    unsigned long long num, mask, result;
    unsigned int opcode;
    unsigned char value;
    bool chk_2_pwr;

    printf("Plz enter long long number in hex: \n");
    scanf("%llx", &num);

    printf("Plz enter bit opcode in hex: \n");
    scanf("%x", &opcode);

    if(opcode <= OPC_BITWISE_XOR)
    {
        printf("Plz enter long long mask in hex: \n");
        scanf("%llx", &mask);
    }
    else if(opcode <= OPC_BITWISE_UPD)
    {
input_again:
        printf("Plz enter 0-based specified bit in dec: \n");
        if(opcode == OPC_BITWISE_SHF)
        {
            printf("[Dir] pos: left \n");
            printf("      neg: right\n");
        }
        scanf("%d", &specified_bit);
        if((specified_bit > 63) || ((specified_bit < -63) && (opcode == OPC_BITWISE_SHF)) || ((specified_bit < 0) && (opcode != OPC_BITWISE_SHF)))
        {
            printf("Invalid specified bit: %d \n", specified_bit);
            goto input_again;
        }
    }
    
    switch(opcode)
    {
        case OPC_BITWISE_AND:
            result = BITWISE_AND(num, mask);
            printf("Bitwise AND: 0x%llx\n", result);
            break;
        case OPC_BITWISE_OR:
            result = BITWISE_OR(num, mask);
            printf("Bitwise OR: 0x%llx\n", result);
            break;
        case OPC_BITWISE_XOR:
            result = BITWISE_XOR(num, mask);
            printf("Bitwise XOR: 0x%llx\n", result);
            break;
        case OPC_BITWISE_SHF:
            if(specified_bit < 0)
                result = BITWISE_R_SHF(num, (specified_bit^0xFFFFFFFF)+1);
            else
                result = BITWISE_L_SHF(num, specified_bit);
            printf("Bitwise Shift: 0x%llx\n", result);
            break;
        case OPC_BITWISE_SET:
            result = BITWISE_SET(num, specified_bit);
            printf("Bitwise SET: 0x%llx\n", result);
            break;
        case OPC_BITWISE_CLR: 
            result = BITWISE_CLR(num, specified_bit);
            printf("Bitwise CLR: 0x%llx\n", result);
            break;
        case OPC_BITWISE_TGL:
            result = BITWISE_TGL(num, specified_bit);
            printf("Bitwise TGL: 0x%llx\n", result);
            break;
        case OPC_BITWISE_CHK:
            result = BITWISE_CHK(num, specified_bit);
            printf("Bitwise CHK: 0x%llx\n", result);
            break;
        case OPC_BITWISE_UPD:
            printf("Plz enter value w/ 0 or 1: \n");
            scanf("%hhu", &value);
            if(value)
                value = 1;
            result = BITWISE_UPD(num, specified_bit, value);
            printf("Bitwise UPD: 0x%llx\n", result);
            break;
        case OPC_BITWISE_NOT:
            result = BITWISE_NOT(num);
            printf("Bitwise NOT: 0x%llx\n", result);
            break;
        case OPC_BITWISE_RVS:
            //result = reverse_bits(num);
            result = reverse_bits_by_swapping_nibbles(num);
            printf("Bitwise RVS: 0x%llx\n", result);
            break;
        case OPC_SWP_ODD_EVN:
            result = swap_odd_even_bits(num);
            printf("Bitwise SWP: 0x%llx\n", result);
            break;
        case OPC_CHK_POW_TWO:
            chk_2_pwr = CHK_POW_TWO(num);
            if(chk_2_pwr)
                printf("Bitwise CHK: 0x%llx is power of two\n", num);
            else
                printf("Bitwise CHK: 0x%llx is NOT power of two\n", num);
            break;
        case OPC_CNT_BRI_KNH:
            result = count_set_bits_brian_kernighan(num);
            printf("Bitwise CNT: 0x%llx has %llu set bits\n", num, result);
            break;
        case OPC_CNT_HAMMING:
            result = pop_count_3(num);
            printf("Bitwise CNT: 0x%llx has %llu set bits\n", num, result);
            break;
        default:
            printf("Invalid Opcode: 0x%x \n", opcode);
            return -1;
    }
    return 0;
}
