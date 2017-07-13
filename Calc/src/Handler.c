/*!
*\file
*\brief Realisation for Hadler-module.
*/

#include"Handler.h"
#include"Handler_real.h"
#include"Global.h"


int NeedCalculate(char const* line)
{
  int i = 0;
  int a = FALSE;
  int b = FALSE;

  //Check for empty string.
  while (line[i] != '\0')
  {
    if (!isspace((unsigned char)line[i]))
    {
      a = TRUE;
      break;
    }
    i++;
  }
  //If string is not empty - check for comment.
  if (a == TRUE)
  {  
    i = 0;
    while (line[i + 1] != '\0')
    {
      if (isalnum((unsigned char)line[i]))
      {
        b = TRUE;
        i++;
      }
      if ((line[i] == '/') && (line[i + 1] == '/') && (b == FALSE))
        return FALSE;
      else if ((b == TRUE) && (line[i] == '/') && (line[i + 1] == '/'))
        return ERR_WRONG_COMMENTS;
      i++;
    }
  }
  else
    return FALSE;

  return TRUE;
}

error_t IsError(char const* line)
{
  UNUSED_PARAMETER(line);
  return ERR_OK;
}
