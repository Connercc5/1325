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
	static vector <Recipe> Chosen_reps;
public:
	Plan(Mealplan m, int day, File N1, string input, int time);
	virtual ~Plan();
	string meal_type;
	string input;
	int day;
	Recipe temp_hold;
	vector<Recipe> get_chosen();
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
	void caseB(Mealplan m);
	void caseL(Mealplan m);
	void caseD(Mealplan m);
	void caseS(Mealplan m);
	void caseE(Mealplan m);
	void cancel_clicked();
	friend class Modify_window;
	friend class EnterRecipe_window;

};


class List_window:public Gtk::Window
{
	public:
	List_window(string Rep_names,string List);
	virtual~List_window();
	protected:
	Gtk::Label Rep_name_label;
	Gtk::Label List_label;
	Gtk::Box box;
	Gtk::Button ok;
	void ok_clicked();	
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
	EnterRecipe_window(Mealplan m, File N1, string NationalityName,string meal_type);
	virtual ~EnterRecipe_window();
	string recipe;
	int hold_index;
protected:
	Gtk::Label recipe_name_label;
	Gtk::Entry entry;
	Gtk::Button enter;
	Gtk::Button cancel;
	Gtk::Box box;
	friend class Plan;
	void cancel_clicked();
	void enter_clicked();

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
	vector <Recipe> Chosen;

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

	void Nationality(File N1);
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


class Plan_2 : public Gtk::Window
{
public:
	Plan_2 (string nationality_p);
	virtual ~Plan_2( );

protected:

	Gtk::Label label;
	Gtk::Label labels;
	Gtk::Label time_label;
	Gtk::Box box;
	Gtk::Button Cancel_button;
	Gtk::Button Br_button ;
	Gtk::Button Lu_button ;
	Gtk::Button Di_button ;
	Gtk::Button  Sn_button ;
	Gtk::Button De_button ;
	void Br_clicked(Glib::ustring n);
	void Lu_clicked(Glib::ustring n);
	void Di_clicked(Glib::ustring n);
	void Sn_clicked(Glib::ustring n);
	void De_clicked(Glib::ustring n);
	void Choice (string nationality_p, string meal_type_p);
	void Cancel_clicked();
	
	friend class Modify_window;
	friend class EnterRecipe_window;
};


class Option_window :public Gtk::Window
{
public:
	Option_window(File N1, string nationality_p, string meal_type_p);
	virtual ~ Option_window();
	string recipe;
	int hold_index;
protected:
	Gtk::Label recipe_name_label;
	Gtk::Button Add_button;
	Gtk::Button Delete_button;
	Gtk::Button Cancel_button;
	Gtk::Box box;
	friend class Plan;
friend class Menuwindow;
	void Cancel_clicked();
	void Add_clicked();
	void Delete_clicked();
};



