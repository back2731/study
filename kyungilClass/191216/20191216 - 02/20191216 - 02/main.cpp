#include <iostream>

using namespace std;
/*
	파일을 처리하기 위한 전처리기문	: #include
	
	형태 정의를 위한 전처리기문		: #define, #undefine
	
	조건 처리를 위한 전처리기문		: #if, #ifndef, #elif 등등

	#include <파일이름> -> 미리 정의 된 include 폴더에서 파일을 찾는다.
	#include "파일이름" -> 현재의 소스코드가 저장 되어 있는 폴더에서 먼저 찾는다.

	#error	-> 컴파일 오류 메세지를 발생
	#elif	-> eles if
	#else	-> else
	#ifndef	-> 식별자가 정의 되어 있지 않으면 참
	#ifndef	-> 식별자가 정의 되어 있으면 참
	#endif	-> #ifndef, #ifdef, #else에 대한 전처리기 부분을 종료한다.
	#pragma	-> 링크할 때 헤더 파일이 한 번만 포함되게 한다.
	#undef	-> 식별자를 정의하지 않는다.

	#와 ##는 전처리기의 연산자로서 컴파일러가 #define 전처리 과정에서만 사용하는 특수한 문자이다.

	
*/
//#define 매크로이름 실제값
#define	NUM 5;
//#define문으로 매크로 상수를 정의 할때 일반적인 주의사항
// 1. #define문은 전처리문이지 코드를 생성하는 명령은 아니다.
// 2. 매크로의 이름도 일종의 명칭이기 때문에 명칭 규칙에 맞게 작성해야한다.
// 3. 매크로 이름에는 공백이 들어갈 수는 없지만, 매크로의 실제값은 공백을 가질수 있다.
// 4. 문자열 상수내에 있는 매크로나 다른 명칭의 일부로 포함된 경우는 치환되지 않는다.
// #define	NUM 5; -> NUM을 찾아 5로 치환한다.
// 5. 매크로는 중첩이 가능하다.
#define	A 3
#define	B (A*3)
// 6. 값을 가지지 않는 빈 매크로도 정의 할 수 있다.
#define AA
// 이 매크로는 값을 가지지 않으며 매크로 상수 자체만 존재할 뿐이다.

#define BULLET 50
const int NUMBER = 50;

int main()
{
	for (int i = 0; i < NUMBER; i++)
	{
		cout << i << endl;
	}

	cout << A * B << endl;

	system("pause");
	return 0;
}