#pragma once
#include "NHS_실습06_Canvas.h"
#include "NHS_실습06_Monster.h"
#include <windows.h>
#define DIM  40
#define MAXMONS 5

class MonsterWorld {
	int map[DIM][DIM];                            //게임 상에서 몬스터가 움직일 필드
	int xMax, yMax, nMon, nMove;
	Monster mon[MAXMONS];
	Canvas	canvas;

	int& Map(int x, int y) { return map[y][x]; }  // 몸스터가 움직일 필드
	bool isDone() { return countItems() == 0; }   // 게임이 끝나는지를 판단하는 함수
	int countItems() {                            // 아이템의 숫자를 파악하는 함수
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {                                // 게임속에서 몬스터가 움직일 필드를 출력하는 함수
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
		for (int i = 0; i < nMon; i++)
			mon[i].draw(canvas);
		canvas.print("[ Monster World (몬스터들의 세상) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			mon[i].print();
	}
public:
	MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld() { }
	void add(Monster m) {                                       // 몬스터의 정보를 추가하는 함수
		if (nMon < MAXMONS) mon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {                          // 실제적인 게임을 실행시키는 함수
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				mon[k].move(map, xMax, yMax);
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};