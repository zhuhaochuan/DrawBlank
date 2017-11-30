#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <iostream>
#include <vector>
#include "Figure.h"

class BlackBoard; 

class FigureManager
{
public:
	std::vector<Figure*> figureList;

	static FigureManager &handle()//��̬��Ա�����ڲ���ʹ�÷Ǿ�̬��Ա  ͬ��Ҳ������ʹ�÷Ǿ�̬��Ա����
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager����������
    virtual ~FigureManager() { }
 
    // FigureManager��ӿ�.
public:
	void input(std::istream &is); 
    void display(BlackBoard &board); 


}; // class FigureManager�ඨ�����.





void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
