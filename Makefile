CC=g++ -std=c++17 
OBJ=main.o bill.o client.o command_interpreter.o date.o help.o logs.o

output: $(OBJ)
	$(CC) -o bill_manager $(OBJ)

main.o: main.cpp
	$(CC) -c main.cpp

bill.o: Res/bill.h Res/bill.cpp
	$(CC) -c Res/bill.cpp

client.o: Res/client.h Res/client.cpp
	$(CC) -c Res/client.cpp

command_interpreter.o: Res/command_interpreter.h Res/command_interpreter.cpp
	$(CC) -c Res/command_interpreter.cpp

date.o: Res/date.h Res/date.cpp
	$(CC) -c Res/date.cpp

help.o: Res/help.h Res/help.cpp
	$(CC) -c Res/help.cpp

logs.o: Res/logs.h Res/logs.cpp
	$(CC) -c Res/logs.cpp

clean:
	rm *.o bill_manager