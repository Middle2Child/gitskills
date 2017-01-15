#include <stdio.h>
#include <stdlib.h>
int main(){
	struct {
		int flyTime;
		int reachTime;
	} schdule[8] = { 
		{ 8 * 60 +  0,  10 * 60 +  16},
		{ 9 * 60 + 43,  11 * 60 +  52},
		{11 * 60 + 19,  13 * 60 +  31},
		{12 * 60 + 47,  15 * 60 +  0},
		{14 * 60 +  0,  16 * 60 +  8},
		{15 * 60 + 45,  17 * 60 +  55},
		{19 * 60 +  0,  21 * 60 +  20},
		{21 * 60 + 45,  23 * 60 +  58},
	};
	int hour,minute;	//用户输入
	int time_input;		//用户输入的时刻距离午夜的分钟数
	int i, j, flag, temp;
	printf("Enter a 24-hour time:");
	scanf("%d:%d",&hour,&minute);
	time_input = hour * 60 + minute;

	for(i = 0; i < 8; i++){
		flag = 0;
		temp = abs( schdule[i].flyTime - time_input );
		for(j = 0; j < 8; j++){
			if(temp <= abs( schdule[j].flyTime - time_input ))
				flag++;
		}
		if(flag == 8)
			break;
	}
	
	printf("Cloest departure time is  %2d:%.2d, arriving at %2d:%.2d.\n",
		schdule[i].flyTime/60, schdule[i].flyTime%60, schdule[i].reachTime/60, schdule[i].reachTime%60);
	
	return 0;
}
