/*!
*\file
*\brief Realisiation for computing module.
* 
* This file has 2 headers. One is interface, second is header for
* internal functions.
*/

#include"Global.h"
#include"Computing.h"
#include"Computing_real.h"

void PrecountPrepare(char const* line, error_t* error)
{
  UNUSED_PARAMETER(line);
  UNUSED_PARAMETER(error);
}

char* SortStation(char const* line, error_t* error)
{
  UNUSED_PARAMETER(line);
  UNUSED_PARAMETER(error);

  return NULL;
}

double Calculate(char const* line, error_t* error)
{
  double result;
  char* rpn_line;

  PrecountPrepare(line, error);
  if (*error != ERR_OK)
  {
    return 0.0;
  }
  rpn_line = SortStation(line, error);
  if (*error != ERR_OK)
  {
    return 0.0;
  }

  UNUSED_PARAMETER(result);
  return 0;
}