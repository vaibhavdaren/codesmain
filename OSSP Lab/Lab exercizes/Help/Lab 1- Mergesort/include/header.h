/*******************************************************************************
*
*     FILENAME       :    header.h
*
*     DESCRIPTION    :    This file defines the macros and the structure of the *   			node used for the list.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     14 May 2016  
*
*     
*
*******************************************************************************/

/********************** Header File Inclusions ********************************/
#include <stdio.h>
#include<stdlib.h>

/********************** Function Declaration **********************************/

void mergesort(int array[], int beg, int end);
void merge(int array[], int lb1, int ub1, int lb2, int ub2);
