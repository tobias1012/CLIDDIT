#Compiler and flags
CXX = g++
CXX_FLAGS = -Wall -Wextra -Werror -Wfatal-errors -Wpedantic -Wno-unused-parameter -std=c++17

ifeq ($(MAKECMDGOALS), debug)
	CXX_FLAGS += -g
else
	CXX_FLAGS += -O3
endif

MKDIR_P = mkdir -p

LIBS = -lsfml-system -lsfml-network -lncurses

#binary name
executable ?= cliddit.out

build_dir = ./build
src_dir = ./src
include_dir = ./include

.PHONY: debug clean

all: dirs $(build_dir)/$(executable) 

$(build_dir)/$(executable): $(src_dir)/*.cpp
	@echo "Building src..."
	$(CXX) $(CXX_FLAGS) -I$(include_dir) $^ -o $@ $(LIBS)

dirs:
	$(MKDIR_P) $(build_dir)

debug: clean all


clean:
	-rm -rf $(build_dir)
