/*!
*\file
*\brief Realisiation for Error module.
*/

#include"Error.h"

char const* GetErrorString(error_t error)
{
  switch (error)
  {
     case(ERR_NOT_ENOUGH_MEMORY):
       return "Not enough memory!";
     case (ERR_WRONG_COMMENTS):
       return "Comment is wrong";
    /*case(ERR_WRONG_EXPRESSION):
       return "Wrong expression!";
     case (ERR_BRACKETS):
       return "Unbalanced brackets!";
     case (ERR_STACK_IS_EMPTY):
       return "Smthg wrong, stack was empty!";
     case (ERR_OUT_OF_DOMAIN):
       return"out of domain function!";
     case (ERR_WRONG_EXPRESSION_EMPTY_BRACKETS):
       return "Wrong expression - empty brackets!";
     case (ERR_NOT_ALLOWED_SYMBOLS):
       return "Not allowed symbol(s) in string!";
     case  (ERR_UNEXPECTED_SYMBOL_E):
       return "Unexpected symbol 'e' in string!";
     case  (ERR_UNEXPECTED_SYMBOL_POINT):
       return "Unexpected point in string!";
     case  (ERR_NO_ARGUMENTS):
       return "No function argument";
     default:
       return "";*/
  }
  return "";
}