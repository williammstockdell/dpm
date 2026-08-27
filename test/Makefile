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

all: IdsTest

clean:
	$(RM) *.o *~
