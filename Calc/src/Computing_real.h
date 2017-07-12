/*!
*\file
*\brief Header file for computing.
*
* This file is realisation of computing module.
*
*/

#ifndef _COMPUTING_REAL_H_INCLUDED
#define _COMPUTING_REAL_H_INCLUDED

#pragma once

#include<stdlib.h>

void PrecountPrepare(char const* line, error_t* error);

char* SortStation(char const* line, error_t* error);

#endif //_COMPUTING_REAL_H_INCLUDED