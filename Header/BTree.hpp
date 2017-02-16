/*
 * =====================================================================================
 *
 *       Filename:  BTree.hpp
 *
 *    Description:  This file contains binary tree implementation
 *
 *        Version:  1.0
 *        Created:  Thursday 16 February 2017 07:34:46  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * =====================================================================================
 */

#ifndef __BTREE_HPP__
#define __BTREE_HPP__

#ifdef __cplusplus
extern "C" {
#endif

using namespace std;
typedef struct tNode{
  tNode *left;
  tNode *right;
  void *data;
};

typedef enum TreeType{
  BST_Tree = 0,
  CompleteBinary_Tree,
  StrictedBanary_Tree
};


class BTree {
public :
  BTree(int (*keyFunc)(tNode *, tNode *), void (*disp)(void*)) {  
    keyFunction = keyFunc;
    displayFunction = disp;
    head = NULL;
    cout<<"Object Creation Successful "<<endl;
  }

  ResultCode InsertToTree(void *data) {
    tNode * temp = NULL;
    tNode * newtemp = NULL;
    int flag = 0;
    /*data null*/
    if (!data) {
      cout<<"Data is Null "<<endl;
      return NullPointerError;
    }
    /*Node creation*/
    if (!(newtemp = CreateNode(data))) {
      cout<<"Memory Allocation failure ::";
      return NullPointerError;
    }

    /*Head null*/
    if (!head) {
      cout<<"First Node Inserted :: "<<endl;
      head = newtemp;
      return NoError;
    }
 
    /*head not null*/
    temp = head; 
    while (1)
    {
      flag = keyFunction(newtemp, temp);
      switch(flag) {
        case 0:
          return NullPointerError;
        case 1:
          temp = temp->left;
          break;
        case 2:
          temp->left = newtemp;
          return NoError;
        case 3:
          temp = temp->right;
          break;
        case 4:
          temp->right = newtemp;
          return NoError;
      }
    }
  }

  ResultCode DeleteFromTree() {
  }
  
  void TraverseTree() {
    cout<<"Pre-Order Traversal ::"<<endl;
    preOrder(head);
    cout<<"In-Order Traversal ::"<<endl;
    inOrder(head);
    cout<<"Post-Order Traversal ::"<<endl;
    postOrder(head);
  }  

protected : 
  tNode  *head;
  TreeType  tType; 
private : 
  int (*keyFunction)(tNode *, tNode *);
  void (*displayFunction)(void *);

  void preOrder(tNode *root) {
    if (!root) {
      return;
    }
    displayFunction(root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
  void postOrder(tNode *root) {
    if (!root) {
      return;
    }
    postOrder(root->left);
    postOrder(root->right);
    displayFunction(root->data);
  }
  void inOrder(tNode *root) {
    if (!root) {
      return;
    }
    inOrder(root->left);
    displayFunction(root->data);
    inOrder(root->right);
  }

  tNode* CreateNode(void * data) {
    tNode *temp = (tNode*)malloc(sizeof(tNode));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
  }
};


#ifdef __cplusplus
}
#endif

#endif /*__BTREE_HPP__*/
