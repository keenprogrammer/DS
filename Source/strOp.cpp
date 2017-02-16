/*
 * =====================================================================================
 *
 *       Filename:  strOp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Friday 03 February 2017 06:08:37  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * =====================================================================================
 */
#include<iostream>
#include<string.h>
/*suppose 
str= "Premvir singh chaudhary"
substr = "singh"*/

using namespace std;

int FindSubStr(char * str, char *substr) {
  int ret = 0;
  int str_i = 0, str_j = 0;
  int sub_str_i = 0;
  while(str[str_i] != '\0') {
   /*March first character*/
    if ((str[str_i] == ' ') || (str[str_i] != substr[sub_str_i])) {
      str_i ++;
      continue;
    }
    /*start comparing if first latter match*/
    str_j = str_i;
    while ((str[str_i] != '\0') && (substr[sub_str_i] != '\0')) {
      if (str[str_i++] != substr[sub_str_i++]) {
        ret = -1;
        break;
      }
    }
    if ((ret == -1) || (str[str_i++] == '\0' && substr[sub_str_i++] != '\0')) {
      ret = -1;
      break;
    } else if (substr[sub_str_i++] == '\0') {
       ret = str_j;
       break;
    } 
  }
  return ret;
}

int StrEqual(char * str1, char *str2) {
  int i = 0, ret = -1;
  while ((str1[i] != '\0') && (str2[i] != '\0') && str1[i] == str2[i++]) {
    if((str1[i] == '\0') && (str2[i] == '\0')) {
      ret = 0;
    }
  }
  return ret;
}

int FindSubStrN(char * str, char *substr){
  int ret = 0;
  int str_i = 0, str_j = 0;
  int sub_str_i = 0;
  int count = 0;
  while(str[str_i] != '\0') {
   /*March first character*/
    if ((str[str_i] == ' ') || (str[str_i] != substr[sub_str_i])) {
      str_i ++;
      continue;
    }
    /*start comparing if first latter match*/
    str_j = str_i;
    while ((str[str_i] != '\0') && (substr[sub_str_i] != '\0')) {
      if (str[str_i++] != substr[sub_str_i++]) {
        ret = -1;
        break;
      }
    }
    if ((ret == -1) || (str[str_i++] == '\0' && substr[sub_str_i++] != '\0')) {
      ret = -1;
      break;
    } else if (substr[sub_str_i++] == '\0') {
      sub_str_i = 0; /*starting substr counter*/
      count ++;
    } 
  }
  return count;
}


int main() {
 string st1;
 string st2;
 char str1[100];
 char str2[100];
 cout<<"Enter 2 Strings"<<endl;
 getline(cin, st1);
 getline(cin, st2);
 
 strcpy(str1, st1.c_str());
 strcpy(str2, st2.c_str());
 cout<<StrEqual(str1, str2)<<endl;
 cout<<FindSubStr(str1,str2)<<endl;
 cout<<FindSubStrN(str1,str2)<<endl;
 return 0;
}

