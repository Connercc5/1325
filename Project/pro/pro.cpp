#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>
#include <gtkmm.h>
#include<memory>
#include"pro.h"
using namespace std;
//START:FUNCTIONS THAT ARE USED TO INTERACT WITH TEXT

File Menuwindow::N1;
int Modify2_window::y = 0;
File Menuwindow::File_read(File N1)
{
	N1.Nationality.clear();
	vector<ingredient> G;
	ifstream inFile;
	Nationalities F1;
	int g = N1.get_filename().length();
	char file[g + 1];
	strcpy(file, N1.get_filename().c_str());
	inFile.open(file);//opens AllFile.txt
	if (!inFile.is_open())
	{
		cout << "file not found.";
		//exit(1);
	}
	char rope[900];
	inFile >> rope;
	int f = 0;
	char *token;
	token = strtok(rope, "\n");
	g = 0;
	int i = 0;
	int fi = 0;
	int s = 0;
	int l = 0;
	int Num = 0;
	inFile >> rope;
	double amount = 0;
	//intializing all meal nums to 0
	F1.Brep_num = 0;//number of Breakfest recipes
	F1.Lrep_num = 0;//number of Lunch recipes
	F1.Drep_num = 0;//number of Dinner recipes
	F1.Srep_num = 0;//number of Snack recipes
	F1.Erep_num = 0;//number of Dessert recipes
	//File read
	while (!inFile.eof())
	{
		token = strtok(rope, "\n");
		get_blank(token);
		string Nation(token);
		F1.nationality = Nation;
		//cout<<"Nationality: "<<Nation<<" "<<endl;
		while (fi < 5)
		{
			inFile >> rope;
			token = strtok(rope, "#");
			string t_name(token);
			token = strtok(NULL, "\n");
			Num = 0;
			Num = atoi(token);
			//			cout<<"TIME: "<<t_name<<"NUM: "<<Num<<endl;
			if (fi == 0)
				F1.Brep_num = Num;
			else if (fi == 1)
				F1.Lrep_num = Num;
			else if (fi == 2)
				F1.Drep_num = Num;
			else if (fi == 3)
				F1.Srep_num = Num;
			else if (fi == 4)
				F1.Erep_num = Num;
			while (s < Num)
			{
				inFile >> rope;
				token = strtok(rope, ":");

				get_blank(token);
				string Rep_name(token);
				token = strtok(NULL, "\n");
				int Rep_num = atoi(token);
				//	cout<<"RECIPE NAME:"<<Rep_name<<" RECIPE INGERDENT NUMBER: "<<Rep_num<<endl;

				inFile >> rope;

				token = strtok(rope, "_");
				i = 0;
				while (i < Rep_num)
				{
					token = strtok(NULL, "_");
					amount = atof(token);
					get_blank(token);
					token = strtok(NULL, "_");
					get_blank(token);
					string unit(token);
					token = strtok(NULL, ",");
					get_blank(token);
					string ingre_name(token);
					//cout<<"INGREDIENT "<<i<<": "<<amount<<" "<<unit<<" "<<ingre_name<<endl;
					G.push_back(ingredient(amount, unit, ingre_name));
					i++;

				}
				i = 0;
				//PUSHES RECIPES INTO THE BREAKFEST-DESSERT CATAGORIES
				if (fi == 0)
				{
					F1.breakfast.push_back(Recipe(Rep_name, G, Rep_num));
				}
				else if (fi == 1)
				{
					F1.lunch.push_back(Recipe(Rep_name, G, Rep_num));
				}
				else if (fi == 2)
				{
					F1.dinner.push_back(Recipe(Rep_name, G, Rep_num));
				}
				else if (fi == 3)
				{
					F1.snack.push_back(Recipe(Rep_name, G, Rep_num));
				}
				else if (fi == 4)
				{
					F1.dessert.push_back(Recipe(Rep_name, G, Rep_num));
				}
				G.clear();
				s++;

			}
			s = 0;
			fi++;
		}
		fi = 0;

		N1.Nationality.push_back(F1);
		i++;
		F1.breakfast.clear();
		F1.lunch.clear();
		F1.dinner.clear();
		F1.snack.clear();
		F1.dessert.clear();
		inFile >> rope;
	}
	inFile.close();
	return N1;
}



void Menuwindow::File_write(File N1)
{
	int g = N1.get_filename().length();
	char file[g + 1];
	strcpy(file, N1.get_filename().c_str());
	ofstream outFile;
	outFile.open(file);
	outFile << "BEGIN" << endl;
	g = 0;
	int j = 0;
	while (g < N1.Nationality.size())
	{

		//Get the modified amount of meals for Breakfast-Dessert

		j = 0;
		//Breakfast
		while (j < N1.Nationality[g].breakfast.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].breakfast[j].recipe_name);
			if (name.compare("DELETE") == 0)
			{
				N1.Nationality[g].Brep_num--;
			}
			j++;
		}

		j = 0;
		//Lunch
		while (j < N1.Nationality[g].lunch.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].lunch[j].recipe_name);
			if (name.compare("DELETE") == 0)
			{
				N1.Nationality[g].Lrep_num--;
			}
			j++;

		}

		j = 0;
		//Dinner
		while (j < N1.Nationality[g].dinner.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].dinner[j].recipe_name);
			if (name.compare("DELETE") == 0)
			{
				N1.Nationality[g].Drep_num--;
			}
			j++;

		}

		j = 0;
		//Snack
		while (j < N1.Nationality[g].snack.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].snack[j].recipe_name);
			if (name.compare("DELETE") == 0)
			{
				N1.Nationality[g].Srep_num--;
			}
			j++;

		}

		j = 0;
		//Dessert
		while (j < N1.Nationality[g].dessert.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].dessert[j].recipe_name);
			if (name.compare("DELETE") == 0)
			{
				N1.Nationality[g].Erep_num--;
			}
			j++;

		}

		//Write to file

		j = 0;
		outFile << N1.Nationality[g].nationality << endl;
		outFile << "Breakfest#" << N1.Nationality[g].Brep_num << endl;
		while (j < N1.Nationality[g].breakfast.size())
		{

			int b = 0;

			string name = get_underscore(N1.Nationality[g].breakfast[j].recipe_name);
			if (name.compare("DELETE") != 0)
			{
				outFile << name << ":" << N1.Nationality[g].breakfast[j].ingr.size() << endl;
				outFile << "START_";
				while (b < N1.Nationality[g].breakfast[j].ingr.size())
				{
					outFile << N1.Nationality[g].breakfast[j].ingr[b].quantity << "_" << get_underscore(N1.Nationality[g].breakfast[j].ingr[b].unit) << "_" << get_underscore(N1.Nationality[g].breakfast[j].ingr[b].name) << ",";
					b++;
				}
				outFile << endl;
			}
			j++;
		}
		j = 0;
		outFile << "Lunch#" << N1.Nationality[g].Lrep_num << endl;
		while (j < N1.Nationality[g].lunch.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].lunch[j].recipe_name);
			if (name.compare("DELETE") != 0)
			{
				outFile << name << ":" << N1.Nationality[g].lunch[j].ingr.size() << endl;
				outFile << "START_";
				while (b < N1.Nationality[g].lunch[j].ingr.size())
				{
					outFile << N1.Nationality[g].lunch[j].ingr[b].quantity << "_" << get_underscore(N1.Nationality[g].lunch[j].ingr[b].unit) << "_" << get_underscore(N1.Nationality[g].lunch[j].ingr[b].name) << ",";
					b++;
				}
				outFile << endl;
			}
			j++;
		}
		j = 0;
		outFile << "Dinner#" << N1.Nationality[g].Drep_num << endl;
		while (j < N1.Nationality[g].dinner.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].dinner[j].recipe_name);
			if (name.compare("DELETE") != 0)
			{
				outFile << name << ":" << N1.Nationality[g].dinner[j].ingr.size() << endl;
				outFile << "START_";
				while (b < N1.Nationality[g].dinner[j].ingr.size())
				{
					outFile << N1.Nationality[g].dinner[j].ingr[b].quantity << "_" << get_underscore(N1.Nationality[g].dinner[j].ingr[b].unit) << "_" << get_underscore(N1.Nationality[g].dinner[j].ingr[b].name) << ",";
					b++;
				}
				outFile << endl;
			}
			j++;
		}

		j = 0;
		outFile << "Snack#" << N1.Nationality[g].Srep_num << endl;
		while (j < N1.Nationality[g].snack.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].snack[j].recipe_name);
			if (name.compare("DELETE") != 0)
			{
				outFile << name << ":" << N1.Nationality[g].snack[j].ingr.size() << endl;
				outFile << "START_";
				while (b < N1.Nationality[g].snack[j].ingr.size())
				{
					outFile << N1.Nationality[g].snack[j].ingr[b].quantity << "_" << get_underscore(N1.Nationality[g].snack[j].ingr[b].unit) << "_" << get_underscore(N1.Nationality[g].snack[j].ingr[b].name) << ",";
					b++;
				}
				outFile << endl;
			}
			j++;
		}
		j = 0;
		outFile << "Dessert#" << N1.Nationality[g].Erep_num << endl;
		while (j < N1.Nationality[g].dessert.size())
		{
			int b = 0;
			string name = get_underscore(N1.Nationality[g].dessert[j].recipe_name);
			if (name.compare("DELETE") != 0)
			{
				outFile << name << ":" << N1.Nationality[g].dessert[j].ingr.size() << endl;
				outFile << "START_";
				while (b < N1.Nationality[g].dessert[j].ingr.size())
				{
					outFile << N1.Nationality[g].dessert[j].ingr[b].quantity << "_" << get_underscore(N1.Nationality[g].dessert[j].ingr[b].unit) << "_" << get_underscore(N1.Nationality[g].dessert[j].ingr[b].name) << ",";
					b++;
				}
				outFile << endl;
			}

			j++;

		}
		g++;
	}
	outFile.close();
}





string Menuwindow::get_underscore(string s)
{
	int f = s.length();
	char token[f + 1];
	int p = 0;
	strcpy(token, s.c_str());
	while (p < s.length())
	{
		if (token[p] == ' ')
			token[p] = '_';
		p++;
	}

	string see(token);
	return see;
}
void Menuwindow::get_blank(char*token)
{
	int f = 0;
	string t(token);
	while (f < t.length())
	{
		if (token[f] == '_')
			token[f] = ' ';
		f++;
	}
}

//END:FUNCTIONS THAT INTERACT WITH TEXTFILE 







//MODIFY2_WINDOW CONSTRUCTOR,DECONSTRUCTOR AND FUNCTIONS
Modify2_window::Modify2_window(File N1, int choice, int day, int time) :box(Gtk::ORIENTATION_VERTICAL), enter_button("Enter"), back_button("Back to main menu") {
	set_size_request(400, 200);
	set_title("Create Shopping List");
	add(box);
	this->choice = choice;
	this->day = day;
	this->time = time;
//	cout << time << endl;
	y = 0;
	string nations = " ";
	while (y < N1.Nationality.size())
	{

		nations += N1.Nationality[y].nationality;
		nations += "\n";
		y++;
	}
	nationality_names_title_label.set_text("Nationalities:");
	nationality_names_label.set_text(nations);
	nations = " ";
	nationality_label.set_text("Enter a nationality: ");
	box.pack_start(nationality_names_title_label);
	box.pack_start(nationality_names_label);
	box.pack_start(nationality_label);

	nationality_entry.set_max_length(50);
	nationality_entry.set_text("Enter nationality");
	nationality_entry.select_region(0, nationality_entry.get_text_length());
	box.pack_start(nationality_entry);

	//entry_ans=nationality_entry.get_text();

	enter_button.signal_clicked().connect(sigc::bind<File>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), N1));
	box.pack_start(enter_button);
	back_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify2_window::back_button_clicked));
	box.pack_start(back_button);

	show_all_children();

}

Modify2_window::~Modify2_window() { hide(); }
void Modify2_window::enter_clicked(File N1)
{
	if (entry_ans.compare("DONE") != 0)
	{
		Mealplan m(N1, choice); //SETTING UP WINDOW FOR MANUAL OPTION
		string input = nationality_entry.get_text();
		hide();
		Plan p(m, day, N1, input, time);
		Gtk::Main::run(p);
		back_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify2_window::back_button_clicked));

		 if((day==6)&&(time==4))
                {
			this->Chosen=p.Chosen_reps;
                        ShoppingList s (p.Chosen_reps);
                        cout<<s.Rep_names<<" "<<s.List<<endl;
                        cout<<"SIZE OF VECTOR:"<<p.Chosen_reps.size()<<endl;
			List_window f (s.Rep_names,s.List);
			Gtk::Main::run(f);
                }

		
		
		
		p.hide();

	}
}
void Modify2_window::back_button_clicked()
{
	hide();
	entry_ans = "DONE";
}



//ENTERRECIPE_WINDOW CONSTRUCTOR DECONSTRUCTOR AND FUNCTIONS

EnterRecipe_window::~EnterRecipe_window()
{
	hide();
}

EnterRecipe_window::EnterRecipe_window(Mealplan m, File N1, string NationalityName, string meal_type) :box(Gtk::ORIENTATION_VERTICAL), enter("Enter"), cancel("Cancel", 3)
{
	set_size_request(300, 300);
	int e = 0;
	while (e < N1.Nationality.size())
	{
		if (N1.Nationality[e].nationality.compare(NationalityName) == 0)
		{

			hold_index = e;
		}
		e++;
	}
	e = 0;
	string recipe_names = " ";



	if (meal_type.compare("Breakfast") == 0)
	{
		while (e < N1.Nationality[hold_index].breakfast.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].breakfast[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type.compare("Lunch") == 0)
	{
		while (e < N1.Nationality[hold_index].lunch.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].lunch[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type.compare("Dinner") == 0)
	{
		while (e < N1.Nationality[hold_index].dinner.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].dinner[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type.compare("Snack") == 0)
	{
		while (e < N1.Nationality[hold_index].snack.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].snack[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type.compare("Dessert") == 0)
	{
		while (e < N1.Nationality[hold_index].dessert.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].dessert[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	//cout << recipe_names << endl;
	add(box);


	recipe_name_label.set_text(recipe_names);

	box.pack_start(recipe_name_label);
	box.pack_start(entry);
	box.pack_start(enter);
	box.pack_start(cancel);
	show_all_children();
	enter.signal_clicked().connect(sigc::mem_fun(*this, &EnterRecipe_window::enter_clicked));
	cancel.signal_clicked().connect(sigc::mem_fun(*this, &EnterRecipe_window::cancel_clicked));
}
void EnterRecipe_window::enter_clicked()
{
	this->recipe = entry.get_text();
	hide();
}
void EnterRecipe_window::cancel_clicked()
{
	hide();

}

//List_window Constructor Deconstructor and Functions
List_window::~List_window(){hide();}
List_window::List_window(string Rep_names,string List):box(Gtk::ORIENTATION_VERTICAL),ok("ok")
{
	set_size_request(400,400);
	Rep_name_label.set_text(Rep_names);
	List_label.set_text(List);
	add(box);
	box.pack_start(Rep_name_label);
	box.pack_start(List_label);
	ok.signal_clicked().connect(sigc::mem_fun(*this, &List_window::ok_clicked));
	show_all_children();
	
}
void List_window::ok_clicked()
{
	hide();
}

//PLAN CONSTRUCTOR DECONSTRUCTOR AND FUNCTIONS
Plan::~Plan()
{
	hide();
}

Plan::Plan(Mealplan m, int day, File N1, string input, int time) :box(Gtk::ORIENTATION_VERTICAL), day0("Breakfast"), day1("Lunch"), day2("Dinner"), day3("Snack"), day4("Dessert"), cancel("Cancel", 3)
{
	string tim[5] = { "Breakfast","Lunch","Dinner","Snack","Dessert" };
	this->N1 = N1;
	set_size_request(400, 200);
	//lab.set_text(time[])
	label.set_text(m.daysList[day].name);
	labels.set_text(input);
	add(box);
	this->day =day;
	this->input = input;
	time_label.set_text("Recipe for " + tim[time]);
	box.pack_start(label);
	box.pack_start(time_label);
	box.pack_start(day0);
	box.pack_start(day1);
	box.pack_start(day2);
	box.pack_start(day3);
	box.pack_start(day4);
	box.pack_start(cancel);
	show_all_children();
	//divde by time then connect by caseR function
	day0.signal_clicked().connect(sigc::bind<Mealplan>(sigc::mem_fun(*this, &Plan::caseB), m));
	day1.signal_clicked().connect(sigc::bind<Mealplan>(sigc::mem_fun(*this, &Plan::caseL), m));
	day2.signal_clicked().connect(sigc::bind<Mealplan>(sigc::mem_fun(*this, &Plan::caseD), m));
	day3.signal_clicked().connect(sigc::bind<Mealplan>(sigc::mem_fun(*this, &Plan::caseS), m));
	day4.signal_clicked().connect(sigc::bind<Mealplan>(sigc::mem_fun(*this, &Plan::caseE), m));
	cancel.signal_clicked().connect(sigc::mem_fun(*this, &Plan::cancel_clicked));

}
void Plan::cancel_clicked(){hide();}

void Plan::caseR(Mealplan m)
{
	hide();
	int y = 0;
	int h = 0;
	EnterRecipe_window e(m, N1, input, meal_type);
	Gtk::Main::run(e);
	string rep_name = e.recipe;
	if (meal_type.compare("Breakfast") == 0)
		while (h < N1.Nationality[e.hold_index].breakfast.size())
		{
			if (N1.Nationality[e.hold_index].breakfast[h].recipe_name.compare(rep_name) == 0)
				this->temp_hold = N1.Nationality[e.hold_index].breakfast[h];
			h++;
		}
	else if (meal_type.compare("Lunch") == 0)
		while (h < N1.Nationality[e.hold_index].lunch.size())
		{
			if (N1.Nationality[e.hold_index].lunch[h].recipe_name.compare(rep_name) == 0)
				this->temp_hold = N1.Nationality[e.hold_index].lunch[h];
			h++;
		}
	else if (meal_type.compare("Dinner") == 0)
		while (h < N1.Nationality[e.hold_index].dinner.size())
		{
			if (N1.Nationality[e.hold_index].dinner[h].recipe_name.compare(rep_name) == 0)
				this->temp_hold = N1.Nationality[e.hold_index].dinner[h];
			h++;
		}
	else if (meal_type.compare("Snack") == 0)
	{
		while (h < N1.Nationality[e.hold_index].snack.size())
		{
			if (N1.Nationality[e.hold_index].snack[h].recipe_name.compare(rep_name) == 0)
				this->temp_hold = N1.Nationality[e.hold_index].snack[h];

			h++;
		}
	}
	else if (meal_type.compare("Dessert") == 0)
	{
		while (h < N1.Nationality[e.hold_index].dessert.size())
		{
			if (N1.Nationality[e.hold_index].dessert[h].recipe_name.compare(rep_name) == 0)
				this->temp_hold = N1.Nationality[e.hold_index].dessert[h];
			h++;
		}
	}
	Chosen_reps.push_back(temp_hold);
	}

void Plan::caseB(Mealplan m)
{
	meal_type = "Breakfast";
	caseR(m);
}
void Plan::caseL(Mealplan m)
{
	meal_type = "Lunch";
	caseR(m);
}
void Plan::caseD(Mealplan m)
{
	meal_type = "Dinner";
	caseR(m);
}
void Plan::caseS(Mealplan m)
{
	meal_type = "Snack";
	caseR(m);
}
void Plan::caseE(Mealplan m)
{
	meal_type = "Dessert";
	caseR(m);
}






//MENUWINDOW CONSTRUCTOR ,DECONSTRUCTOR AND FUNCTIONS
Menuwindow::Menuwindow() :box(Gtk::ORIENTATION_VERTICAL)
, case1("Modify Recipes"), case2("Create Meal Plan Shopping List", 2), case3("Choose Old Shopping list"), case4("Exit", 3)
{
	set_size_request(400, 200);
	set_title("Preppy Meal");
	add(box);
	Gtk::Label label = Gtk::Label();
	label.set_text("Pick a option");
	label.set_padding(10, 10);
	box.pack_start(label);
	box.pack_start(case1);
	box.pack_start(case2);
	box.pack_start(case3);
	box.pack_start(case4);
	show_all_children();


	case1.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case1_clicked));

	case2.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case2_clicked));
	case4.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case4_clicked));



}
Menuwindow::~Menuwindow()
{
	hide();
}


void Menuwindow::case1_clicked() {
	hide();
	N1 = File_read(N1);
	Modify_window w(N1);
	Gtk::Main::run(w);
}

void Menuwindow::case2_clicked()
{
	N1 = File_read(N1);//gives access to data from valid
	//setting up the dialog box for random option 
	Gtk::Dialog dialog = Gtk::Dialog();
	dialog.add_button("Yes", 1);
	dialog.add_button("No", 0);
	dialog.add_button("Cancel", 3);
	dialog.set_transient_for(*this);
	dialog.set_title("-Selection Option-");
	dialog.set_size_request(300, 100);
	Gtk::Label label = Gtk::Label();
	label.show();

	dialog.get_content_area()->pack_start(label);
	label.set_text("Random Selction");
	int choice = dialog.run();
	//We randomaly choose or user choose CHECK OUT mealplan.cpp
	if (choice == 3)
	{
		dialog.hide();
	}
	else if (choice == 1)
	{







		//Random option
	}
	else
	{
		//manual option
		dialog.hide();
		//hide(); 
	 //SETTING UP WINDOW FOR MANUAL OPTION
		int day = 0;
		int time = 0;
		while (day < 7)
		{
			time = 0;
			while (time < 5)
			{

				Modify2_window w(N1, choice, day, time);
				Gtk::Main::run(w);
				if (w.entry_ans.compare("DONE") == 0)
				{
					w.hide();

					time = 5;
					day = 7;
				}

				time++;
			}
			day++;
		}

	}


}


void Menuwindow::case4_clicked() {
	Gtk::Main::quit();
}

//MODIFY_WINDOW CONSTRUCTOR, DECONSTRUCTOR AND FUNCTIONS
Modify_window::Modify_window(File N1) :box(Gtk::ORIENTATION_VERTICAL), nationality_button("Enter"), back_button("Back to main menu") {
	set_size_request(400, 200);
	set_title("Modify a recipe");
	add(box);

	int y = 0;
	string nations;
	while (y < N1.Nationality.size())
	{
		nations += N1.Nationality[y].nationality;
		nations += "\n";
		y++;
	}

	nationality_names_title_label.set_text("Nationalities:");
	nationality_names_label.set_text(nations);

	nationality_label.set_text("Enter a nationality: ");
	box.pack_start(nationality_names_title_label);
	box.pack_start(nationality_names_label);
	box.pack_start(nationality_label);

	nationality_entry.set_max_length(50);
	nationality_entry.set_text("Enter nationality");
	nationality_entry.select_region(0, nationality_entry.get_text_length());
	box.pack_start(nationality_entry);

	entry_ans = nationality_entry.get_text();

	nationality_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify_window::Nationality));
	box.pack_start(nationality_button);
	back_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify_window::back_button_clicked));
	box.pack_start(back_button);

	show_all_children();

}


void Modify_window::Nationality() {}
Modify_window::~Modify_window() {}
void Modify_window::back_button_clicked() {
	hide();
	Menuwindow w;
	Gtk::Main::run(w);
}
