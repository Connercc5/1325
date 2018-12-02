#ifndef MEAL_PLAN
#define MEAL_PLAN
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"recipe.h"
#include"days.h"
#include"file.h"
class Mealplan
{
	public:
	vector <Days> daysList;
	Mealplan();
	void add_mealplan();


};






#endif
