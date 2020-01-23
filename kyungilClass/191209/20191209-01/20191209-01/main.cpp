#include <iostream>
using namespace std;

/* 
	(조건문)
	if 조건문 -> 만약에
	if(조건)					-> 이 조건이 만족하면
	{
		실행할 코드(문장)		-> 여기를 실행해라.
	}
	else if(조건)			-> 자신보다 윗 줄에 있는 if문이 거짓일때만 진입한다.	
	{
		실행할 코드(문장)		-> 여기를 실행해라.
	}
	else					-> 윗 줄에 있는 조건이 아무것도 아닌 경우 실행한다.

	if 작성은 제한이 없다.
*/

int main()
{
	
	//cout << "A의 이상형 나이를 알아보자." << endl;

	//int girlAge; 

	//cout << "나이를 입력하시오 : ";
	//cin >> girlAge;

	//if (girlAge < 20)							// 입력한 값이 20보다 작다면 
	//{
	//	cout << "개쓰레기" << endl;				// 여기를 실행하라.
	//}
	//else if (girlAge >= 20 && girlAge <= 24)	// 20 ~ 24 사이라면
	//{
	//	cout << "나이스" << endl;
	//}
	//else if (girlAge > 24 && girlAge < 29)		// 25 ~ 28
	//{
	//	cout << "이 정도면 뭐" << endl;
	//}
	//else										// 위의 조건이 전부 만족하지 않으면 여기 실행
	//{
	//	cout << "어.. 음.. 그래요." << endl;
	//}
	/*
		지금 해볼것
		영어, 수학, 과학, 국어 점수를 입력하고 
		입력한 과목의 평균을 구한 다음 
		95점 이상이면 A 
		85점 이상이면 B
		75점 이상이면 C
		65점 이상이면 D
		65점 미만이면 낙제
	*/
	/*
	float english = 0;
	float math = 0;
	float science = 0;
	float korean = 0;
	
	cout << "영어 점수를 입력하시오 : ";
	cin >> english;
	cout << "수학 점수를 입력하시오 : ";
	cin >> math;
	cout << "과학 점수를 입력하시오 : ";
	cin >> science;
	cout << "국어 점수를 입력하시오 : ";
	cin >> korean;

	float result = (english + math + science + korean) * 0.25;

	cout << "당신의 평균 점수는 : " << result << "입니다." << endl;

	if (result >= 95)
	{
		cout << "A학점" << endl;
	}
	else if (result >= 85)
	{
		cout << "B학점" << endl;
	}
	else if (result >= 75)
	{
		cout << "C학점" << endl;
	}
	else if (result >= 65)
	{
		cout << "D학점" << endl;
	}
	else
	{
		cout << "낙제" << endl;
	}
	*/

	return 0;
}
