#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"ingredient.h"




ingredient::ingredient(double amount, string unit, string ingre_name)
{
        this->quantity = amount;
        this->unit = unit;
        this->name = ingre_name;

}
ingredient::ingredient(){}
