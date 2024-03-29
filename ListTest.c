//-----------------------------------------------------------------------------
// Name: Lia Cui
// CRUZID: ljcui
// Assignment Name: PA1
//
//-----------------------------------------------------------------------------

/****************************************************************************************
*  ListTest.c
*  Test client for List ADT
*****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"List.h"

int main(int argc, char* argv[]){
   
   List A = newList();
   List B = newList();
   List C = NULL;
   int i;

   for(i=1; i<=20; i++){
      append(A,i);
      prepend(B,i);
   }

   printList(stdout,A); 
   printf("\n");
   printList(stdout,B); 
   printf("\n");

   for(moveFront(A); index(A)>=0; moveNext(A)){
      printf("%d ", get(A));
   }
   printf("\n");
   for(moveBack(B); index(B)>=0; movePrev(B)){
      printf("%d ", get(B));
   }
   printf("\n");

   C = copyList(A);
   printf("%s\n", equals(A,B)?"true":"false");
   printf("%s\n", equals(B,C)?"true":"false");
   printf("%s\n", equals(C,A)?"true":"false");


   moveFront(A);
   for(i=0; i<5; i++) moveNext(A); // at index 5
   //printList(stdout, A);
   //printf("\n");
   insertBefore(A, -1);            // at index 6
  // printList(stdout, A);
   //printf("\n");
   for(i=0; i<9; i++) moveNext(A); // at index 15
   insertAfter(A, -2);
   for(i=0; i<5; i++) movePrev(A); // at index 10
   printf("Front %d\n", front(A));
   printf("Back %d\n", back(A));
   printList(stdout,A);

   printf("\nDelete Front\n");
   deleteFront(A);
   printList(stdout,A);
   printf("\n");

   printf("\nDelete Back\n");
   deleteBack(A);
   printList(stdout,A);
   printf("\n");

   printf("\nFront %d\n", front(A));
   printf("Back %d\n", back(A));

   printList(stdout,A);

   moveFront(A); 
   for(i=0; i<10; i++) moveNext(A); // at index 10
   printf("\nRun Set\n");
   set(A, 200);
   printList(stdout,A);
   printf("\n");


   printf("\nDelete\n");
   moveFront(A);
   for(i=0; i<16; i++) moveNext(A);
   delete(A);
   printList(stdout,A);
   printf("\n");
   printf("%d\n", length(A));
   clear(A);
   printf("%d\n", length(A));

   

   freeList(&A);
   freeList(&B);
   freeList(&C);

   return(0);
}

/*
Output of this program:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
false
false
true
Front 1
Back 20
1 2 3 4 5 -1 6 7 8 9 10 11 12 13 14 15 -2 16 17 18 19 20
Delete Front
2 3 4 5 -1 6 7 8 9 10 11 12 13 14 15 -2 16 17 18 19 20

Delete Back
2 3 4 5 -1 6 7 8 9 10 11 12 13 14 15 -2 16 17 18 19

Front 2
Back 19
2 3 4 5 -1 6 7 8 9 10 11 12 13 14 15 -2 16 17 18 19
Run Set
2 3 4 5 -1 6 7 8 9 10 200 12 13 14 15 -2 16 17 18 19

Delete
2 3 4 5 -1 6 7 8 9 10 200 12 13 14 15 -2 17 18 19
19
0
*/