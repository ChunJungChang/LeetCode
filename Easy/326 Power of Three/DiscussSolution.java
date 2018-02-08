/* The idea is to convert the original number into radix-3 format
 * and check if it is of format 10* where 0* means k zeros, k >= 0
 */

 public boolean isPowerOfThree(int n) {
    return Integer.toString(n, 3).matches("10*");
 }
