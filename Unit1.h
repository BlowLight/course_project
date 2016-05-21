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
        TCheckBox *CheckBoxFileExtension;
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
        void __fastcall CheckBoxFileExtensionClick(TObject *Sender);
        void __fastcall ButtonDeleteFileClick(TObject *Sender);
        void __fastcall ButtonRenameFileClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ButtonOpenFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FileListBoxDblClick(TObject *Sender);
        void __fastcall ButtonDeleteFolderClick(TObject *Sender);
        void __fastcall ButtonCreateFileClick(TObject *Sender);
        void __fastcall ButtonUpdateClick(TObject *Sender);
private:        // User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
