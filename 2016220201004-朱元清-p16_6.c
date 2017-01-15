#include <stdio.h>
struct date {
	int month, day, year;
};
int compare_dates(struct date d1, struct date d2);
int main(){
	struct date d1, d2;
	printf("Enter first date (mm/dd/yy):");
	scanf("%d/%d/%d",&d1.month,&d1.day,&d1.year);
	printf("Enter second date (mm/dd/yy):");
	scanf("%d/%d/%d",&d2.month,&d2.day,&d2.year);
	if(compare_dates(d1,d2) < 0)
		printf("%d/%d/%d is earlier than %d/%d/%d\n",
		 d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
	else if(compare_dates(d1,d2) > 0)
		printf("%d/%d/%d is earlier than %d/%d/%d\n",
		 d2.month, d2.day, d2.year, d1.month, d1.year, d1.year);
	else
		printf("SAME DATE\n");	
}
/*
** 情况			返回值
** d1在d2之前		-1
** d1在d2之后		+1
** d1 = d2			 0	
*/
int compare_dates(struct date d1, struct date d2){
	int value_d1;
	int value_d2;
	if(d1.year < d2.year)
		return -1;
	if(d1.year > d2.year)
		return 1;
	
	value_d1 = 31 * d1.month + d1.day;
	value_d2 = 31 * d2.month + d2.day;
	
	if(value_d1 < value_d2)
		return -1;
	else if(value_d1 > value_d2)
		return 1;
	else
		return 0;
}