//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSplashForm::SplashTimerTimer(TObject *Sender)
{
    SplashTimer->Enabled= false;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSplashForm::FormCreate(TObject *Sender)
{
    AnsiString SplashLogo = "SplashLogo.jpg";
    ImageSplash->Picture->LoadFromFile(SplashLogo);
}
//---------------------------------------------------------------------------

