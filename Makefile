CC=g++ -std=c++17 
OBJ=main.o bill.o client.o command_interpreter.o date.o echo.o help.o logs.o

output: $(OBJ)
	$(CC) -o bill_manager $(OBJ)

main.o: main.cpp
	$(CC) -c main.cpp

bill.o: src/bill.hpp src/bill.cpp
	$(CC) -c src/bill.cpp

client.o: src/client.hpp src/client.cpp
	$(CC) -c src/client.cpp

command_interpreter.o: src/command_interpreter.hpp src/command_interpreter.cpp
	$(CC) -c src/command_interpreter.cpp

date.o: src/date.hpp src/date.cpp
	$(CC) -c src/date.cpp

echo.o: src/echo.hpp src/echo.cpp
	$(CC) -c src/echo.cpp

help.o: src/help.hpp src/help.cpp
	$(CC) -c src/help.cpp

logs.o: src/logs.hpp src/logs.cpp
	$(CC) -c src/logs.cpp

clean:
	rm *.o bill_manager