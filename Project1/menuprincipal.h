#pragma once
#include "Myform.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnJugar;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->Location = System::Drawing::Point(599, 38);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(121, 29);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnJugar_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(732, 449);
			this->Controls->Add(this->btnJugar);
			this->DoubleBuffered = true;
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnJugar_Click(System::Object^  sender, System::EventArgs^  e) {
		
		MyForm ^Formulario_que_contiene_el_nivel1 = gcnew MyForm();
		Formulario_que_contiene_el_nivel1->ShowDialog();
		this->Hide();
	}
	private: System::Void MenuPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
