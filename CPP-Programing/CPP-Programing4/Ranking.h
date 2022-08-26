#include <cstdio>

struct PlayInfo {
	char	name[200];	                          // 선수의 이름을 저장할 멤버 name[200]
	int	nMove;		                              // 퍼즐 조각을 움직인 횟수 멤버 nMove
	double	tElapsed;	                          // 경기 시간 멤버 tElapsed
};
extern void loadRanking(char* filename);          //랭킹 파일 생성
extern void storeRanking(char* filename);         //파일에 랭킹 저장
extern void printRanking();                       //랭킹 출력
extern int addRanking(int nMove, double tElap);   //기존랭킹에 새로운 정보를 저장