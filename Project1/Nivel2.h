#pragma once
#include "Juego.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nivel2
	/// </summary>
	public ref class Nivel2 : public System::Windows::Forms::Form
	{
	private:
		int ctd;
		int r;
		int ctd2;
		int segundos;
		int minutos;
	private: System::Windows::Forms::Label^  lblTiempo;
			 bool si = false;
	public:
		Nivel2(void)
		{
			segundos = 0;
			minutos = 0;
			InitializeComponent();
			g = this->CreateGraphics();
			juego = new Juego();
			
			T = gcnew Bitmap("mc.png");
			E = gcnew Bitmap("enemigo_mundo_2.png");
			A = gcnew Bitmap("Enemigo_beta_mundo_2.png");
			H = gcnew Bitmap("ayuda.png");
			bmpSuelo = gcnew Bitmap("Piso.png");
			bmpEdificio = gcnew Bitmap("edificio.png");
			bmpFuente = gcnew Bitmap("Fuente.png");
			ctd = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Nivel2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: Graphics ^g;
			 Graphics ^gr;
	private: System::Windows::Forms::Timer^  timer1;

			 Bitmap ^T;
			 Bitmap ^E;
			 Bitmap ^A;
			 Bitmap ^H;
			 Bitmap ^bmpSuelo;
			 Bitmap ^bmpEdificio;
			 Bitmap ^bmpFuente;

			 Juego *juego;
	private: System::Windows::Forms::Label^  lblpuntos;
	private: System::Windows::Forms::Label^  Vidas2;
			 Juego *juego1;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->lblpuntos = (gcnew System::Windows::Forms::Label());
				 this->Vidas2 = (gcnew System::Windows::Forms::Label());
				 this->lblTiempo = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2::timer1_Tick);
				 // 
				 // lblpuntos
				 // 
				 this->lblpuntos->AutoSize = true;
				 this->lblpuntos->BackColor = System::Drawing::Color::Black;
				 this->lblpuntos->Font = (gcnew System::Drawing::Font(L"Stencil", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblpuntos->ForeColor = System::Drawing::Color::Yellow;
				 this->lblpuntos->Location = System::Drawing::Point(754, 28);
				 this->lblpuntos->Name = L"lblpuntos";
				 this->lblpuntos->Size = System::Drawing::Size(105, 24);
				 this->lblpuntos->TabIndex = 0;
				 this->lblpuntos->Text = L"Puntos: ";
				 // 
				 // Vidas2
				 // 
				 this->Vidas2->AutoSize = true;
				 this->Vidas2->BackColor = System::Drawing::Color::Black;
				 this->Vidas2->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Vidas2->ForeColor = System::Drawing::Color::Yellow;
				 this->Vidas2->Location = System::Drawing::Point(759, 77);
				 this->Vidas2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->Vidas2->Name = L"Vidas2";
				 this->Vidas2->Size = System::Drawing::Size(78, 24);
				 this->Vidas2->TabIndex = 1;
				 this->Vidas2->Text = L"Vidas:";
				 this->Vidas2->Click += gcnew System::EventHandler(this, &Nivel2::Vidas2_Click);
				 // 
				 // lblTiempo
				 // 
				 this->lblTiempo->AutoSize = true;
				 this->lblTiempo->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
				 this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Stencil", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblTiempo->ForeColor = System::Drawing::Color::Yellow;
				 this->lblTiempo->Location = System::Drawing::Point(758, 128);
				 this->lblTiempo->Name = L"lblTiempo";
				 this->lblTiempo->Size = System::Drawing::Size(103, 24);
				 this->lblTiempo->TabIndex = 2;
				 this->lblTiempo->Text = L"Tiempo: ";
				 // 
				 // Nivel2
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(902, 1045);
				 this->Controls->Add(this->lblTiempo);
				 this->Controls->Add(this->Vidas2);
				 this->Controls->Add(this->lblpuntos);
				 this->Name = L"Nivel2";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Nivel2";
				 this->Load += gcnew System::EventHandler(this, &Nivel2::Nivel2_Load);
				 this->ResizeBegin += gcnew System::EventHandler(this, &Nivel2::Wenas);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2::Presionado);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void Nivel2_Load(System::Object^  sender, System::EventArgs^  e) {
		juego->CambiarNivel2();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		lblpuntos->Text = "Puntos: " + juego->Get_Puntos();
		Vidas2->Text = "Vidas " + juego->Get_vidas();

		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);

		ctd++;
		ctd2++;

		juego->dibujar2(bf->Graphics, bmpEdificio, bmpSuelo , bmpFuente);

		if (ctd2 % 7 == 0) {
			segundos++;
			if (segundos == 60) {
				segundos = 0;
				minutos++;
			}
		}
		lblTiempo->Text = "Tiempo:   " + minutos + " : " + segundos;


		if (ctd<= 25)
		juego->MostrarAlfas(bf->Graphics, E);
		if (ctd == 55)
			ctd = 0;
		int nivel_usado;
		nivel_usado = 2;
		juego->MostrarJugador(bf->Graphics, T, nivel_usado);
		juego->MostrarBetas(bf->Graphics, A);

		r = rand() % 50;
		if (r == 15)
			si = true;
		if (si == true && juego->Get_algo() == true) {
			juego->DibujarHada(bf->Graphics, H);
			juego->MoverHada(g);
		}

		if (juego->Get_Puntos() != 20) {
			juego->MoverAlfas(g);
		}

		bf->Render(g);
		delete bf, bfc;


		juego->MoverBetas(g);
		juego->moverBalas();
		juego->Colisiones();
		if (juego->GetEnemigos() + juego->GetEnemigos1() == 0) {
			Close();
		}

		if (minutos == 5) {
			Close();
		}

	}
	private: System::Void Presionado(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		juego->MoverJugador(e->KeyCode, g);
		if (e->KeyCode == Keys::Space)
			juego->Disparar();
	}
	private: System::Void Wenas(System::Object^  sender, System::EventArgs^  e) {
		g = this->CreateGraphics();

	}

	private: System::Void Vidas2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
