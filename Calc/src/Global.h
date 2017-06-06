/*!
*\file
*\brief Header file with global function, macros and variable. 
*
* This file is included in almost all other and contains functions used
* in several modules at the same time. According to the principle of moduls
* was made separating interface and realistaion, but were found things, which 
* is used in both of this 2 moduls and needed to create this file.
*/

#ifndef _GLOBAL_H
#define _GLOBAL_H

#pragma once
/*!
*\brief Macros for parameters, which is not used.
* 
* The cast to type void. We have max security level and all unused parameters
* trigger warning.
*/
#define UNUSED_PARAMETER(name) (void)name

#endif // _GLOBAL_H