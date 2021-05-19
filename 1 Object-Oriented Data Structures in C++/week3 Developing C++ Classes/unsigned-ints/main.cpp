
/**
 * An example of the effects of unsigned integers
 * 
 * @author
 *   Eric Huber - University of Illinois Staff
 */

#include <iostream>

int main() {
  
  // This is an ordinary "signed" int by default.
  int a = 7;

  // You could also write "signed int" or "signed" to get the same type:
  // signed int a = 7;
  // signed a = 7;

  // This is an "unsigned" int.
  unsigned int b = 8;

  // You could also write "unsigned" to get the same type:
  // unsigned b = 8;
  
  // Unsigned ints can't represent negative values. Instead, they have
  // a higher upper positive limit to the value range that they can represent.  
  // This can cause strange behavior if you mix signed and unsigned ints.

  // If you do arithmetic between signed and unsigned ints, then you can
  // get undesired results if negative values should logically have arisen.

  // Addition with unsigned values may be no problem, as long as you don't
  // exceed the maximum range. This is 7+8 and shows 15 as expected:
  std::cout << (a+b) << std::endl;

  // However, you do need to be careful if you are approaching the upper
  // limit for a signed int even if you are using unsigned ints.
  // Signed ints have a lower maximum value.

  // Now let's look at issues that can arise if you do subtraction with
  // unsigned ints and try to imply negative values that can't be represented.
  
  unsigned int x = 10;
  unsigned int y = 20;

  // This is 20-10 in unsigned arithmetic, which results in 10 as expected:
  std::cout << (y-x) << std::endl;

  // The next example is 10-20, but the unsigned arithmetic can't represent -10,
  // and instead results in a very large positive value.
  // The output is 4294967286, which is close to the maximum for an unsigned 32-bit integer.
  std::cout << (x-y) << std::endl;

  // If we explicitly cast the result back to a signed integer,
  // then we might get something usable again. The output of this is -10:
  std::cout << (int)(x-y) << std::endl;

  // You can also do a casting operation to convert to signed int just by
  // assigning an unsigned result to a signed int variable. This also outputs -10:
  int z = x - y;
  std::cout << z << std::endl;

  // However, casting a result is not the best way to handle this!
  // Instead, you may want to cast working values to signed before performing
  // operations on them. You might want to check if the values are in range
  // manually when casting to another format.

  int test_val = (x-y);
  if (test_val < 0) {
    // The standard error stream (cerr) will be displayed in the terminal.
    // You can also handle it separately from the standard output stream (cout)
    // if you are logging things to files.
    std::cerr << "Warning: unsigned value cast to signed int resulted in a negative value" << std::endl;
  }

  // Comparisons between signed and unsigned ints can also cause issues.
  // This next line may give a warning or error. We have commented it out for now:
  // std::cout << (a<b) << std::endl;

  // Be careful when you are dealing with unsigned integers!
  // In general, you should only use unsigned integers when you absolutely
  // need to, such as if you are trying to maximize the range of positive
  // values you can store in the same amount of memory. For everyday
  // high-level programming purposes, signed integers may be all you need.
  // If you need to ensure positive values during your code execution,
  // you can write safety checks into the code to monitor values
  // and issue warnings or errors if a certain range is exceeded.

  return 0;
}

