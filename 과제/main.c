// 페이지 입력을 받고
// 각 역할을 하는 함수들을 호출함
#include "Header.h"

int main(void)
{
	int Tnum, Dnum; 
	int i,j; 
	int TPage; 
	int count[10];
	scanf("%d", &Tnum);

	// 테스트 진행
	for (i = 0; i < Tnum; i++) {
		scanf("%d", &TPage);
		Dnum = findDigit(TPage);
		for (j = 0; j < 10; j++) {
			count[j] = cntPage(j,TPage,Dnum);
		}
		printRes(count,10);
	}
	return 0;
}
