/*!
*\mainpage Application for arithmetic calculations.
*\authors Andrey Trinogin.
*\date 6 june of 2017.
*\version 2.0.
*
* Based on Reverse Polish Notation (RPN) algorithm.
* Realisation - C programming language.
*
* Program works with real number. Dot - separator.
* Program can have one argument - file for reading. 
* Allowed to use comments. Write any number space symbols
* and after "//" you write any text. But no one symbol before
 "//", because it will be interpretated like an error.
*\warning If number of arguments > 2 - this is error.
*/

/*!
*\file
*\brief Main file of program.
*
*/

#pragma warning(disable:4996)

#include"Global.h"
#include"Error.h"
#include"vld.h"
#include<stdio.h>
#include<stdlib.h>

/*!
\brief Report about error.
\param[in] error Error.
*/
void ReportError(error_t error)
{
  printf("ERROR: ");
  puts(GetErrorString(error));
}

void ProcessLine(char const* line, error_t* error)
{

}

char* ReadLine(FILE* in, error_t* error)
{
  UNUSED_PARAMETER(in);
  UNUSED_PARAMETER(error);
  return NULL;
}

int main(int argc, char const* argv[])
{
  FILE* in = stdin;
  char* line;// = NULL;
  error_t current_Error = ERR_OK;

  if (argc > 2)
  {
    printf("ERROR: Too much arguments for call\n");
    return -1;
  }

  if (argc > 1 && (in = fopen(argv[1], "r")) == NULL)
  {
    printf("ERROR: Cannot open file '%s'\n", argv[1]);
    return -1;
  }

  while ((line = ReadLine(in, &current_Error)) != NULL)
  {
    ProcessLine(line, &current_Error);
    free(line);
  }

  if (in != stdin)
    fclose(in);
  return 0;
}