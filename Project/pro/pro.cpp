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
#include <sstream>
#include"pro.h"
using namespace std;

//BASED ON CODE PUSHED ON GITHUB CURRENTLY THESE ARE THE THINGS THAT NEED TO BE DONE
//THINGS THAT HAVE NOT BEEN  CODED YET
//
//THE MODIFY RECIPE OPTION
//THE CREATE RANDOM SHOPPING LIST OPTION	(FOR THIS JUMP TO LINE 814 IN CODE)
//LOOK AT OLD SHOPPING LIST OPTION		(FOR THIS JUMP TO LINE 774 IN CODE)









//ALL STATIC MEMBERS FROM .H FILE
File Menuwindow::N1;
int Modify2_window::y = 0;
vector <Recipe> Modify2_window::Chosen_recipes;
int Add_window:: numI=0;//num of ingredients added
vector <ingredient> Add_window::tempI;
Recipe Add_window:: R;
string Add_window:: rep_name;//name of recipe

//START:FUNCTIONS THAT ARE USED TO INTERACT WITH ALLFILE.TXT
void Menuwindow ::get_writeFileFunction(File N1)
{
	File_write(N1);
}


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
	token = strtok(rope, "\n");//BEGIN
	g = 0;
	int i = 0;
	int fi = 0;
	int s = 0;
	int l = 0;
	int Num = 0;
	inFile >> rope;//first nationalities name
	double amount = 0;
	//intializing all meal nums to 0
	F1.Brep_num = 0;//number of Breakfast recipes
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
					get_blank(token);//remove underscore
					token = strtok(NULL, "_");
					get_blank(token);//remove underscore
					string unit(token);
					token = strtok(NULL, ",");
					get_blank(token);//remove underscore
					string ingre_name(token);
					//cout<<"INGREDIENT "<<i<<": "<<amount<<" "<<unit<<" "<<ingre_name<<endl;
					G.push_back(ingredient(amount, unit, ingre_name));//each ingredient object contains 1 double for amount 2 strings one for name of ingredients and the other for the unit of amount
					i++;

				}
				i = 0;
				//PUSHES RECIPES INTO THE BREAKFAST-DESSERT CATAGORIES
				//each recipe object contains a ingredient vector , string for name of recipe and int fot the num of ingredients in vector
				//each nationalities object contains 5 recipe vectors for breafast-dessert and 5 int for the number of recipes in each of those catagories
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
		//pushes nationality vector on the file object
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
//if user deleted a recipe the code would enter one of hte 5 loops to decrease the number of meals in that catagory
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
		outFile << "Breakfast#" << N1.Nationality[g].Brep_num << endl;
		while (j < N1.Nationality[g].breakfast.size())
		{

			int b = 0;

			string name = get_underscore(N1.Nationality[g].breakfast[j].recipe_name);
			if (name.compare("DELETE") != 0)//if user wanted recipe deleted do not print file
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

//END:FUNCTIONS THAT INTERACT WITH TEXTFILE ALLFILE.TXT



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


	//this is the visit old shopping list option
	case3.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case3_clicked));
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
	label.set_text("Random Selection");
	int choice = dialog.run();
	//We randomaly choose or user chooseS
	if (choice == 3)
	{
		dialog.hide();
	}
	else if (choice == 1)
	{
				//RANDOM YES
		string listWrite;
		string repNames;
		vector<string> days;
		days.push_back("Monday");
		days.push_back("Tuesday");
		days.push_back("Wednesday");
		days.push_back("Thursday");
		days.push_back("Friday");
		days.push_back("Saturday");
		days.push_back("Sunday");
		int b=0;
        ostringstream strs;
        int i=0;
        while(i<days.size())
        {


            //random nationality, stays static though random
            int natRand=rand()%N1.Nationality.size();

            //random recipies from 0 to the size of breakfast
            int recipeRandBreakfast=rand()%N1.Nationality[natRand].breakfast.size();
            int recipeRandLunch=rand()%N1.Nationality[natRand].lunch.size();
            int recipeRandDinner=rand()%N1.Nationality[natRand].dinner.size();
            int recipeRandSnack=rand()%N1.Nationality[natRand].snack.size();
            int recipeRandDessert=rand()%N1.Nationality[natRand].dessert.size();
            //building recipe names string for list window
            repNames=repNames+days.at(i)+": ";
            repNames=repNames+N1.Nationality[natRand].breakfast[recipeRandBreakfast].recipe_name+", ";
            repNames=repNames+N1.Nationality[natRand].lunch[recipeRandLunch].recipe_name+", ";
            repNames=repNames+N1.Nationality[natRand].dinner[recipeRandDinner].recipe_name+", ";
            repNames=repNames+N1.Nationality[natRand].snack[recipeRandSnack].recipe_name+", ";
            repNames=repNames+N1.Nationality[natRand].dessert[recipeRandDessert].recipe_name+"\n";


            //get ingredients for each & build list string for list window
            while (b < N1.Nationality[natRand].breakfast[recipeRandBreakfast].ingr.size())
            {
                strs.clear();
                strs.str("");
                strs<<N1.Nationality[natRand].breakfast[recipeRandBreakfast].ingr[b].quantity;
                string temp = strs.str();
                listWrite=listWrite+temp+" "+ N1.Nationality[natRand].breakfast[recipeRandBreakfast].ingr[b].unit+" "+ N1.Nationality[natRand].breakfast[recipeRandBreakfast].ingr[b].name+"\n";
                b++;

            }
            b=0;
            while (b < N1.Nationality[natRand].lunch[recipeRandLunch].ingr.size())
            {
                strs.clear();
                strs.str("");
                strs<<N1.Nationality[natRand].lunch[recipeRandLunch].ingr[b].quantity;
                string temp = strs.str();
                listWrite=listWrite+temp+" "+ N1.Nationality[natRand].lunch[recipeRandLunch].ingr[b].unit+" "+ N1.Nationality[natRand].lunch[recipeRandLunch].ingr[b].name+"\n";
                b++;

            }
            b=0;
            while (b < N1.Nationality[natRand].dinner[recipeRandDinner].ingr.size())
            {
                strs.clear();
                strs.str("");
                strs<<N1.Nationality[natRand].dinner[recipeRandDinner].ingr[b].quantity;
                string temp = strs.str();
                listWrite=listWrite+temp+" "+ N1.Nationality[natRand].dinner[recipeRandDinner].ingr[b].unit+" "+ N1.Nationality[natRand].dinner[recipeRandDinner].ingr[b].name+"\n";
                b++;

            }
            b=0;
            while (b < N1.Nationality[natRand].snack[recipeRandSnack].ingr.size())
            {
                strs.clear();
                strs.str("");
                strs<<N1.Nationality[natRand].snack[recipeRandSnack].ingr[b].quantity;
                string temp = strs.str();
                listWrite=listWrite+temp+" "+ N1.Nationality[natRand].snack[recipeRandSnack].ingr[b].unit+" "+ N1.Nationality[natRand].snack[recipeRandSnack].ingr[b].name+"\n";
                b++;

            }
            b=0;
            while (b < N1.Nationality[natRand].dessert[recipeRandDessert].ingr.size())
            {
                strs.clear();
                strs.str("");
                strs<<N1.Nationality[natRand].dessert[recipeRandDessert].ingr[b].quantity;
                string temp = strs.str();
                listWrite=listWrite+temp+" "+ N1.Nationality[natRand].dessert[recipeRandDessert].ingr[b].unit+" "+ N1.Nationality[natRand].dessert[recipeRandDessert].ingr[b].name+"\n";
                b++;

            }
            strs.clear();
            strs.str("");
            i++;
        }

        List_window(repNames,listWrite,1);
	}
	else
	{
		//RANDOM NO
		//manual option
		dialog.hide();
		hide();
	 //SETTING UP WINDOW FOR MANUAL OPTION
		int day = 0;
		int time = 0;
		while (day < 7)//ASK SEVEN DAYS A WEEK
		//while (day < 1)//this is here because i am testing code
		{
			time = 0;
			while (time < 5)//ASK FOR EACH MEAL BREAKFAST-DESSERT
			{

				Modify2_window w(N1, day, time);//CHECK OUT MODIFY2_WINDOW CONSTRUCTOR
				Gtk::Main::run(w);
				time -=w.error;//user entered a invalid recipe so add back time so they can still select recipe for that time of day
				if (w.entry_ans.compare("DONE") == 0)//if user wishes to cancel manual option
				{
					w.hide();
					Menuwindow m;
					Gtk::Main::run(m);

					time = 5;
					day = 7;
				}

				time++;
			}
			day++;
		}

	}


}

void Menuwindow::case3_clicked() {
	Gtk::MessageDialog dialog(*this,"Choose old shopping list",false,Gtk::MESSAGE_INFO);
	dialog.set_secondary_text("Please look in saved folder list");
	dialog.run();
}


void Menuwindow::case4_clicked() {
	Gtk::Main::quit();
}

//J'ai modifié
//MODIFY_WINDOW CONSTRUCTOR, DECONSTRUCTOR AND FUNCTIONS
Modify_window::Modify_window(File N1) :box(Gtk::ORIENTATION_VERTICAL), nationality_button("Enter"), back_button("Back to main menu") {
	set_size_request(400, 200);
	set_title("Modify a recipe");
	add(box);

	int y = 0;
	string nations;
	//	cout << N1.Nationality.size() << endl;
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

	nationality_button.signal_clicked().connect(sigc::bind<File>(sigc::mem_fun(*this, &Modify_window::Nationality), N1));
	box.pack_start(nationality_button);
	back_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify_window::back_button_clicked));
	box.pack_start(back_button);

	show_all_children();

}

//J'ai modifié
void Modify_window::Nationality(File N1) {
  string user_input = nationality_entry.get_text ();
   //there was a bug here if you entered anything other then irish the MESSAGEDIALOG would put up
  bool check=false;//check if name matches nationality
  for (int i = 0; i < N1.Nationality.size (); i++)
  {
   //there was a bug here
    if (user_input == N1.Nationality[i].nationality)
    {

      	hide();
	Plan_2 p( N1, user_input);
	Gtk::Main::run(p);
	check=true;
	break;
    }
  }
  if(check ==false)
  {
      Gtk::MessageDialog dialog (*this, "Wrong input, try again", false, Gtk::MESSAGE_INFO);
      dialog.run();
      //just added this
	//Menuwindow w;
	//Gtk::Main::run(w);
   }



}

Modify_window::~Modify_window() {}
void Modify_window::back_button_clicked() {
	hide();
	Menuwindow w;
	Gtk::Main::run(w);}




Plan_2::~Plan_2()
{
	hide();
}

Plan_2::Plan_2(File N1, string nationality_p) :box(Gtk::ORIENTATION_VERTICAL), Br_button("Breakfast"), Lu_button("Lunch"), Di_button("Dinner"), Sn_button("Snack"), De_button("Dessert"), Cancel_button("Cancel")
{

         this->N1 = N1;
	set_size_request(400, 200);
	set_title ("In which category ?");
	add(box);



		Br_button.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &Plan_2::Br_clicked), nationality_p));
		box.pack_start(Br_button);
	       	Lu_button.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &Plan_2::Lu_clicked), nationality_p));
		box.pack_start(Lu_button);
	       	Di_button.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &Plan_2::Di_clicked), nationality_p));
		box.pack_start(Di_button);
	       	Sn_button.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &Plan_2::Sn_clicked), nationality_p));
		box.pack_start(Sn_button);
	       	De_button.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &Plan_2::De_clicked), nationality_p));
		box.pack_start(De_button);
		Cancel_button.signal_clicked().connect(sigc::mem_fun(*this, &Plan_2::Cancel_clicked));
		box.pack_start(Cancel_button);
		show_all_children();


}

void Plan_2::Choice (string nationality_p, string meal_type_p) {
	hide();
	Option_window o( N1,  nationality_p, meal_type_p);
	Gtk::Main::run(o);
}

void Plan_2::Cancel_clicked(){
	hide();
	Menuwindow w;
	Gtk::Main::run(w);
}

void Plan_2::Br_clicked (Glib::ustring nationality_p) {
  string meal_type  = "Breakfast";
   Choice  (nationality_p, meal_type);
}


void Plan_2::Lu_clicked (Glib::ustring nationality_p) {
  string meal_type  = "Lunch";
   Choice  (nationality_p, meal_type);
}


void Plan_2::Di_clicked (Glib::ustring nationality_p) {
//We are using Dinner  not Diner the spelling was causing that input not to be read in from file
string meal_type  = "Dinner";
  Choice  (nationality_p, meal_type);
}

void Plan_2::Sn_clicked (Glib::ustring nationality_p) {
  string meal_type  = "Snack";
   Choice  (nationality_p, meal_type);
}

void Plan_2::De_clicked (Glib::ustring nationality_p) {
  string meal_type  = "Dessert";
   Choice  (nationality_p, meal_type);
}





Option_window::~Option_window()
{
	hide();
}

Option_window::Option_window( File N1, string nationality_p, string meal_type_p) :box(Gtk::ORIENTATION_VERTICAL), Add_button("Add"), Delete_button("Delete"),Cancel_button("Cancel")
{
  this->N1= N1;

	set_size_request(300, 300);
	int e = 0;
	while (e < N1.Nationality.size())
	{

		if (N1.Nationality[e].nationality.compare(nationality_p) == 0)
		{

			hold_index = e;
		}
		e++;
	}


	e = 0;
	string recipe_names = " ";



	if (meal_type_p.compare("Breakfast") == 0)
	{


		while (e < N1.Nationality[hold_index].breakfast.size())
		{

			recipe_names = recipe_names + N1.Nationality[hold_index].breakfast[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Lunch") == 0)
	{
		while (e < N1.Nationality[hold_index].lunch.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].lunch[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Dinner") == 0)
	{
		while (e < N1.Nationality[hold_index].dinner.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].dinner[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Snack") == 0)
	{
		while (e < N1.Nationality[hold_index].snack.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].snack[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Dessert") == 0)
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
	box.pack_start(Add_button);
	box.pack_start (Delete_button);
	box.pack_start(Cancel_button);
	show_all_children();
	Add_button.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Option_window::Add_clicked), nationality_p , meal_type_p));
	Delete_button.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Option_window::Delete_clicked), nationality_p , meal_type_p));
	Cancel_button.signal_clicked().connect(sigc::mem_fun(*this, &Option_window::Cancel_clicked));
}
void Option_window::Add_clicked(Glib::ustring nationality_p, Glib::ustring meal_type_p)
{
      hide();
      Add_window a( N1,  hold_index, meal_type_p);
       Gtk::Main::run(a);
       // cout << N1.Nationality.size() << endl;
  // cout << nationality_p << endl << meal_type_p << endl;
}


void Option_window::Delete_clicked(Glib::ustring nationality_p, Glib::ustring meal_type_p)
{
  //  cout << N1.Nationality.size() << endl;
  // cout << nationality_p << endl << meal_type_p << endl;
    hide();
      Delete_window d( N1,  nationality_p, meal_type_p);
       Gtk::Main::run(d);

}


void Option_window::Cancel_clicked()
{
	hide();
		Menuwindow w;
	Gtk::Main::run(w);
}




/////////


Delete_window::~Delete_window()
{
	hide();
}

Delete_window::Delete_window( File N1, string nationality_p, string meal_type_p) :box(Gtk::ORIENTATION_VERTICAL), Send_button("Send"),Cancel_button("Cancel")
{
  this->N1= N1;

	set_size_request(300, 300);
	int e = 0;
	while (e < N1.Nationality.size())
	{

		if (N1.Nationality[e].nationality.compare(nationality_p) == 0)
		{

			hold_index = e;
		}
		e++;
	}


	e = 0;
	string recipe_names = " ";



	if (meal_type_p.compare("Breakfast") == 0)
	{


		while (e < N1.Nationality[hold_index].breakfast.size())
		{

			recipe_names = recipe_names + N1.Nationality[hold_index].breakfast[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Lunch") == 0)
	{
		while (e < N1.Nationality[hold_index].lunch.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].lunch[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Dinner") == 0)
	{
		while (e < N1.Nationality[hold_index].dinner.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].dinner[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Snack") == 0)
	{
		while (e < N1.Nationality[hold_index].snack.size())
		{
			recipe_names = recipe_names + N1.Nationality[hold_index].snack[e].recipe_name;
			recipe_names = recipe_names + "\n";
			e++;
		}
	}
	else if (meal_type_p.compare("Dessert") == 0)
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

	question_label.set_text ("Which recipe would you like to delete ?");
	box.pack_start (question_label);

	recipe_name_entry.set_max_length(50);
	recipe_name_entry.set_text("Enter");
	recipe_name_entry.select_region(0, recipe_name_entry.get_text_length());
	box.pack_start(recipe_name_entry);

	box.pack_start(Send_button);
	box.pack_start(Cancel_button);
	show_all_children();
	Send_button.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Delete_window::Send_clicked), nationality_p , meal_type_p));
	Cancel_button.signal_clicked().connect(sigc::mem_fun(*this, &Delete_window::Cancel_clicked));
}


void Delete_window::Send_clicked(Glib::ustring nationality_p, Glib::ustring meal_type_p)
{
    hide ();
    string user_input = recipe_name_entry.get_text();
   int i=0;


	while(i<1000)
    {
if(i<N1.Nationality[hold_index].Brep_num)
if( user_input.compare(N1.Nationality[hold_index].breakfast[i].recipe_name)==0)
    {

	   N1.Nationality[hold_index].breakfast[i].recipe_name="DELETE";
  	 break;

    }
if(i<N1.Nationality[hold_index].Lrep_num)
     if(user_input.compare(N1.Nationality[hold_index].lunch[i].recipe_name)==0)
    {
	   N1.Nationality[hold_index].lunch[i].recipe_name="DELETE";
  	 break;


    }
if(i<N1.Nationality[hold_index].Drep_num)
    if(user_input.compare(N1.Nationality[hold_index].dinner[i].recipe_name)==0)
    {
	   N1.Nationality[hold_index].dinner[i].recipe_name="DELETE";
  	 break;
    }
if(i<N1.Nationality[hold_index].Srep_num)
   if(user_input.compare(N1.Nationality[hold_index].snack[i].recipe_name)==0)
   {
	   N1.Nationality[hold_index].snack[i].recipe_name="DELETE";
  	 break;



    }
if(i<N1.Nationality[hold_index].Erep_num)
    if(user_input.compare(N1.Nationality[hold_index].dessert[i].recipe_name)==0)
    {


	  N1.Nationality[hold_index].dessert[i].recipe_name="DELETE";

  	 break;
    }

    i++;
    }

   Menuwindow r;
    r.get_writeFileFunction(N1);
    Gtk::MessageDialog dialog(*this,"Done",false,Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("Recipe Deleted!");
    dialog.run();
    Menuwindow m;
    dialog.hide();
    Gtk::Main::run(m);


}
void Delete_window::Cancel_clicked()
{
	hide();
		Menuwindow w;
	Gtk::Main::run(w);
}

Add_window::~Add_window()
{
	hide();
}


static int counter = 0;

//when user click the add button
Add_window::Add_window( File N1, int hold_index, string meal_type_p) :box(Gtk::ORIENTATION_VERTICAL), Add_button("Add"),Cancel_button("Cancel"), Done_button ("Done")
{

 this->N1= N1;
	this->hold_index=hold_index;
	this->meal_type=meal_type_p;

	set_size_request(300, 300);

	add(box);

	//this appears only once to get the recipe name... but I'm struggling to transfer the input to the Done_clicked function
	if (counter == 0) {
	recipe_name_label.set_text("Enter recipe name:");
	box.pack_start(recipe_name_label);


	recipe_name_entry.set_max_length(50);
	recipe_name_entry.set_text("recipe name");
	recipe_name_entry.select_region(0, recipe_name_entry.get_text_length());
	box.pack_start(recipe_name_entry);
	counter++;
	}

	amount_label.set_text("Enter amount:");
	box.pack_start(amount_label);


	amount_entry.set_max_length(50);
	amount_entry.set_text("amount");
	amount_entry.select_region(0, amount_entry.get_text_length());
	box.pack_start(amount_entry);

	unit_label.set_text ("Enter unit:");
	box.pack_start (unit_label);

	unit_entry.set_max_length(50);
	unit_entry.set_text("unit");
	unit_entry.select_region(0, unit_entry.get_text_length());
	box.pack_start(unit_entry);

	ingredient_name_label.set_text ("Enter ingredient name");
	box.pack_start (ingredient_name_label);

	ingredient_name_entry.set_max_length(50);
	ingredient_name_entry.set_text("ingredient name");
	ingredient_name_entry.select_region(0, ingredient_name_entry.get_text_length());
	box.pack_start(ingredient_name_entry);

	box.pack_start(Add_button);
	box.pack_start(Done_button);
	box.pack_start(Cancel_button);
	show_all_children();
	Add_button.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Add_window::Add_clicked), "nationality" , meal_type_p));
	Done_button.signal_clicked().connect (sigc::mem_fun(*this, &Add_window::Done_clicked));
	Cancel_button.signal_clicked().connect(sigc::mem_fun(*this, &Add_window::Cancel_clicked));

}
void Add_window::Cancel_clicked()
{
	hide();
		Menuwindow w;
	Gtk::Main::run(w);
}


static string ingredients;
static int c = 0 ;


//Done function
void Add_window::Done_clicked()
{
   string amount_input = amount_entry.get_text();
    string unit_input = unit_entry.get_text();
    string ingredient_input = ingredient_name_entry.get_text();

	if(numI ==0)
{
	string recipe_name = recipe_name_entry.get_text();
	numI++;
	rep_name=recipe_name;
	 int goo=amount_input.length();
        char amm[goo];
        strcpy(amm,amount_input.c_str());
  double amount = atof(amm);
  	tempI.push_back(ingredient(amount,unit_input,ingredient_input));

}
   Recipe R (rep_name,tempI,numI);
cout<<meal_type<<endl;
   this->R =R;

   if(meal_type.compare("Breakfast")==0)
   {	N1.Nationality[hold_index].breakfast.push_back(R);
   	N1.Nationality[hold_index].Brep_num++;
   }
   else if(meal_type.compare("Lunch")==0)
   {
	   N1.Nationality[hold_index].lunch.push_back(R);
   	   N1.Nationality[hold_index].Lrep_num++;
   }
   else if(meal_type.compare("Dinner")==0)
   {
	   N1.Nationality[hold_index].dinner.push_back(R);
   	   N1.Nationality[hold_index].Drep_num++;

   }
   else if(meal_type.compare("Snack")==0)
   {
	   N1.Nationality[hold_index].snack.push_back(R);
   	   N1.Nationality[hold_index].Srep_num++;

   }else if(meal_type.compare("Dessert")==0)
   {
	   N1.Nationality[hold_index].dessert.push_back(R);
   	   N1.Nationality[hold_index].Erep_num++;
   }
    ingredients  += amount_input +" " + unit_input + " " + ingredient_input  +",";  // add the ingredient in the recipe
    cout << ingredients.substr(0 , ingredients.length() -1) << endl;
    hide ();
	    rep_name = "Recipe name: " + rep_name;
    Gtk::MessageDialog dialog(*this,rep_name,false,Gtk::MESSAGE_INFO);
    dialog.set_secondary_text(ingredients.substr(0 , ingredients.length() -1));
    dialog.run();
	rep_name = "";
    ingredients ="";
    counter = 0;
	 tempI.clear();
    Menuwindow m;
    m.get_writeFileFunction(N1);
    dialog.hide();
    Gtk::Main::run(m);




}

void Add_window::Add_clicked(Glib::ustring nationality_p, Glib::ustring meal_type_p)
{
  if(numI==0)
	  this-> rep_name = recipe_name_entry.get_text();
  string amount_input = amount_entry.get_text();
  string unit_input = unit_entry.get_text();
  string ingredient_input = ingredient_name_entry.get_text();
 int goo=amount_input.length();
	char amm[goo];
	strcpy(amm,amount_input.c_str());
  double amount = atof(amm);
  	tempI.push_back(ingredient(amount,unit_input,ingredient_input));

  ingredients  += amount_input +" " + unit_input + " " + ingredient_input  +","; // adding recipe ingredients
    cout << rep_name << endl;
 numI++;
  hide();
  Add_window a( N1,  hold_index, meal_type_p);
  Gtk::Main::run(a);

}


