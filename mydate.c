#include <sys/time.h>		// 시스템 시간 라이브러리
#include <unistd.h>		// 접근권한 라이브러리
#include <stdio.h>		// 입출력 라이브러리
#include <time.h>		// 시간 라이브러리
int main(void)
{
    time_t curr;	 // 현재 시간 가져오기위함
    struct tm *store;	// 타임 함수 구조체 사용
    curr=time(NULL);	// 시간 값 초기화
    store=localtime(&curr);	// 로컬 타임 저장
    printf("%s", asctime(store)); // 로컬 타임 출력
    return 0;
}


