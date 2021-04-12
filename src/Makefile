PACKAGES = libandroid-properties

CFLAGS = -O2 $(shell pkg-config --cflags $(PACKAGES))
LIBS = $(shell pkg-config --libs $(PACKAGES))

SYMLINKS = \
	android_bootctl \
	android_logcat \
	android_lshal \
	android_getprop \
	android_setprop \
	android_reboot \
	logcat \
	lshal

all: waitforservice

waitforservice: waitforservice.c
	# hybris-common lacks a proper pkg-config definition
	$(CC) $(CFLAGS) $< -o $@ $(LIBS) -lhybris-common

install: waitforservice halium-lxc-exec.sh
	install -d $(DESTDIR)/usr/bin
	install -d $(DESTDIR)/usr/sbin
	install -d $(DESTDIR)/usr/lib/halium-wrappers
	install -m 755 waitforservice $(DESTDIR)/usr/bin
	install -m 755 halium-lxc-exec.sh $(DESTDIR)/usr/lib/halium-wrappers

	for link in $(SYMLINKS); do \
		ln -s /usr/lib/halium-wrappers/halium-lxc-exec.sh $(DESTDIR)/usr/sbin/$${link}; \
	done

.PHONY: all install
