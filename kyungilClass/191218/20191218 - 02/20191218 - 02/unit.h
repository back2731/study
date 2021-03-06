#pragma once
#include <iostream>
using namespace std;

/*
	상속관계란?
	"무엇은 무엇의 한 종류이다."라는 뜻으로 파생됐다.
	서브클래싱, 확장 등 여러 이름으로 불리며
	객체지향프로그램의 근간이 된다.

	부모 -> 자식

	클래스간의 상속관계를 맺을 때에는 공통의 기능을
	상위 클래스에 묶어 넣어 다른 클래스로 확장할 수 있게
	하는 것이 목적이다.

	만약 클래스들이 서로 비슷하거나 또는 완전히 같은 코드를 가지고 있다면,
	해당 코드를 상위 클래스로 묶어 내는 것을 고려하는 것이 좋다.

	이유 : 프로그램 변경에 대응을 유연하게 할 수 있다.
	기능을 추가함에 따른 프로그램 확장도 편리하다.

	ex) 사람 클래스
	(이름, 나이 등등 속성들이 존재하고 게임하기, 똥싸기, 먹기 등등 행동들이 존재한다.)

	ex) 학생 클래스
	(이름, 나이 등등 속성이 존재 게임하기, 똥싸기, 먹기 등등 행동들이 있다.)

	그래서 공통적으로 가지고 있는 속성과 행동을 가지고 있다면, 물려받아서 사용하는 것이 좋다.
*/

class unit
{
private:
	int privateMoney;		// 부모님의 비자금

public:
	int publicMoney;		// 길에서 돈주움(아무나 주울 수 있다.)

protected:	// 상속관계에서만 허용된다.
	int familyMoney;		// 우리집 한달 생활비

public:
	unit();
	~unit();

	void init();
};

