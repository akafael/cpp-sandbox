##
# Makefile to compile all files
#
# @author akafael
##

# Variables -------------------------------------------------------------------

# Get Makefile dir as reference to help create absolute path
PROJ_ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# Define recursive wildcard
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Compiler definition
CC:= clang++
CC_FLAGS:= -Wall -std=c++17
FORMATER:= clang-format
FORMATER_FLAGS:= -style=file -i

# Get all source files
SRC := $(call rwildcard, ${PROJ_ROOT_DIR}/src,*.cpp)
BIN := $(patsubst %.cpp, %, ${SRC})

# Roles -----------------------------------------------------------------------   

# Build all source files
.PHONY: build
build: ${BIN}

# Format and Compile everything
%: %.cpp
	${FORMATER} ${FORMATER_FLAGS} $< &&\
	${CC} ${CC_FLAGS} $< -o $@


# Format all source files
.PHONY: format
format:
	${FORMATER} ${FORMATER_FLAGS} ${SRC}

# Remove generated files
.PHONY: clean
clean:
	@rm -fv ${BIN}
