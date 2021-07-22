#pragma once
#include "Juego.h"
#include "Nivel2.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int r;
		int ctd;
		int ctd2; 
		int segundos;
		int minutos;
		bool si = false;
	private: System::Windows::Forms::Label^  lblTiempo;

	private: System::Windows::Forms::Label^  lblVidas;


			 
	public:
		MyForm(void)
		{
			segundos = 0;
			minutos = 0;
			InitializeComponent();
			g = this->CreateGraphics();
			juego = new Juego();

			T = gcnew Bitmap("mc.png");
			E = gcnew Bitmap("ENEMIGO_MUNDO2_Alfa.png");
			A = gcnew Bitmap("enemigo.png");
			bmpSuelo = gcnew Bitmap("pasto.png");
			bmpSolido = gcnew Bitmap("arbol.png");
			bmpDestruible = gcnew Bitmap("tronco.png");
			H = gcnew Bitmap("Hada.png");
			ctd = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
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
			 Bitmap ^H;
			 Bitmap ^T;
			 Bitmap ^E;
			 Bitmap ^A;
			 Bitmap ^bmpSuelo;
			 Bitmap ^bmpSolido;
			 Bitmap ^bmpDestruible;

			 Juego *juego;
	private: System::Windows::Forms::Label^  lblpuntos;
	private: System::Windows::Forms::Button^  btnNivel2;


	private: System::Windows::Forms::Button^  btnNivel1;

			 Juego *juego1;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblpuntos = (gcnew System::Windows::Forms::Label());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::Black;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Stencil", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->Location = System::Drawing::Point(754, 68);
			this->lblVidas->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(78, 24);
			this->lblVidas->TabIndex = 5;
			this->lblVidas->Text = L"Vidas:";
			this->lblVidas->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
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
			this->lblpuntos->Click += gcnew System::EventHandler(this, &MyForm::lblpuntos_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnNivel2->Enabled = false;
			this->btnNivel2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnNivel2->Location = System::Drawing::Point(96, 254);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(321, 109);
			this->btnNivel2->TabIndex = 1;
			this->btnNivel2->Text = L"Presione para entrar al Nivel 2";
			this->btnNivel2->UseVisualStyleBackColor = false;
			this->btnNivel2->Visible = false;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &MyForm::btnNivel2_Click);
			// 
			// btnNivel1
			// 
			this->btnNivel1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnNivel1->Enabled = false;
			this->btnNivel1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnNivel1->Location = System::Drawing::Point(462, 254);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(321, 109);
			this->btnNivel1->TabIndex = 4;
			this->btnNivel1->Text = L"Presione Para repetir el nivel 1";
			this->btnNivel1->UseVisualStyleBackColor = false;
			this->btnNivel1->Visible = false;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Stencil", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(758, 109);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(97, 24);
			this->lblTiempo->TabIndex = 6;
			this->lblTiempo->Text = L"Tiempo:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(963, 1045);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->btnNivel1);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->lblpuntos);
			this->ForeColor = System::Drawing::Color::Yellow;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResizeBegin += gcnew System::EventHandler(this, &MyForm::Wenas);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Presionado);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		juego->CambiarNivel();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		lblpuntos->Text = "Puntos: " + juego->Get_Puntos();
		lblVidas->Text = "Vidas: " + juego->Get_vidas();

		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);

		ctd++;
		ctd2++;
		

		juego->dibujar(bf->Graphics,bmpSuelo,bmpSolido,bmpDestruible);

		if (ctd2%7 == 0 ) {
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
		nivel_usado = 1;
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

		if (juego->GetEnemigos() + juego->GetEnemigos1() == 0){
			btnNivel2->Visible = true;
			btnNivel2->Enabled = true;
			btnNivel1->Enabled = true;
			btnNivel1->Visible = true;
		}
		if (juego->Get_vidas() == 0) {
			btnNivel2->Visible = false;
			btnNivel2->Enabled = false;
			btnNivel1->Enabled = true;
			btnNivel1->Visible = true;
		}

		if (minutos == 5) {
			btnNivel2->Visible = false;
			btnNivel2->Enabled = false;
			btnNivel1->Enabled = true;
			btnNivel1->Visible = true;
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

private: System::Void btnNivel2_Click(System::Object^  sender, System::EventArgs^  e) {

	Nivel2 ^Formulario_que_contiene_el_nivel2 = gcnew Nivel2();
	Formulario_que_contiene_el_nivel2->ShowDialog();
	Close();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm ^Formulario_que_contiene_el_nivel1 = gcnew MyForm();
	Formulario_que_contiene_el_nivel1->ShowDialog();
	Close();
}
private: System::Void lblpuntos_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}

};
}
