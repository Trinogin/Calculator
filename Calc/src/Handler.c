/*!
*\file
*\brief
*
*/

#include"Handler.h"
#include"Handler_real.h"
#include"Global.h"

int NeedCalculate(char const* line)
{
  UNUSED_PARAMETER(line);
  return TRUE;
}

error_t IsError(char const* line)
{
  UNUSED_PARAMETER(line);
  return ERR_OK;
}
