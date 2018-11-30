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

//BASED ON CODE PUSHED ON GITHUB CURRENTLY THESE ARE THE THINGS THAT NEED TO BE DONE
//THINGS THAT HAVE NOT BEEN  CODED YET

//THE MODIFY RECIPE OPTION
//THE CREATE RANDOM SHOPPING LIST OPTION	(FOR THIS JUMP TO LINE 814 IN CODE)
//LOOK AT OLD SHOPPING LIST OPTION		(FOR THIS JUMP TO LINE 774 IN CODE)









//ALL STATIC MEMBERS FROM .H FILE
File Menuwindow::N1;
int Modify2_window::y = 0;
vector <Recipe> Modify2_window::Chosen_recipes;

//START:FUNCTIONS THAT ARE USED TO INTERACT WITH ALLFILE.TXT
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





//IF YOUR TRYING TO UNDERSTAND WHAT I DID FOR THE CREATE MEALPLAN SHOPPING LIST OPTION, BEFORE YOU LOOK AT THIS GO START TO THE MENUWINDOW CASE2_CLICKED FUNCTION

//MODIFY2_WINDOW CONSTRUCTOR,DECONSTRUCTOR AND FUNCTIONS

//ASK USER TO CHOOSE NATIONALITY
Modify2_window::Modify2_window(File N1, int day, int time) :box(Gtk::ORIENTATION_VERTICAL),cancel("Cancel"), brea("Breakfast"), lunc("Lunch"),dinn("Dinner"),snac("Snack"),dess("Dessert") {
	set_size_request(400, 200);
	set_title("Create Shopping List");
	add(box);
	this->day = day;
	this->time = time;
	this->N1 =N1;
	this->error=0;

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
	label.set_text(m.daysList[day].name);
	//labels.set_text(input);

	nationality_entry.set_max_length(50);
	//nationality_entry.set_text("Enter nationality");
	nationality_entry.set_text("Mexican");//just using this to test program
	nationality_entry.select_region(0, nationality_entry.get_text_length());
	box.pack_start(nationality_entry);
	time_label.set_text(tim[time]+" Recipe");



	box.pack_start(label);

	box.pack_start(time_label);
	box.pack_start(brea);
	box.pack_start(lunc);
	box.pack_start(dinn);
	box.pack_start(snac);
	box.pack_start(dess);
	box.pack_start(cancel);
	box.pack_start(cancel);

	 brea.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Breakfast"));
	 lunc.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Lunch"));
	 dinn.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Dinner"));
	 snac.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Snack"));
	 dess.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Dessert"));
	 cancel.signal_clicked().connect(sigc::mem_fun(*this, &Modify2_window::cancel_clicked));
	//box.pack_start(back_button);

	show_all_children();

}

Modify2_window::~Modify2_window() { hide(); }
void Modify2_window::enter_clicked(string type)
{
	if (entry_ans.compare("DONE") != 0)
	{
		//Mealplan m; //SETTING UP WINDOW FOR MANUAL OPTION
		this->	entry_ans=nationality_entry.get_text();
		//string input = nationality_entry.get_text();
		hide();
		Send2_ER(m,type);//this function will go to the EnterRecipe Window
		//if((day==6)&&(time==4))//THIS IS FOR GETTING THE LABELS FOR THE FINAL SHOPPING LIST WINDOW
		if((day==0)&&(time==4))//this is here because i am testing code
                {
                        //this->Chosen_recipe=
			ShoppingList s (Chosen_recipes);
                        cout<<s.Rep_names<<" "<<s.List<<endl;
                        cout<<"SIZE OF VECTOR:"<<Chosen_recipes.size()<<endl;
			List_window f (s.Rep_names,s.List);
			Gtk::Main::run(f);

                }

	}
}
void Modify2_window::cancel_clicked()
{
	hide();
	entry_ans = "DONE";
}

void Modify2_window::Send2_ER(Mealplan m, string meal_type)
{
        //hide();
        int y = 0;
        int h = 0;
        EnterRecipe_window e(m, N1, entry_ans, meal_type);
        Gtk::Main::run(e);
        string rep_name = e.recipe;//rep_name now holds the input from the entry in EnterRecipe window
	string entryR,FileR;//use this for case error
	bool found=false;
        entryR=rep_name;
	transform(entryR.begin(),entryR.end(),entryR.begin(),::toupper);
	if(e.cancel_==true)//they click cancel in ER(EnterRecipe window)
	{
		error=1;
		return;
	}

        if (meal_type.compare("Breakfast") == 0)//if user clicked breakfast
                while (h < N1.Nationality[e.hold_index].breakfast.size())
                {

                        FileR=N1.Nationality[e.hold_index].breakfast[h].recipe_name;
			transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);//make text upper case so user can enter recipe name in any case
			if (FileR.compare(entryR) == 0)
			{
			     	this->temp_hold = N1.Nationality[e.hold_index].breakfast[h];
				found=true;
			}
			h++;
                }
        else if (meal_type.compare("Lunch") == 0)
                while (h < N1.Nationality[e.hold_index].lunch.size())
                {
                        FileR=N1.Nationality[e.hold_index].lunch[h].recipe_name;
                    	transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
			if (FileR.compare(entryR) == 0)
			{
				this->temp_hold = N1.Nationality[e.hold_index].lunch[h];
				found=true;

			}
			h++;
                }
        else if (meal_type.compare("Dinner") == 0)
                while (h < N1.Nationality[e.hold_index].dinner.size())
                {
                        FileR=N1.Nationality[e.hold_index].dinner[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
			if (FileR.compare(entryR) == 0)
			{
		     		this->temp_hold = N1.Nationality[e.hold_index].dinner[h];
				found=true;

			}
			h++;
                }
        else if (meal_type.compare("Snack") == 0)
        {
                while (h < N1.Nationality[e.hold_index].snack.size())
                {
                        FileR=N1.Nationality[e.hold_index].snack[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
			if (FileR.compare(entryR) == 0)
			{
				this->temp_hold = N1.Nationality[e.hold_index].snack[h];
				found=true;

			}
			h++;
                }
        }
        else if (meal_type.compare("Dessert") == 0)
        {
                while (h < N1.Nationality[e.hold_index].dessert.size())
                {

		        FileR=N1.Nationality[e.hold_index].dessert[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
			if (FileR.compare(entryR) == 0)
			{
				this->temp_hold = N1.Nationality[e.hold_index].dessert[h];
				found=true;

			}
			h++;
                }
        }
        if(found==false)
	{
		warning();
		return;
	}
        // there is a bug here it is only add on 1 recipe
        Chosen_recipes.push_back(temp_hold);
        }


void Modify2_window:: warning()
{
	Gtk::MessageDialog dialog(*this,"Not Found",false,Gtk::MESSAGE_INFO);
        dialog.set_secondary_text("Recipe was not found");
	dialog.run();
	error=1;

}






//ENTERRECIPE_WINDOW CONSTRUCTOR DECONSTRUCTOR AND FUNCTIONS

EnterRecipe_window::~EnterRecipe_window()
{
	hide();
}

EnterRecipe_window::EnterRecipe_window(Mealplan m, File N1, string NationalityName, string meal_type) :box(Gtk::ORIENTATION_VERTICAL), enter("Enter"), cancel("Cancel", 3)
{
	this->cancel_=false;
	set_size_request(300, 300);
	int e = 0;
	string Nation;
	transform(NationalityName.begin(),NationalityName.end(),NationalityName.begin(),::toupper);
	while (e < N1.Nationality.size())
	{
		Nation=N1.Nationality[e].nationality;
	      	transform(Nation.begin(),Nation.end(),Nation.begin(),::toupper);

		if(Nation.compare(NationalityName) == 0)
		{
			hold_index = e;
		}
		e++;
	}
	e = 0;
	string recipe_names = " ";


//this will display the recipes in catagory that the user clicked
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
	add(box);


	recipe_name_label.set_text(recipe_names);
	entry.set_text("Flan");//this is just here so i can test the code
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
	this->	cancel_=true;

}

//List_window Constructor Deconstructor and Functions
List_window::~List_window(){hide();}
List_window::List_window(string Rep_names,string List):box(Gtk::ORIENTATION_VERTICAL),ok("Ok")
{

	Gtk::Entry entry=Gtk::Entry();
	Gtk::Label lab= Gtk::Label();
	entry.set_text("Ex: file.txt or List.txt... etc");
	lab.set_text("Enter a file name:");
	Gtk::MessageDialog dialog(*this,"Save List",false,Gtk::MESSAGE_INFO);
	dialog.set_secondary_text("What name would you like to save this list under?");
	dialog.get_content_area()->pack_start(lab);
        dialog.get_content_area()->pack_start(entry);
        dialog.set_size_request(400,200);
        entry.show();
        lab.show();
        dialog.run();
        string s= entry.get_text();
	//write the recipe names and list of ingredients to a file.
    string path = "./savedList/"+s;
    ofstream outfile (path);
    outfile <<Rep_names<<"\n"<<List<<endl;
    outfile.close();
	set_size_request(400,400);
	Rep_name_label.set_text(Rep_names);
	List_label.set_text(List);
	add(box);
	box.pack_start(Rep_name_label);
	box.pack_start(List_label);
	box.pack_start(ok);
	ok.signal_clicked().connect(sigc::mem_fun(*this, &List_window::ok_clicked));
	show_all_children();

}
void List_window::ok_clicked()
{
	hide();
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


	//this is the visit old shopping list option
	//case3.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case3_clicked));
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
		//Random option






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
		//while (day < 7)//ASK SEVEN DAYS A WEEK
		while (day < 1)//this is here because i am testing code
		{
			time = 0;
			while (time < 5)//ASK FOR EACH MEAL BREAKFAST-DESSERT
			{

				Modify2_window w(N1, day, time);//CHECK OUT MODIFY2_WINDOW CONSTRUCTOR
				Gtk::Main::run(w);
				time -=w.error;//user entered and invalid recipe so add back time so they can still select recipe for that time of day
				if(w.error ==1)
					cout<<"ERROR"<<endl;
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


void Menuwindow::case4_clicked() {
	Gtk::Main::quit();
}
//
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
