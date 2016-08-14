/*
 * ================================================================================================
 *
 *       Filename:  dbp.h
 *
 *    Description:  Prototype function used defined in ds.c
 *
 *        Version:  1.0
 *        Created:  Friday 12 August 2016 01:33:59  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * ================================================================================================
 */
#ifndef __DSP_H__
#define __DSP_H__

#include <BasicType.h>
#include <ds.h>
/*
 *=================================================================================================
 * Singly Linked List Function's Declaration
 *=================================================================================================
 */
ResultCode SLListInit(SLList  *);
/*insertion*/
ResultCode SLListInsertHead(SLList  *, SLNode  *);
ResultCode SLListInsertTail(SLList  *, SLNode  *);
ResultCode SLListInsertNth(SLList  *, SLNode  *,  U64);
ResultCode SLListInsertOrdered(SLList *, SLNode *, ResultMove (*NodeCompare)(PVoid , PVoid));

/*Deletion*/
ResultCode SLListDeleteHead(SLList  *, ResultCode (*NodeDelete)(SLNode *));
ResultCode SLListDeleteTail(SLList  *, ResultCode (*NodeDelete)(SLNode *));
ResultCode SLListDeleteNode(SLList  *, SLNode *, ResultCode (*NodeDelete)(SLNode *), 
                                                 ResultCode (*NodeCompare)(PVoid, PVoid));
ResultCode SLListDeleteNth(SLList  *, ResultCode (*NodeDelete)(SLNode *),  U64);
ResultCode SLListDeleteList(SLList  *, ResultCode (*NodeDelete)(SLNode *));

/*
 *=================================================================================================
 * Doubly Linked List Function's Declaration
 *=================================================================================================
 */
ResultCode DLListInit(DLList *);

#endif /*__DSP_H__*/
