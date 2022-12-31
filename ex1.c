#include "ex1.h"

int is_big_endian() {
    /*
     * When creating an integer variable, and giving it the value 1,
     * there are 2 possible ways of it being represented in memory:
     *
     *          higher memory
     *            ------>
     * 1. 00000000 00000000 00000000 00000001 (little)
     * 2. 00000001 00000000 00000000 00000000 (big)
     * ,depending on the endianness.
     *
     * We can check which way is it, by pointing to the first
     * byte of the integer, and comparing the unsigned value to 0.
     */

    int x = 1;

    unsigned char* ptr = (unsigned char*) &x;

    return !(*ptr);
}

int get_sign_magnitude(bool bitArray[8]) {
    /*
     * In sign-magnitude representation, the MSB determines the number's sign.
     * Therefore, calculating the unsigned value of the first n-1 bits, and then adding a sign if
     * necessary is sufficient.
     */

    int res = 0, pow = 1, i;

    for (i = 0; i < 7; ++i) {
        res += bitArray[i] * pow;
        pow *= 2;
    }

    return bitArray[7] ? -res : res;
}

int get_two_comp(bool bitArray[8]) {
    /*
     * In two's complement representation, the value of the number represented
     * can be calculated taking the unsigned value of the first n-1 bits,
     * and subtracting the weight of the MSB from it.
     */

    int res = 0, pow = 1, i;

    for (i = 0; i < 7; ++i) {
        res += bitArray[i] * pow;
        pow *= 2;
    }

    res -= bitArray[7] * pow;

    return res;
}
