/*******************************************************************************
*
*     FILENAME       :    mergesort
*
*     DESCRIPTION    :    This file defines the binary function.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*                             New code for linear
*
*    
*
*******************************************************************************/

#include <header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    insertion
*
*     DESCRIPTION     :    This function sorts the array using merge sort
*     RETURNS         :    void
*
*******************************************************************************/


void mergesort(int array[30],int beg, int end)
	{
		int mid;		/* variables middle term */
		
		if(beg<end)
			{
				mid=(beg+end)/2;
				mergesort(array, beg, mid);
				mergesort(array, mid+1, end);
				merge(array, beg, mid, mid+1, end);
			}
	}


/******************************************************************************
*
*     FUNCTION NAME   :    merge
*
*     DESCRIPTION     :    This function sorts the array using merge sort
*     RETURNS         :    void
********************************************************************************/

void merge( int array[30],     /* array to be received */
	    int lb1,		/* parameters declared for position */
	    int ub1,
	    int lb2,
	    int ub2)
	{
		int c[30];	/* temporary array declared*/
		int kindex; 	/* temporary array index*/
		int lindex;  /* index for lower half */
		int uindex;  /* index for upper half */

		lindex=lb1;
		uindex=lb2;
		kindex=0;
		
		while(lindex<=ub1 && uindex<=ub2)
			{
				if(array[lindex]<=array[uindex])
					{

						c[kindex]=array[lindex];
						kindex++;
						lindex++;
					}
				else
					{
						c[kindex]=array[uindex];
						kindex++;
						uindex++;
					}
			}
		
		while(lindex<=ub1)
			{
				c[kindex]=array[lindex];
				kindex++;
				lindex++;
			}
		while(uindex<=ub2)
			{
				c[kindex]=array[uindex];
				kindex++;
				uindex++;
			}

		kindex=0;
		lindex=lb1;
		
		while(lindex<=ub2)
			{
				array[lindex]=c[kindex];
				lindex++;
				kindex++;	
			}
	}
		
		
