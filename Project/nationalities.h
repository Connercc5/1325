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
        int Brep_num;//num of Breakfest recipes
        int Lrep_num;//num of Lunch recipes
        int Drep_num;//num of Dinner recipes
        int Srep_num;//num of Snack recipes      
        int Erep_num;//num of Dessert recipes
};




#endif
