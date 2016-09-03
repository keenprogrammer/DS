/*
 * ================================================================================================
 *
 *       Filename:  DH.hpp
 *
 *    Description:  File Contains Data Structure Hash Declaration
 *
 *        Version:  1.0
 *        Created:  Saturday 03 September 2016 08:42:02  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * ================================================================================================
 */
#ifndef __DH_HPP__
#define __DH_HPP__

#include "BasicType.h"
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ================================================================================================
 *  Hash Table Node 
 * ================================================================================================
 */
typedef struct DHash{
  void  *pData; /*Pointer to user data */
  struct DHash  *next; /*Pointer to next node*/
}DHash_t;

/*
 * ================================================================================================
 *  Hash Table Declaration
 * ================================================================================================
 */
class DHashTable{
/*Private Section*/
private:
#define DHashTableNameMaxLength  100
/* TableSize is to hold size of HashTable. Size of HashTable means size of bucket in Hash */
U64  TableSize;

/* Count is to hold number of element present in hash */
U64  Count;

/* pHashTableName, Opltional Perameter, Default Null */
char  *pHashTableName;

/* pCountPerBucket, Optional Perameter, will hold Number of Node/item per bucket, Default Null */
U64  *pCountPerBucket;

/**p_pHashTable, double pointer to HashTable Memory*/
DHash_t  **p_pHashTable;

/*Protected Section*/
protected:

/*Function Pointer to user Difined Function which will return bucket index*/
U64 (*getBucketNumber)(pVoid);

/*Function Pointer to user Difined Function which will compare the Nodes*/
ResultMove (*IsFound)(pVoid, pVoid);

/*Public Section*/
public:

/*~DHashTable*/
~DHashTable(){
/*Delete All everything in Objet*/
  DeleteHashTable();
}
/*Non-Perameterize Constructor*/
DHashTable(){
    TableSize = 0;
    Count = 0;
    pHashTableName = 0;
    pCountPerBucket = 0;
    p_pHashTable = 0;
}

/*Perameterize Constructor with default Name*/
DHashTable(U64 size, const char *pName = NULL){
    TableSize = size;
    Count = 0;
    pCountPerBucket = 0;
    /*Allocate Memory For p_pHashTable*/
    if(CreateHashTable(size) != NoError){
      LOG("HashTable Creation Failure");
      /*Should be abort*/
      exit(0);
    }
    setHashTableName(pName);
}

/*setHashTableName*/
void setHashTableName(const char *pName = NULL){
    if(pName){
      pHashTableName = (char *)DMALLOC(DHashTableNameMaxLength);
      if(pHashTableName && (DSTRLEN(pName) <= DHashTableNameMaxLength)){
        DSTRCPY(pHashTableName, pName);
      }else{
        /*Display Error Msg and return*/
        LOG("Memory Allocation Failure of HashTableName Length Exceeded");
      }
    }else{
      LOG("HashTableName Pass as Null");
    }
}

/*CreateHashTable*/
ResultCode CreateHashTable(U64 size){
  ResultCode rc = NoError;
  if(size <= 0){
    LOG("HashTable Size received as Invalid values");
    exit(0);
  }
  if(p_pHashTable = (DHash_t **)DMALLOC(sizeof(DHash_t) * size)){
    LOG("HashTable Allocation Successfull");
  }else{
    rc = NullPointerError;
  }
  return rc;
}

/*HashRegisterFunctions*/
ResultCode HashRegisterFunctions(U64 (*getB)(pVoid), ResultMove (*IsF)(pVoid, pVoid)){
  ResultCode rc = NoError;
  if (getB && IsF){
    getBucketNumber = getB;
    IsFound = IsF;
  }else {
    rc = NullPointerError;
  }
}

/*HashInsertNode*/
ResultCode HashInsertNode(DHash_t *pNode){
  ResultCode  rc = NoError;
  if(p_pHashTable){
    U64 BucketNo = getBucketNumber(pNode);
  /*Insert Node @ head of Bucket irrespect previous node*/
    pNode->next = p_pHashTable[BucketNo];
    Count ++;
  } else{
    rc = NullPointerError;
  }
  return rc;
}

/*HashDeleteNode*/
ResultCode HashDeleteNode(DHash_t *pNode){
  ResultCode  rc = NoError;
  DHash_t  *pWalkerNode = NULL;
  if(p_pHashTable){
    U64 BucketNo = getBucketNumber(pNode);
    pWalkerNode = p_pHashTable[BucketNo];
    if(pWalkerNode == pNode){
      p_pHashTable[BucketNo] = pWalkerNode->next;
      Count --;
    }else{    
      while(pWalkerNode && (pWalkerNode->next != pNode)){
        pWalkerNode = pWalkerNode->next;
      }
      if(pWalkerNode){
        pWalkerNode->next = pWalkerNode->next->next;
        Count --;
      }else{
        rc = DNodeNotPresent;
      }
    }
  } else{
    rc = NullPointerError;
  }
  return rc;
}

/*HashSearchNode*/
DHash_t * HashSearchNode(DHash_t  *pNode){
  DHash_t  *pWalkerNode = NULL;
  if(p_pHashTable){
    U64 BucketNo = getBucketNumber(pNode);
    pWalkerNode = p_pHashTable[BucketNo];
    if(IsFound(pWalkerNode, pNode)){
      return pWalkerNode;
    }else{    
      while(pWalkerNode && !IsFound(pWalkerNode->next, pNode)){
        pWalkerNode = pWalkerNode->next;
      }
      if(pWalkerNode){
        return pWalkerNode->next;
      }
    }
  }
  return NULL;
}

/*DeleteHashTable*/
ResultCode DeleteHashTable(){
  if (p_pHashTable)
      DFREE(p_pHashTable);
  
  if (pHashTableName)
      DFREE(pHashTableName);
  
  if (pCountPerBucket){
      DFREE(pCountPerBucket);
  }
 
  Count = 0;
  TableSize = 0;
}

/*getHashTableCount*/
U64 getHashTableCount(){
  return Count;
}

/*getHashPerBucketCount*/
ResultCode getHashPerBucketCount(U64 *pValue){
  if(!pCountPerBucket){
    return NullPointerError;
  }
  for(int i = 0; i < Count; i++){
    pValue[0] = pCountPerBucket[0];
  }
  return NoError;
}

/*End of Class DHashTable*/
};

#ifdef __cplusplus
}
#endif

#endif /*__DH_HPP__*/
