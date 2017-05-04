##by @bnatalha.

CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0

#For debugging
#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g

INC =-I include

.PHONY: all init val clean

#Creates everything that is needed in order to compile, compiles and then deletes the .o files
all: init bin/main clean

#Creates the 'bin' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p bin;\

#Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
#Generates .html documentation via doxygen at the folder 'docs'
doc: Doxyfile
	mkdir -p docs ;\
	doxygen	

#Runs valgrind with 'bin/main'
val:
	valgrind --leak-check=yes bin/main

#Generates executable files
bin/main: bin/main.o
	g++ $^ -o $@

#Generates objects
bin/main.o: src/main.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

#Removes objects
clean:
	$(RM) bin/*.o