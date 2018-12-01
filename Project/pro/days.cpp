#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"days.h"

Days::Days(string name)
{
	this->name=name;
}
Days::Days(Recipe b,Recipe l,Recipe d,Recipe s,Recipe e)
{
	this->breakfast= b;
	this->lunch= l;
	this->dinner= d;
	this->snack= s;
	this->dessert= e;


}
