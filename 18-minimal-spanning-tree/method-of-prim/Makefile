CXX = g++
LIB = -std=c++11

main : weighted-graph main.cpp
	$(CXX) $(LIB) main.cpp

weighted-graph : gewogengraaf weighted-graph.h
	$(CXX) $(LIB) weighted-graph.h

gewogengraaf : graaf gewogengraaf.h
	$(CXX) $(LIB) gewogengraaf.h

graaf : graaf.h
	$(CXX) $(LIB) graaf.h

clean :
	rm -f *.gch
