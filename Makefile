COMPILER=clang++
FLAGS=-std=c++17
SOURCE=main.cpp gm1.cpp gm2.cpp

all:
	$(COMPILER) $(FLAGS) $(SOURCE) -o bandc.out

debug:
	$(COMPILER) $(FLAGS) -g $(SOURCE) -o d_bandc.out

release:
	$(COMPILER) $(FLAGS) -O3 $(SOURCE) -o r_bandc.out

gdb:
	g++ -std=c++17 -g $(SOURCE) -o d_bandc.out

clean:
	rm *.out
