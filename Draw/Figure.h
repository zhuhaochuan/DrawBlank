#ifndef _FIGURE_H_
#define _FIGURE_H_
#include <string>
#include <iostream>
#include "BlackBoard.h" 

class Figure 
{
public:
	struct parameter {
		int data;
		std::string description;
		};

	std::string prompt;
	virtual void displayFigure(BlackBoard &board) {}

	virtual std::string getDescription(){return prompt;}

	virtual int getArgSize(){return 0;}

	virtual parameter& getArgData(int i){parameter temp;return temp;}

	virtual std::string getArgDescription(int i){return prompt;}
};


class Circle :public Figure
{
public:
	struct parameter arg[3];

	Circle () {
		prompt = "请输入圆的圆心坐标和半径(x, y, radius) ：";
		arg[0].description = "Center X: ";
		arg[1].description = "Center Y: ";
		arg[2].description = "Radius: ";
		}

	virtual void displayFigure(BlackBoard &board) {
		board.DrawCircle(arg[0].data, arg[1].data, arg[2].data); 
		}

	virtual std::string getDescription(){
		return prompt;
		}

	virtual int getArgSize(){
		return sizeof(arg)/sizeof(parameter);
		}

	virtual parameter& getArgData(int i){
		return arg[i];
		}

	virtual std::string getArgDescription(int i){
		return arg[i].description;
		}
};

class Line :public Figure
{
public:
	struct parameter arg[4];

	Line() {
		prompt = "请输入线段的起点和终点坐标(x1, y1, x2, y2) ：";
		arg[0].description = "X1: ";
		arg[1].description = "Y1: ";
		arg[2].description = "X2: ";
		arg[3].description = "Y2: ";
		}

	virtual void displayFigure(BlackBoard &board) {
		board.DrawLine(arg[0].data, arg[1].data, arg[2].data, arg[3].data); 
		}

	virtual std::string getDescription(){
		return prompt;
		}

	virtual int getArgSize(){
		return sizeof(arg)/sizeof(parameter);
		}

	virtual parameter& getArgData(int i){
		return arg[i];
		}

	virtual std::string getArgDescription(int i){
		return arg[i].description;
		}
};

class Rect :public Figure
{
public:
	struct parameter arg[4];

	Rect() {
		prompt = "请输入矩形的左上角和右下角坐标(x1, y1, x2, y2) ：";
		arg[0].description = "Left: ";
		arg[1].description = "Top: ";
		arg[2].description = "Right: ";
		arg[3].description = "Bottom: ";
		}

	virtual void displayFigure(BlackBoard &board) {
		board.DrawLine(arg[0].data, arg[1].data, arg[0].data, arg[3].data); 
		board.DrawLine(arg[0].data, arg[3].data, arg[2].data, arg[3].data); 
		board.DrawLine(arg[2].data, arg[3].data, arg[2].data, arg[1].data); 
		board.DrawLine(arg[2].data, arg[1].data, arg[0].data, arg[1].data);
		}

	virtual std::string getDescription(){
		return prompt;
		}

	virtual int getArgSize(){
		return sizeof(arg)/sizeof(parameter);
		}

	virtual parameter& getArgData(int i){
		return arg[i];
		}

	virtual std::string getArgDescription(int i){
		return arg[i].description;
		}
};

class Triangle: public Figure{
	public:
	struct parameter arg[6];

	Triangle() {
		prompt = "请输入三角形的三个顶点坐标(x1, y1, x2, y2, x3, y3) ：";
		arg[0].description = "x1: ";
		arg[1].description = "y1: ";
		arg[2].description = "x2: ";
		arg[3].description = "y2: ";
		arg[4].description = "x3: ";
		arg[5].description = "y3: ";
		}

	virtual void displayFigure(BlackBoard &board) {
		board.DrawLine(arg[0].data, arg[1].data, arg[2].data, arg[3].data); 
		board.DrawLine(arg[0].data, arg[1].data, arg[4].data, arg[5].data); 
		board.DrawLine(arg[2].data, arg[3].data, arg[4].data, arg[5].data); 
		}

	virtual std::string getDescription(){
		return prompt;
		}

	virtual int getArgSize(){
		return sizeof(arg)/sizeof(parameter);
		}

	virtual parameter& getArgData(int i){
		return arg[i];
		}

	virtual std::string getArgDescription(int i){
		return arg[i].description;
		}
	};
#endif // #ifndef _FIGURE_H_