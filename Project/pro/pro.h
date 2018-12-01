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

	void Nationality();
	void back_button_clicked();


	Gtk::Label nationality_names_title_label;
	Gtk::Label nationality_names_label;
	Gtk::Label nationality_label;
	Gtk::Entry nationality_entry;
	Gtk::Button nationality_button;
	Gtk::Button back_button;
	Gtk::Box box;
};


#endif

