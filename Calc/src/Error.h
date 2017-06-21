/*!
*\file
*\brief Header file for error.
*
* This file contains all with error in calculator.
*/

#ifndef _ERROR_H_INCLUDED
#define _ERROR_H_INCLUDED

#pragma once

///Set of the possible errors
typedef enum
{
  ERR_OK, ///< No error. 
  ERR_NOT_ENOUGH_MEMORY, ///< Error means that memory is not enough.
  ERR_WRONG_COMMENTS, ///< Wrong comment, smthg before //.
  ERR_OUT_OF_DOMAIN, ///< Out of domain of the function.
} error_t;

/*!
\brief Choose the right string to report error.
\param[in] error Error.
\return String to print.
*/
char const* GetErrorString(error_t error);

#endif  //_ERROR_H_INCLUDED