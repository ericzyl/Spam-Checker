/*
 * Filename: testhash
 * Author: Yilin Zhu
 * Userid: A15862322
 * Description: Unit test program to test the function hash().
 * Date: 2022 8.14
 * Sources of Help: Lecture slides, C documentation.
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa1.h"

void testhash() {

  TEST( hash( "abc" ) == 693737 );
  TEST( hash( "paul" ) == 26452777 );

  // Test hash on empty string
  TEST( hash( "" ) == 11);

  // Test hash on single character
  TEST( hash( "e" ) == 508);

  // Test hash on the numeric
  TEST( hash( "123" ) == 626201);

  // Test hash on alphanumeric
  TEST( hash( "e1" ) == 18845);

}

/* 
 * Function Name: main()
 * Function prototype: int main();
 * Description: The test driver. Runs specified tests.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 on exit success.
 */
int main() {
  fprintf( stderr, "Testing hash...\n\n" );
  testhash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
