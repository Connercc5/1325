CXXFLAGS += -std=c++11
GTKFLAGS=`/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex:pro_main.o pro.o
	$(CXX) $(CXXFLAGS) -o pro pro_main.o pro.o $(GTKFLAGS)
pro_main.o: pro_main.cpp pro.h
	$(CXX) $(CXXFLAGS) -c pro_main.cpp $(GTKFLAGS)
pro.o: pro.h pro.cpp
	$(CXX) $(CXXFLAGS) -c pro.cpp $(GTKFLAGS)                                                      
