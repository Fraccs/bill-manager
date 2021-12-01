output: main.o bill.o client.o command_interpreter.o date.o help.o logs.o
	g++ -o bill_manager main.o bill.o client.o command_interpreter.o date.o help.o logs.o

main.o: main.cpp
	g++ -c main.cpp

bill.o: Res/bill.h Res/bill.cpp
	g++ -c Res/bill.cpp

client.o: Res/client.h Res/client.cpp
	g++ -c Res/client.cpp

command_interpreter.o: Res/command_interpreter.h Res/command_interpreter.cpp
	g++ -c Res/command_interpreter.cpp

date.o: Res/date.h Res/date.cpp
	g++ -c Res/date.cpp

help.o: Res/help.h Res/help.cpp
	g++ -c Res/help.cpp

logs.o: Res/logs.h Res/logs.cpp
	g++ -c Res/logs.cpp

clean:
	rm *.o bill_manager