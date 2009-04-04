# This file contains port specific Makefile rules. It is automatically
# included by the default (main) Makefile.
#
# $URL$
# $Id$


#
# UNIX specific
#
install: all
	$(INSTALL) -d "$(DESTDIR)$(BINDIR)"
	$(INSTALL) -c -s -m 755 "./$(EXECUTABLE)" "$(DESTDIR)$(BINDIR)/$(EXECUTABLE)"
	#$(INSTALL) -d "$(DESTDIR)$(MANDIR)/man6/"
	#$(INSTALL) -c -m 644 "$(srcdir)/dists/residual.6" "$(DESTDIR)$(MANDIR)/man6/residual.6"
	$(INSTALL) -d "$(DESTDIR)$(PREFIX)/share/pixmaps/"
	$(INSTALL) -c -m 644 "$(srcdir)/icons/residual.xpm" "$(DESTDIR)$(PREFIX)/share/pixmaps/residual.xpm"
	$(INSTALL) -d "$(DESTDIR)$(PREFIX)/share/doc/residual/"
	$(INSTALL) -c -m 644 "$(srcdir)/AUTHORS" "$(srcdir)/COPYING.LGPL" "$(srcdir)/COPYING.GPL" "$(srcdir)/NEWS" "$(srcdir)/README" "$(srcdir)/TODO" "$(DESTDIR)$(PREFIX)/share/doc/residual/"

uninstall:
	rm -f "$(DESTDIR)$(BINDIR)/$(EXECUTABLE)"
	#rm -f "$(DESTDIR)$(MANDIR)/man6/residual.6"
	rm -f "$(DESTDIR)$(PREFIX)/share/pixmaps/residual.xpm"
	rm -rf "$(DESTDIR)$(PREFIX)/share/doc/residual/"

deb:
	ln -sf dists/debian;
	debian/prepare
	fakeroot debian/rules binary


# Special target to create a application wrapper for Mac OS X
bundle_name = Residual.app
bundle: residual-static $(srcdir)/dists/macosx/Info.plist
	mkdir -p $(bundle_name)/Contents/MacOS
	mkdir -p $(bundle_name)/Contents/Resources
	echo "APPL????" > $(bundle_name)/Contents/PkgInfo
	cp $(srcdir)/dists/macosx/Info.plist $(bundle_name)/Contents/
	cp $(srcdir)/icons/residual.icns $(bundle_name)/Contents/Resources/
	$(srcdir)/tools/credits.pl --rtf > $(bundle_name)/Contents/Resources/Credits.rtf
	chmod 644 $(bundle_name)/Contents/Resources/*
	cp residual-static $(bundle_name)/Contents/MacOS/residual
	chmod 755 $(bundle_name)/Contents/MacOS/residual
	strip $(bundle_name)/Contents/MacOS/residual

iphonebundle: $(srcdir)/dists/iphone/Info.plist
	mkdir -p $(bundle_name)
	cp $(srcdir)/dists/iphone/Info.plist $(bundle_name)/
	cp residual $(bundle_name)/Residual
	cp $(srcdir)/dists/iphone/icon.png $(bundle_name)/icon.png
	cp $(srcdir)/dists/iphone/Default.png $(bundle_name)/Default.png

# location of additional libs for OS X usually /sw/ for fink or
# /opt/local/ for darwinports
OSXOPT=/sw

# Location of static libs for the iPhone
ifneq ($(BACKEND), iphone)
# Static libaries, used for the scummvm-static and iphone targets
OSX_STATIC_LIBS := `$(STATICLIBPATH)/bin/sdl-config --static-libs`
endif

ifdef USE_VORBIS
OSX_STATIC_LIBS += \
		$(STATICLIBPATH)/lib/libvorbisfile.a \
		$(STATICLIBPATH)/lib/libvorbis.a \
		$(STATICLIBPATH)/lib/libogg.a
endif

ifdef USE_TREMOR
OSX_STATIC_LIBS += $(STATICLIBPATH)/lib/libvorbisidec.a
endif

ifdef USE_FLAC
OSX_STATIC_LIBS += $(STATICLIBPATH)/lib/libFLAC.a
endif

ifdef USE_MAD
OSX_STATIC_LIBS += $(STATICLIBPATH)/lib/libmad.a
endif

ifdef USE_MPEG2
OSX_STATIC_LIBS += $(STATICLIBPATH)/lib/libmpeg2.a
endif

BUILD_DATE := `date +%y%m%d`
#BUILD_DATE := rev`svn info | grep '^Revision' | sed -e 's/Revision: *//'`

# Special target to create a static linked binary for Mac OS X.
# We use -force_cpusubtype_ALL to ensure the binary runs on every
# PowerPC machine.
residual-static: $(OBJS)
	$(CXX) $(LDFLAGS) -force_cpusubtype_ALL -o residual-static $(OBJS) \
		-framework CoreMIDI \
		$(OSX_STATIC_LIBS) \
		-lSystemStubs -lz

# Special target to create a static linked binary for the iPhone
iphone: $(OBJS)
	$(CXX) $(LDFLAGS) -o residual $(OBJS) \
		$(OSX_STATIC_LIBS) \
		-framework UIKit -framework CoreGraphics -framework CoreSurface \
		-framework GraphicsServices -framework CoreFoundation -framework QuartzCore \
		-framework Foundation -framework AudioToolbox -framework CoreAudio \
		-lobjc -lz

# Special target to create a snapshot disk image for Mac OS X
# TODO: Replace AUTHORS by Credits.rtf
osxsnap: bundle
	mkdir Residual-snapshot
	cp $(srcdir)/AUTHORS ./Residual-snapshot/Authors
	cp $(srcdir)/COPYING.LGPL ./Residual-snapshot/License.LGPL
	cp $(srcdir)/COPYING.GPL ./Residual-snapshot/License.GPL
	cp $(srcdir)/NEWS ./Residual-snapshot/News
	cp $(srcdir)/TODO ./Residual-snapshot/Todo
	cp $(srcdir)/README ./Residual-snapshot/Residual\ ReadMe
	/Developer/Tools/SetFile -t ttro -c ttxt ./Residual-snapshot/*
	/Developer/Tools/CpMac -r $(bundle_name) ./Residual-snapshot/
	#cp $(srcdir)/dists/macosx/DS_Store ./Residual-snapshot/.DS_Store
	#cp $(srcdir)/dists/macosx/background.jpg ./Residual-snapshot/background.jpg
	#/Developer/Tools/SetFile -a V ./Residual-snapshot/.DS_Store
	#/Developer/Tools/SetFile -a V ./Residual-snapshot/background.jpg
	hdiutil create -ov -format UDZO -imagekey zlib-level=9 -fs HFS+ \
					-srcfolder Residual-snapshot \
					-volname "Residual snapshot $(BUILD_DATE)" \
					Residual-svn-$(BUILD_DATE).dmg
	rm -rf Residual-snapshot

#
# Windows specific
#

residualico.o: $(srcdir)/icons/residual.ico
	$(WINDRES) -I$(srcdir) $(srcdir)/dists/residual.rc residualico.o

# Special target to create a win32 snapshot binary under Windows
win32dist: $(EXECUTABLE)
	mkdir -p $(WIN32PATH)
	$(STRIP) $(EXECUTABLE) -o $(WIN32PATH)/$(EXECUTABLE)
	cp $(srcdir)/AUTHORS $(WIN32PATH)/AUTHORS.txt
	cp $(srcdir)/COPYING.LGPL $(WIN32PATH)/COPYING_LGPL.txt
	cp $(srcdir)/COPYING.GPL $(WIN32PATH)/COPYING_GPL.txt
	cp $(srcdir)/NEWS $(WIN32PATH)/NEWS.txt
	cp $(srcdir)/README $(WIN32PATH)/README.txt
	cp $(srcdir)/TODO $(WIN32PATH)/TODO.txt
	cp /usr/local/README-SDL.txt $(WIN32PATH)
	cp /usr/local/bin/SDL.dll $(WIN32PATH)
	u2d $(WIN32PATH)/*.txt

# Special target to create a win32 snapshot binary under Debian Linux using cross mingw32 toolchain
crosswin32dist: $(EXECUTABLE)
	mkdir -p ResidualWin32
	$(STRIP) $(EXECUTABLE) -o ResidualWin32/$(EXECUTABLE)
	cp $(srcdir)/AUTHORS ResidualWin32/AUTHORS.txt
	cp $(srcdir)/COPYING.LGPL ResidualWin32/COPYING_LGPL.txt
	cp $(srcdir)/COPYING.GPL ResidualWin32/COPYING_GPL.txt
	cp $(srcdir)/NEWS ResidualWin32/NEWS.txt
	cp $(srcdir)/README ResidualWin32/README.txt
	cp $(srcdir)/TODO ResidualWin32/TODO.txt
	cp $(srcdir)/dists/residual.ini.example ResidualWin32
	cp $(srcdir)/dists/residual.iss ResidualWin32
	cp /usr/i586-mingw32msvc/README-SDL.txt ResidualWin32
	cp /usr/i586-mingw32msvc/bin/SDL.dll ResidualWin32
	toms ResidualWin32/*.txt
	toms ResidualWin32/residual.ini.example
	toms ResidualWin32/residual.iss

#
# AmigaOS specific
#

# Special target to create an AmigaOS snapshot installation
aos4dist: $(EXECUTABLE)
	mkdir -p $(AOS4PATH)
	$(STRIP) $(EXECUTABLE) -o $(AOS4PATH)/$(EXECUTABLE)_SVN
	cp icons/residual.info $(AOS4PATH)/$$(EXECUTABLE)_SVN.info
	cp $(DIST_FILES_THEMES) $(AOS4PATH)/themes/
	cp $(DIST_FILES_ENGINEDATA) $(AOS4PATH)/extras/
	cp $(srcdir)/AUTHORS $(AOS4PATH)/AUTHORS.txt
	cp $(srcdir)/COPYING.LGPL $(AOS4PATH)/COPYING_LGPL.txt
	cp $(srcdir)/COPYING.GPL $(AOS4PATH)/COPYING_GPL.txt
	cp $(srcdir)/NEWS $(AOS4PATH)/NEWS.txt
	cp $(srcdir)/README $(AOS4PATH)/README.txt
	cp $(srcdir)/TODO $(AOS4PATH)/TODO.txt
	cp /sdk/local/documentation/SDL-1.2.9/README-SDL.txt $(AOS4PATH)

.PHONY: deb bundle osxsnap win32dist install uninstall
