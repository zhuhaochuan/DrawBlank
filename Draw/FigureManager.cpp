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
    // 1����ӡ�˵������û�ѡ������ͼ��
	// �˵���ʽΪ
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// ���벻Ҫ��std::cin
	// �ñ��������������is���÷�ͬcin

	// 2���û���������(1/2/3/0)ѡ��󣬸��ݲ�ͬ��ͼ�Σ���ʾ����ͼ�εĲ���
	// ����Բ�Ĳ�������ΪԲ��x��y���뾶����˰�����ʾ����������������½��

	int input_type = 0;
	cout<<"������ͼ�ε�����(0���߶Σ�1�����Σ�2��Բ��3: �����Σ�-1������)��" << endl;
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
			std::cout<< "��������ȷ��ֵ��";
		}
		cout<<"������ͼ�ε�����(0���߶Σ�1�����Σ�2��Բ��3: �����Σ�-1������)��" << endl;
		is >> input_type;
	}



	// 3������ò����󣬽�ͼ�α�������������֮�����

	// 4���ص�1��������ӡ�˵���ֱ���û�ѡ��0���˳�input����


}

void FigureManager::display(BlackBoard &board)
{
	// ������input�������ͼ�����������λ���
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

	// ����board�ṩ��DrawCircle��DrawLine������ͼ����������һ��Բ����30,30λ�ã��뾶Ϊ100��Բ
	//board.DrawCircle(30, 30, 100); 

	// �پ����������Σ��þ������Ͻ�Ϊ(30, 20)�����½�Ϊ��200,300��
	//board.DrawLine(30, 20, 30, 300); 
	//board.DrawLine(30, 300, 200, 300); 
	//board.DrawLine(200, 300, 200, 20); 
	//board.DrawLine(200, 20, 30, 20); 
}

// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{

}


