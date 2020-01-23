#include <iostream>
#include <string>
using namespace std;
/*
	구조체 : 변수들의 집합체
	프로그래밍중에 사용되는 많은 변수들을 하나로 묶어서 관리하기 위해 구조체를 사용한다.

	
	구조체는 무조건 퍼블릭
	클레스는 접근지정자가 퍼블릭 / 프라이빗 이 나누어져있다.
	
	ex) 몬스터의 데이터(이름, 설명, 능력치 등등...)저장한다고 할 때
	하나의 몬스터 데이터를 저장하기 위해서 많은 변수가 필요하다.
	이럴 때 구조체를 이용하면 관리하기 수월하다.	
	
	// 정의 형식
	struct Monster
	{
		int Hp;				// 멤버변수1
		int Mp;				// 멤버변수2
		int Atk;			// 멤버변수3
		int Def;			// 멤버변수4
		string name;		// 멤버변수5
	};

	// 명시한 이름으로 구조체 타입을 정의한다.
	내부에 정의된 변수들은 구조체가 가지는 멤버변수이다.

*/
//struct Monster
//{
//	int Hp;				// 멤버변수
//	int Mp;				// 멤버변수
//	int Atk;			// 멤버변수
//	int Def;			// 멤버변수
//	string name;		// 멤버변수
//};


struct tagUnit
{
	string name;
	int Hp;
	float Atk;
	bool Die;
};
/*
	지금 해볼것
	구조체를 이용해서 개인정보 노출하기.
	가족이름, 가족나이, 전화번호, 생년월일, 사는곳, 성별, 사람이가?
	좋아하는 음식 좋아하는 게임

*/
struct family
{
	string name;
	int age;
	string phoneNumber;
	string birthDate;
	string state;
	string gender;
	bool human;
	string food;
	string game;
	string idealtype;
};

int main()
{
	/* 
	구조체 멤버변수의 접근하기 위해서는
	.연산자를 이용한다. (멤버연산)
	*/

	/*tagUnit marin;
	
	cout << "마린 인터페이스" << endl;
	cout << "==============================" << endl;

	marin.name = "해병";
	marin.Hp = 100;
	marin.Atk = 5.5;
	marin.Die = false;

	cout << "이름 : " << marin.name << endl;

	cout << "Hp  : " << marin.Hp  << endl;
	cout << "Atk : " << marin.Atk << endl;
	cout << "Die : " << marin.Die << endl;

	tagUnit zergling;

	cout << "저글링 인터페이스" << endl;
	cout << "==============================" << endl;


	zergling.name = "저글링";
	zergling.Hp = 50;
	zergling.Atk = 2.5;
	zergling.Die = true;

	cout << "이름 : " << zergling.name << endl;

	cout << "Hp  : " << zergling.Hp << endl;
	cout << "Atk : " << zergling.Atk << endl;
	cout << "Die : " << zergling.Die << endl;

	string name;
	int phoneNumber;
	string game;
*/

	family father;
	father.name = "백종윤";
	father.age = 52;
	father.birthDate = "0501";
	father.gender = "남자";
	father.human = true;
	father.state = "광주";
	father.food = "새우";
	father.phoneNumber = "010-0000-0000";
	father.game = "고스톱";
	father.idealtype = "?";

	cout << "이름 : " << father.name << endl;
	cout <<	"나이 : " << father.age << endl;
	cout << "생일 : " << father.birthDate << endl;
	cout << "성별 : " << father.gender << endl;
	cout << "사람 : " << father.human << endl;
	cout << "사는곳 : " << father.state << endl;
	cout << "전화번호 : " << father.phoneNumber << endl;
	cout << "좋아하는 음식 : " << father.food << endl;
	cout << "좋아하는 게임 : " << father.game << endl;
	cout << "이상형 : " << father.idealtype << endl;
	cout << "==============================" << endl;
	
	family mother;
	mother.name = "김경자";
	mother.age = 50;
	mother.birthDate = "1202";
	mother.gender = "여자";
	mother.human = true;
	mother.state = "서울";
	mother.food = "고기";
	mother.phoneNumber = "010-0000-0000";
	mother.game = "딱히?";
	mother.idealtype = "?";

	cout << "이름 : " << mother.name << endl;
	cout << "나이 : " << mother.age << endl;
	cout << "생일 : " << mother.birthDate << endl;
	cout << "성별 : " << mother.gender << endl;
	cout << "사람 : " << mother.human << endl;
	cout << "사는곳 : " << mother.state << endl;
	cout << "전화번호 : " << mother.phoneNumber << endl;
	cout << "좋아하는 음식 : " << mother.food << endl;
	cout << "좋아하는 게임 : " << mother.game << endl;
	cout << "이상형 : " << mother.idealtype << endl;
	cout << "==============================" << endl;

	family my;
	my.name = "백경준";
	my.age = 28;
	my.birthDate = "0617";
	my.gender = "남자";
	my.human = true;
	my.state = "서울";
	my.food = "고기";
	my.phoneNumber = "010-2597-9206";
	my.game = "웬만하면 다 좋아함";
	my.idealtype = "?";

	cout << "이름 : " << my.name << endl;
	cout << "나이 : " << my.age << endl;
	cout << "생일 : " << my.birthDate << endl;
	cout << "성별 : " << my.gender << endl;
	cout << "사람 : " << my.human << endl;
	cout << "사는곳 : " << my.state << endl;
	cout << "전화번호 : " << my.phoneNumber << endl;
	cout << "좋아하는 음식 : " << my.food << endl;
	cout << "좋아하는 게임 : " << my.game << endl;
	cout << "이상형 : " << my.idealtype << endl;
	cout << "==============================" << endl;

	family sister;
	sister.name = "백지수";
	sister.age = 26;
	sister.birthDate = "0702";
	sister.gender = "여자";
	sister.human = true;
	sister.state = "서울";
	sister.food = "고기";
	sister.phoneNumber = "010-0000-0000";
	sister.game = "안함";
	sister.idealtype = "?";

	cout << "이름 : " << sister.name << endl;
	cout << "나이 : " << sister.age << endl;
	cout << "생일 : " << sister.birthDate << endl;
	cout << "성별 : " << sister.gender << endl;
	cout << "사람 : " << sister.human << endl;
	cout << "사는곳 : " << sister.state << endl;
	cout << "전화번호 : " << sister.phoneNumber << endl;
	cout << "좋아하는 음식 : " << sister.food << endl;
	cout << "좋아하는 게임 : " << sister.game << endl;
	cout << "이상형 : " << sister.idealtype << endl;
	cout << "==============================" << endl;

	system("pause");
	return 0;
}