include	../standard_definitions.mk

install:
	cp -L -rf X11 $(DESTDIR)/$(INCDIR)
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "Name: Xproto" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "Description: Xproto headers" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "Version: 7.0.17" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xproto.pc
