#include <stdio.h>
#include <stdlib.h>
#include <mx/mx.h>
#include <mx/mxSettings.h>
#include "mdltools.h"



MDLTools::MDLTools (mxWindow *parent)
: mxWindow (0, 100, 100, 364, 150, "Configure Tools", mxWindow::Dialog)
{
	new mxLabel (this, 5, 3, 120, 18, "Path to \"studiomdl\"");
	leStudioMdl = new mxLineEdit (this, 5, 20, 320, 18, "");
	new mxButton (this, 330, 20, 22, 18, "...", IDC_TOOLS_STUDIOMDL);

	new mxLabel (this, 5, 48, 120, 18, "Path to \"mdldec\"");
	leMdlDec = new mxLineEdit (this, 5, 65, 320, 18, "");
	new mxButton (this, 330, 65, 22, 18, "...", IDC_TOOLS_MDLDEC);

	new mxButton (this, 145, 92, 74, 22, "&OK", IDC_TOOLS_OK);
}



MDLTools::~MDLTools ()
{
}



int
MDLTools::handleEvent (mxEvent *event)
{
	const char *filter;
	mxLineEdit *lePtr = 0;

#if _WIN32
	filter = "Executables (*.exe;*.com)";
#else
	filter = "All Files (*.*)";
#endif

	switch (event->event)
	{                       
	case mxEvent::Action:
	{
		switch (event->action)
		{
		case IDC_TOOLS_OK:
		{
			if (!saveSettings ())
				mxMessageBox (0, "Error saving configuration.", "Error Saving Configuration", MX_MB_OK | MX_MB_ERROR);
			setVisible (false);
		}
		break;

		case IDC_TOOLS_STUDIOMDL:
		{
			lePtr = leStudioMdl;
		}
		break;

		case IDC_TOOLS_MDLDEC:
		{
			lePtr = leMdlDec;
		}
		break;
		default:
			return 0;
		}
	}
	break;
	}

	if (lePtr)
	{
		const char *path = mxGetOpenFileName (this, "", filter);

		if (path)
		{
			char buf[MAX_USERSETTINGS_ENTRY_SIZE];

			snprintf (buf, sizeof buf, "%s", path);
			lePtr->setLabel (buf);
		}
	}

	return 1;
}



int
MDLTools::init ()
{
	char path[MAX_USERSETTINGS_ENTRY_SIZE] = {0,};

	mx_get_usersettings_string ("Compiler", path);
	leStudioMdl->setLabel (path);

	mx_get_usersettings_string ("Decompiler", path);
	leMdlDec->setLabel (path);

	return 1;
}



int
MDLTools::saveSettings ()
{
	if (mx_create_usersettings ())
	{
		mx_set_usersettings_string ("Compiler", leStudioMdl->getLabel ());
		mx_set_usersettings_string ("Decompiler", leMdlDec->getLabel ());

		return 1;
	}

	return 0;
}

