CXXFLAGS += -std=c++11
GTKFLAGS=`/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex:pro_main.o pro.o file.o recipe.o ingredient.o nationalities.o days.o mealplan.o listW.o enterrecipeW.o modify2W.o
	$(CXX) $(CXXFLAGS) -o pro pro_main.o pro.o recipe.o ingredient.o nationalities.o days.o mealplan.o file.o listW.o enterrecipeW.o modify2W.o $(GTKFLAGS)
pro_main.o: pro_main.cpp pro.h
	$(CXX) $(CXXFLAGS) -c pro_main.cpp $(GTKFLAGS)
pro.o: pro.h pro.cpp
	$(CXX) $(CXXFLAGS) -c pro.cpp $(GTKFLAGS) 
file.o: file.h file.cpp	
	$(CXX) $(CXXFLAGS) -c file.cpp $(GTKFLAGS)
recipe.o: recipe.h recipe.cpp
	$(CXX) $(CXXFLAGS) -c recipe.cpp $(GTKFLAGS)
intgredient.o: ingredient.h ingredient.cpp
	$(CXX) $(CXXFLAGS) -c ingredient.cpp $(GTKFLAGS)
nationlities.o:nationalities.h nationalities.cpp
	$(CXX) $(CXXFLAGS) -c nationalities.cpp $(GTKFLAGS)
days.o: days.h days.cpp
	$(CXX) $(CXXFLAGS) -c days.cpp $(GTKFLAGS)
mealplan.o: mealplan.h mealplan.cpp
	$(CXX) $(CXXFLAGS) -c mealplan.cpp $(GTKFLAGS)
listW.o: listW.h listW.cpp
	$(CXX) $(CXXFLAGS) -c listW.cpp $(GTKFLAGS)
enterrecipeW.o: enterrecipeW.h enterrecipeW.cpp
	$(CXX) $(CXXFLAGS) -c enterrecipeW.cpp $(GTKFLAGS)
modify2W.o: modify2W.h modify2W.cpp
	$(CXX) $(CXXFLAGS) -c modify2W.cpp $(GTKFLAGS)
