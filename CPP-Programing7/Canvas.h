#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
<<<<<<< HEAD
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
=======
	string line[MAXLINES];	                                         // 화면 출력을 위한 문자열
	int xMax, yMax;		                                             // 맵의 크기
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {          // 몬스터가 움직일 캔버스를 디폴트 매개변수를 이용한 초기화
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {                            // 몬스터가 움직일 화면을 그리는 함수
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}
	void clear(string val = ". ") {	                                 // 몬스터 움직일 화면을 초기화 하는 함수
>>>>>>> cp7/main
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
<<<<<<< HEAD
	void print(const char* title = "<My Canvas>") {                     // 게임화면을 출력하는 함수
=======
	void print(const char* title = "<My Canvas>") {                  // 몬스터가 움직일 전체 게임 화면을 출력하는 함수
>>>>>>> cp7/main
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};