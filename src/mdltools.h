#ifndef INCLUDED_MDLTOOLS
#define INCLUDED_MDLTOOLS



#ifndef INCLUDED_MXWINDOW
#include <mx/mxWindow.h>
#endif



#define IDC_TOOLS_OK		1001
#define IDC_TOOLS_STUDIOMDL	1002
#define IDC_TOOLS_MDLDEC	1003



class MDLTools : public mxWindow
{
	mxLineEdit *leStudioMdl, *leMdlDec;

public:
	// CREATORS
	MDLTools (mxWindow *parent);
	virtual ~MDLTools ();

	// MANIPULATORS
	int handleEvent (mxEvent *event);
	int init ();
	int saveSettings ();

	// NO ACCESSORS
};

#endif // INCLUDED_MDLTOOLS

