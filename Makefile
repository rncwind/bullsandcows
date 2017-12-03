COMPILER=clang++
FLAGS=-std=c++17
SOURCE=main.cpp gm1.cpp

all:
	$(COMPILER) $(FLAGS) $(SOURCE) -o bandc.out

debug:
	$(COMPILER) $(FLAGS) -g $(SOURCE) -o d_bandc.out

clean:
	rm *.out
