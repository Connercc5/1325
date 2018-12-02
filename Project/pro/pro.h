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



//used in option 2
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
	Gtk::ScrolledWindow scrolled_window;


	void ok_clicked();	
};







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
//used in option 2
class EnterRecipe_window :public Gtk::Window//ER
{
public:
	EnterRecipe_window(Mealplan m, File N1, string NationalityName,string meal_type);
	virtual ~EnterRecipe_window();
	string recipe;
	int hold_index;
	bool cancel_=false;
protected:
	Gtk::Label recipe_name_label;
	Gtk::Entry entry;
	Gtk::Button enter;
	Gtk::Button cancel;
	Gtk::Box box;
	void cancel_clicked();
	void enter_clicked();


};
//used in option 2
class Modify2_window : public Gtk::Window {//Used for create shopping option

	static int y;
	static vector <Recipe> Chosen_recipes;
	public:
	string tim[5] = { "Breakfast","Lunch","Dinner","Snack","Dessert" };
	Modify2_window(File N1, int day, int time);
	virtual ~Modify2_window();
	string entry_ans;
	int day;
	int time;
	int error=0;

	File N1;
        string meal_type;
        string input;
        Recipe temp_hold;
        vector<Recipe> get_chosen();
	Mealplan m;
	protected:

	void enter_clicked(string type);

	void warning();//entered something that was not an option
	Gtk::Label label;
        Gtk::Label labels;
        Gtk::Label time_label;
        Gtk::Button cancel;
        Gtk::Button brea;
        Gtk::Button lunc;
        Gtk::Button dinn;
        Gtk::Button snac;
        Gtk::Button dess;
        void Send2_ER(Mealplan m,string meal_type);
        void cancel_clicked();


	Gtk::Label nationality_names_title_label;
	Gtk::Label nationality_names_label;
	Gtk::Label nationality_label;
	Gtk::Entry nationality_entry;
	Gtk::Button enter_button;
	Gtk::Button back_button;
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


#endif
