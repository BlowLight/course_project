//---------------------------------------------------------------------------

#ifndef FileManagerH
#define FileManagerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDirectoryListBox *DirListBox;
	TLabel *LabelPathToFile;
	TFileListBox *FileListBox;
	TDriveComboBox *DriveComboBox;
	TFilterComboBox *FilterComboBox;
	void __fastcall DriveComboBoxChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
