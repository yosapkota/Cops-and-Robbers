project: main.o fraction.o point.o
	g++ -o project main.o fraction.o point.o
	
main.o: main.cc fraction.h point.h
	g++ -c main.cc

fraction.o: fraction.cc fraction.h point.h
	g++ -c fraction.cc
	
point.o: point.cc fraction.h point.h
	g++ -c point.cc
