#pragma once
#include <string>
class FileException {	                                                 // 파일 예외 클래스
	string filename;													 // 파일 이름
	bool bRead;		        											 // 파일 모드
public:
	FileException(string name, bool b) : filename(name), bRead(b) {}     // 생성자를 이용한 멤버변수 초기화
};