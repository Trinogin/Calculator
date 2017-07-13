/*!
*\file
*\brief Header file for second module.
*
* This file is interface of handler module.
* For finding errors, comments and etc.
*/

#ifndef _HANDLER_H_INCLUDED
#define _HANDLER_H_INCLUDED

#pragma once

#include"Error.h"
#include<ctype.h>

/*!
*\brief Checking for calculating.
*\param[in] line Expression for checking.
*
* Check is it empty string, comment or wrong comment.
*/
int NeedCalculate(char const* line);

error_t IsError(char const* line);

#endif //_HANDLER_H_INCLUDED