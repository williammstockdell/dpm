LIBDIR := $(PREFIX)/lib

CXXSOCKETS := $(PREFIX)/utility/src/cxxsockets/libcxxsockets.a

ROOT := ..

CXX := g++-14

CXXFLAGS := \
    -std=c++20 \
    -g \
    -Wall \
    -Wextra \
    -Wconversion \
    -Werror \
    -pthread \
    -I$(ROOT) \
    -I$(ROOT)/utility/include \
    -I$(ROOT)/src/master \
    -I$(ROOT)/src \
    -Icatch2

CATCH_OBJ := catch2/catch_amalgamated.o

IDS_OBJ := $(ROOT)/src/master/common/Ids.o

BGUTILITY := $(ROOT)/utility/src/libbgutility.so


IdsTest: IdsTest.o TestLogging.o $(CATCH_OBJ) $(IDS_OBJ) $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		IdsTest.o \
		TestLogging.o \
		$(CATCH_OBJ) \
		$(IDS_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-llog4cxx \
		-lcrypto \
		-lssl \
		-pthread

ABS_OBJ := $(ROOT)/src/master/common/AgentBase.o
ABS_OBJ += $(ROOT)/src/master/common/BinaryController.o

AgentBaseTest: AgentBaseTests.o TestLogging.o $(CATCH_OBJ) $(ABS_OBJ)  $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		AgentBaseTests.o \
		TestLogging.o \
		$(CATCH_OBJ) \
		$(ABS_OBJ) \
		$(IDS_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-llog4cxx \
		-lcrypto \
		-lssl    \
		-pthread


HostTest: HostTest.o TestLogging.o $(CATCH_OBJ)  $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		HostTest.o \
		TestLogging.o \
		$(CATCH_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-llog4cxx \
		-lcrypto \
		-lssl    \
		-pthread

NoDelayTest: NoDelayTest.o TestLogging.o $(CATCH_OBJ)  $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		NoDelayTest.o \
		TestLogging.o \
		$(CATCH_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-lcrypto \
		-lssl    \
		-llog4cxx

UserErrorExceptionTest: UserErrorExceptionTest.o TestLogging.o $(CATCH_OBJ)  $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		UserErrorExceptionTest.o \
		TestLogging.o \
		$(CATCH_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-lcrypto \
		-lssl    \
		-llog4cxx

test: IdsTest AgentBaseTest HostTest NoDelayTest UserErrorExceptionTest

clean:
	$(RM) *.o *~
