object Form1: TForm1
  Left = 1008
  Top = 221
  Width = 808
  Height = 631
  Caption = #1060#1072#1081#1083#1086#1074#1099#1081' '#1084#1077#1085#1077#1076#1078#1077#1088
  Color = clMenu
  Ctl3D = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnCreate = FormCreate
  DesignSize = (
    800
    600)
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 410
    Top = 480
    Width = 380
    Height = 110
    BevelOuter = bvNone
    BorderWidth = 1
    BorderStyle = bsSingle
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 11
    object LabelFileOperations: TLabel
      Left = 8
      Top = 8
      Width = 139
      Height = 16
      Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1092#1072#1081#1083#1072#1084#1080
    end
  end
  object DriveComboBox: TDriveComboBox
    Left = 10
    Top = 112
    Width = 190
    Height = 22
    Ctl3D = False
    DirList = DirectoryListBox1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 0
    TextCase = tcUpperCase
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 10
    Top = 144
    Width = 380
    Height = 329
    BevelInner = bvNone
    BevelOuter = bvNone
    Ctl3D = False
    DirLabel = LabelPathFolder
    FileList = FileListBox
    ItemHeight = 16
    ParentCtl3D = False
    TabOrder = 1
  end
  object FileListBox: TFileListBox
    Left = 410
    Top = 144
    Width = 380
    Height = 330
    Align = alCustom
    Anchors = [akTop, akRight]
    Ctl3D = False
    ItemHeight = 16
    MultiSelect = True
    ParentCtl3D = False
    TabOrder = 2
    OnDblClick = FileListBoxDblClick
  end
  object FilterComboBox: TFilterComboBox
    Left = 600
    Top = 112
    Width = 190
    Height = 24
    Anchors = [akRight]
    Ctl3D = False
    FileList = FileListBox
    Filter = 
      #1042#1089#1077' '#1092#1072#1081#1083#1099' (*.*)|*.*|'#1044#1086#1082#1091#1084#1077#1085#1090#1099' (*.doc, *.docx, *.txt)|*.doc*;*doc' +
      'x*;*.txt*|'#1055#1088#1086#1075#1088#1072#1084#1084#1099' (*.exe)|*.exe*|'#1060#1086#1090#1086#1075#1088#1072#1092#1080#1080' (*.jpg, *.jpeg, *p' +
      'ng)|*.jpg.*;*.jpeg*;*.png*|'#1042#1080#1076#1077#1086' (*.mp4, *.avi)|*.mp4*;*.avi*|'#1040#1088 +
      #1093#1080#1074#1099' (*.zip, *.rar)|*.zip*;*.rar*'
    ParentCtl3D = False
    TabOrder = 3
  end
  object CheckBoxFileExtension: TCheckBox
    Left = 410
    Top = 115
    Width = 169
    Height = 20
    Caption = #1056#1072#1089#1096#1080#1088#1077#1085#1080#1103' '#1092#1072#1081#1083#1086#1074
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 4
    OnClick = CheckBoxFileExtensionClick
  end
  object EditRenameFile: TEdit
    Left = 540
    Top = 550
    Width = 121
    Height = 22
    TabOrder = 7
  end
  object ButtonRenameFile: TButton
    Left = 540
    Top = 515
    Width = 120
    Height = 30
    Caption = #1055#1077#1088#1077#1080#1084#1077#1085#1086#1074#1072#1090#1100
    TabOrder = 6
    OnClick = ButtonRenameFileClick
  end
  object ButtonOpenFile: TButton
    Left = 420
    Top = 515
    Width = 100
    Height = 30
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 10
    OnClick = ButtonOpenFileClick
  end
  object ButtonDeleteFile: TButton
    Left = 420
    Top = 550
    Width = 100
    Height = 30
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 5
    OnClick = ButtonDeleteFileClick
  end
  object Panel2: TPanel
    Left = 10
    Top = 480
    Width = 380
    Height = 110
    BevelOuter = bvNone
    BorderWidth = 1
    BorderStyle = bsSingle
    TabOrder = 12
    object LabelPathFolder: TLabel
      Left = 10
      Top = 8
      Width = 108
      Height = 16
      Caption = 'E:\Course_Project'
      Constraints.MaxWidth = 360
    end
    object ButtonDeleteFolder: TButton
      Left = 144
      Top = 39
      Width = 120
      Height = 30
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1087#1072#1087#1082#1091
      Enabled = False
      TabOrder = 0
      OnClick = ButtonDeleteFolderClick
    end
  end
  object Button1: TButton
    Left = 24
    Top = 520
    Width = 120
    Height = 30
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1087#1072#1087#1082#1091
    TabOrder = 8
    OnClick = Button1Click
  end
  object EditCreateFolder: TEdit
    Left = 24
    Top = 560
    Width = 120
    Height = 22
    TabOrder = 9
  end
  object ButtonCreateFile: TButton
    Left = 680
    Top = 515
    Width = 100
    Height = 30
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 13
    OnClick = ButtonCreateFileClick
  end
  object EditFileCreate: TEdit
    Left = 680
    Top = 550
    Width = 100
    Height = 22
    TabOrder = 14
  end
  object PanelHeader: TPanel
    Left = 10
    Top = 10
    Width = 780
    Height = 90
    BevelOuter = bvNone
    BorderWidth = 1
    BorderStyle = bsSingle
    TabOrder = 15
  end
  object ButtonUpdate: TButton
    Left = 290
    Top = 110
    Width = 100
    Height = 30
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100
    TabOrder = 16
    OnClick = ButtonUpdateClick
  end
end
