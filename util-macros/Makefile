include	../standard_definitions.mk

install:
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "pkgdatadir=$(DATADIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "docdir=$(DOCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "Name: X.Org Macros" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "Description: A set of autoconf project macros for X.Org modules" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
	@echo "Version: 1.19.0" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xorg-macros.pc
