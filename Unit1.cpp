//---------------------------------------------------------------------------
#include <stdlib.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <dir.h>
#include <windows.h>
#include <Sysutils.hpp>
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    AddFontResourceEx("OpenSans-Regular.ttf", FR_PRIVATE, 0);
    AnsiString FontX = "OpenSans";

    Form1->Font->Name = FontX;

    EditCreateFolder->Enabled = False;
    EditRenameFile->Enabled = False;
    EditFileCreate->Enabled = False;

    ButtonDeleteFile->Enabled = False;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxFileExtensionClick(TObject *Sender)
{
    if (CheckBoxFileExtension->Checked)
    {
        int a = 0;
        
        for(int i = 0; i<FileListBox->Items->Count; i++)
        {
            if ((a = FileListBox->Items->Strings[i].Pos(".")) > 1)
            {
                FileListBox->Items->Strings[i] = FileListBox->Items->Strings[i].SubString(1,a-1);
            }
        }
    }
    else
    {
        int a = 0;
        for(int i = 0; i<FileListBox->Items->Count; i++)
        {
            if ((a = FileListBox->Items->Strings[i].Pos(".")) > 1)
            {
                FileListBox->Items->Strings[i] = FileListBox->Items->Strings[i].SubString(1,a-1);
            }
        }
    }
}

void __fastcall TForm1::ButtonDeleteFileClick(TObject *Sender)
{
    DeleteFile(FileListBox->FileName);
    MessageDlg("Файл " + FileListBox->FileName + " удален.", mtInformation, TMsgDlgButtons() << mbOK, 0);
    FileListBox->Update();
}
//---------------------------------------------------------------------------

AnsiString EditFileTemp = "";
void __fastcall TForm1::ButtonRenameFileClick(TObject *Sender)
{
    EditRenameFile->Enabled = True;
    EditRenameFile->SetFocus();
    if (EditFileTemp != EditRenameFile->Text)
    {
        RenameFile(EditFileTemp.c_str(), EditRenameFile->Text.c_str());
        MessageDlg("Файл переименован.", mtInformation, TMsgDlgButtons() << mbOK, 0);
        FileListBox->Update();
        Form1->EditRenameFile->Text = "";
        EditRenameFile->Enabled = False;
    }
    EditFileTemp = FileListBox->FileName;
    EditRenameFile->Text = FileListBox->FileName;
    EditRenameFile->SelectAll();

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
        MessageDlg("Папка " + EditPath + " создана.", mtInformation, TMsgDlgButtons() << mbOK, 0);
        DirectoryListBox1->Update();
        Form1->EditCreateFolder->Text = "";
        EditCreateFolder->Enabled = False;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenFileClick(TObject *Sender)
{
    ShellExecute(Handle, "open", FileListBox->FileName.c_str(), NULL, NULL,SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileListBoxDblClick(TObject *Sender)
{
    ShellExecute(Handle, "open", FileListBox->FileName.c_str(), NULL, NULL,SW_RESTORE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteFolderClick(TObject *Sender)
{
    AnsiString Path;
    Path = DirectoryListBox1->GetItemPath(DirectoryListBox1->ItemIndex);
    RemoveDirectory(Path.c_str());
    MessageDlg("Папка удалена.", mtInformation, TMsgDlgButtons() << mbOK, 0);
    DirectoryListBox1->Update();

    /*AnsiString S=DirectoryListBox1->Directory;
    DirectoryListBox1->ItemIndex=DirectoryListBox1->ItemIndex-1;
    //DirectoryListBox1->OpenCurrent();
    MyDelete(S+"\\","*.*");
    RmDir(S); */
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonCreateFileClick(TObject *Sender)
{
    AnsiString FullPath, FolderPath, FileName;

    EditFileCreate->Enabled = True;
    EditFileCreate->SetFocus();
    FolderPath = DirectoryListBox1->GetItemPath(DirectoryListBox1->ItemIndex);
    FileName = EditFileCreate->Text;
    if (FileName != "")
    {
        FullPath = FolderPath + FileName;
        FileCreate(FullPath);
        MessageDlg("Файл " + FileName + " создан.", mtInformation, TMsgDlgButtons() << mbOK, 0);
        FileListBox->Update();
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

