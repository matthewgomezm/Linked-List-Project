hw6: main.o linklist.o
	g++ -o hw6 -std=c++11 main.o linklist.o
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
linklist.o: linklist.cpp linklist.h
	g++ -c -std=c++11 linklist.cpp
	g++ -c -std=c++11 linklist.h
clear:
	rm *.o
	rm *.h.gch
	rm hw6
