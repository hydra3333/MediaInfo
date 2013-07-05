/*  Copyright (c) MediaArea.net SARL. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// WxWidgets GUI for MediaInfo
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
#ifndef GUI_MainH
#define GUI_MainH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "GUI/Common/GUI_Main_Common_Core.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// the application icon (under Windows and OS/2 it is in resources)
#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    //#include "mondrian.xpm"
#endif
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifdef MEDIAINFO_DLL_RUNTIME
    #include "MediaInfoDLL/MediaInfoDLL.h"
    #define MediaInfoNameSpace MediaInfoDLL
#elif defined MEDIAINFO_DLL_STATIC
    #include "MediaInfoDLL/MediaInfoDLL_Static.h"
    #define MediaInfoNameSpace MediaInfoDLL
#else
    #include "MediaInfo/MediaInfoList.h"
    #define MediaInfoNameSpace MediaInfoLib
#endif
using namespace MediaInfoNameSpace;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class Core;
class FileDrop;
class GUI_Main_Common_Core;
//---------------------------------------------------------------------------

//***************************************************************************
// GUI_Main
//***************************************************************************

class GUI_Main : public wxFrame
{
public:
    GUI_Main (int argc, MediaInfoNameSpace::Char** argv, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
    ~GUI_Main ();

    //Menu - List
    wxMenuBar*  Menu;
    wxMenu*     Menu_File;
    wxMenu*     Menu_File_Open;
    wxMenuItem* Menu_File_Open_Files;
    wxMenuItem* Menu_File_Open_Directory;
    wxMenuItem* Menu_File_Quit;
    wxMenu*     Menu_View;
    wxMenuItem* Menu_View_Easy;
    wxMenuItem* Menu_View_Sheet;
    wxMenuItem* Menu_View_Tree;
    wxMenuItem* Menu_View_HTML;
    wxMenuItem* Menu_View_Text;
    wxMenu*     Menu_Debug;
    wxMenuItem* Menu_Debug_Complete;
    wxMenuItem* Menu_Debug_Details;
    wxMenu*     Menu_Debug_Demux;
    wxMenuItem* Menu_Debug_Demux_None;
    wxMenuItem* Menu_Debug_Demux_Elementary;
    wxMenuItem* Menu_Debug_Demux_All;
    wxMenu*     Menu_Help;
    wxMenuItem* Menu_Help_About;
    wxMenuItem* Menu_Help_Info_Codecs;
    wxMenuItem* Menu_Help_Info_Formats;
    wxMenuItem* Menu_Help_Info_Parameters;

    //Menu - Actions
    void Menu_Create();
    void OnMenu_File_Open_Files         (wxCommandEvent &event);
    void OnMenu_File_Open_Directory     (wxCommandEvent &event);
    void OnMenu_File_Quit               (wxCommandEvent &event);
    void OnMenu_View_Easy               (wxCommandEvent &event);
    void OnMenu_View_Sheet              (wxCommandEvent &event);
    void OnMenu_View_Tree               (wxCommandEvent &event);
    void OnMenu_View_HTML               (wxCommandEvent &event);
    void OnMenu_View_Text               (wxCommandEvent &event);
    void OnMenu_Debug_Complete          (wxCommandEvent &event);
    void OnMenu_Debug_Details           (wxCommandEvent &event);
    void OnMenu_Debug_Demux_None        (wxCommandEvent &event);
    void OnMenu_Debug_Demux_Elementary  (wxCommandEvent &event);
    void OnMenu_Debug_Demux_All         (wxCommandEvent &event);
    void OnMenu_Help_About              (wxCommandEvent &event);
    void OnMenu_Help_Info_Codecs        (wxCommandEvent &event);
    void OnMenu_Help_Info_Formats       (wxCommandEvent &event);
    void OnMenu_Help_Info_Parameters    (wxCommandEvent &event);
    void OnSize                         (wxSizeEvent    &event);

    //ToolBar - List
    wxToolBar*  ToolBar;

    //ToolBar - Actions
    void ToolBar_Create();

    //Helpers
    void View_Refresh() {View->GUI_Refresh();}

private:
    //Non-GUI Elements
    Core* C;

    //GUI
    GUI_Main_Common_Core* View;

    //wxWidgets
    DECLARE_EVENT_TABLE() //Any class wishing to process wxWindows events must use this macro
};

#endif