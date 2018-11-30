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
	Mealplan();//if they entered yes or no	
	void combine_ingredents();
	void add_mealplan();
	void modify_mealplan();
	void delete_mealplan();


};






#endif
