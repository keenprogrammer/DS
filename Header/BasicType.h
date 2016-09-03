/*
 * ================================================================================================
 *
 *       Filename:  BasicType.h
 *
 *    Description:  Contains all basic system and user defined data types 
 *
 *        Version:  1.0
 *        Created:  Friday 12 August 2016 01:13:01  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * ================================================================================================
 */
#ifndef __BasicType_H__
#define __BasicType_H__

#include <stdio.h>
#include<string.h>
#include<stdlib.h>


#define  DMALLOC    malloc
#define  DFREE      free
#define  DSTRLEN    strlen
#define  DSTRCPY    strcpy
#define  DSTRNCPY   strncpy
#define  DSTRCMP    strcmp

#define  LOG(str)    


typedef void * pVoid;

typedef signed char  S8;
typedef unsigned char  U8;
typedef signed char * pS8;
typedef unsigned char * pU8;

typedef unsigned short int U16;
typedef signed short int S16;

typedef unsigned int  U32;
typedef signed int  S32;

typedef unsigned long long U64;
typedef signed long long S64;

typedef enum Move{
  MoveFalse = 0,
  MoveTrue
}ResultMove;

typedef enum Error{
  NoError,
  NullPointerError,
  LLInvalidPosError,
  LLHeadNullError,
  LLUnderFlowError,
  DNodeNotPresent
}ResultCode;


#endif /*__BasicType_H__*/
