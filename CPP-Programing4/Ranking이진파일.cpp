#define _CRT_SECURE_NO_WARNINGS                           //fopen에서 자꾸 오류가 발생하여서 선언
#include "NHS_실습04_Ranking.h"              
#define NUM_MVP 10                                        // 상수 10를 NUM_MVP로 정의
static PlayInfo MVP[NUM_MVP];	                          // 랭킹 배열
static int nMVP = NUM_MVP;	                              // 랭킹 배열의 길이

static void initRanking() {                               //랭킹 초기화 함수       
	PlayInfo noname = { "C++좋아요", 1000, 1000.0 };      //초기화 시킬 내용
	for (int i = 0; i < nMVP; i++)                        //배열의 길이만큼 저장
		MVP[i] = noname;
}

void loadRanking(char* filename) {                        //랭킹을 저장할 파일 열기
	FILE* fp = fopen(filename, "r");                      //읽기모드로 파일을 연다.
	if (fp == NULL)                                       //파일이 없다면
		initRanking();                                    //초기화 함수 실행
	else {                                              
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);       //랭킹 저장할 파일 읽기
		fclose(fp);                                       //파일을 닫는다
	}
}
void storeRanking(char* filename) {                       //랭킹을 저장하는 함수
	FILE* fp = fopen(filename, "w");					  //파일을 저장모드로 연다.
	if (fp == NULL) return;								  //파일이 없다면 반환값 없음
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);		  //파일에 랭킹을 저장한다.
	fclose(fp);										      //파일을 닫는다
 }														  
														  
void printRanking() {                                                               //랭킹을 출력할 함수
	printf("  [순위] 이동횟수 이름            걸린시간   점수\n");                 
	for (int i = 0; i < nMVP; i++) {                                                //랭킹에 등록되어있는 각각의 정보 출력
		double score = 1000 -  MVP[i].tElapsed;
		printf("  [%2d위]  %4d    %-16s  %5.1f   %5.1f\n", i + 1, MVP[i].nMove,        
			MVP[i].name, MVP[i].tElapsed, score);
	}
		
}
int addRanking(int nMove, double tElap) {                                           // 게임 결과를 랭킹에 추가 저장
	if (nMove < MVP[nMVP - 1].nMove) {                                              // 기존의 저장된 정보에 따른 움직인횟수 확인
		int pos = nMVP - 1;                                                         
		for (; pos > 0; pos--) {                                                   
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;                                                     //새로운 정보를 기존 배열의 인덱스에 저장 
		MVP[pos].tElapsed = tElap;
		printf(" %d위입니다. 이름을 입력하세요: ", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}