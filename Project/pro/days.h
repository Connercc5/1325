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
		Days(Recipe b,Recipe l,Recipe d,Recipe s,Recipe e);
		string name;
		Recipe breakfast;
		Recipe lunch;
		Recipe dinner;
		Recipe snack;
		Recipe dessert;

};
#endif

