//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FileManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DriveComboBoxChange(TObject *Sender)
{
	DirListBox->Drive = DriveComboBox->Drive;
}
//---------------------------------------------------------------------------
