DIRS =
DIRS += xml
DIRS += utility
DIRS += include
DIRS += src
DIRS += src/docs

PREFIX ?= $(CURDIR)

BINDIR  = $(DPM_INSTALL_DIR)/bin
SBINDIR = $(DPM_INSTALL_DIR)/sbin
LIBDIR  = $(DPM_INSTALL_DIR)/lib
ETCDIR  = $(DPM_INSTALL_DIR)/etc

export PREFIX
export BINDIR
export SBINDIR
export LIBDIR
export ETCDIR

TARGETS_ALL       = $(addsuffix .all,$(DIRS))
TARGETS_CLEAN     = $(addsuffix .clean,$(DIRS))
TARGETS_DISTCLEAN = $(addsuffix .distclean,$(DIRS))
TARGETS_INSTALL	  = $(addsuffix .install,$(DIRS))


TARGETS  = $(TARGETS_ALL)
TARGETS += $(TARGETS_CLEAN)
TARGETS += $(TARGETS_DISTCLEAN)

.PHONY: default all clean install distclean test $(TARGETS)


# Add check to this list when cppcheck is cleared up
all: $(TARGETS_ALL)

default: all

db:
	bear -- make -j$(nproc) all

test: all
	$(MAKE) --directory test test

install:
	$(MAKE) --directory utility install
	$(MAKE) --directory src install
	$(MAKE) --directory xml install

# Build prerequisites between major trees.
src.all: xml.all utility.all include.all
docs.all: src.all

clean: $(TARGETS_CLEAN)
	$(RM) -rf $(CURDIR)/lib
	$(RM) -rf $(CURDIR)/bin
	$(RM) -rf $(CURDIR)/sbin
	$(RM) -rf $(CURDIR)/etc

distclean: $(TARGETS_DISTCLEAN)

$(TARGETS):
	$(MAKE) --directory $(basename $@) $(subst .,,$(suffix $@))

check:
	NO_COLOR=1 cppcheck --project=compile_commands.json -isrc/master/protocol -itest/catch2 --enable=warning,style,performance,portability --inline-suppr --inconclusive --force --error-exitcode=1
