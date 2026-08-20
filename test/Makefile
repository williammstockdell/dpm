LIBDIR := $(PREFIX)/lib

CXXSOCKETS := $(PREFIX)/utility/src/cxxsockets/libcxxsockets.a
BGUTILITY  := $(LIBDIR)/libbgutility.so

COMMON_TEST_OBJS := \
    CommonTest.o \
    ../src/master/common/BinaryController.o

common_tests: $(PORT_TEST_OBJS) $(CATCH_OBJ) $(CXXSOCKETS) $(BGUTILITY)
	$(CXX) -o $@ \
	    $(PORT_TEST_OBJS) \
	    $(CATCH_OBJ) \
	    $(CXXSOCKETS) \
	    -L$(LIBDIR) -lbgutility \
	    $(LDFLAGS)
