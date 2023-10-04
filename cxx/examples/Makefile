.PHONY: all clean

BINDIR:=./bin

SRC=$(wildcard *.cpp)
EXE=$(SRC:%.cpp=${BINDIR}/%.exe)

all: clean $(EXE)
	@echo $(SRC)
	@echo $(EXE)

${BINDIR}/%.exe: %.cpp
	g++ -std=c++2b -o $@ $<

clean:
	#rm -rf ${BINDIR}
	mkdir -p ${BINDIR}
