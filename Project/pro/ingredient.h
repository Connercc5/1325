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


	double quantity;//amount of each ingredent



	string unit;
	//THESE FUNCTION DECLARATION  HAVE NOT BEEN GIVEN USES YET
	//THESE DECLARATIONS DO NOT A PROTOTYPES IN THE .CPP FILE YET
	//void add_ingredient();
        //void modify_ingredient();
        //void delete_ingredient();


};






#endif

