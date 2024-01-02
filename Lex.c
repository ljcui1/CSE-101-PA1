//-----------------------------------------------------------------------------
// Name: Lia Cui
// CRUZID: ljcui
// Assignment Name: PA1
//
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"List.h"

#define MAX_LEN 300

int main(int argc, char * argv[]){

   int line_count;
   FILE *in, *out;
   char line[MAX_LEN];
   //char tokenBuffer[MAX_LEN];
   //char* token;

   //open files for reading and writing 
   //check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }
   in = fopen(argv[1], "r");
      if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

   out = fopen(argv[2], "w");
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   // read each line of input file, then count and print tokens
   line_count = 0;
   while( fgets(line, MAX_LEN, in) != NULL)  {
      line_count++;

   }
   rewind(in);
   char** lex_array = (char**) calloc (line_count, sizeof(char*));
   int ll_index = 0;
   
   while( fgets(line, MAX_LEN, in) != NULL) {
      //printf("%s",lex_list[ll_index]);
      lex_array[ll_index] = malloc((sizeof(line) + 1) * sizeof(char));

      strcpy(lex_array[ll_index], line);
      ll_index++;
    
   }

   List lex_list = newList();
   
   append(lex_list, 0);
   moveFront(lex_list);
   int j = 0;
   for(int i = 1; i < line_count; i++){
      moveFront(lex_list);
      j = 0;
      while(j < line_count){
         // strcpy(line, lex_array[i]);
         // int x = get(lex_list);
         // strcpy(line, lex_array[x]);
         if(strcmp(lex_array[get(lex_list)], lex_array[i]) >= 0){
            insertBefore(lex_list, i);//continue
            break;
         }else if(strcmp(lex_array[get(lex_list)], lex_array[i]) < 0){
            moveNext(lex_list);
            j++;
         }
         if(index(lex_list) < 0){
            append(lex_list, i);
            break;
         }
      }
   }


   moveFront(lex_list);
   while(index(lex_list) >= 0){
      int indices = get(lex_list);
      fprintf(out, "%s", lex_array[indices]);
      moveNext(lex_list);
   }
   
   freeList(&lex_list);
   for(int i = 0; i < line_count; i++){
      free(lex_array[i]);
   }
   free(lex_array);


   //close files 
   fclose(in);
   fclose(out);

   return(0);
}