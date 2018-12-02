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
#include"listW.h"
#include"enterrecipeW.h"
#include"modify2W.h"






class Menuwindow : public Gtk::Window
{ 
	//START:FUNCTIONS THAT ARE USED FOR ALLFILE.TXT INTERACTION

	static void File_write(File N1);
	static void get_blank(char*token);
	static string get_underscore(string s);
	static File File_read(File N1);
	static File N1;

	//END:FUNCTIONS THAT ARE USED FOR ALLFILE.TXT INTERACTION

public:
	void get_writeFileFunction(File N1);
	Menuwindow();
	virtual ~Menuwindow();
protected:
	void case1_clicked();
	void case2_clicked();
	void case3_clicked();
	void case4_clicked();

	friend class Delete_window;
	Gtk::Button case1;
	Gtk::Button case2;
	Gtk::Button case3;
	Gtk::Button case4;
	Gtk::Box box;

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


class Plan_2 : public Gtk::Window
{
public:
	Plan_2 (File N1, string nationality_p);
	virtual ~Plan_2( );
	File N1;

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
	File N1;
protected:
	Gtk::Label recipe_name_label;
	Gtk::Button Add_button;
	Gtk::Button Delete_button;
	Gtk::Button Cancel_button;
	Gtk::Box box;
	friend class Plan;
friend class Menuwindow;
	void Cancel_clicked();
	void Add_clicked(Glib::ustring n, Glib::ustring m);
	void Delete_clicked(Glib::ustring n, Glib::ustring m);
};

class Delete_window:public Gtk::Window
{
public: 
	Delete_window (File N1, string nationality_p, string meal_type_p);
	virtual ~ Delete_window (); 
	string recipe; 
	int hold_index; 
	File N1; 

protected: 

	Gtk::Label recipe_name_label; 
	Gtk::Label question_label;
	Gtk::Button Send_button; 
	Gtk::Button Cancel_button; 
	Gtk::Entry recipe_name_entry; 
	Gtk::Box box; 
	friend class Plan; 
	friend class Menuwindow; 
	void Cancel_clicked();
	void Send_clicked(Glib::ustring n, Glib::ustring m);
	
}; 

class Add_window:public Gtk::Window
{
public: 
	Add_window (File N1,int hold_index, string meal_type_p);
	virtual ~ Add_window (); 
	string recipe; 
	static string rep_name;
	int hold_index; 
	File N1;
       	string meal_type;
	static int numI;//num of ingredients added	
	static vector <ingredient> tempI;
	static Recipe R;
protected: 
	
	Gtk::Label recipe_name_label; 
	Gtk::Label ingredient_name_label;
	Gtk::Label amount_label; 
	Gtk::Label unit_label;
	Gtk::Button Add_button; 
	Gtk::Button Done_button;
	Gtk::Button Cancel_button; 
	Gtk::Entry ingredient_name_entry;
	Gtk::Entry amount_entry; 
	Gtk::Entry unit_entry;
	Gtk::Entry recipe_name_entry;
	Gtk::Box box; 
	friend class Plan; 
	friend class Menuwindow; 
	void Cancel_clicked();
	void Add_clicked(Glib::ustring n, Glib::ustring m);
	void Done_clicked();
}; 


#endif
