object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'File Manager'
  ClientHeight = 320
  ClientWidth = 480
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelPathToFile: TLabel
    Left = 8
    Top = 299
    Width = 118
    Height = 13
    Caption = 'C:\WINDOWS\System32'
  end
  object DirListBox: TDirectoryListBox
    Left = 8
    Top = 32
    Width = 225
    Height = 261
    DirLabel = LabelPathToFile
    FileList = FileListBox
    TabOrder = 0
  end
  object FileListBox: TFileListBox
    Left = 239
    Top = 32
    Width = 233
    Height = 261
    ItemHeight = 13
    TabOrder = 1
  end
  object DriveComboBox: TDriveComboBox
    Left = 8
    Top = 8
    Width = 225
    Height = 19
    Hint = 'Select Drive'
    DirList = DirListBox
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    TextCase = tcUpperCase
    OnChange = DriveComboBoxChange
  end
  object FilterComboBox: TFilterComboBox
    Left = 384
    Top = 8
    Width = 88
    Height = 21
    FileList = FileListBox
    Filter = 'All files|*.*|Pictures|*.jpg*|Text|*.txt*|Video|*.mp4*'
    TabOrder = 3
  end
end
