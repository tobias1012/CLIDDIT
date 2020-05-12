#Compiler and flags
CXX = g++
CXX_FLAGS = -Wall -Wextra -Werror -Wfatal-errors -Wpedantic -Wno-unused-parameter -std=c++17

ifeq ($(MAKECMDGOALS), debug)
	CXX_FLAGS += -g
else
	CXX_FLAGS += -O3
endif

MKDIR_P = mkdir -p

LIBS = -lcurl -lncurses

#binary name
executable ?= cliddit.out

build_dir = ./build
src_dir = ./src
include_dir = ./include
parser_dir = ./parser

.PHONY: debug clean

all: dirs parse.yy.hpp lex.yy.cpp $(build_dir)/$(executable) 

#complie flex and bison
lex.yy.cpp: $(parser_dir)/*.l 
	flex -o $(src_dir)/$@ $^ 

parse.yy.hpp: $(parser_dir)/*.y
	bison -o $(include_dir)/$@ $^

$(build_dir)/$(executable): $(src_dir)/*.cpp
	@echo "Building src..."
	$(CXX) $(CXX_FLAGS) -I$(include_dir) $^ -o $@ $(LIBS)

dirs:
	$(MKDIR_P) $(build_dir)

debug: clean all


clean:
	-rm -rf $(build_dir)
	-rm $(include_dir)/parse.yy.hpp
	-rm $(src_dir)/lex.yy.cpp 