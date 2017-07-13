/*!
*\mainpage Application for ariphmetic calculations.
*\authors Andrey Trinogin.
*\date 06.06.2017.
*\version 2.5
*
* Based on Reverse Polish Notation (RPN) algorithm.
* Realisation - C programming language.
*
* Program works with real number. Dot - separator.
* Program can have one argument - file for reading. 
* Allowed to use comments. Write any number space symbols
* and after "//" you write any text. But no one symbol before
* "//", because it will be interpretated like an error.
*
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
#include"Computing.h"
#include"Handler.h"
#include"vld.h"
#include<stdio.h>
#include<stdlib.h>

/*!
*\brief Report about error.
*\param[in] error Error.
*
*/
void ReportError(error_t error)
{
  printf("ERROR: ");
  puts(GetErrorString(error));
}

/*!
*\brief Main work with string.
*\param[in] line Math expression.
*\param[in] error Error pointer.
*/
void ProcessLine(char const* line, error_t* error)
{
  double result;

  if (*error != ERR_OK)
  {
    ReportError(*error);
    return;
  }

  if (NeedCalculate(line) == FALSE)
  {
    puts(line);
    return;
  }
  
  if (IsError(line) != ERR_OK)
  {
    ReportError(*error);
    return;
  }

  printf("%s == ", line);

  result = Calculate(line, error);
  if (*error == ERR_OK)
    printf("%lg\n", result);
  else
  {
    ReportError(*error);
    *error = ERR_OK;
  }
    
}

/*!
*\brief Reading string.
*\param[in] in Stream pointer.
*\param[in] error Error pointer.
*/
char* ReadLine(FILE* in, error_t* error)
{
  char* line = NULL;
  char* str;
  char ch;
  int num;
  int end_Flag;

  end_Flag = FALSE;
  num = 1;
  while ((ch = (char)getc(in)) != '\n')
  {
    str = realloc(line, num * sizeof(char));
    if (str != NULL)
    {
      line = str;
      if (ch == EOF)
      {
        line[num - 1] = '\0';
        end_Flag = TRUE;
      }
      else
      {
        line[num - 1] = ch;
        num++;
      }
    }
    else
    {
      *error = ERR_NOT_ENOUGH_MEMORY;
      free(line);
      if (ch == '\n') // Если ошибка случилась на последнем символе
        return (char*)1;
      else if (ch == EOF)
        return NULL;
      else  // Чтение вхолостую до конца строки
      {
        while ((ch = (char)getc(in)) != '\n')
        {
          if (ch == EOF)
            return (char*)1;
        }
        return (char*)1;
      }
    }
    if (end_Flag == TRUE)
      break;
  }
  if (end_Flag == TRUE)
  {
    if (*line == '\0')
    {
      free(line);
      line = NULL;
      return NULL;
    }
    else
      return line;
  }
  str = realloc(line, num * sizeof(char));
  if (str != NULL)
  {
    line = str;
    line[num - 1] = '\0';
  }
  else
  {
    *error = ERR_NOT_ENOUGH_MEMORY;
    return (char*)1;
  }
  return line;
}

int main(int argc, char const *argv[])
{
  FILE* in = stdin;
  char* line = NULL;
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
    if (current_Error == ERR_NOT_ENOUGH_MEMORY)
    {
      ReportError(current_Error);
      current_Error = ERR_OK;
      continue;
    }
    ProcessLine(line, &current_Error);
    current_Error = ERR_OK;
    free(line);
  }
  if (in != stdin)
    fclose(in);
  return 0;
}