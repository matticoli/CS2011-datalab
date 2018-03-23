/*
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;//leftmost bit
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int mask = 0x55;
    int mask1 = mask << 24;
    int mask2 = mask << 16;
    int mask3 = mask << 8;
    return mask | mask1 | mask2 | mask3;
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    int y = (x + 2) + x; // Will be 0 if x is tmax or -1
    int notNeg1 = !(x + 1); // 1 if -1 else 0
    return !y & !notNeg1;// return 1 only if (tmax or -1) and (not -1)
}

/*
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));//DeMorgan's Law TODO Figure out wtf this is doing
}

/*
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int mask = !x; //0 if x is true (non-zero), 1 if x is false (zero)
    mask = ~mask + 1; // Two's Complement: 0 becomes 0 (all 0's), 1 becomes -1 (all 1's)
    return (y & ~mask) | (z & mask); // invert bits again for true case: (y & ~mask) = y if ~mask is true, else 0
    // vice versa for (z & mask)
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
    int isNegative = x >> 31; // 1 if negative else 0 (sign bit)
    int signMask = isNegative << 31; // Mask with just sign bit
    int tmin = 1 << 31; //  Mask with sign bit of 1
    int oneIfXNotZero, mask;

    // Copy MSB into all bits to right of it
    x = x | x >> 1;
    x = x | x >> 2;
    x = x | x >> 4;
    x = x | x >> 8;
    x = x | x >> 16;

    oneIfXNotZero = ((0 & !x) | (1 & !!x));// 1 if x!=0 else 0
    mask = (x >> 1) + oneIfXNotZero;// Conditional
    mask = (tmin & signMask) | (mask & ~signMask);
    // Return tMin for 0 or greatest bit pos

    return mask;
}

/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int mask = (1 << n) + ~0;
    int equalizer = (x >> 31) & mask;
    return ((x + equalizer) >> n);
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
    return !(x >> 31);// Shift by 31 to get sign bit and invert
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    int THREExME, signX, sign2X, sign3X, overflowMask, signMask, mask;
    THREExME = x + x;// mult by 3
    signX = x >> 31;// Get le sine bit
    sign2X = THREExME >> 31;
    THREExME = THREExME + x;
    sign3X = THREExME >> 31;
    overflowMask = ((signX & sign2X & sign3X) | !(signX + sign2X + sign3X));
    //0 if x is true (non-zero), 1 if x is false (zero)

//    printf("%d\n", -1 >> 31);
    mask = ~!!overflowMask + 1; // Two's Complement: 0 becomes 0 (all 0's), 1 becomes -1 (all 1's)

    signMask = ~(!signX) + 1;
    signMask = (signMask ) ^ (1 << 31);

    return (signMask & ~mask) | (THREExME & mask);
}

/*
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    int xPos = !(x >> 31);// 1 if x is positive or 0, else 0
    int yPos = !(y >> 31);// 1 if y is positive or 0, else 0
    int diffPos = !((x + ~y) >> 31); // 1 if (x-y) is positive or 0, else 0

    int diffNotZero = !!(x ^ y); // 1 if (x - y) is not zero, else 0


    int isGreater = (xPos & !yPos); // x+, y-
    isGreater = isGreater + (xPos & yPos & diffPos);// x+, y+, (x-y)+
    isGreater = isGreater + (!xPos & !yPos & diffPos);// x-, y-, (x-y)+

    return isGreater & diffNotZero; // 1 if a criterion is met for x>=y AND x-y is not 0
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // 48 <= x <= 57
    // 110000 <= x <= 111001
    //
    // 110 = 6
    // 1110 = 14
    int one2seven = !((x >> 3) ^ 6);// 1 if bits in pos 4-7 are 110 (ascii '1'-'7'), else 0
    int belowSemicolon = !((x >> 2) ^ 14);// 1 if bits in pos 3-7 are 1110 (ascii '8'-';'), else 0
    int lastThree = x << 29;// Isolates last 3 bits
    int eight2nine = belowSemicolon & !((lastThree >> 29) ^ !!(lastThree));
    // 1 if last 3 bits are 000 or 001 AND x is between '8' and ';' (dec 56 thru 59), else 0

    return one2seven | eight2nine;// 1 if x is between '1' and '9', else 0
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(~) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x) {
    int oneEighthX, onesPlace, twosPlace, foursPlace, signMask, remainder, sum;
    oneEighthX = x >> 3; // Divide x by 8
    onesPlace = x & 1; // Get the rightmost bit
    twosPlace = x & 2; // Get the 2nd rightmost bit
    foursPlace = x & 4;// Get the 3d rightmost bit
    signMask = (x >> 31) & 7;// Mask of sign bit on 3 rightmost bits

    remainder = (foursPlace | twosPlace | onesPlace);// Combine 3 rightmost bits
        remainder = remainder + remainder + remainder + remainder + remainder;// multiply remainder by 5
    sum = oneEighthX + oneEighthX + oneEighthX + oneEighthX + oneEighthX;// multiply x/8 by 5

    return sum + ((remainder + signMask) >> 3);// eights, remainders, and sign bias together
}

/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    int mask, y, answer;
    mask = !(x >> 16);// Check if there are any bits to the left of 16th pos
    mask = ~mask + 1;// Conditional
    y = ((x >> 16) & ~mask) | (x & mask);// y contains left or right half of bits (whichever has msb)
    answer = (16 & ~mask);// If shifting, add 16 bits to ans

    mask = !(y >> 8);// Check if there are any bits to the left of 8th pos
    mask = ~mask + 1;// Conditional
    y = ((y >> 8) & ~mask) | (y & mask);// y contains left or right half of bits (whichever has msb)
    answer = answer + (8 & ~mask);// If shifting, add 8 bits to ans

    mask = !(y >> 4);// Check if there are any bits to the left of 4th pos
    mask = ~mask + 1;// Conditional
    y = ((y >> 4) & ~mask) | (y & mask);// y contains left or right half of bits (whichever has msb)
    answer = answer + (4 & ~mask);// If shifting, add 4 bits to ans

    mask = !(y >> 2);// Check if there are any bits to the left of 2nd pos
    mask = ~mask + 1;// Conditional
    y = ((y >> 2) & ~mask) | (y & mask);// y contains left or right half of bits (whichever has msb)
    answer = answer + (2 & ~mask);// If shifting, add 2 bits to ans

    mask = !(y >> 1);// Check if there are any bits to the left of 1st pos
    mask = ~mask + 1;// Conditional
    y = ((y >> 1) & ~mask) | (y & mask);// y contains left or right half of bits (whichever has msb)
    answer = answer + (1 & ~mask);// If shifting, add 1 bit to ans
    return answer;
}

/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    int e = uf >> 23 & 255;// Isolate exponent
    int m = uf & 0x7fffff;// Isolate mantissa

    if((m != 0) & (e == 255)) {// If NaN
        // Return arg
        return uf;
    }
    // If valid number, return -uf
    return uf ^ (1 << 31);
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the b it-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    unsigned sign, m, e, mTemp, b, top, bottom;
    const int maxM = 0x7FFFFF; // maximum value for mantissa
    const int tMin = 0x80000000;// tmin
    const int maxE = 0xFF000000;
    e = 150;// Max value for exponent
    b = 2;

    if (x == 0) {// If x is 0, nothing to do
        return 0;
    } else if (x == tMin) {// If x is tmin, return
        return 3472883712;// Return tmin as float
    }

    sign = (x & tMin);// Get sign bit of x
    m = sign ? -x : x;// Set m to +/- x based on sign bit

    mTemp = m;
    // While original mantissa has max exponent
    while (mTemp & maxE) {
        // Round up or down appropriately
        mTemp = (m + (b / 2)) / (b);
        b <<= 1;
        e++;// Increment exponent
    }
    while (mTemp <= maxM) {
        // Multiply mTemp by 2 until it passes maxM
        mTemp <<= 1;
        // Decrement exponent every time
        e--;
    }

    // If there's still an exponent in the mantissa var
    if (m & maxE) {
        b = 1 << (e - 150);

        mTemp = m / b;
        bottom = m % b;
        top = b - bottom;

        // Round up or down as appropriate
        if ((top < bottom) || ((top == bottom) & mTemp)){
            mTemp++;
        }

        // Restore mantissa
        m = mTemp;
    } else {
        // Left shift to multiply by 2 until m passes maxM
        while (m <= maxM) {
            m = m << 1;
        }
    }

    // Combine sign, exponent, and mantissa to get result
    return (sign) | (e << 23) | (m & maxM);
}

/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    unsigned e = (uf >> 23) & 255;// Isolate exponent
    unsigned sign = uf & (1 << 31);// Isolate sign bit
    unsigned m = uf & 0x007FFFFF;// Isolate fraction bits

    if (e == 255 || (e == 0 && m == 0)) {// Check for overflow
        return uf;// If overflow, return arg
    }

    // Otherwise it won't overflow
    if (e) {
        e++;// If there's an exponent, increment exponent to multiply by 2
    } else if (m == 0x7FFFFF) { // If fraction is tmax
        m--;// 2x tMax = tMax - 1 (with exponent incremented)
        e++;// Increment exponent
    } else {// Fraction is less than tmax
        m = m << 1;// Multiply fraction by 2
    }

    // Combine sign, exponent, and fraction to get result
    return (sign) | (e << 23) | (m);
}
