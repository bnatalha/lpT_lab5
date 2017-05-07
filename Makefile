##by @bnatalha.

CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0

#For debugging
#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g

INC =-I include

.PHONY: all init val clean docs

#Creates everything that is needed in order to compile, compiles and then deletes the .o files
all: init bin/Programa_1 clean

#Creates the 'bin' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p bin

#Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
#Generates .html documentation via doxygen at the folder 'docs'
docs: Doxyfile
	mkdir -p docs ;\
	doxygen	

#Runs valgrind with 'bin/Programa_1'
val1:
	valgrind --leak-check=yes bin/Programa_1

#Generates executable files
bin/Programa_1: bin/main_1.o bin/funcionario.o bin/empresa.o
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

#Removes objects
clean:
	$(RM) bin/*.o