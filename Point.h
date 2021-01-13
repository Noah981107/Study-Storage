#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Point {
	int x, y;		        //  점의 x와 y 좌표 값
	friend class Monster;	//  Monster를 친구 클래스로 등록
	friend class Canvas;	//  Canvas를 친구 클래스로 등록
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {  } // 생성자와 디폴트 매개변수를 이용한 멤버 초기화 리스트
	int& operator[] (int id) {	// 인덱스 연산자 중복
		if (id == 0) return x;
		else if (id == 1) return y;
		else exit(0);
	}
	operator double() { return sqrt((double)x * x + y * y); }   // double 형 변환 중복
	void operator()(int maxx, int maxy) {                       // () 연산자 중복
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	Point operator- () { return Point(-x, -y); }                    //-연산자 중복
	bool operator== (Point& p) { return x == p.x && y == p.y; }     // == 연산자 중복
	bool operator!= (Point& p) { return x != p.x || y != p.y; }		// != 연산자 중복
	Point operator- (Point& p) { return Point(x - p.x, y - p.y); }	// - 연산자 중복
	Point operator+ (Point& p) { return Point(x + p.x, y + p.y); }	// + 연산자 중복
	void operator+= (Point p) { x += p.x, y += p.y; }				// += 연산자 중복
	void operator-= (Point& p) { x -= p.x, y -= p.y; }				// -= 연산자 중복
};





