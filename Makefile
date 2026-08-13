DIRS =
DIRS += xml
DIRS += utility
DIRS += include
DIRS += src
DIRS += src/docs

PREFIX ?= $(CURDIR)

BINDIR  = $(PREFIX)/bin
SBINDIR = $(PREFIX)/sbin
LIBDIR  = $(PREFIX)/lib

export PREFIX
export BINDIR
export SBINDIR
export LIBDIR

TARGETS_ALL       = $(addsuffix .all,$(DIRS))
TARGETS_CLEAN     = $(addsuffix .clean,$(DIRS))
TARGETS_DISTCLEAN = $(addsuffix .distclean,$(DIRS))
TARGETS_INSTALL	  = $(addsuffix .install,$(DIRS))


TARGETS  = $(TARGETS_ALL)
TARGETS += $(TARGETS_CLEAN)
TARGETS += $(TARGETS_DISTCLEAN)

.PHONY: default all clean install distclean $(TARGETS)

default: all

all: $(TARGETS_ALL)
install:
	$(MAKE) --directory utility install
	$(MAKE) --directory src install

# Build prerequisites between major trees.
src.all: xml.all utility.all include.all
docs.all: src.all

clean: $(TARGETS_CLEAN)
	$(RM) -rf $(CURDIR)/lib
	$(RM) -rf $(CURDIR)/bin
	$(RM) -rf $(CURDIR)/sbin

distclean: $(TARGETS_DISTCLEAN)

$(TARGETS):
	$(MAKE) --directory $(basename $@) $(subst .,,$(suffix $@))

debug:
	@echo $(CURDIR)
