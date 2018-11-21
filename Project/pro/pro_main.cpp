#include"pro.h"
#include"recipe.h"
#include"ingredient.h"
#include"days.h"
#include"nationalities.h"
#include"file.h"
#include"mealplan.h"
#include<gtkmm/application.h>
#include<iostream>

int main(int argc, char *argv[])
{

        Gtk::Main app(argc,argv);
        Menuwindow w;
        Gtk::Main::run(w);
        return 0;

}

