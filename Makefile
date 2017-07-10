TARGET=thread_test
OBJS=main.o g.o
INCLUDES=
LIBS=-pthread
CXXFLAGS=-Wall

all: ${TARGET}

${TARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

${OBJS}: %.o: %.cpp
	${CXX} ${CXXFLAG} ${INCLUDES} -O2 -c $< -o $@
