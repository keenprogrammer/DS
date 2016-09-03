/*
 * ================================================================================================
 *
 *       Filename:  dbp.h
 *
 *    Description:  File Contains Data Structure Singly/Doubly Linked List prototype
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

#include <DL.h>
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
ResultCode SLListInsertOrdered(SLList *, SLNode *, ResultMove (*NodeCompare)(pVoid , pVoid));

/*Deletion*/
ResultCode SLListDeleteHead(SLList  *, ResultCode (*NodeDelete)(SLNode *));
ResultCode SLListDeleteTail(SLList  *, ResultCode (*NodeDelete)(SLNode *));
ResultCode SLListDeleteNode(SLList  *, SLNode *, ResultCode (*NodeDelete)(SLNode *), 
                                                 ResultCode (*NodeCompare)(pVoid, pVoid));
ResultCode SLListDeleteNth(SLList  *, ResultCode (*NodeDelete)(SLNode *),  U64);
ResultCode SLListDeleteList(SLList  *, ResultCode (*NodeDelete)(SLNode *));

/*
 *=================================================================================================
 * Doubly Linked List Function's Declaration
 *=================================================================================================
 */
ResultCode DLListInit(DLList *);

#endif /*__DSP_H__*/
