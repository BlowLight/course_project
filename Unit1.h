//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FileCtrl.hpp>
#include <Tabs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TDriveComboBox *DriveComboBox;
    TDirectoryListBox *DirectoryListBox1;
    TFileListBox *FileListBox;
    TFilterComboBox *FilterComboBox;
    TButton *ButtonDeleteFile;
    TButton *ButtonRenameFile;
    TEdit *EditRenameFile;
    TButton *Button1;
    TEdit *EditCreateFolder;
    TButton *ButtonOpenFile;
    TPanel *Panel1;
    TLabel *LabelFileOperations;
    TPanel *Panel2;
    TLabel *LabelPathFolder;
    TButton *ButtonDeleteFolder;
    TButton *ButtonCreateFile;
    TEdit *EditFileCreate;
    TPanel *PanelHeader;
    TButton *ButtonUpdate;
    TButton *ButtonCopyFile;
    TButton *ButtonCutFile;
    TButton *ButtonPasteFile;
        TButton *Button2;
    void __fastcall ButtonDeleteFileClick(TObject *Sender);
    void __fastcall ButtonRenameFileClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ButtonOpenFileClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FileListBoxDblClick(TObject *Sender);
    void __fastcall ButtonDeleteFolderClick(TObject *Sender);
    void __fastcall ButtonCreateFileClick(TObject *Sender);
    void __fastcall ButtonUpdateClick(TObject *Sender);
    void __fastcall ButtonCopyFileClick(TObject *Sender);
    void __fastcall ButtonPasteFileClick(TObject *Sender);
    void __fastcall EditRenameFileChange(TObject *Sender);
    void __fastcall ButtonCutFileClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall DriveComboBoxChange(TObject *Sender);
private:
    void DeleteDir (AnsiString Dir, AnsiString tmp)
    {
        TSearchRec SR;
        int ires;
        ires = FindFirst(Dir + tmp, faAnyFile, SR);
        while (ires==0)
        {
            DeleteFile(Dir + SR.Name);
            ires=FindNext(SR);
        }
        FindClose(SR);
    }
public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
