#pragma once
#include "NHS_실습11_Canvas.h"
#include "NHS_실습11_Point.h"

class Monster {
public:
	string name, icon; 	                                // 몬스터 이름과 화면 출력용 아이콘
	int nItem;		                                    // 먹은 아이템 수
	Point q, p;		                                    // 이전 위치(q)와 현재 위치(p)
	int nSleep;		                                    // 쉬어야 하는 횟수
	double dist;		                                // 쉬고 난 다음 움직인 거리
	double total;		                                // 총 움직인 거리

	void clip(int maxx, int maxy) { p(maxx, maxy); }    // 몬스터가 밖으로 나가지 않게 하는 함수
	void eat(int** map) {                               // 몬스터가 아이템을 먹는 함수
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
		}
		dist += (double)(p - q);						
		total += (double)(p - q);
		q = p;
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}
	}
	bool isSleep() {                                   // 쉬어야 할 횟수를 판단하는 함수
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}
public:
	Monster(string n = "무명괴물", string i = "※", int x = 0, int y = 0)         // 생성자 디폴트 매개변수를 이용한 초기화
		: name(n), icon(i), nItem(0),
		p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}					  
	virtual ~Monster() { cout << icon << nItem << "거리:" << total << endl; }     // 소멸자를 이용한 내용 출력										  
	void draw(Canvas& canvas) { canvas.draw(p, icon); }							  // 몬스터가 움직일 화면을 그리는 함수
	virtual void move(int** map, int maxx, int maxy) {							  // 몬스터가 움직이는 함수 8가지의 방향으로 움직임
		if (!isSleep()) {
			int num = rand() % 9 + 1;	// 1 ~ 9
			p += Point(num % 3 - 1, num / 3 - 1);
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }    // 몬스터에 대한 정보 출력
};



																			