#pragma once
#include"gameNode.h"

class mainGame :  public gameNode
{
private:
	image * _bgImage;
	image* _hoon;


	int _index;		//������ �ε���
	int _count;		//������ ���� ī��Ʈ
	bool _isLeft;	//������?
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

