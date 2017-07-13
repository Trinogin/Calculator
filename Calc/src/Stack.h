/*!
*\file
*\brief Header file for stack.
*
* This file contains things for stack.
* Realization only for this project,
* it is no universal type stack and operations.
*/

#ifndef _STACK_H_INCLUDED
#define _STACK_H_INCLUDED

#pragma once

#include"Error.h"
#include<stdlib.h>

#define START_STACK_SIZE 128

/// Struct - stack iplementation
typedef struct
{
  double* data; ///< Data pointer
  int size;  ///< Number of elements in stack
  int last;  ///< Number of the last element
  error_t error;  ///< For errors
} stack_t;

/*!
*\brief Create a new stack.
*\param[in] error Error pointer.
*\return Pointer to new stack.
*
*Possible errors: not enough memory.
*/
stack_t* NewStackCreate(error_t* error);

/*!
*\brief Increase stack.
*\param[in] stack pointer so stack.
*\param[in] error error pointer
*
* This is helper function, invoked if size of stack is too small.
* Possible errors: not enough memory.
*/
void ResizeStackData(stack_t* stack, error_t* error);

/*!
*\brief Delete stack.
*\param[in] stack Stack pointer.
*
* Free all stack data's.
*/
void DeleteStack(stack_t* stack);

/*!
*\brief Add element to stack.
*\param[in] stack Stack pointer.
*\param[in] error Error pointer.
*\param[in] arg Adding number.
*
* Checks stack size, if needed increase it and add element to stack.
*/
void PushToStack(stack_t* stack, error_t* error, double arg);

/*!
*\brief
*\param[in] stack Stack pointer.
*\param[in] error Error pointer.
*\return Real number, last in stack.
*
* Get last stack's element and reduce number of last element.
* Possible errors: stack is empty.
*/
double PopFromStack(stack_t* stack, error_t* error);


#endif  //_STACK_H_INCLUDED