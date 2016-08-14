/*
 * ================================================================================================
 *
 *       Filename:  ds.c
 *
 *    Description: contains all necessory data structure implementation 
 *                 1. SLList 2. DLList
 *
 *        Version:  1.0
 *        Created:  Friday 12 August 2016 12:44:19  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * ================================================================================================
 */
#include<dsp.h>
#include<stdlib.h>

/*
 * ================================================================================================
 * Name : SLListInit
 * Description : Function to initialize Singly Linked List
 * Params : SLList *
 * Return : ResultCode, Appropriate error code
 * ================================================================================================
 */
ResultCode SLListInit(SLList *list){
  ResultCode res = NoError;
  if(list){
    list->count = 0;
    list->head.next = NULL;
    list->tail.next = NULL;
  }
  else{
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListInsertHead
 * Description : Function to insert node at list head
 * Params : SLList *, SLNode *
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListInsertHead(SLList *list, SLNode *node){
  ResultCode res = NoError;
  if(list && node){
    node->next = list->head.next;
    list->head.next = node;
    if(!list->tail.next){ /*node is first element for list*/
      list->tail.next = node;
    }
    list->count ++;  
  }else{
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListInsertTail
 * Description : Function to insert node at list tail
 * Params : SLList *, SLNode *
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListInsertTail(SLList *list, SLNode *node){
  ResultCode res = NoError;
  if(list && node){
    if(!list->tail.next){ /*node is first element for list*/
      res = SLListInsertHead(list, node);
    }else{ /*insert at tail and update tail*/
      list->tail.next = node;
      list->count ++;
    }
  }else {
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListInsertNth
 * Description : Function to insert node at Nth pos in list
 * Params : SLList *, SLNode *, U64
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListInsertNth(SLList *list, SLNode *node, U64 N){
  ResultCode res = NoError;
  if(N == list->count + 1){ /*insert element @tail*/
    res = SLListInsertTail(list, node);
    return res; 
  } else if(N == 1){ /*insert element @head*/
    res = SLListInsertHead(list, node);
    return res;
  } else if(N > list->count){ /*Invalid N*/
    return LLInvalidPosError;
  }
  if(list && node){
    int PosCounter = 2; /*2 means second element of list*/
    SLNode *WalkerNode = list->head.next->next; /*WalkerNode will start from second element*/
    SLNode *PreWalker = list->head.next; /*PreWalker will start from 1st element*/
    while(PosCounter < N){
      PreWalker = WalkerNode;
      WalkerNode = WalkerNode->next;
      PosCounter ++;
    }
    PreWalker->next = node;
    node->next = WalkerNode;
    list->count ++;
  } else{
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListInsertOrdered
 * Description : Function to Insert node in sortef order
 * Params : SLList *, Pointer to a NodeCompare function(userdefined)
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListInsertOrdered(SLList *list, SLNode *node, ResultMove (*NodeCompare)(PVoid, PVoid)){
  ResultCode res = NoError;
  ResultMove resM = MoveFalse;
  if(list && NodeCompare){
    if((resM = NodeCompare(list->head.next, node)) == MoveFalse){
      res = SLListInsertHead(list, node);
    } else if((resM = NodeCompare(list->tail.next, node)) == MoveTrue){
      res = SLListInsertTail(list, node);
    } else{
      SLNode * WalkerNode = list->head.next->next; 
      SLNode * PreWalker = list->head.next;
      while(WalkerNode && NodeCompare(WalkerNode, node)){
        PreWalker = WalkerNode;
        WalkerNode = WalkerNode->next;
      }
      PreWalker->next = node;
      node->next= WalkerNode;
    }
  }else{
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListDeleteHead
 * Description : Function to delete node at head pos in list
 * Params : SLList *, Pointer to a deletenode function(userdefined)
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListDeleteHead(SLList *list, ResultCode (*DeleteNode)(SLNode *)){
  ResultCode res = NoError;
  if(list->count <= 0){
    return LLUnderFlowError;
  }
  if(list && DeleteNode){
    if(list->head.next){
      SLNode *NodeToDelete = list->head.next;
      list->head.next = list->head.next->next;
      res = DeleteNode(NodeToDelete);
      list->count --;
    }else {
      res = LLHeadNullError;
    }
  } else {
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListDeleteTail
 * Description : Function to delete node at tail pos in list
 * Params : SLList *, Pointer to a deletenode function(userdefined)
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListDeleteTail(SLList *list, ResultCode (*DeleteNode)(SLNode *)){
  ResultCode res = NoError;
  if(list->count <= 0){
    return LLUnderFlowError;
  }
  if(list && DeleteNode){
    SLNode *WalkerNode = list->head.next;
    SLNode *NodeToDelete = NULL;
    while(WalkerNode->next){
      NodeToDelete = WalkerNode;
      WalkerNode = WalkerNode->next;
    }
    WalkerNode->next = NULL;
    list->count --;
    if(NodeToDelete){
      res = DeleteNode(NodeToDelete);
    }
  }else{
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListDeleteNth
 * Description : Function to delete node at Nth pos in list
 * Params : SLList *, Pointer to a deletenode function(userdefined), N
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListDeleteNth(SLList *list, ResultCode (*DeleteNode)(SLNode *), U64 N){
  ResultCode res = NoError;
  if(N > list->count){
    return LLInvalidPosError;
  }
  if(list && DeleteNode){
    if(N == 1){
      res = SLListDeleteHead(list, DeleteNode);
    }else if(N == list->count){
      res = SLListDeleteTail(list, DeleteNode);
    }else{
      U64  PosCounter = 2;/*from Second Node*/
      SLNode *WalkerNode = list->head.next->next; /*from second node*/
      SLNode *PreWalker = list->head.next; /*from first node*/
      while(PosCounter < N){
        PreWalker = WalkerNode;
        WalkerNode = WalkerNode->next;
      }
      PreWalker->next = NULL;
      if(WalkerNode){
        res = DeleteNode(WalkerNode);
      }
      list->count --;
    }
  }else{
    res = NullPointerError;
  }
  return res;
}

/*
 * Name : SLListDeleteNode
 * Description : Function to delete node from list
 * Params : SLList *, SLNode *,Pointer to a deletenode function(userdefined)
 * Returns : ResultCode, Appropriate error code
 */
ResultCode SLListDeleteNode(
  SLList *list, SLNode *node, 
  ResultCode (*DeleteNode)(SLNode *),
  ResultCode (*NodeCompare)(PVoid, PVoid)
  ){

  ResultCode res = NoError;
  ResultMove resM = MoveFalse;
  U64 N = 1;

  if(list && node && DeleteNode && NodeCompare){
    if((resM = NodeCompare(list->head.next, node)) == MoveFalse){
      res = SLListDeleteHead(list, DeleteNode);
    }else if((resM = NodeCompare(list->tail.next, node)) == MoveTrue){
      res = SLListDeleteTail(list, DeleteNode);
    }else{
      SLNode *WalkerNode = list->head.next->next;
      SLNode *PreWalker = list->head.next;
      while(WalkerNode && NodeCompare(WalkerNode->next, node)){
        PreWalker = WalkerNode;
        WalkerNode = WalkerNode->next;
      }
      PreWalker->next = WalkerNode->next;
      res = DeleteNode(WalkerNode);
      list->count--;
    }
  }else{
    res = NullPointerError;
  } 
 return res;
}

/*
 * Name : SLListDeleteList
 * Description : Function to delete list
 * Params : SLList *, Pointer to a deletenode function(userdefined)
 * Returns : ResultCode, Appropriate error code
 */

ResultCode SLListDeleteList(SLList *list, ResultCode (*DeleteNode)(SLNode *)){
  ResultCode res = NoError;
  if(list && list->head.next && DeleteNode){
    SLNode *NodeToDelete = list->head.next;
    while(NodeToDelete->next){
      if((res = DeleteNode(NodeToDelete))){
        break;
      }
    }
  }else{
    res = NullPointerError;
  }
  return res;
}
