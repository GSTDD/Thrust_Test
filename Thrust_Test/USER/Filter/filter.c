#include "filter.h"

#define Filter_N 15
/*---------------------------------------------------------------------------------------------------------*/
/* Function: Moving_Average                                                                                */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*               buf	- [in]                                                                               */
/*               data	- [in]                                                                               */
/* Returns:                                                                                                */
/*	          Filter_ / (Filter_N-1)                                                                       */
/*                                                                                                         */
/* Description:                                                                                            */
/*             	                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
float Moving_Average(float *buf,float data)
{
	int i;
	float Filter_Sum = 0.0;	
	
	buf[Filter_N-1] = data;
	for(i=0;i<Filter_N;i++)
	{
		buf[i] = buf[i+1];
		Filter_Sum = Filter_Sum + buf[i];
	}
	return  (Filter_Sum / (Filter_N-1));
}
