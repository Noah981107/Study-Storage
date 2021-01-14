#pragma once
#include "NHS_실습08_Canvas.h"
#include "NHS_실습08_VariousMonsters.h"
#include "NHS_실습08_Matrix.h"
#include <windows.h>
#define MAXMONS 9

class MonsterWorld {                                         // Monster 클래스 객체 b
	Matrix world;											 // Matrix 클래스 객체 world
	int xMax, yMax, nMon, nMove;							 // 멤버 변수 xMax, yMax, nMon, nMove
	Monster* pMon[MAXMONS];									 // 몬스터의 객체를 동적할당 하기위하여 포인트 배열 사용
	Canvas	canvas;											 // Canvas 클래스 객체 canvas

	int& Map(int x, int y) { return world.elem(x, y); }		 // 게임이 실행되는 필드 출력
	bool isDone() { return countItems() == 0; }				 // 게임의 종료여부 확인하는 함수
	int countItems() {										 // 아이템 숫자를 반환하는 함수
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {										     // 게임 속에서 몬스터가 활동하는 전체적인 화면 출력 하는 함수
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World (세상의 모든 귀신) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}
public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {   // 생성자를 이용한 몬스터 맵 설정
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;  
	} 
	~MonsterWorld() {                                                            // 소멸자를 이용한 동적 할당 해제
		for (int i = 0; i < nMon; i++) 
			delete pMon[i];
	}
	void add(Monster* m) {                                                       // 몬스터의 정보를 추가하는 함수
		if (nMon < MAXMONS)
			pMon[nMon++] = m;
	}																			
	void play(int maxwalk, int wait) {										     // 실제적인 게임을 실행시키는 함수
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {                                      // 몬스터에 대한 움직임 실행
			((Zombie*)pMon[0])->move(world.Data(), xMax, yMax);
			((Vampire*)pMon[1])->move(world.Data(), xMax, yMax);
			((KGhost*)pMon[2])->move(world.Data(), xMax, yMax);
			((Jiangshi*)pMon[3])->move(world.Data(), xMax, yMax);
			((Jiangshi*)pMon[4])->move(world.Data(), xMax, yMax);
			((Smombi*)pMon[5])->move(world.Data(), xMax, yMax);
			((Siangshi*)pMon[6])->move(world.Data(), xMax, yMax);
			((Siangshi*)pMon[7])->move(world.Data(), xMax, yMax);
			((HyunSeung*)pMon[8])->move(world.Data(), xMax, yMax);
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};