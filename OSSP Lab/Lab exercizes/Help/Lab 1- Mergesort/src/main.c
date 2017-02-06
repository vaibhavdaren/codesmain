/********************************************************************************
*     FILENAME       :    main.c
*
*     DESCRIPTION     :  The main takes the array of integers to sort
*     Revision History    :
*     DATE        NAME                	REFERENCE            REASON
*     ----------------------------------------------------------	
*    
*
*******************************************************************************/

#include<header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    main	
*     
*     DESCRIPTION     :    sorts  array
*     RETURNS         : SUCCESS 
*
*******************************************************************************/
int main(void)
{
	int index, range;
	int array[30];		// array of words to be input

	printf(" enter the number of numbers \n");
	scanf("%d", &range);
	
	for(index=0;index<range;index++)
		{
			printf(" enter the number\n");
        		scanf("%d", &array[index]);
	
		}
	
	for(index=0;index<range;index++)
		printf("%d \t",array[index]);


	mergesort(array,0, range-1);
        
	printf("\n");
	
	for(index=0;index<range;index++)
		printf("--->%d",array[index]);

return 0;
}
