#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"progressBar.h"
#define PLAYERSPEED 5

/*
	참고 : 헤더파일이 많아 질수록 컴파일 속도가 저하된다.
	class A가 a.h에 있고 class B가 b.h에 있는데
	B가 A를 사용하고 A가 B를 사용할 경우 설계가 잘못되었다고 볼 수 있다.
	이렇게 하면 이해하기도 힘들고 추적이 힘들다.

	A는 B의 데이터를 알기 위해서 당연히 B의 구조를 알아야 하고
	즉, b.h를 인클루드 해야한다.
	하지만 B에서 이미 a.h를 인클루드 하고 있기에 B의 헤더를 A에 인클루드하면 상호 참조 에러가 된다.
	구조를 바꾸지 않으면 인클루드 할 수 없다.

	A에서 B를 인클루드 한다고 할 때, 만약 b.h가 수정되면 인클루드 부분도 이 영향을 받기 때문에
	수정이 많아 질수록 컴파일 속도도 저하된다.
	이것을 해결하기 위한 방법은 클래스 전방선언이다.
	
	장점
	참조하려는 헤더파일에 변경이 생겨도 참조하는 헤더파일에서는 재컴파일이 이루어지지 않는다.
	단, 주의 해야 할점 : 전방선언을 사용할 경우 그 클래스 관련 객체는 포인터형으로 선언해야 한다.
	만약 포인터형이 아닌 객체를 생성할 경우 전방선언의 특징상 그 객체의 크기를 정확히 파악하여 할당을 못해준다.
	(해당 클래스가 있다는 정보만 알고 사이즈를 모른다.)
*/
// 상호참조용 적 매니저 클래스 전방선언
class enemyManager;

class rocket :public gameNode
{
private:

	image * _player;
	
	missile* _missile;
	nuclear* _nuclear;
	RECT rc;

	// 프로그레스바
	progressBar* _hpBar;
	float _maxHp;
	float _currentHp;

	enemyManager* _em;		// 적 매니저 클래스 선언

public:
	rocket();
	~rocket();

	HRESULT init();
	void release();
	void update();
	void render();

	// 불렛 삭제
	void removeBullet(int arrNum);
	
	// 충돌
	void collision();

	// 피깎는 함수
	void hitDamage(float damage);

	// 뉴클리어 가져오기
	nuclear* getNuclear() { return _nuclear; }
	image* getRocketImage() { return _player; }


	void setEnemyMemoryLink(enemyManager* em) { _em = em; }
};

