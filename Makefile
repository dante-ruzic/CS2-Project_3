#============================================================================
# Assembler and Stack
#
# CS II Kent State University
# J. Maletic Spring 2025
#
#
#  Makefile works for string.cpp in either local (.) or ../string/
#
###############################################################
# Variables
CPP          = g++
CPP_FLAGS    = -g -Werror -W -Wunused -Wuninitialized -Wshadow -std=c++17


#===========================================================================
# Your STACK tests here.
STACK_TESTS =  test_ctor_default test_equal test_push_pop test_ctor_copy test_swap test_assign


#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   tests     - Compile and run tests for stack (Milestone 1)'
	@echo '   postfix   - Compile and run postfix tests   (Milestone 2)  '
	@echo '   assembler - Compile and run assembler code  (Milestone 3)'
	@echo '   string    - Compile string'
	@echo '   clean     - Removes all .o and executables'

#===========================================================================
# Compile string.o from Project 2.

string.o:	string.hpp  string.cpp
	${CPP} ${CPP_FLAGS} -c string.cpp

string:	string.hpp  string.cpp
	${CPP} ${CPP_FLAGS} -c string.cpp


#===========================================================================
# No compile for stack - it is a template.


#===========================================================================
# Compile test programs for stack
test_%: string.o test_%.o 
	${CPP} ${CPP_FLAGS} string.o test_$*.o -o test_$* 

test_%.o: string.hpp string.cpp stack.hpp test_%.cpp
	${CPP} ${CPP_FLAGS} -c test_$*.cpp


#===========================================================================
# Run test programs
# INSERT your tests for the stack here.
tests: stack.hpp string.hpp string.cpp ${STACK_TESTS}
	./test_ctor_default
	./test_push_pop
	./test_equal
	./test_swap
#	./test_assign
#	./test_ctor_copy
#   ./test_dtor



#===========================================================================
# Compile postfix

utilities.o: utilities.cpp utilities.hpp string.cpp string.hpp stack.hpp
	${CPP} ${CPP_FLAGS} -c utilities.cpp 

postfix.o: postfix.cpp string.hpp string.cpp stack.hpp utilities.hpp
	${CPP} ${CPP_FLAGS} -c postfix.cpp 

postfix: postfix.o string.o utilities.o
	${CPP} ${CPP_FLAGS} postfix.o string.o utilities.o -o postfix

#===========================================================================
# Compile assembler

assembler.o: assembler.cpp string.hpp string.cpp stack.hpp utilities.hpp
	${CPP} ${CPP_FLAGS} -c assembler.cpp 

assembler: assembler.o string.o utilities.o
	${CPP} ${CPP_FLAGS} string.o assembler.o  utilities.o -o assembler



#============================================================================
clean:
	rm -f *.o
	rm -f postfix 
	rm -f assembler
	rm -f $(STACK_TESTS)

