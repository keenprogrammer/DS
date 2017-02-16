/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  Function to compile cpp files
 *
 *        Version:  1.0
 *        Created:  Saturday 03 September 2016 11:03:26  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * =====================================================================================
 */

#include <DH.hpp>
#include <BTree.hpp>



#ifdef   __cplusplus
extern "C"  {
#endif
void Hash_copmipation()
{
  std::cout<<"C++ Hash Compilation Done"<<std::endl;
  return;
}

int arr[] = {10,20,5,23,45,3,2,4,745,11};
void display (void *data) {
 cout<<*((int*)data)<<endl;
}

int key_function(tNode *newt, tNode *node) {
  if (!newt || !node) {
    return 0;
  } else if ((*(int *)(newt->data) < *(int *)(node->data)) && node->left) {
    return 1;
  } else if ((*(int *)(newt->data) < *(int *)(node->data)) && !node->left) {
    return 2;
  } else if ((*(int *)(newt->data) > *(int *)(node->data)) && node->right) {
    return 3;
  } else if ((*(int *)(newt->data) > *(int *)(node->data)) && !node->right) {
    return 4;
  }
}
void Tree_Test() {
  BTree tree(key_function, display);
  tree.InsertToTree(&arr[0]);
  tree.InsertToTree(&arr[1]);
  tree.InsertToTree(&arr[2]);
  tree.InsertToTree(&arr[3]);
  tree.InsertToTree(&arr[4]);
  tree.InsertToTree(&arr[5]);
  tree.InsertToTree(&arr[6]);
  tree.InsertToTree(&arr[7]);
  tree.InsertToTree(&arr[8]);
  tree.InsertToTree(&arr[9]);
  
  tree.TraverseTree();
}


#ifdef  __cplusplus
}
#endif

