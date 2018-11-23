#ifndef DAY_S
#define DAY_S
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"recipe.h"


class Days
{
        public:
		Days(string day);
		string name;
		Recipe breakfast(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients);
		Recipe lunch(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients);
		Recipe dinner(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients);
		Recipe snack (string recipe_name ,vector <ingredient> ingr,int num_of_ingredients);
		Recipe dessert(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients);
};
#endif

