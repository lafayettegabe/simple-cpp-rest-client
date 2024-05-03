#!/bin/bash

g++ -o app main.cpp api/api.cpp datetime/datetime.cpp -lcpprest -lboost_system -lssl -lcrypto

if [ $? -eq 0 ]; then
	echo "Compilation successful. Running the program..."
	./app
else
	echo "Compilation failed."
fi
