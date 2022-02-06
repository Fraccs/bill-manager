CC=g++ -std=c++17 
OBJ=main.o bill.o client.o command_interpreter.o date.o help.o logs.o

output: $(OBJ)
	$(CC) -o bill_manager $(OBJ)

main.o: main.cpp
	$(CC) -c main.cpp

bill.o: src/bill.h src/bill.cpp
	$(CC) -c src/bill.cpp

client.o: src/client.h src/client.cpp
	$(CC) -c src/client.cpp

command_interpreter.o: src/command_interpreter.h src/command_interpreter.cpp
	$(CC) -c src/command_interpreter.cpp

date.o: src/date.h src/date.cpp
	$(CC) -c src/date.cpp

help.o: src/help.h src/help.cpp
	$(CC) -c src/help.cpp

logs.o: src/logs.h src/logs.cpp
	$(CC) -c src/logs.cpp

clean:
	rm *.o bill_manager