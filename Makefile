output: main.o bill.o client.o command_interpreter.o date.o help.o logs.o
	g++ -o bill_manager

main.o: main.cpp
	g++ -c main.cpp

bill.o: bill.h bill.cpp
	g++ -c bill.cpp

client.o: client.h client.cpp
	g++ -c client.cpp

command_interpreter.o: command_interpreter.h command_interpreter.cpp
	g++ -c command_interpreter.cpp

date.o: date.h date.cpp
	g++ -c date.cpp

help.o: help.h help.cpp
	g++ -c help.cpp

logs.o: logs.h logs.cpp
	g++ -c logs.cpp

clean:
	rm *.o bill_manager