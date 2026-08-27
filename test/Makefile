LIBDIR := $(PREFIX)/lib

CXXSOCKETS := $(PREFIX)/utility/src/cxxsockets/libcxxsockets.a

# BGUTILITY  := $(LIBDIR)/libbgutility.so

# COMMON_TEST_OBJS := \
#     CommonTest.o \
#     ../src/master/common/BinaryController.o

# common_tests: $(PORT_TEST_OBJS) $(CATCH_OBJ) $(CXXSOCKETS) $(BGUTILITY)
# 	$(CXX) -o $@ \
# 	    $(PORT_TEST_OBJS) \
# 	    $(CATCH_OBJ) \
# #	    $(CXXSOCKETS) \
# 	    -L$(LIBDIR) -lbgutility \
# 	    $(LDFLAGS)
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

IdsTest: IdsTest.o $(CATCH_OBJ) $(IDS_OBJ) $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		IdsTest.o \
		$(CATCH_OBJ) \
		$(IDS_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-llog4cxx \
		-lcrypto \
		-pthread

ABS_OBJ := $(ROOT)/src/master/common/AgentBase.o
ABS_OBJ += $(ROOT)/src/master/common/BinaryController.o

AgentBaseTest: AgentBaseTests.o $(CATCH_OBJ) $(ABS_OBJ)  $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
		AgentBaseTests.o \
		$(CATCH_OBJ) \
		$(ABS_OBJ) \
		$(IDS_OBJ) \
		$(CXXSOCKETS) \
		$(BGUTILITY) \
		-llog4cxx \
		-lcrypto \
		-pthread

test: IdsTest AgentBaseTest

clean:
	$(RM) *.o *~
