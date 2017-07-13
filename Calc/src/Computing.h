/*!
*\file
*\brief Header file for computing.
*
* This file is interface of computing module.
*/


#ifndef _COMPUTING_H_INCLUDED
#define _COMPUTING_H_INCLUDED

#pragma once

#include"Error.h"

/*!
*\brief Hard fucntion for calculating.
*\param[in] line Expression for calculate.
*\param[in] error Error pointer.
*
* Function contains other functions, which does different work.
*/
double Calculate(char const* line, error_t* error);

#endif //_COMPUTING_H_INCLUDED