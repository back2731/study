#include "mainGame.h"



mainGame::mainGame()
{
	output(1);
	// �����Ϸ��� �˾Ƽ� �Ű������� Ÿ���� �����ϰ�
	// �Ʒ��� ���� �Լ��� �ν��Ͻ�ȭ ��Ų��.
	/*void output(int a)
	{
		cout << "������ : " << a << endl;
	}*/
	output(3.556f);			// �Ű������� Ÿ���� float
	output("�ȳ��ϼ���");	// �Ű������� Ÿ���� string
	cout << "====================================" << endl;

	output1(10, 10);
	cout << "====================================" << endl;
	// output1(10, 3.5f);	// �Ű������� 2������ typename�� �ϳ��� ��쿡�� �ȵȴ�.

	output2(10, "�ȳ�");		// typename�� 2���� �ٸ� �ڷ����� ��ȯ.

	output3("A","��");
}


mainGame::~mainGame()
{
}
