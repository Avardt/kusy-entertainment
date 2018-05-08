//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TImage *scianal;
        TImage *scianap;
        TImage *scianag;
        TImage *scianad;
        TImage *p2;
        TImage *p20;
        TImage *p5;
        TImage *p16;
        TImage *p1;
        TImage *p4;
        TImage *p3;
        TImage *p7;
        TImage *p8;
        TImage *p9;
        TImage *p10;
        TImage *p11;
        TImage *p12;
        TImage *p13;
        TImage *p14;
        TImage *p15;
        TImage *p19;
        TImage *p6;
        TImage *p21;
        TImage *p22;
        TImage *p23;
        TImage *p24;
        TImage *p18;
        TImage *p25;
        TImage *p26;
        TImage *p27;
        TImage *p28;
        TImage *pietrek;
        TTimer *pietrektimer;
        TTimer *lewo;
        TTimer *prawo;
        TTimer *gora;
        TTimer *dol;
        TButton *restart8;
        TImage *p17;
        TImage *p29;
        TImage *tlo_inst;
        TLabel *Punkty_sp;
        TButton *ZakonczGre;
        TImage *Image1;
        TImage *zli1;
        TImage *zli2;
        TImage *zli3;
        TImage *zli4;
        void __fastcall lewoTimer(TObject *Sender);
        void __fastcall prawoTimer(TObject *Sender);
        void __fastcall goraTimer(TObject *Sender);
        void __fastcall dolTimer(TObject *Sender);
        void __fastcall restart8Click(TObject *Sender);
        void __fastcall pietrektimerTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ZakonczGreClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
