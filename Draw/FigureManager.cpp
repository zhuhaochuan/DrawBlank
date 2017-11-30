#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"
#include "Figure.h"
using namespace std;


void addFigure(Figure* figure) {
		//Line* a = new Line;
		cout <<figure->getDescription()<< endl;

		for(int i=0;i<(figure->getArgSize());i++) {
			std::cout << figure->getArgDescription(i) << endl; 
			std::cin >> (figure->getArgData(i)).data; 
		}
		FigureManager::handle().figureList.push_back(figure);
}

void FigureManager::input(std::istream &is)
{
    // 1、打印菜单，让用户选择输入图形
	// 菜单格式为
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// 输入不要用std::cin
	// 用本函数的输入参数is，用法同cin

	// 2、用户输入数字(1/2/3/0)选择后，根据不同的图形，提示输入图形的参数
	// 其中圆的参数依次为圆心x、y、半径，因此包含提示的输入代码类似以下结果

	int input_type = 0;
	cout<<"请输入图形的种类(0：线段，1：矩形，2：圆，3: 三角形，-1：结束)：" << endl;
	is >> input_type;

	while(-1!=input_type) {
		switch(input_type) {
		case 0: {
			Line* figureObj = new Line;
			addFigure(figureObj);
			break;
			}
		case 1: {
			Rect* figureObj = new Rect;
			addFigure(figureObj);
			break;
			}
		case 2: {
			Circle* figureObj = new Circle;
			addFigure(figureObj);
			break;
			}
		case 3: {
			Triangle* figureObj = new Triangle;
			addFigure(figureObj);
			break;
			}
		default:
			std::cout<< "请输入正确的值。";
		}
		cout<<"请输入图形的种类(0：线段，1：矩形，2：圆，3: 三角形，-1：结束)：" << endl;
		is >> input_type;
	}



	// 3，输入好参数后，将图形保存下来，用于之后绘制

	// 4，回到1，继续打印菜单，直到用户选择0，退出input函数


}

void FigureManager::display(BlackBoard &board)
{
	// 将所有input中输入的图形在这里依次画出
#if 0
	for(int i=0;i<handle().figureList.size();i++) {
		Figure* temp = handle().figureList[i];
		if(temp->name=="line") {
			Line* p = reinterpret_cast<Line*> (temp);
			board.DrawLine(p->_x1, p->_y1, p->_x2, p->_y2); 
		}
		else if(temp->name=="rect") {
			Rect* p = reinterpret_cast<Rect*> (temp);
			board.DrawLine(p->_left, p->_top, p->_left, p->_bottom); 
			board.DrawLine(p->_left, p->_bottom, p->_right, p->_bottom); 
			board.DrawLine(p->_right, p->_bottom, p->_right, p->_top); 
			board.DrawLine(p->_right, p->_top, p->_left, p->_top); 
		}
		else if(temp->name=="circle") {
			Circle* p = reinterpret_cast<Circle*> (temp);
			board.DrawCircle(p->_x, p->_y, p->_radius); 
		}
	}
#endif
	for(int i=0;i<handle().figureList.size();i++) {
		Figure* curFigure = handle().figureList[i];
		curFigure->displayFigure(board);		
	}

	// 借助board提供的DrawCircle和DrawLine函数画图，举例，画一个圆心在30,30位置，半径为100的圆
	//board.DrawCircle(30, 30, 100); 

	// 再举例，画矩形，该矩形左上角为(30, 20)，右下角为（200,300）
	//board.DrawLine(30, 20, 30, 300); 
	//board.DrawLine(30, 300, 200, 300); 
	//board.DrawLine(200, 300, 200, 20); 
	//board.DrawLine(200, 20, 30, 20); 
}

// 如果你的实现需要一些必要的初始化，可放在这个函数中，main函数会调用
// 如果没有，则忽略
void InitiateFigureManager()
{

}


