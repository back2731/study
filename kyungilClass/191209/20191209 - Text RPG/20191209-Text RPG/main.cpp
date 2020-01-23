#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	cout << "=====================" << endl;
	cout << "||Enter The Gungeon||" << endl;
	cout << "=====================" << endl;

	Sleep(1000);
	cout << "Now";
	Sleep(1000);
	cout << " Loding";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;

	system("cls");

	int chooseCharacter;
	while (true)
	{
		cout << "ĳ���͸� �����Ͻÿ�." << endl;
		cout << "1. �غ� 2. ���Ϸ� 3. �˼� 4. ��ɲ�" << endl;
		cin >> chooseCharacter;
		switch (chooseCharacter)
		{
			case 1:
			{
				cout << "�غ��� �����ϼ̽��ϴ�." << endl;
				cout << "�������� �����մϴ�." << endl;
				break;
			}
			break;
			case 2:
			{
				cout << "���Ϸ��� �����ϼ̽��ϴ�." << endl;
				cout << "�������� �����մϴ�." << endl;
				break;

			}
			break;
			case 3:
			{
				cout << "�˼��� �����ϼ̽��ϴ�." << endl;
				cout << "�������� �����մϴ�." << endl;
				break;

			}
			break;
			case 4:
			{
				cout << "��ɲ��� �����ϼ̽��ϴ�." << endl;
				cout << "�������� �����մϴ�." << endl;
				break;
			}
			break;
			default:
			{
				cout << "�߸��� �����Դϴ�. �ٽ� ������ �ּ���." << endl; 
				Sleep(1500);
				system("cls");
				continue;
			}
		}//end of switch
		break;
	}
	
	Sleep(1500);
	system("cls");

	// �÷��̾� �������ͽ�
	int playerHp = 300;
	int playerMagic = 50;
	int playerAtk = 50;
	int playerDef = 50;

	// �ǵ��� �������ͽ�
	int gunDeadHp = 100;
	int gunDeadMagic = 10;
	int gunDeadAtk = 10;
	int gunDeadDef = 10;

	// ���ű���� �������ͽ�
	int gatlingGullHp = 200;
	int gatlingGullMagic = 20;
	int gatlingGullAtk = 20;
	int gatlingGullDef = 20;

	//��ġ �������ͽ�
	int lichHp = 500;
	int lichMagic = 50;
	int lichAtk = 50;
	int lichDef = 50;

	int playerState;
	int monsterState;

	int monsterChoose = rand() % 3;

	bool gamePlay = true;
	while (gamePlay)
	{
		switch (monsterChoose)
		{
		case 0:				// �ǵ��� 
			{
			cout << "============================================================" << endl;
			cout << "====================�ǵ��带 �������ϴ�!====================" << endl;
			cout << "============================================================" << endl;
			cout << "�÷��̾� hp		: " << playerHp << "\t\t" << "�ǵ��� Hp	  : " << gunDeadHp << endl;
			cout << "�÷��̾� �������ݷ�	: " << playerAtk<< "\t\t" << "�ǵ��� �������ݷ� : " << gunDeadAtk << endl;
			cout << "�÷��̾� �������ݷ�	: " << playerMagic << "\t\t" << "�ǵ��� �������ݷ� : " << gunDeadMagic << endl;
			cout << "�÷��̾� ����		: " << playerDef << "\t\t" << "�ǵ��� ����	  : " << gunDeadDef << endl;
			cout << "============================================================" << endl;
			cout << "======================������ �����մϴ�.====================" << endl;
			cout << "============================================================" << endl;
			cout << "1. ���� 2. ��� 3. ��ų" << endl;
			cin >> playerState;

			monsterState = rand() % 3 + 1;
			int cri = rand() % 10;

			switch (monsterState)
			{
			case 1:								// ���Ͱ� ������ ������ ���
				if (playerState == 1)			// �÷��̾� ���� vs ���� ����
				{
					cout << "�÷��̾� : ���� vs ���� : �ǵ���" << endl;
					cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
				}
				else if (playerState == 2)		// �÷��̾� ��� ���� ����
				{
					cout << "�÷��̾� : ��� vs ���� : �ǵ���" << endl;
					if (cri > 7)
					{
						cout << "�÷��̾��� ũ��Ƽ�� ī����!" << endl;
						gunDeadHp -= (playerDef + gunDeadAtk) * 2;
						cout << "�ǵ����� Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "�ǵ��带 �����߷Ƚ��ϴ�!" << endl;
							gamePlay = false;
						}
					}
					else
					{
						cout << "�÷��̾��� ī����!" << endl;
						gunDeadHp -= playerDef + gunDeadAtk;

						cout << "�ǵ����� Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "�ǵ��带 �����߷Ƚ��ϴ�!" << endl;
							gamePlay = false;
						}
					}
				}
				else							// �÷��̾� ��ų ���� ����
				{
					cout << "�÷��̾� : ��ų vs ���� : �ǵ���" << endl;
					cout << "�ǵ��尡 �÷��̾��� ��ų�� �����ϴ�!" << endl;
					if (cri > 7)
					{
						cout << "ũ��Ƽ�� ��Ʈ!" << endl;
						playerHp -= (playerMagic + gunDeadAtk) * 2;
						cout << "�÷��̾��� Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
					else
					{
						playerHp -= playerMagic + gunDeadAtk;
						cout << "�÷��̾��� Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
				}
				break;
			case 2:								// ���Ͱ� �� ������ ���
				if (playerState == 1)
				{
					cout << "�÷��̾� : ���� vs ��� : �ǵ���" << endl;
					if (cri > 7)
					{
						cout << "�ǵ����� ũ��Ƽ�� ī����!" << endl;
						playerHp -= (playerAtk + gunDeadDef) * 2;
						cout << "�÷��̾��� Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
					else
					{
						cout << "�ǵ����� ī����!" << endl;
						playerHp -= playerAtk + gunDeadDef;
						cout << "�÷��̾��� Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
				}
				else if (playerState == 2)
				{
					cout << "�÷��̾� : ��� vs ��� : �ǵ���" << endl;
					cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
				}
				else
				{
					cout << "�÷��̾� : ��ų vs ��� : �ǵ���" << endl;
					cout << "�÷��̾ �ǵ����� �� �����ϴ�!" << endl;
					if (cri > 7)
					{
						cout << "ũ��Ƽ�� ��Ʈ!" << endl;
						gunDeadHp -= (playerMagic + gunDeadDef) * 2;
						cout << "������ Hp :" << gunDeadHp << endl;

						if (gunDeadHp <= 0)
						{
							cout << "�ǵ��带 �����߷Ƚ��ϴ�!" << endl;
							gamePlay = false;
						}

					}
					else
					{
						gunDeadHp -= playerMagic + gunDeadDef;
						cout << "������ Hp :" << gunDeadHp << endl;

						if (gunDeadHp <= 0)
						{
							cout << "�ǵ��带 �����߷Ƚ��ϴ�!" << endl;
							gamePlay = false;
						}
					}
				}
				break;
			case 3:								//���Ͱ� ��ų�� ������ ���
				if (playerState == 1)
				{
					cout << "�÷��̾� : ���� vs ��ų : �ǵ���" << endl;
					cout << "�÷��̾ �ǵ����� ��ų�� �����ϴ�!" << endl;
					if (cri > 7)
					{
						cout << "ũ��Ƽ�� ��Ʈ!" << endl;
						gunDeadHp -= (playerAtk + gunDeadMagic) * 2;
						cout << "�ǵ����� Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "�ǵ��带 �����߷Ƚ��ϴ�." << endl;
							gamePlay = false;
						}
					}
					else
					{
						gunDeadHp -= playerAtk + gunDeadMagic;
						cout << "�ǵ����� Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "�ǵ��带 �����߷Ƚ��ϴ�." << endl;
							gamePlay = false;
						}
					}
				}
				else if (playerState == 2)
				{
					cout << "�÷��̾� : ��� vs ��ų : �ǵ���" << endl;
					cout << "�ǵ��尡 �÷��̾��� �� �����ϴ�!" << endl;
					{
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							playerHp -= (playerDef + gunDeadMagic) * 2;
							cout << "�÷��̾��� Hp :" << playerHp << endl;

							if (playerHp <= 0)
							{
								cout << "Game over" << endl;
								gamePlay = false;
							}

						}
						else
						{
							playerHp -= playerDef + gunDeadMagic;
							cout << "�÷��̾��� Hp :" << playerHp << endl;

							if (playerHp <= 0)
							{
								cout << "Game over" << endl;
								gamePlay = false;
							}
						}
					}
				}
				else
				{
					cout << "�÷��̾� : ��ų vs ��ų : �ǵ���" << endl;
					cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
				}
				break;
			}
			Sleep(5000);
			system("cls");
		}
		break;
		case 1:				// ���ű����
		{
			{	
				cout << "============================================================" << endl;
				cout << "==================���ű������ �������ϴ�!==================" << endl;
				cout << "============================================================" << endl;
				cout << "�÷��̾� hp		: " << playerHp << "\t\t" << "���ű���� Hp		: " << gatlingGullHp << endl;
				cout << "�÷��̾� �������ݷ�	: " << playerAtk << "\t\t" << "���ű���� �������ݷ�   : " << gatlingGullAtk << endl;
				cout << "�÷��̾� �������ݷ�	: " << playerMagic << "\t\t" << "���ű���� �������ݷ�   : " << gatlingGullMagic << endl;
				cout << "�÷��̾� ����		: " << playerDef << "\t\t" << "���ű���� ����       : " << gatlingGullDef << endl;
				cout << "============================================================" << endl;
				cout << "======================������ �����մϴ�.====================" << endl;
				cout << "============================================================" << endl;
				cout << "1. ���� 2. ��� 3. ��ų" << endl;
				cin >> playerState;

				monsterState = rand() % 3 + 1;
				int cri = rand() % 10;

				switch (monsterState)
				{
				case 1:								// ���Ͱ� ������ ������ ���
					if (playerState == 1)			// �÷��̾� ���� vs ���� ����
					{
						cout << "�÷��̾� : ���� vs ���� : ���ű����" << endl;
						cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
					}
					else if (playerState == 2)		// �÷��̾� ��� ���� ����
					{
						cout << "�÷��̾� : ��� vs ���� : ���ű����" << endl;
						if (cri > 7)
						{
							cout << "�÷��̾��� ũ��Ƽ�� ī����!" << endl;
							gatlingGullHp -= (playerDef + gatlingGullAtk) * 2;
							cout << "���ű������ Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "���ű������ �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "�÷��̾��� ī����!" << endl;
							gatlingGullHp -= playerDef + gatlingGullAtk;
							cout << "���ű������ Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "���ű������ �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}
						}
					}
					else							// �÷��̾� ��ų ���� ����
					{
						cout << "�÷��̾� : ��ų vs ���� : ���ű����" << endl;
						cout << "���ű���Ѱ� �÷��̾��� ��ų�� �����ϴ�!" << endl;
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							playerHp -= (playerMagic + gatlingGullAtk) * 2;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							playerHp -= playerMagic + gatlingGullAtk;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 2:								// ���Ͱ� �� ������ ���
					if (playerState == 1)
					{
						cout << "�÷��̾� : ���� vs ��� : ���ű����" << endl;
						if (cri > 7)
						{
							cout << "���ű������ ũ��Ƽ�� ī����!" << endl;
							playerHp -= (playerAtk + gatlingGullDef) * 2;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "���ű������ ī����!" << endl;
							playerHp -= playerAtk + gatlingGullDef;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "�÷��̾� : ��� vs ��� : ���ű����" << endl;
						cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
					}
					else
					{
						cout << "�÷��̾� : ��ų vs ��� : ���ű����" << endl;
						cout << "�÷��̾ ���ű������ �� �����ϴ�!" << endl;
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							gatlingGullHp -= (playerMagic + gatlingGullDef) * 2;
							cout << "������ Hp :" << gatlingGullHp << endl;

							if (gatlingGullHp <= 0)
							{
								cout << "���ű���Ѹ� �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}

						}
						else
						{
							gatlingGullHp -= playerMagic + gatlingGullDef;
							cout << "������ Hp :" << gatlingGullHp << endl;

							if (gatlingGullHp <= 0)
							{
								cout << "���ű���Ѹ� �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 3:								//���Ͱ� ��ų�� ������ ���
					if (playerState == 1)
					{
						cout << "�÷��̾� : ���� vs ��ų : ���ű����" << endl;
						cout << "�÷��̾ ���ű������ ��ų�� �����ϴ�!" << endl;
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							gatlingGullHp -= (playerAtk + gatlingGullMagic) * 2;
							cout << "���ű������ Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "���ű���Ѹ� �����߷Ƚ��ϴ�." << endl;
								gamePlay = false;
							}
						}
						else
						{
							gatlingGullHp -= playerAtk + gatlingGullMagic;
							cout << "���ű������ Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "���ű���Ѹ� �����߷Ƚ��ϴ�." << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "�÷��̾� : ��� vs ��ų : ���ű����" << endl;
						cout << "���ű���Ѱ� �÷��̾��� �� �����ϴ�!" << endl;
						{
							if (cri > 7)
							{
								cout << "ũ��Ƽ�� ��Ʈ!" << endl;
								playerHp -= (playerDef + gatlingGullMagic) * 2;
								cout << "�÷��̾��� Hp :" << playerHp << endl;

								if (playerHp <= 0)
								{
									cout << "Game over" << endl;
									gamePlay = false;
								}

							}
							else
							{
								playerHp -= playerDef + gatlingGullMagic;
								cout << "�÷��̾��� Hp :" << playerHp << endl;

								if (playerHp <= 0)
								{
									cout << "Game over" << endl;
									gamePlay = false;
								}
							}
						}
					}
					else
					{
						cout << "�÷��̾� : ��ų vs ��ų : ���ű����" << endl;
						cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
					}
					break;
				}
				Sleep(5000);
				system("cls");
			}
		}
		break;
		case 2:				// ��ġ
		{
			{
				cout << "============================================================" << endl;
				cout << "======================��ġ�� �������ϴ�!====================" << endl;
				cout << "============================================================" << endl;
				cout << "�÷��̾� hp		: " << playerHp << "\t\t" << "��ġ Hp		  : " << lichHp << endl;
				cout << "�÷��̾� �������ݷ�	: " << playerAtk << "\t\t" << "��ġ �������ݷ�   : " << lichAtk << endl;
				cout << "�÷��̾� �������ݷ�	: " << playerMagic << "\t\t" << "��ġ �������ݷ�   : " << lichMagic << endl;
				cout << "�÷��̾� ����		: " << playerDef << "\t\t" << "��ġ ����       : " << lichDef << endl;
				cout << "============================================================" << endl;
				cout << "======================������ �����մϴ�.====================" << endl;
				cout << "============================================================" << endl;
				cout << "1. ���� 2. ��� 3. ��ų" << endl;
				cin >> playerState;

				monsterState = rand() % 3 + 1;
				int cri = rand() % 10;

				switch (monsterState)
				{
				case 1:								// ���Ͱ� ������ ������ ���
					if (playerState == 1)			// �÷��̾� ���� vs ���� ����
					{
						cout << "�÷��̾� : ���� vs ���� : ��ġ" << endl;
						cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
					}
					else if (playerState == 2)		// �÷��̾� ��� ���� ����
					{
						cout << "�÷��̾� : ��� vs ���� : ��ġ" << endl;
						if (cri > 7)
						{
							cout << "�÷��̾��� ũ��Ƽ�� ī����!" << endl;
							lichHp -= (playerDef + lichAtk) * 2;
							cout << "��ġ�� Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "��ġ�� �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "�÷��̾��� ī����!" << endl;
							lichHp -= playerDef + lichAtk;
							cout << "��ġ�� Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "��ġ�� �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}
						}
					}
					else							// �÷��̾� ��ų ���� ����
					{
						cout << "�÷��̾� : ��ų vs ���� : ��ġ" << endl;
						cout << "��ġ�� �÷��̾��� ��ų�� �����ϴ�!" << endl;
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							playerHp -= (playerMagic + lichAtk) * 2;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							playerHp -= playerMagic + lichAtk;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 2:								// ���Ͱ� �� ������ ���
					if (playerState == 1)
					{
						cout << "�÷��̾� : ���� vs ��� : ��ġ" << endl;
						if (cri > 7)
						{
							cout << "��ġ�� ũ��Ƽ�� ī����!" << endl;
							playerHp -= (playerAtk + lichDef) * 2;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "��ġ�� ī����!" << endl;
							playerHp -= playerAtk + lichDef;
							cout << "�÷��̾��� Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "�÷��̾� : ��� vs ��� : ��ġ" << endl;
						cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
					}
					else
					{
						cout << "�÷��̾� : ��ų vs ��� : ��ġ" << endl;
						cout << "�÷��̾ ��ġ�� �� �����ϴ�!" << endl;
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							lichHp -= (playerMagic + lichDef) * 2;
							cout << "������ Hp :" << lichHp << endl;

							if (lichHp <= 0)
							{
								cout << "��ġ�� �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}

						}
						else
						{
							lichHp -= playerMagic + lichDef;
							cout << "������ Hp :" << lichHp << endl;

							if (lichHp <= 0)
							{
								cout << "��ġ�� �����߷Ƚ��ϴ�!" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 3:								//���Ͱ� ��ų�� ������ ���
					if (playerState == 1)
					{
						cout << "�÷��̾� : ���� vs ��ų : ��ġ" << endl;
						cout << "�÷��̾ ��ġ�� ��ų�� �����ϴ�!" << endl;
						if (cri > 7)
						{
							cout << "ũ��Ƽ�� ��Ʈ!" << endl;
							lichHp -= (playerAtk + lichMagic) * 2;
							cout << "��ġ�� Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "��ġ�� �����߷Ƚ��ϴ�." << endl;
								gamePlay = false;
							}
						}
						else
						{
							lichHp -= playerAtk + lichMagic;
							cout << "��ġ�� Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "��ġ�� �����߷Ƚ��ϴ�." << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "�÷��̾� : ��� vs ��ų : ��ġ" << endl;
						cout << "��ġ�� �÷��̾��� �� �����ϴ�!" << endl;
						{
							if (cri > 7)
							{
								cout << "ũ��Ƽ�� ��Ʈ!" << endl;
								playerHp -= (playerDef + lichMagic) * 2;
								cout << "�÷��̾��� Hp :" << playerHp << endl;

								if (playerHp <= 0)
								{
									cout << "Game over" << endl;
									gamePlay = false;
								}

							}
							else
							{
								playerHp -= playerDef + lichMagic;
								cout << "�÷��̾��� Hp :" << playerHp << endl;

								if (playerHp <= 0)
								{
									cout << "Game over" << endl;
									gamePlay = false;
								}
							}
						}
					}
					else
					{
						cout << "�÷��̾� : ��ų vs ��ų : ��ġ" << endl;
						cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�!" << endl;
					}
					break;
				}
				Sleep(3000);
				system("cls");
			}
		}
		break;
		}
	}
	system("pause");
}