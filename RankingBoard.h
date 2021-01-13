#pragma once
#include <iostream>
#include <fstream>
#include "NHS_실습11_FileException.h"
using namespace std;
#define NUM_MVP	5

struct PlayInfo {		                                              // 게임 정보 클래스
	string name;		                                              // 게이머의 이름
	int nItem;		                                                  // 획득한 아이템의 수
	double itemPerMove;	                                              // 이동 거리당 아이템 수
	PlayInfo(string na = "신인류", int ni = 0, double ipm = 0.0)      // 생성자와 디폴트 매개변수를 이용한 멤버 초기화 리스트 사용
		: name(na), nItem(ni), itemPerMove(ipm) {}
};

class RankingBoard {		                                          // 랭킹 관리 클래스
	PlayInfo MVP[NUM_MVP];                                            // 플레이어의 정보를 저장하는 클래스
	int nMVP = NUM_MVP;                                               // 플레이어 숫자
public:
	void load(string filename) {                                      // 파일을 여는 함수
		ifstream is;                
		is.open(filename);
		if (!is) 
			throw(FileException(filename, true));                     // 파일이 열리지 않을 때 예외 처리 -> catch로 넘어감
		for (int i = 0; i < nMVP; i++)
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;
		is.close();
	}
	void store(string filename) {                                     // 파일에 저장하는 함수
		ofstream os;
		os.open(filename);
		if (!os)
			throw(FileException(filename, false));                    // 파일에 저장할 수 없을 때 예외 처리 -> catch로 넘어감
		for (int i = 0; i < nMVP; i++)
			os << MVP[i].nItem << " " << MVP[i].name << " "
			<< MVP[i].itemPerMove << "\n";
		os.close();
	}
	void print(string title = "게임 랭킹") {                          // 게임 결과화면 출력하는 함수
		cout << endl << title << endl;
		for (int i = 0; i < nMVP; i++)
			cout << "[" << i + 1 << "위] " << MVP[i].name << "\t"
			<< MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";
		cout << "엔터를 입력하세요.";
		getchar();
		cout << endl;
	}
	int add(int nItem, double ipm) {                                  // 사용자 정보를 추가하는 함수
		if (nItem <= MVP[nMVP - 1].nItem) return 0;

		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (nItem <= MVP[pos - 1].nItem) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nItem = nItem;
		MVP[pos].itemPerMove = ipm;
		cout << "\n[" << pos + 1 << "위] 이름을 입력하세요: ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
};