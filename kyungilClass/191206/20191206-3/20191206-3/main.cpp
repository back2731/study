#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	// 시드 값 초기화 -> 컴파일 할때 마다 값이 변한다.
	srand(time(NULL));

	// rand() -> 랜덤한 숫자를 뽑아낼 때 사용한다.
	int rndNum = rand();
	cout << rndNum << endl;

	// rand() % 5		-> 0 ~ 4 까지 랜덤한 숫자를 뽑아 낸다.
	int randomNumber = rand() % 5;
	cout << randomNumber << endl;
	// rand() % 5 + 1;	-> 1 ~ 5 까지 랜덤한 숫자를 뽑아 낸다.
	int randomNumber1 = rand() % 5 + 1;
	cout << randomNumber1 << endl;

	cout << "웰컴투 경일 게임 아카데미" << endl;

	int orcHp = 500;
	int orcAtk = rand() % 50;
	int humanHp = 500;
	int humanAtk = rand() % 50;
	int healingPotion = 200;

	cout << "A와 B가 만났다!!" << endl;
	cout << "A의 공격!" << endl;
	
	humanHp = humanHp - orcAtk;

	cout << "공격 " << orcAtk << "을 받아서 B의 체력이" << humanHp << "이(가) 되었다." << endl;
	
	orcHp -= humanAtk;
	cout << "B의 반격!!" << humanAtk << "만큼 반격을 가함! A의 체력이" << orcHp << "만큼 남았다!" << endl;

	humanHp += healingPotion;

	cout << "오른쪽 주머니에서 맥주캔을 꺼내 마셨다. 체력을 " << healingPotion << "만큼 회복!" << endl;
	cout << "B의 현재 체력은 : " << humanHp << endl;

	cout << sizeof(double);
	return 0;
}