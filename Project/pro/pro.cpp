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

/*
void Menuwindow::File_read(File N1)
{
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

		//Get the modified amount of meals for Breakfest-Dessert

		j = 0;
		//Breakfest
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
string Menuwindow::void get_blank(char*token)
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

*/




//END:FUNCTIONS THAT INTERACT WITH TEXTFILE 












Menuwindow::Menuwindow():box(Gtk::ORIENTATION_VERTICAL)
,case1("Modify Recipes"),case2("Create Meal Plan Shopping List",2),case3("Choose Old Shopping list"),case4("Exit",3)
{
    set_size_request(400,200);
    set_title("Preppy Meal");
    add(box);
    Gtk::Label label=Gtk::Label();
    label.set_text("Pick a option");
    label.set_padding(10,10);
    box.pack_start(label);
    box.pack_start(case1);
    box.pack_start(case2);
    box.pack_start(case3);
    box.pack_start(case4);
    show_all_children();


    case1.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case1_clicked));
    case4.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case4_clicked));


}
Menuwindow::~Menuwindow()
{
}


void Menuwindow::case1_clicked() {
    hide ();
    Modify_window w;
    Gtk::Main::run(w);
}
void Menuwindow::case4_clicked() {
    Gtk::Main::quit();
}

Modify_window::Modify_window():box(Gtk::ORIENTATION_VERTICAL), nationality_button("Enter") ,back_button("Back to main menu"){
    set_size_request(400,200);
    set_title("Modify a recipe");
    add(box);

    nationality_label.set_text ("Enter a nationality: ");
    box.pack_start (nationality_label);

    nationality_entry.set_max_length (50);
    nationality_entry.set_text("Enter nationality");
    nationality_entry.select_region(0, nationality_entry.get_text_length());
    box.pack_start(nationality_entry);



    nationality_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify_window::Nationality));
    box.pack_start(nationality_button);
    back_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify_window::back_button_clicked));
    box.pack_start(back_button);

     show_all_children();

}


void Modify_window::Nationality() {}
Modify_window::~Modify_window(){}
void Modify_window::back_button_clicked(){
hide ();
Menuwindow w;
Gtk::Main::run(w);
}
