/**
 * ---------------------------------------------------------
 * @author: David Whiteside
 * @date: 09/20/09
 * @description: The Main Parent Window of Every Other Window
 * Copyright 2004-2009 Whiteside Solutions LLC (www.whitesidesolutions.com)
 * ---------------------------------------------------------
 */
#ifndef guiParentWindow_H
#define guiParentWindow_H


#define wxUSE_DEBUG_NEW_ALWAYS 0
#include <wx/wx.h>
#include <wx/menu.h>
#include "../inc/main.h"

class guiParentWindow : public wxFrame
{
private:
	// Event Declerations
   enum {	ID_FILE_OPEN=wxID_HIGHEST+1,
			ID_FILE_NEW,
			ID_FILE_SAVE,
			ID_FILE_SAVEAS,
			ID_FILE_LOADFIELDKIT,
			ID_EDIT_UNDO,
			ID_EDIT_REDO,
			ID_EDIT_DELETE,
			ID_EDIT_SELECTNONE,
			ID_EDIT_MIRRORFIELD,
			ID_EDIT_RESIZEFIELD,
			ID_VIEW_TOP,
			ID_VIEW_FIRSTPERSON,
			ID_VIEW_PERSPECTIVE,
			ID_VIEW_RESET,
			ID_VIEW_OPTIONS,
			ID_RENDER_SAVESCREENSHOT,
			ID_ABOUT_HELP,
			ID_ABOUT_INFO,
			ID_ABOUT_REGISTER,
			ID_ROTATEVIEW,
			ID_MOVEVIEW,
			ID_ROTATEOBJ,
			ID_MOVEOBJ,
			ID_SELECTOBJ,
			ID_CREATEOBJ,
			ID_CLONEOBJ					}; // eND OF eNUM

protected:
	wxMenuBar *mMenubar;
	wxMenu *mFile;
	wxMenu *mEdit;
	wxMenu *mView;
	wxMenu *mRender;
	wxMenu *mAbout;
	wxToolBar *mToolbar;

	inline void EnableLastToolbar() {
		int old_tool_id = 0;
		int val = (int)(MyApp::s_CursorTool);
		if (val == ROTATEVIEW) old_tool_id = ID_ROTATEVIEW;
		if (val == MOVEVIEW) old_tool_id = ID_MOVEVIEW;
		if (val == MOVEOBJ) old_tool_id = ID_MOVEOBJ;
		if (val == ROTATEOBJ) old_tool_id = ID_ROTATEOBJ;
		if (val == SELECTOBJ) old_tool_id = ID_SELECTOBJ;
		if (val == CREATEOBJ) old_tool_id = ID_CREATEOBJ;
		if (val == CLONEOBJ) old_tool_id = ID_CLONEOBJ;

		if (old_tool_id != 0) {
			mToolbar->EnableTool(old_tool_id, true);
		}
	}

public:
	guiParentWindow(const wxString& title);
	~guiParentWindow();

	void OnSize(wxSizeEvent& event);

	void OnFileNew(wxCommandEvent& event);
	void OnFileOpen(wxCommandEvent& event);
	void OnFileSave(wxCommandEvent& event);
	void OnFileSaveAs(wxCommandEvent& event);
	void OnLoadFieldKit(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);

	void OnUndo(wxCommandEvent& event);
	void OnRedo(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnSelectNone(wxCommandEvent& event);
	void OnMirrorField(wxCommandEvent& event);
	void OnResizeField(wxCommandEvent& event);

	void OnViewTop(wxCommandEvent& event);
	void OnViewFirstPerson(wxCommandEvent& event);
	void OnViewPerspective(wxCommandEvent& event);
	void OnViewReset(wxCommandEvent& event);
	void OnViewOptions(wxCommandEvent& event);

	void OnSaveScreenshot(wxCommandEvent& event);

	void OnHelp(wxCommandEvent& event);
	void OnInfo(wxCommandEvent& event);
	void OnRegister(wxCommandEvent& event);

	void OnMoveView(wxCommandEvent& event);
	void OnRotateView(wxCommandEvent& event);
	void OnMoveObj(wxCommandEvent& event);
	void OnRotateObj(wxCommandEvent& event);
	void OnSelectObj(wxCommandEvent& event);
	void OnCreateObj(wxCommandEvent& event);
	void OnCloneObj(wxCommandEvent& event);

	void OnKeyDown(wxKeyEvent& event);
};

#endif // guiParentWindow_H
