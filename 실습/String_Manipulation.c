#include "Header.h"

// 전처리 과정
void Remove_Blanks_At_The_End( char *line ) {
	int i, k, newline_flag = 0;

	for ( k = 0; ; k++ ) {
		if ( line[k] == '\n' ) {
			newline_flag = 1;
			break;
		}
		else if ( line[k] == '\0' ) {
			break;
		}
	}
	// 뒤에서 부터 오는데 첫 단어를 만나면 break
	// k부터 시작하면 '\n' 이나 '\0' 만나면서 바로 종료
	for ( i = k-1; i >= 0; i-- ) {
		if ( line[i] != ' ' ) {
			break;
		}
	}
	// 줄바꿈 문자가 있다면 단어 뒤에 줄바꿈 문자를 붙여준다.
	if ( newline_flag == 1 ) {
		line[i+1] = '\n';
		line[i+2] = '\0';
	}
	else {
		line[i+1] = '\0';
	}
}

void Get_Blanks_Chars( char *line, int Start, int *N_Blanks, int *N_Chars ) {
	int i, blank_flag=0;

	// 공백, 문자 수 초기화
	*N_Blanks=0;
	*N_Chars=0;

	for ( i = Start; ; i++ ) {
		if ( (line[i] == '\n') || (line[i] == '\0') ) {
			break;
		}
		else if ( line[i] == ' ' ) {
			// 단어 이전에 만나 공백인지, 단어 다음에 나오는 공백인지 구분
			if ( blank_flag == 0 ) {
				++(*N_Blanks);
			}
			// 단어가 끝났다는 의미
			else {
				break;
			}
		}
		else {
			blank_flag = 1;
			++(*N_Chars);
		}
	}
}

