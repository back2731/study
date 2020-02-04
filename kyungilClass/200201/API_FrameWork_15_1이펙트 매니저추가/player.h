#pragma once
class player
{
private:

protected:
	int playerHp;
	int playerMp;
	int playerAtk;
	int playerDef;
	int playerDex;
	int playerLux;
	int playerGold;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

};

