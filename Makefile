CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 

interpret: main.o compiler.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm *.o


