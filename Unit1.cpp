#include <vcl.h>
#include <dir.h>
#include <fstream.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
int Option;
AnsiString Ad,Fn;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    AddFontResourceEx("OpenSans-Regular.ttf", FR_PRIVATE, 0);
    AnsiString FontX = "OpenSans";

    Form1->Font->Name = FontX;

    EditCreateFolder->Enabled = False;
    EditFileCreate->Enabled = False;

    ButtonRenameFile->Enabled = False;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteFileClick(TObject *Sender)
{
    DeleteFile(FileListBox->FileName);
    FileListBox->Update();
}
//---------------------------------------------------------------------------

AnsiString EditFileTemp = "";
void __fastcall TForm1::ButtonRenameFileClick(TObject *Sender)
{
    RenameFile(FileListBox->FileName.c_str(),EditRenameFile->Text.c_str());
    FileListBox->Update();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    String FirstPath, EditPath, Path;

    EditCreateFolder->Enabled = True;
    EditCreateFolder->SetFocus();
    EditPath = EditCreateFolder->Text;
    if (EditPath != "")
    {
        FirstPath = DirectoryListBox1->GetItemPath(DirectoryListBox1->ItemIndex);
        Path = FirstPath + "\\" + EditPath;
        CreateDirectory(Path.c_str(), NULL);
        DirectoryListBox1->Update();
        Form1->EditCreateFolder->Text = "";
        EditCreateFolder->Enabled = False;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenFileClick(TObject *Sender)
{
    ShellExecute(Handle, "open", FileListBox->FileName.c_str(), NULL, NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileListBoxDblClick(TObject *Sender)
{

    ShellExecute(Handle, "open", FileListBox->FileName.c_str(), NULL, NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteFolderClick(TObject *Sender)
{
    AnsiString S = DirectoryListBox1->Directory;
    DirectoryListBox1->ItemIndex = DirectoryListBox1->ItemIndex-1;
    DirectoryListBox1->OpenCurrent();
    DeleteDir(S+"\\","*.*");
    RmDir(S);
    DirectoryListBox1->Update();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonCreateFileClick(TObject *Sender)
{
    AnsiString FileName;
    char * b;

    EditFileCreate->Enabled = True;
    EditFileCreate->SetFocus();
    FileName = EditFileCreate->Text;
    b = FileName.c_str();
    std::ofstream ofs;

    if (FileName != "")
    {
        ofs.open (b, std::ofstream::out | std::ofstream::app);
        ofs.close();
        FileListBox->Update();
        DirectoryListBox1->Update();
        Form1->EditFileCreate->Text = "";
        EditFileCreate->Enabled = False;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonUpdateClick(TObject *Sender)
{
    DirectoryListBox1->Update();
    FileListBox->Update();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCopyFileClick(TObject *Sender)
{
    Fn = EditRenameFile->Text;
    Ad = FileListBox->FileName;
    Option = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPasteFileClick(TObject *Sender)
{
    if (Option == 1)
    {
        Fn = "\\"+Fn;
        Fn = LabelPathFolder->Caption+Fn;
        CopyFile(Ad.c_str(),Fn.c_str(),1);
        FileListBox->Update();
    }
    else
    if (Option == 2)
    {
        Fn = "\\"+Fn;
        Fn = LabelPathFolder->Caption+Fn;
        CopyFile(Ad.c_str(),Fn.c_str(),1);
        DeleteFile(Ad.c_str());
        FileListBox->Update();
    }
    Option = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditRenameFileChange(TObject *Sender)
{
    ButtonRenameFile->Enabled = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCutFileClick(TObject *Sender)
{
    Fn = EditRenameFile->Text;
    Ad = FileListBox->FileName;
    Option = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    while (DirectoryListBox1->ItemIndex != 0)
    {
        DirectoryListBox1->ItemIndex = DirectoryListBox1->ItemIndex-1;
    }
    DirectoryListBox1->OpenCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DriveComboBoxChange(TObject *Sender)
{
    char drv;
    drv = UpCase(DriveComboBox->Drive);

    if (DiskSize(Byte(drv) - 0x40)  == -1)
    {
        String error = "В дисководе " + AnsiString(drv) + ": нет носителя.";
        ShowMessage(error);
    }
}

//---------------------------------------------------------------------------

