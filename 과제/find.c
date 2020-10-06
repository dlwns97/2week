#include "Header.h"

int findDigit(int Page)
{
	int Digit = 0;

	if (Page < 1) {
		printf("Error, Wrong Input! \n");
		return -1;

	}
	else {
		while (1) {
			Digit++;
			if ((Page /= 10) == 0)
				break;
		}
	}
	return Digit;
}

int cntPage(int target, int TPage, int Dnum) {
	int count = 0; 
	int i;
	int ExtraHelp;
	
	int digit_num[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
	// i번째 자리에 target의 등장 횟수
	for (i = 1; i <= Dnum; i++)
	{
		// Base
		// 0일 때 특수성이 있음을 인지
		if (Dnum > 1) {
			if (i == Dnum && target == 0)
				break;
		}
		count += ((TPage / digit_num[i]))*digit_num[i-1];
		// Extra
		// ExtraHelp 는 TPage의 i번째 자리의 수
		ExtraHelp = (TPage % digit_num[i]) / digit_num[i - 1];
		if (target < ExtraHelp) {
			count += digit_num[i - 1];
		}
		else if (target == ExtraHelp) {
			count += (TPage % digit_num[i]) % digit_num[i - 1] + 1;
		}
		else {}
		if (target == 0)
			count -= digit_num[i - 1];
	}
	return count;
}
