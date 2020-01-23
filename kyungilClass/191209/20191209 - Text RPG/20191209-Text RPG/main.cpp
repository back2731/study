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
		cout << "캐릭터를 선택하시오." << endl;
		cout << "1. 해병 2. 파일럿 3. 죄수 4. 사냥꾼" << endl;
		cin >> chooseCharacter;
		switch (chooseCharacter)
		{
			case 1:
			{
				cout << "해병을 선택하셨습니다." << endl;
				cout << "던전으로 진입합니다." << endl;
				break;
			}
			break;
			case 2:
			{
				cout << "파일럿을 선택하셨습니다." << endl;
				cout << "던전으로 진입합니다." << endl;
				break;

			}
			break;
			case 3:
			{
				cout << "죄수를 선택하셨습니다." << endl;
				cout << "던전으로 진입합니다." << endl;
				break;

			}
			break;
			case 4:
			{
				cout << "사냥꾼을 선택하셨습니다." << endl;
				cout << "던전으로 진입합니다." << endl;
				break;
			}
			break;
			default:
			{
				cout << "잘못된 선택입니다. 다시 선택해 주세요." << endl; 
				Sleep(1500);
				system("cls");
				continue;
			}
		}//end of switch
		break;
	}
	
	Sleep(1500);
	system("cls");

	// 플레이어 스테이터스
	int playerHp = 300;
	int playerMagic = 50;
	int playerAtk = 50;
	int playerDef = 50;

	// 건데드 스테이터스
	int gunDeadHp = 100;
	int gunDeadMagic = 10;
	int gunDeadAtk = 10;
	int gunDeadDef = 10;

	// 갈매기관총 스테이터스
	int gatlingGullHp = 200;
	int gatlingGullMagic = 20;
	int gatlingGullAtk = 20;
	int gatlingGullDef = 20;

	//리치 스테이터스
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
		case 0:				// 건데드 
			{
			cout << "============================================================" << endl;
			cout << "====================건데드를 만났습니다!====================" << endl;
			cout << "============================================================" << endl;
			cout << "플레이어 hp		: " << playerHp << "\t\t" << "건데드 Hp	  : " << gunDeadHp << endl;
			cout << "플레이어 물리공격력	: " << playerAtk<< "\t\t" << "건데드 물리공격력 : " << gunDeadAtk << endl;
			cout << "플레이어 마법공격력	: " << playerMagic << "\t\t" << "건데드 마법공격력 : " << gunDeadMagic << endl;
			cout << "플레이어 방어력		: " << playerDef << "\t\t" << "건데드 방어력	  : " << gunDeadDef << endl;
			cout << "============================================================" << endl;
			cout << "======================전투를 시작합니다.====================" << endl;
			cout << "============================================================" << endl;
			cout << "1. 공격 2. 방어 3. 스킬" << endl;
			cin >> playerState;

			monsterState = rand() % 3 + 1;
			int cri = rand() % 10;

			switch (monsterState)
			{
			case 1:								// 몬스터가 공격을 선택한 경우
				if (playerState == 1)			// 플레이어 공격 vs 몬스터 공격
				{
					cout << "플레이어 : 공격 vs 공격 : 건데드" << endl;
					cout << "아무 일도 일어나지 않았다!" << endl;
				}
				else if (playerState == 2)		// 플레이어 방어 몬스터 공격
				{
					cout << "플레이어 : 방어 vs 공격 : 건데드" << endl;
					if (cri > 7)
					{
						cout << "플레이어의 크리티컬 카운터!" << endl;
						gunDeadHp -= (playerDef + gunDeadAtk) * 2;
						cout << "건데드의 Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "건데드를 쓰러뜨렸습니다!" << endl;
							gamePlay = false;
						}
					}
					else
					{
						cout << "플레이어의 카운터!" << endl;
						gunDeadHp -= playerDef + gunDeadAtk;

						cout << "건데드의 Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "건데드를 쓰러뜨렸습니다!" << endl;
							gamePlay = false;
						}
					}
				}
				else							// 플레이어 스킬 몬스터 공격
				{
					cout << "플레이어 : 스킬 vs 공격 : 건데드" << endl;
					cout << "건데드가 플레이어의 스킬을 깼습니다!" << endl;
					if (cri > 7)
					{
						cout << "크리티컬 히트!" << endl;
						playerHp -= (playerMagic + gunDeadAtk) * 2;
						cout << "플레이어의 Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
					else
					{
						playerHp -= playerMagic + gunDeadAtk;
						cout << "플레이어의 Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
				}
				break;
			case 2:								// 몬스터가 방어를 선택한 경우
				if (playerState == 1)
				{
					cout << "플레이어 : 공격 vs 방어 : 건데드" << endl;
					if (cri > 7)
					{
						cout << "건데드의 크리티컬 카운터!" << endl;
						playerHp -= (playerAtk + gunDeadDef) * 2;
						cout << "플레이어의 Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
					else
					{
						cout << "건데드의 카운터!" << endl;
						playerHp -= playerAtk + gunDeadDef;
						cout << "플레이어의 Hp :" << playerHp << endl;
						if (playerHp <= 0)
						{
							cout << "Game Over" << endl;
							gamePlay = false;
						}
					}
				}
				else if (playerState == 2)
				{
					cout << "플레이어 : 방어 vs 방어 : 건데드" << endl;
					cout << "아무 일도 일어나지 않았다!" << endl;
				}
				else
				{
					cout << "플레이어 : 스킬 vs 방어 : 건데드" << endl;
					cout << "플레이어가 건데드의 방어를 깼습니다!" << endl;
					if (cri > 7)
					{
						cout << "크리티컬 히트!" << endl;
						gunDeadHp -= (playerMagic + gunDeadDef) * 2;
						cout << "몬스터의 Hp :" << gunDeadHp << endl;

						if (gunDeadHp <= 0)
						{
							cout << "건데드를 쓰러뜨렸습니다!" << endl;
							gamePlay = false;
						}

					}
					else
					{
						gunDeadHp -= playerMagic + gunDeadDef;
						cout << "몬스터의 Hp :" << gunDeadHp << endl;

						if (gunDeadHp <= 0)
						{
							cout << "건데드를 쓰러뜨렸습니다!" << endl;
							gamePlay = false;
						}
					}
				}
				break;
			case 3:								//몬스터가 스킬을 선택한 경우
				if (playerState == 1)
				{
					cout << "플레이어 : 공격 vs 스킬 : 건데드" << endl;
					cout << "플레이어가 건데드의 스킬을 깼습니다!" << endl;
					if (cri > 7)
					{
						cout << "크리티컬 히트!" << endl;
						gunDeadHp -= (playerAtk + gunDeadMagic) * 2;
						cout << "건데드의 Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "건데드를 쓰러뜨렸습니다." << endl;
							gamePlay = false;
						}
					}
					else
					{
						gunDeadHp -= playerAtk + gunDeadMagic;
						cout << "건데드의 Hp :" << gunDeadHp << endl;
						if (gunDeadHp <= 0)
						{
							cout << "건데드를 쓰러뜨렸습니다." << endl;
							gamePlay = false;
						}
					}
				}
				else if (playerState == 2)
				{
					cout << "플레이어 : 방어 vs 스킬 : 건데드" << endl;
					cout << "건데드가 플레이어의 방어를 깼습니다!" << endl;
					{
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							playerHp -= (playerDef + gunDeadMagic) * 2;
							cout << "플레이어의 Hp :" << playerHp << endl;

							if (playerHp <= 0)
							{
								cout << "Game over" << endl;
								gamePlay = false;
							}

						}
						else
						{
							playerHp -= playerDef + gunDeadMagic;
							cout << "플레이어의 Hp :" << playerHp << endl;

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
					cout << "플레이어 : 스킬 vs 스킬 : 건데드" << endl;
					cout << "아무 일도 일어나지 않았다!" << endl;
				}
				break;
			}
			Sleep(5000);
			system("cls");
		}
		break;
		case 1:				// 갈매기관총
		{
			{	
				cout << "============================================================" << endl;
				cout << "==================갈매기관총을 만났습니다!==================" << endl;
				cout << "============================================================" << endl;
				cout << "플레이어 hp		: " << playerHp << "\t\t" << "갈매기관총 Hp		: " << gatlingGullHp << endl;
				cout << "플레이어 물리공격력	: " << playerAtk << "\t\t" << "갈매기관총 물리공격력   : " << gatlingGullAtk << endl;
				cout << "플레이어 마법공격력	: " << playerMagic << "\t\t" << "갈매기관총 마법공격력   : " << gatlingGullMagic << endl;
				cout << "플레이어 방어력		: " << playerDef << "\t\t" << "갈매기관총 방어력       : " << gatlingGullDef << endl;
				cout << "============================================================" << endl;
				cout << "======================전투를 시작합니다.====================" << endl;
				cout << "============================================================" << endl;
				cout << "1. 공격 2. 방어 3. 스킬" << endl;
				cin >> playerState;

				monsterState = rand() % 3 + 1;
				int cri = rand() % 10;

				switch (monsterState)
				{
				case 1:								// 몬스터가 공격을 선택한 경우
					if (playerState == 1)			// 플레이어 공격 vs 몬스터 공격
					{
						cout << "플레이어 : 공격 vs 공격 : 갈매기관총" << endl;
						cout << "아무 일도 일어나지 않았다!" << endl;
					}
					else if (playerState == 2)		// 플레이어 방어 몬스터 공격
					{
						cout << "플레이어 : 방어 vs 공격 : 갈매기관총" << endl;
						if (cri > 7)
						{
							cout << "플레이어의 크리티컬 카운터!" << endl;
							gatlingGullHp -= (playerDef + gatlingGullAtk) * 2;
							cout << "갈매기관총의 Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "갈매기관총을 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "플레이어의 카운터!" << endl;
							gatlingGullHp -= playerDef + gatlingGullAtk;
							cout << "갈매기관총의 Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "갈매기관총을 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}
						}
					}
					else							// 플레이어 스킬 몬스터 공격
					{
						cout << "플레이어 : 스킬 vs 공격 : 갈매기관총" << endl;
						cout << "갈매기관총가 플레이어의 스킬을 깼습니다!" << endl;
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							playerHp -= (playerMagic + gatlingGullAtk) * 2;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							playerHp -= playerMagic + gatlingGullAtk;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 2:								// 몬스터가 방어를 선택한 경우
					if (playerState == 1)
					{
						cout << "플레이어 : 공격 vs 방어 : 갈매기관총" << endl;
						if (cri > 7)
						{
							cout << "갈매기관총의 크리티컬 카운터!" << endl;
							playerHp -= (playerAtk + gatlingGullDef) * 2;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "갈매기관총의 카운터!" << endl;
							playerHp -= playerAtk + gatlingGullDef;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "플레이어 : 방어 vs 방어 : 갈매기관총" << endl;
						cout << "아무 일도 일어나지 않았다!" << endl;
					}
					else
					{
						cout << "플레이어 : 스킬 vs 방어 : 갈매기관총" << endl;
						cout << "플레이어가 갈매기관총의 방어를 깼습니다!" << endl;
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							gatlingGullHp -= (playerMagic + gatlingGullDef) * 2;
							cout << "몬스터의 Hp :" << gatlingGullHp << endl;

							if (gatlingGullHp <= 0)
							{
								cout << "갈매기관총를 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}

						}
						else
						{
							gatlingGullHp -= playerMagic + gatlingGullDef;
							cout << "몬스터의 Hp :" << gatlingGullHp << endl;

							if (gatlingGullHp <= 0)
							{
								cout << "갈매기관총를 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 3:								//몬스터가 스킬을 선택한 경우
					if (playerState == 1)
					{
						cout << "플레이어 : 공격 vs 스킬 : 갈매기관총" << endl;
						cout << "플레이어가 갈매기관총의 스킬을 깼습니다!" << endl;
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							gatlingGullHp -= (playerAtk + gatlingGullMagic) * 2;
							cout << "갈매기관총의 Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "갈매기관총를 쓰러뜨렸습니다." << endl;
								gamePlay = false;
							}
						}
						else
						{
							gatlingGullHp -= playerAtk + gatlingGullMagic;
							cout << "갈매기관총의 Hp :" << gatlingGullHp << endl;
							if (gatlingGullHp <= 0)
							{
								cout << "갈매기관총를 쓰러뜨렸습니다." << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "플레이어 : 방어 vs 스킬 : 갈매기관총" << endl;
						cout << "갈매기관총가 플레이어의 방어를 깼습니다!" << endl;
						{
							if (cri > 7)
							{
								cout << "크리티컬 히트!" << endl;
								playerHp -= (playerDef + gatlingGullMagic) * 2;
								cout << "플레이어의 Hp :" << playerHp << endl;

								if (playerHp <= 0)
								{
									cout << "Game over" << endl;
									gamePlay = false;
								}

							}
							else
							{
								playerHp -= playerDef + gatlingGullMagic;
								cout << "플레이어의 Hp :" << playerHp << endl;

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
						cout << "플레이어 : 스킬 vs 스킬 : 갈매기관총" << endl;
						cout << "아무 일도 일어나지 않았다!" << endl;
					}
					break;
				}
				Sleep(5000);
				system("cls");
			}
		}
		break;
		case 2:				// 리치
		{
			{
				cout << "============================================================" << endl;
				cout << "======================리치를 만났습니다!====================" << endl;
				cout << "============================================================" << endl;
				cout << "플레이어 hp		: " << playerHp << "\t\t" << "리치 Hp		  : " << lichHp << endl;
				cout << "플레이어 물리공격력	: " << playerAtk << "\t\t" << "리치 물리공격력   : " << lichAtk << endl;
				cout << "플레이어 마법공격력	: " << playerMagic << "\t\t" << "리치 마법공격력   : " << lichMagic << endl;
				cout << "플레이어 방어력		: " << playerDef << "\t\t" << "리치 방어력       : " << lichDef << endl;
				cout << "============================================================" << endl;
				cout << "======================전투를 시작합니다.====================" << endl;
				cout << "============================================================" << endl;
				cout << "1. 공격 2. 방어 3. 스킬" << endl;
				cin >> playerState;

				monsterState = rand() % 3 + 1;
				int cri = rand() % 10;

				switch (monsterState)
				{
				case 1:								// 몬스터가 공격을 선택한 경우
					if (playerState == 1)			// 플레이어 공격 vs 몬스터 공격
					{
						cout << "플레이어 : 공격 vs 공격 : 리치" << endl;
						cout << "아무 일도 일어나지 않았다!" << endl;
					}
					else if (playerState == 2)		// 플레이어 방어 몬스터 공격
					{
						cout << "플레이어 : 방어 vs 공격 : 리치" << endl;
						if (cri > 7)
						{
							cout << "플레이어의 크리티컬 카운터!" << endl;
							lichHp -= (playerDef + lichAtk) * 2;
							cout << "리치의 Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "리치를 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "플레이어의 카운터!" << endl;
							lichHp -= playerDef + lichAtk;
							cout << "리치의 Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "리치를 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}
						}
					}
					else							// 플레이어 스킬 몬스터 공격
					{
						cout << "플레이어 : 스킬 vs 공격 : 리치" << endl;
						cout << "리치가 플레이어의 스킬을 깼습니다!" << endl;
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							playerHp -= (playerMagic + lichAtk) * 2;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							playerHp -= playerMagic + lichAtk;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 2:								// 몬스터가 방어를 선택한 경우
					if (playerState == 1)
					{
						cout << "플레이어 : 공격 vs 방어 : 리치" << endl;
						if (cri > 7)
						{
							cout << "리치의 크리티컬 카운터!" << endl;
							playerHp -= (playerAtk + lichDef) * 2;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
						else
						{
							cout << "리치의 카운터!" << endl;
							playerHp -= playerAtk + lichDef;
							cout << "플레이어의 Hp :" << playerHp << endl;
							if (playerHp <= 0)
							{
								cout << "Game Over" << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "플레이어 : 방어 vs 방어 : 리치" << endl;
						cout << "아무 일도 일어나지 않았다!" << endl;
					}
					else
					{
						cout << "플레이어 : 스킬 vs 방어 : 리치" << endl;
						cout << "플레이어가 리치의 방어를 깼습니다!" << endl;
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							lichHp -= (playerMagic + lichDef) * 2;
							cout << "몬스터의 Hp :" << lichHp << endl;

							if (lichHp <= 0)
							{
								cout << "리치를 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}

						}
						else
						{
							lichHp -= playerMagic + lichDef;
							cout << "몬스터의 Hp :" << lichHp << endl;

							if (lichHp <= 0)
							{
								cout << "리치를 쓰러뜨렸습니다!" << endl;
								gamePlay = false;
							}
						}
					}
					break;
				case 3:								//몬스터가 스킬을 선택한 경우
					if (playerState == 1)
					{
						cout << "플레이어 : 공격 vs 스킬 : 리치" << endl;
						cout << "플레이어가 리치의 스킬을 깼습니다!" << endl;
						if (cri > 7)
						{
							cout << "크리티컬 히트!" << endl;
							lichHp -= (playerAtk + lichMagic) * 2;
							cout << "리치의 Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "리치를 쓰러뜨렸습니다." << endl;
								gamePlay = false;
							}
						}
						else
						{
							lichHp -= playerAtk + lichMagic;
							cout << "리치의 Hp :" << lichHp << endl;
							if (lichHp <= 0)
							{
								cout << "리치를 쓰러뜨렸습니다." << endl;
								gamePlay = false;
							}
						}
					}
					else if (playerState == 2)
					{
						cout << "플레이어 : 방어 vs 스킬 : 리치" << endl;
						cout << "리치가 플레이어의 방어를 깼습니다!" << endl;
						{
							if (cri > 7)
							{
								cout << "크리티컬 히트!" << endl;
								playerHp -= (playerDef + lichMagic) * 2;
								cout << "플레이어의 Hp :" << playerHp << endl;

								if (playerHp <= 0)
								{
									cout << "Game over" << endl;
									gamePlay = false;
								}

							}
							else
							{
								playerHp -= playerDef + lichMagic;
								cout << "플레이어의 Hp :" << playerHp << endl;

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
						cout << "플레이어 : 스킬 vs 스킬 : 리치" << endl;
						cout << "아무 일도 일어나지 않았다!" << endl;
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