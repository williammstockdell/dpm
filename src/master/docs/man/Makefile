include ../../../../Make.hlcs.rules

MAN_INSTALL_DIR=$(DPM_INSTALL_DIR)/man/man8


XML_SRC = list_agents.xml
XML_SRC += list_clients.xml
XML_SRC += get_errors.xml
XML_SRC += get_history.xml
XML_SRC += dpm_server.xml
XML_SRC += master_stop.xml
XML_SRC += alias_wait.xml
XML_SRC += binary_status.xml
XML_SRC += binary_wait.xml
XML_SRC += fail_over.xml
XML_SRC += master_start.xml
XML_SRC += master_status.xml
XML_SRC += reload_config.xml
XML_SRC += dpm_server_log_level.xml
XML_SRC += dpm_agentd.xml
XML_SRC += monitor_master.xml
XML_SRC += dpm_server_refresh_config.xml

XML_OBJ = $(XML_SRC:%.xml=%.8)

DOCBOOK := /usr/share/xml/docbook/stylesheet/docbook-xsl/manpages/docbook.xsl

ifneq ($(DOCBOOK), no)

debug:
	@echo $(MAN_INSTALL_DIR)
	@echo %.8

$(MAN_INSTALL_DIR):
	mkdir -p $@

$(MAN_INSTALL_DIR)/%.8: %.8 | $(MAN_INSTALL_DIR)
	cp $^ $@

%.8:	%.xml
	@echo "generating man pages"
	xmllint --noout --valid $<
	xsltproc $(DOCBOOK) $<

default: all

all:	docs

docs: $(XML_OBJ)

install: $(addprefix $(MAN_INSTALL_DIR)/, $(XML_OBJ))

#uninstall:
#	$(RM) -r $(MAN_INSTALL_DIR)

else

all:
#install:

endif

clean:
	$(RM) *.8 *~

distclean: clean
