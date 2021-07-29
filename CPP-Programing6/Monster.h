#pragma once
#include "NHS_실습06_Canvas.h"
#define DIM 40

class Monster {
	string name, icon;            	// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem, Energy;		// 현재 위치와 먹은 아이템 수

	void clip(int maxx, int maxy) {  // 몬스터가 정해진 배열 안에서만 움직일 수 있도록 하는 함수  
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int map[DIM][DIM]) {    // 몬스터가 아이템을 먹는 함수
		if (map[y][x] == 1) {        // 배열의 칸이 1이면 실행
			map[y][x] = 0;           // 아이템을 1이라고 생각하면, 그 자리에 해당하는 아이템을 먹었으니 0으로 변환
			nItem++;                 // 아이템의 숫자를 1증가
			Energy = Energy + 8;     // 아이템을 먹었기 때문에 에너지는 8 증가
		}
		else {                       // 아이템이 없는 칸
			Energy = Energy - 1;     // 에너지를 1감소
			if (Energy < 0)          // 에너지가 0보다 작아진다면, 에너지의 최솟값이 0이기 때문에 0으로 변환
				Energy = 0;
		}
	}
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0, int nEnergy = 0)  // 생성자를 통한 디폴트 매개변수를 이용하여 몬스터의 정보를 받음
		: name(n), icon(i), x(px), y(py), Energy(nEnergy), nItem(0) {}
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }                      // 소멸자를 이용한 문구 출력

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }							        // 게임화면을 그리는 함수 
	void move(int map[DIM][DIM], int maxx, int maxy) {                                      // 몬스터가 움직이는 함수
		switch (rand() % 8) {                                                               // 위치한 칸을 기준으로 총 8가지의 경우의 수를 가지고 이동 가능
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
	void print() { cout << "\t" << name << icon << ":" << nItem << "\t" << "E :" << Energy << endl; } // 게임에서 몬스터의 정보를 출력
};