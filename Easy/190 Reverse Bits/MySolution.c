uint32_t reverseBits(uint32_t n) {
    uint32_t bitValue = 0, ret = 0;
    int i = 0;

    for (i = 0; i < 32; i++) {
        bitValue = n >> i & 1;
        bitValue = bitValue << (32 - 1 - i);
        ret |= bitValue;
    }

    return ret;
}
