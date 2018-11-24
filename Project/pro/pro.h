#ifndef MEAL_P
#define MEAL_P
#include <gtkmm.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
//SLOWLY INTEGRATING IN ALL OF OUR CLASS
#include"file.h"
#include"nationalities.h"
#include"recipe.h"
#include"ingredient.h"
#include"days.h"
#include"mealplan.h"




class Plan : public Gtk::Window
{
public:
	Plan(Mealplan m, int day, File N1, string input, int time);
	virtual ~Plan();
	string meal_type;
	File N1;
protected:

	Gtk::Label label;
	Gtk::Label labels;
	Gtk::Label time_label;
	Gtk::Box box;
	Gtk::Button cancel;
	Gtk::Button day0;
	Gtk::Button day1;
	Gtk::Button day2;
	Gtk::Button day3;
	Gtk::Button day4;
	void caseR(Mealplan m);
	friend class Modify_window;
};











class Menuwindow : public Gtk::Window
{ //START:FUNCTIONS THAT ARE USED FOR FILE INTERACTIONS

	static void File_write(File N1);
	static void get_blank(char*token);
	static string get_underscore(string s);
	static File File_read(File N1);
	static File N1;

	//END:FUNCTIONS THAT ARE USED FOR FILE INTERACTIONS*/

public:

	Menuwindow();
	virtual ~Menuwindow();
protected:
	void case1_clicked();
	void case2_clicked();
	//void case2_clicked(File N1);
	void case3_clicked();
	void case4_clicked();


	Gtk::Button case1;
	Gtk::Button case2;
	Gtk::Button case3;
	Gtk::Button case4;
	Gtk::Box box;

};

class EnterRecipe_window :public Gtk::Window
{
public:
	EnterRecipe_window(Mealplan m, File N1, string NationalityName);
	virtual ~EnterRecipe_window();

protected:
	Gtk::Label recipe_name_label;
	Gtk::Entry entry;
	Gtk::Button enter;
	Gtk::Button cancel;
	Gtk::Box box;


};
class Modify2_window : public Gtk::Window {//Used for create shopping option

	static int y;
	public:
	Modify2_window(File N1, int choice, int day, int time);
	virtual ~Modify2_window();
	string entry_ans;
	int day;
	int time;
	int choice;

protected:

	void enter_clicked(File N1);
	void back_button_clicked();



	Gtk::Label nationality_names_title_label;
	Gtk::Label nationality_names_label;
	Gtk::Label nationality_label;
	Gtk::Entry nationality_entry;
	Gtk::Button enter_button;
	Gtk::Button back_button;
	Gtk::Box box;
	friend class Plan;
};




class Modify_window : public Gtk::Window {
public:
	Modify_window(File N1);
	virtual ~Modify_window();
	string entry_ans;

protected:

	void Nationality();
	void back_button_clicked();


	Gtk::Label nationality_names_title_label;
	Gtk::Label nationality_names_label;
	Gtk::Label nationality_label;
	Gtk::Entry nationality_entry;
	Gtk::Button nationality_button;
	Gtk::Button back_button;
	Gtk::Box box;
	friend class Plan;
};


class Recipe_Info {
public:
	string food_type, recipe_name, recipe;
	Recipe_Info(string food_type_p, string recipe_name_p, string recipe_p);
};
#endif

