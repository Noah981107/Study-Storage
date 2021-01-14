#pragma once
#include "NHS_실습08_Canvas.h"
#define DIM 40

class Monster {
protected:
	string name, icon;	                         // 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem; 	                         // 현재 위치와 먹은 아이템 수

	void clip(int maxx, int maxy) {              // 몬스터가 밖으로 나가지 않게 하는 함수
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	} 
	void eat(int** map) {                        // 몬스터가 아이템을 먹는 함수
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
		}
	}
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)  // 생성자 디폴트 매개변수를 이용한 초기화
		: name(n), icon(i), x(px), y(py), nItem(0) {}
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }     // 소멸자를 이용한 내용 출력

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }                 // 몬스터가 움직일 화면을 그리는 함수
	void move(int** map, int maxx, int maxy) {                             // 몬스터가 움직이는 함수 8가지의 방향으로 움직임
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << endl; }  // 몬스터에 대한 정보 출력
};