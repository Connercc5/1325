#ifndef INGRE_S
#define INGRE_S
#include<iostream>
using namespace std;
#include<string>
#include <vector>


class ingredient
{
        public:
        string name;//name of the ingredient
	ingredient(double amount,string unit,string ingre_name);
	ingredient();
	double quantity;//amount of each ingredent
	string unit;
};






#endif

