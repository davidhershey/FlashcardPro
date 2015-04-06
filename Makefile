#############################################################################
# Makefile for building: FlashcardPro
# Generated by qmake (3.0) (Qt 5.4.0)
# Project:  FlashcardPro.pro
# Template: app
# Command: F:\Qt\5.4\msvc2013_64\bin\qmake.exe -spec win32-msvc2013 CONFIG+=debug -o Makefile FlashcardPro.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = F:\Qt\5.4\msvc2013_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = copy /y
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: FlashcardPro.pro F:\Qt\5.4\msvc2013_64\mkspecs\win32-msvc2013\qmake.conf F:\Qt\5.4\msvc2013_64\mkspecs\features\spec_pre.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\common\shell-win32.conf \
		F:\Qt\5.4\msvc2013_64\mkspecs\qconfig.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axbase.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axbase_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axcontainer.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axcontainer_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axserver.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axserver_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_bluetooth.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_bluetooth_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_bootstrap_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_clucene_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_concurrent.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_concurrent_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_core.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_core_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_declarative.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_declarative_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_designer.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_designer_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_designercomponents_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_enginio.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_enginio_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_gui.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_gui_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_help.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_help_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_location.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_location_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimedia.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimedia_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_network.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_network_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_nfc.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_nfc_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_opengl.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_opengl_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_openglextensions.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_openglextensions_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_platformsupport_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_positioning.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_positioning_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_printsupport.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_printsupport_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qml.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qml_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qmltest.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qmltest_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quick.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quick_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quickparticles_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_script.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_script_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_scripttools.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_scripttools_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sensors.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sensors_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_serialport.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_serialport_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sql.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sql_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_svg.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_svg_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_testlib.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_testlib_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_uitools.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_uitools_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webchannel.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webchannel_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webengine.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webengine_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginecore.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginecore_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkit.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkit_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkitwidgets.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkitwidgets_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_websockets.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_websockets_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webview.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webview_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_widgets.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_widgets_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_winextras.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_winextras_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xml.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xml_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\qt_functions.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\qt_config.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\qt_config.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\win32-msvc2013\qmake.conf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\spec_post.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\exclusive_builds.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\default_pre.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\default_pre.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\resolve_config.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\exclusive_builds_post.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\default_post.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\rtti.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\precompile_header.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\warn_on.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\qt.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\resources.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\moc.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\opengl.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\uic.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\windows.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\testcase_targets.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\exceptions.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\yacc.prf \
		F:\Qt\5.4\msvc2013_64\mkspecs\features\lex.prf \
		FlashcardPro.pro \
		F:/Qt/5.4/msvc2013_64/lib/qtmaind.prl \
		F:/Qt/5.4/msvc2013_64/lib/Qt5Cored.prl \
		F:/Qt/5.4/msvc2013_64/lib/Qt5OpenGL.prl \
		F:/Qt/5.4/msvc2013_64/lib/Qt5Widgets.prl \
		F:/Qt/5.4/msvc2013_64/lib/Qt5Gui.prl \
		F:/Qt/5.4/msvc2013_64/lib/Qt5Core.prl
	$(QMAKE) -spec win32-msvc2013 CONFIG+=debug -o Makefile FlashcardPro.pro
F:\Qt\5.4\msvc2013_64\mkspecs\features\spec_pre.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\common\shell-win32.conf:
F:\Qt\5.4\msvc2013_64\mkspecs\qconfig.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axbase.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axbase_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axcontainer.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axcontainer_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axserver.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_axserver_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_bluetooth.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_bluetooth_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_bootstrap_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_clucene_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_concurrent.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_concurrent_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_core.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_core_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_declarative.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_declarative_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_designer.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_designer_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_designercomponents_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_enginio.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_enginio_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_gui.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_gui_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_help.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_help_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_location.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_location_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimedia.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimedia_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_network.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_network_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_nfc.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_nfc_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_opengl.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_opengl_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_openglextensions.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_openglextensions_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_platformsupport_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_positioning.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_positioning_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_printsupport.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_printsupport_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qml.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qml_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qmldevtools_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qmltest.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qmltest_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quick.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quick_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quickparticles_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_quickwidgets_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_script.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_script_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_scripttools.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_scripttools_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sensors.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sensors_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_serialport.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_serialport_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sql.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_sql_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_svg.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_svg_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_testlib.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_testlib_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_uitools.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_uitools_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webchannel.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webchannel_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webengine.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webengine_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginecore.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginecore_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkit.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkit_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkitwidgets.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webkitwidgets_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_websockets.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_websockets_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webview.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_webview_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_widgets.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_widgets_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_winextras.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_winextras_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xml.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xml_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
F:\Qt\5.4\msvc2013_64\mkspecs\features\qt_functions.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\qt_config.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\qt_config.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\win32-msvc2013\qmake.conf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\spec_post.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\exclusive_builds.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\default_pre.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\default_pre.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\resolve_config.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\exclusive_builds_post.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\default_post.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\rtti.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\precompile_header.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\warn_on.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\qt.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\resources.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\moc.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\opengl.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\uic.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\win32\windows.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\testcase_targets.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\exceptions.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\yacc.prf:
F:\Qt\5.4\msvc2013_64\mkspecs\features\lex.prf:
FlashcardPro.pro:
F:/Qt/5.4/msvc2013_64/lib/qtmaind.prl:
F:/Qt/5.4/msvc2013_64/lib/Qt5Cored.prl:
F:/Qt/5.4/msvc2013_64/lib/Qt5OpenGL.prl:
F:/Qt/5.4/msvc2013_64/lib/Qt5Widgets.prl:
F:/Qt/5.4/msvc2013_64/lib/Qt5Gui.prl:
F:/Qt/5.4/msvc2013_64/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-msvc2013 CONFIG+=debug -o Makefile FlashcardPro.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
	-$(DEL_FILE) FlashcardPro.exp
	-$(DEL_FILE) FlashcardPro.ilk
	-$(DEL_FILE) FlashcardPro.idb
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) FlashcardPro.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
