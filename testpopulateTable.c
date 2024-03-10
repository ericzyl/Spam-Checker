/*
 * Filename: testpopulateTable
 * Author: Yilin Zhu
 * Userid: A15862322
 * Description: Unit test program to test the function hash().
 * Date: 2022 8.16
 * Sources of Help: Lecture slides, C documentation.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa1.h"

void testpopulateTable() {

  // Test populate table (a few emails)
  linkedListNode_t ** table = newLinkedListArray(2003);
  FILE *fptr = fopen("pa1file1.txt", "r");
  populateTable(table, fptr);
  TEST(strcmp((**(table + 693737%2003)).value, "abc") == 0);
  TEST(strcmp((**(table + 26452777%2003)).value, "paul") == 0);
  TEST(strcmp((**(table + 626201%2003)).value, "123") == 0);
  TEST(strcmp((**(table + 18845%2003)).value, "e1") == 0);
  TEST(strcmp((**(table + 508%2003)).value, "e") == 0);

  // Test populate table when contents are all capital letters
  // PA1FILE1.txt would contain ABC, PAUL ...
  linkedListNode_t ** captable = newLinkedListArray(2003);
  fptr = fopen("PA1FILE1.txt", "r");
  populateTable(captable, fptr);
  TEST(strcmp((**(table + 693737%2003)).value, "abc") == 0);
  TEST(strcmp((**(table + 26452777%2003)).value, "paul") == 0);
  TEST(strcmp((**(table + 626201%2003)).value, "123") == 0);
  TEST(strcmp((**(table + 18845%2003)).value, "e1") == 0);
  TEST(strcmp((**(table + 508%2003)).value, "e") == 0);



  // Test populate table (no email)
  linkedListNode_t ** table2 = newLinkedListArray(3);
  FILE *emptyFile = fopen("empty.txt", "r");
  populateTable(table2, emptyFile);
  TEST(*(table2) == NULL);
  TEST(*(table2 + 1) == NULL);
  TEST(*(table2 + 2) == NULL); 

  // Test populate table when the file pointer is NULL
  linkedListNode_t ** table3 = newLinkedListArray(3);
  fptr = fopen("wrongName.txt", "r");
  populateTable(table3, fptr);
  TEST(*table3 ==  NULL);
  TEST(*(table3+1) == NULL);
  TEST(*(table3+2) == NULL);
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
  testpopulateTable();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
