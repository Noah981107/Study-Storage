#pragma once
#include <iostream>
#include <string>
#include "NHS_실습11_Point.h"			
#define MAXLINES 100
using namespace std;

class Canvas {														
	string line[MAXLINES];                                         // 화면 출력을 위한 문자열
	int xMax, yMax;												   // 맵의 크기
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {		   // 몬스터가 움직일 캔버스를 디폴트 매개변수를 이용한 초기화
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {						   // 몬스터가 움직일 화면을 그리는 함수
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}

	void draw(Point& p, string val) { draw(p.x, p.y, val); }       // draw 함수를 중복하여 몬스터가 움직일 화면을 그리는 함수

	void clear(string val = ". ") {                                // 몬스터 움직일 화면을 초기화 하는 함수
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char* title = "<My Canvas>") {				   // 몬스터가 움직일 전체 게임 화면을 출력하는 함수
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};