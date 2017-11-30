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

	static FigureManager &handle()//静态成员函数内不能使用非静态成员  同样也不可以使用非静态成员函数
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager类析构函数
    virtual ~FigureManager() { }
 
    // FigureManager类接口.
public:
	void input(std::istream &is); 
    void display(BlackBoard &board); 


}; // class FigureManager类定义结束.





void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
