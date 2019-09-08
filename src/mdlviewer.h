//
//                 Half-Life Model Viewer (c) 1999 by Mete Ciragan
//
// file:           mdlviewer.h
// last modified:  Apr 28 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
// version:        1.2
//
// email:          mete@swissquake.ch
// web:            http://www.swissquake.ch/chumbalum-soft/
//
#ifndef INCLUDED_MDLVIEWER
#define INCLUDED_MDLVIEWER



#ifndef INCLUDED_MXWINDOW
#include <mx/mxWindow.h>
#endif



#define IDC_FILE_LOADMODEL			1001
#define IDC_FILE_LOADBACKGROUNDTEX	1002
#define IDC_FILE_LOADGROUNDTEX		1003
#define IDC_FILE_UNLOADGROUNDTEX	1004
#define IDC_FILE_SAVEMODEL		1005
#define IDC_FILE_OPENPAKFILE		1006
#define IDC_FILE_CLOSEPAKFILE		1007
#define IDC_FILE_RECENTMODELS1		1008
#define IDC_FILE_RECENTMODELS2		1009
#define IDC_FILE_RECENTMODELS3		1010
#define IDC_FILE_RECENTMODELS4		1011
#define IDC_FILE_RECENTPAKFILES1	1012
#define IDC_FILE_RECENTPAKFILES2	1013
#define IDC_FILE_RECENTPAKFILES3	1014
#define IDC_FILE_RECENTPAKFILES4	1015
#define IDC_FILE_EXIT				1016

#define IDC_OPTIONS_COLORBACKGROUND	1101
#define IDC_OPTIONS_COLORGROUND		1102
#define IDC_OPTIONS_COLORLIGHT		1103
#define IDC_OPTIONS_COLORCROSSHAIR	1104
#define IDC_OPTIONS_CENTERVIEW		1105
#define IDC_OPTIONS_MAKESCREENSHOT	1106
#define IDC_OPTIONS_DUMP		1108
#define IDC_OPTIONS_SAVE		1109
#define IDC_OPTIONS_SOUNDFOLDER		1110
#define IDC_OPTIONS_SAVEVIEW		1111
#define IDC_OPTIONS_RECALLVIEW		1112
#define IDC_OPTIONS_FILEASSOCIATIONS	1201

#define IDC_HELP_GOTOHOMEPAGE		1301
#define IDC_HELP_ABOUT			1302
#define IDC_HELP_KEYBOARDSHORCUTS	1303

#define IDC_TOOLS_MODELCOMPILE		1401
#define IDC_TOOLS_MODELDECOMPILE	1402
#define IDC_TOOLS_CONFIGURE		1403
#define IDC_TOOLS_QCFILEEDIT		1404

class mxMenuBar;
class GlWindow;
class ControlPanel;
class PAKViewer;
class MDLTools;



class MDLViewer : public mxWindow
{
	mxMenuBar *mb;
	GlWindow *d_GlWindow;
	ControlPanel *d_cpl;
	PAKViewer *d_PAKViewer;
	MDLTools *d_MDLTools;

	void loadRecentFiles ();
	void saveRecentFiles ();
	void initRecentFiles ();

public:
	// CREATORS
	MDLViewer ();
	~MDLViewer ();

	// MANIPULATORS
	virtual int handleEvent (mxEvent *event);
	void redraw ();

	// ACCESSORS
	mxMenuBar *getMenuBar () const { return mb; }
	GlWindow *getGlWindow () const { return d_GlWindow; }
	PAKViewer *getPAKViewer () const { return d_PAKViewer; }
	MDLTools *getMDLTools () const { return d_MDLTools; }
};



extern MDLViewer *g_MDLViewer;
extern const char *g_appTitle;



#endif // INCLUDED_MDLVIEWER
