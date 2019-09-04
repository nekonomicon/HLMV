//
//                 Half-Life Model Viewer (c) 1999 by Mete Ciragan
//
// file:           ViewerSettings.cpp
// last modified:  May 29 1999, Mete Ciragan
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
#include "ViewerSettings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mx/mxSettings.h>

ViewerSettings g_viewerSettings;



void
InitViewerSettings (void)
{
	g_viewerSettings.rot[0] = -90.0f;
	g_viewerSettings.trans[2] = 50.0f;
	g_viewerSettings.renderMode = RM_TEXTURED;
	g_viewerSettings.transparency = 1.0f;

	g_viewerSettings.yaw = 65.0f;
	g_viewerSettings.bgColor[0] = 0.25f;
	g_viewerSettings.bgColor[1] = 0.5f;
	g_viewerSettings.bgColor[2] = 0.5f;

	g_viewerSettings.gColor[0] = 0.85f;
	g_viewerSettings.gColor[1] = 0.85f;
	g_viewerSettings.gColor[2] = 0.69f;

	g_viewerSettings.lColor[0] = 1.0f;
	g_viewerSettings.lColor[1] = 1.0f;
	g_viewerSettings.lColor[2] = 1.0f;

	g_viewerSettings.guColor[0] = 1.0f;
	g_viewerSettings.guColor[1] = 0.0f;
	g_viewerSettings.guColor[2] = 0.0f;

	g_viewerSettings.speedScale = 1.0f;
	g_viewerSettings.textureLimit = 256;

	g_viewerSettings.textureScale = 1.0f;
}



int
LoadViewerSettings ()
{
	InitViewerSettings ();

	mx_get_usersettings_vec4d ("Background Color", g_viewerSettings.bgColor);
	mx_get_usersettings_vec4d ("Light Color", g_viewerSettings.lColor);
	mx_get_usersettings_vec4d ("Ground Color", g_viewerSettings.gColor);
	mx_get_usersettings_vec4d ("Guides Color", g_viewerSettings.guColor);
	mx_get_usersettings_int ("Show Ground", (int *)&g_viewerSettings.showGround);

	return 1;
}



int
SaveViewerSettings ()
{
	if (mx_create_usersettings ())
	{
		mx_set_usersettings_vec4d ("Background Color", g_viewerSettings.bgColor);
		mx_set_usersettings_vec4d ("Light Color", g_viewerSettings.lColor);
		mx_set_usersettings_vec4d ("Ground Color", g_viewerSettings.gColor);
		mx_set_usersettings_vec4d ("Guides Color", g_viewerSettings.guColor);
		mx_set_usersettings_int ("Show Ground", (int)g_viewerSettings.showGround);

		return 1;
	}

	return 0;
}
