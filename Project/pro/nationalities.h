#ifndef NATION_M
#define NATION_M
#include<vector>
#include<string>
#include<iostream>
using namespace std;
#include"recipe.h"

class Nationalities
{
public:
        string nationality;
        vector<Recipe> lunch;//LUNCH RECIPES
        vector<Recipe> dinner;//DINNER RECIPES
        vector<Recipe> breakfast;//BREAKFEST RECIPES
        vector<Recipe> dessert;//DESSERT RECIPES
        vector<Recipe> snack;//SNACK RECIPES
	int Brep_num=0;//num of Breakfest recipes
        int Lrep_num=0;//num of Lunch recipes
        int Drep_num=0;//num of Dinner recipes
        int Srep_num=0;//num of Snack recipes      
        int Erep_num=0;//num of Dessert recipes
};




#endif
