//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TLabel *Poziom2;
        TLabel *Label1;
        TLabel *Pytanie1;
        TLabel *Odpa1;
        TLabel *Odpb1;
        TLabel *Odpc1;
        TLabel *Odpd1;
        TButton *sprawdz1;
        TLabel *Label2;
        TButton *KoniecPoziomu2;
        TLabel *Label3;
        TButton *Restart;
        TImage *przegrana;
        TImage *zwyciestwo;
        TImage *Konrad;
        TImage *Pomocnicze;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Odpa1Click(TObject *Sender);
        void __fastcall Odpb1Click(TObject *Sender);
        void __fastcall Odpc1Click(TObject *Sender);
        void __fastcall Odpd1Click(TObject *Sender);
        void __fastcall sprawdz1Click(TObject *Sender);
        void __fastcall KoniecPoziomu2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
