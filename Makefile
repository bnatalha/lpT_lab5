##by @bnatalha.

#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0

#For debugging
CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g

INC =-I include

.PHONY: all init val clean test vai

#Creates everything that is needed in order to compile, compiles and then deletes the .o files
all: init bin/Programa_1 bin/Programa_2 clean

#Creates the 'bin' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p bin

#Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
#Generates .html documentation via doxygen at the folder 'docs'
doc: Doxyfile
	mkdir -p docs ;\
	doxygen	

#Runs valgrind with 'bin/main'
val1:
	valgrind --leak-check=yes bin/Programa_1

val2:
	valgrind --leak-check=yes bin/Programa_2

#Generates executable files
bin/Programa_1: bin/main_1.o bin/funcionario.o bin/empresa.o
	g++ $^ -o $@

bin/Programa_2: bin/main_2.o
	g++ $^ -o $@

#Generates objects
#
#For Programa_1:
bin/main_1.o: src/Programa_1/main.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_1 -c -o $@

bin/funcionario.o: src/Programa_1/funcionario.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_1 -c -o $@

bin/empresa.o: src/Programa_1/empresa.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_1 -c -o $@

#For Programa_2:
bin/main_2.o: src/Programa_2/main.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_1 -c -o $@

#Removes objects
clean:
	$(RM) bin/*.o

## test
test: test/main

vai:
	test/main

test/main: test/main.o
	g++ $^ -o $@

test/main.o: test/main.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@