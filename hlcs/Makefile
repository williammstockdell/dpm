DIRS =
DIRS += xml
DIRS += utility
DIRS += include
DIRS += src
DIRS += docs

TARGETS_ALL       = $(addsuffix .all,$(DIRS))
TARGETS_CLEAN     = $(addsuffix .clean,$(DIRS))
TARGETS_DISTCLEAN = $(addsuffix .distclean,$(DIRS))

TARGETS  = $(TARGETS_ALL)
TARGETS += $(TARGETS_CLEAN)
TARGETS += $(TARGETS_DISTCLEAN)

.PHONY: default all clean distclean $(TARGETS)

default: all

all: $(TARGETS_ALL)

# Build prerequisites between major trees.
src.all: xml.all utility.all include.all
docs.all: src.all

clean: $(TARGETS_CLEAN)
distclean: $(TARGETS_DISTCLEAN)

$(TARGETS):
	$(MAKE) --directory $(basename $@) $(subst .,,$(suffix $@))
