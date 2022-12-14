# This is a simple Makefile, it adds more macros to example2.mak
#
# Use it by running:
#     cs70-make
# or
#     make
#
# (or specify any other target from the the file)

TARGETS  = example

CXX      = clang++
CXXFLAGS = -gdwarf-4 -Wall -Wextra -pedantic -std=c++17
CPPFLAGS =                  # Used for -D, -isystem and -I preprocessor options
LDFLAGS  = -ltestinglogger  # Used for -l  linking options

# Note: The rules below use useful-but-cryptic make "Automatic variables"
#       to avoid duplicating information in multiple places, the most useful
#       of which are:
#
#   $@  The file name of the target of the rule  (e.g., cs70-make below)
#   $^  The names of all the prerequisites, with spaces between them.
#   $<  The name of the first prerequisite
#
# For GNU make, you'll find that it supports quite an extensive list, at
#   http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# for cs70-make, $@, $<, $?, $* and $^ are supported.

all: $(TARGETS)

example: example.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGETS)

# Specify a special kind of rule, a default rule for turning .cpp -> .o, 
# which is used by all subsequent rules
.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

example.o: example.cpp
