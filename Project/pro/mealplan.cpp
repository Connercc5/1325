#include<gtkmm.h>
#include<iostream>
using namespace std;
#include<string>
#include"mealplan.h"
#include<vector>

//this class will probably hold the random function
Mealplan::Mealplan()
{
	add_mealplan();//fill vector of days with names of days
}


void Mealplan::combine_ingredents()
{



}
void Mealplan::add_mealplan()
{
	string name;
	int g =0;
	while(g<7)
	{	if(g==0)
			name="Monday";
		else if(g==1)
			name="Tuesday";
		else if(g==2)
			name="Wednesday";
		else if(g==3)
			name="Thursday";
		else if(g==4)
			name="Friday";
		else if(g==5)
			name="Saturday";
		else if(g==6)
			name="Sunday";
		daysList.push_back(Days(name));
		g++;
	}


}
void Mealplan::modify_mealplan()
{




}
void Mealplan::delete_mealplan()
{




}
