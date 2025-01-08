.PHONY: all clean

BINDIR:=./bin

SRC=$(wildcard *.cpp)
EXE=$(SRC:%.cpp=${BINDIR}/%.exe)

all: clean $(EXE)
	@echo $(SRC)
	@echo $(EXE)

${BINDIR}/%.exe: %.cpp
	gcc-14 --std=c++23 -o $@ $< -lstdc++ -lm

clean:
	rm -rf ${BINDIR}
	mkdir -p ${BINDIR}
