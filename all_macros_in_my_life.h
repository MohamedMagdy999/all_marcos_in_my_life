#define SET_BIT(REG, BIT) (REG |= (1 << BIT))

#define CLEAR_BIT(REG, BIT) (REG &= (~(1 << BIT)))

#define TOGGLE_BIT(REG, BIT) (REG ^= (1 << BIT))

// Macro to Swap Nibbles in a Byte
// SwapNibbles(0b 0011 0001 )  -> 0b 0001 0011
#define SwapNibbles(data) (((data & 0x0F) << 4) | ((data & 0xF0) >> 4))

// Macro to Swap Two Bytes
#define SwapTwoBytes(data) (((data & 0x00FF) << 8) | ((data & 0xFF00) >> 8))

// Macro to Swap two numbers
#define SWAP(x, y) (x ^= y ^= x ^= y)

// rotat bits from left and right
// 0b 00110001 --> Rotate_from_right(,3)  --> 0b 00100110
#define Rotate_from_right(REG, num) (REG = (REG >> num) | (REG << (8 - num)))
#define Rotate_from_left(REG, num) (REG = (REG << num) | (REG >> (8 - num)))

// check if the bit set or clear
#define BIT_IS_SET(REG, BIT) (REG & (1 << BIT))
#define BIT_IS_CLEAR(REG, BIT) ((REG & (1 << BIT)) == 0)

// ---------------------------------

// get the low and high 8-bits of the number
// lowByte ( 0b 0011 0001 0000 0000 )  - > 0b 0000 0000  the low 8-bites
// highByte ( 0b 0011 0001 0000 0000 )  - > 0b 0000 0000  the low 8-bites
#define lowByte(w) ((uint8_t)((w)&0xff))
#define highByte(w) ((uint8_t)((w) >> 8))

/* ———— Macros For Building BitFields ————– */

#define BIT_SET(ADDRESS, BIT) (ADDRESS |= (1 << BIT))
#define BIT_CLEAR(ADDRESS, BIT) (ADDRESS &= ~(1 << BIT))
#define BIT_WRITE(n, ADDRESS, BIT) (n ? BIT_SET(ADDRESS, BIT) : BIT_CLEAR(ADDRESS, BIT))
#define BIT_CHECK(ADDRESS, BIT) (ADDRESS & (1 << BIT))
#define BIT_FLIP(ADDRESS, BIT) (ADDRESS ^= (1 << BIT))
#define BIT_GET(ADDRESS, BIT) (ADDRESS & (1 << BIT))

/*_____from the ardino scr code */
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

// good macros for absulte value | -5 |=5
#define abs(x) ((x) > 0 ? (x) : -(x))

// if i have three value and want to return the begger
#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

#define round(x) ((x) >= 0 ? (long)((x) + 0.5) : (long)((x)-0.5))

// to return the degree to raddian and vice versa
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)

#define sq(x) ((x) * (x))

/*-----------------------------------------------*/

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

// Macro to Convert one Endian into another Endian
#define SwapEndians(value) ((value & 0x000000FF) << 24) | ((value & 0x0000FF00) << 8) | \
                               ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24)

// Macro to Swap Eight Bytes of Data
#define SwapEightBytes(data) ((((data) >> 56) & 0x00000000000000FF) | (((data) >> 40) & 0x000000000000FF00) | \
                              (((data) >> 24) & 0x0000000000FF0000) | (((data) >> 8) & 0x00000000FF000000) |  \
                              (((data) << 8) & 0x000000FF00000000) | (((data) << 24) & 0x0000FF0000000000) |  \
                              (((data) << 40) & 0x00FF000000000000) | (((data) << 56) & 0xFF00000000000000))

// check if the amt value is between the two values
#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#define round(x) ((x) >= 0 ? (long)((x) + 0.5) : (long)((x)-0.5))

#define interrupts() sei()
#define noInterrupts() cli()

#define clock_Cycles_Per_Microsecond() (F_CPU / 1000000L)
#define clock_Cycles_To_Microseconds(a) ((a) / clockCyclesPerMicrosecond())
#define microseconds_To_ClockCycles(a) ((a)*clockCyclesPerMicrosecond())
