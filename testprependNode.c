/*
 * Filename: testprependNode
 * Author: Yilin Zhu
 * Userid: A15862322
 * Description: Unit test program to test the function hash().
 * Date: 2022 8.14
 * Sources of Help: Lecture slides, C documentation, tutors.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa1.h"

void testprependNode() {

  // Initialize a linkedlist
  linkedListNode_t ** arr  = newLinkedListArray(2003);
  linkedListNode_t * node1 = newLinkedListNode();
  linkedListNode_t * node2 = newLinkedListNode();
  linkedListNode_t * node3 = newLinkedListNode();
  *arr = node1; // pointer to a pointer
  (*node1).value = "apple";
  (*node1).next = node2;
  (*node2).value = "eric";
  (*node2).next = node3;
  (*node3).value = "number123";
  (*node3).next = NULL;

  // Test multi case one
  prependNode(arr, "hello");
  TEST(strcmp((**arr).value, "hello") == 0);
  TEST((**arr).next == node1);

  // Test multi case two
  linkedListNode_t * newNode = *arr;
  prependNode(arr, "12345");
  TEST(strcmp((**arr).value, "12345") == 0);
  TEST((**arr).next == newNode);

  // Test multi case three
  newNode = *arr;
  prependNode(arr, "eric123@gmail.com");
  TEST(strcmp((**arr).value, "eric123@gmail.com") == 0);
  TEST((**arr).next == newNode);

  // Test empty linked list
  prependNode(arr+1, "first");
  TEST(strcmp((**(arr+1)).value, "first") == 0);
  TEST((**(arr+1)).next == NULL);

  // Test when there is only one element
  linkedListNode_t * singleNode = newLinkedListNode();
  (*singleNode).value = "singleNode";
  (*singleNode).next = NULL;
  *(arr+2) = singleNode;
  prependNode(arr+2, "second");
  TEST(strcmp((**(arr+2)).value, "second") == 0);
  TEST((**(arr+2)).next == singleNode);

  // Test prepend multiple times on empty list
  prependNode(arr+3, "something1");
  prependNode(arr+3, "something2");
  prependNode(arr+3, "something3");
  TEST(strcmp((**(arr+3)).value, "something3") == 0);
  TEST(strcmp((*((**(arr+3)).next)).value, "something2") == 0);
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
  testprependNode();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
