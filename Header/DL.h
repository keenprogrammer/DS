/*
 * ================================================================================================
 *
 *       Filename:  ds.h
 *
 *    Description:  Contains all the data declaration used in ds.c
 *
 *        Version:  1.0
 *        Created:  Friday 12 August 2016 12:50:32  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * ================================================================================================
 */
#ifndef __DS_H__
#define __DS_H__

/*
 *=================================================================================================
 * Singly Linked List Declaration
 *=================================================================================================
 */
typedef struct SinglyListNode{
  struct SinglyListNode *next;
}SLNode;

typedef struct SinglyList{
  U64  count;
  SLNode head;
  SLNode tail;
}SLList;

/*
 *=================================================================================================
 * Doubly Linked List Declaration
 *=================================================================================================
 */
typedef struct DoublyListNode{
  struct DoublyListNode  *next;
  struct DoublyListNode  *prev;
}DLNode;

typedef struct DoublyList{
  U64  count;
  DLNode node;
}DLList; 

#endif /*__DS_H__*/
