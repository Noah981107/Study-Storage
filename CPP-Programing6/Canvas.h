#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];												// 화면 출력을 위한 문자열
	int xMax, yMax;														// 맵의 크기
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {				// 디폴트 매개변수 nx,ny를 이용하여 초기화 
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');						    // 출력되는 칸이 2bit의 크기를 가지고 있음
	}
	void draw(int x, int y, string val) {                               // 화면의 랜덤한 위치를 갖는 함수 
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}
	void clear(string val = ". ") {		                                // 캔버스를 동일한 val로 저장
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char* title = "<My Canvas>") {                     // 게임화면을 출력하는 함수
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};