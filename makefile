compilar : src/main.cpp
	g++ src/main.cpp -Iinclude -o programa

ejecutar: bin/programa
	./bin/programa