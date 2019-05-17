#pragma once
#include "DataManager.h"
#include "DotNetUtilities.h"
#include "Powell.h"
#include "Newton.h"
#define THRESOLD 10E-8
//#define DEBUG


namespace Optimization {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			//
			//TODO:  在此加入建構函式程式碼
			initialY->Enabled = false;
			Y1->Enabled = false;
			Y2->Enabled = false;
			//
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	public:

	private: System::Windows::Forms::Label^  OutputText;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::TextBox^  Output;






	private: System::Windows::Forms::Label^  InputText;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::CheckBox^  two;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  initialX;
	private: System::Windows::Forms::TextBox^  initialY;
	private: System::Windows::Forms::TextBox^  X1;
	private: System::Windows::Forms::TextBox^  Y1;
	private: System::Windows::Forms::TextBox^  X2;
	private: System::Windows::Forms::TextBox^  Y2;
	protected:
		/// <summary>
		DataManager* dataManager;
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadEquationsToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		String^ userInput;
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEquationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->InputText = (gcnew System::Windows::Forms::Label());
			this->OutputText = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->two = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->initialX = (gcnew System::Windows::Forms::TextBox());
			this->initialY = (gcnew System::Windows::Forms::TextBox());
			this->X1 = (gcnew System::Windows::Forms::TextBox());
			this->Y1 = (gcnew System::Windows::Forms::TextBox());
			this->X2 = (gcnew System::Windows::Forms::TextBox());
			this->Y2 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->menuStrip1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 95)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(734, 860);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(734, 27);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadEquationsToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(45, 23);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadEquationsToolStripMenuItem
			// 
			this->loadEquationsToolStripMenuItem->Name = L"loadEquationsToolStripMenuItem";
			this->loadEquationsToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			this->loadEquationsToolStripMenuItem->Text = L"Load Equations";
			this->loadEquationsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadEquationsToolStripMenuItem_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->Output, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->InputText, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->OutputText, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->Input, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 46);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 5;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(728, 811);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// Output
			// 
			this->Output->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Output->Location = System::Drawing::Point(3, 379);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(722, 429);
			this->Output->TabIndex = 3;
			// 
			// InputText
			// 
			this->InputText->AutoSize = true;
			this->InputText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InputText->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->InputText->Location = System::Drawing::Point(3, 150);
			this->InputText->Name = L"InputText";
			this->InputText->Size = System::Drawing::Size(722, 20);
			this->InputText->TabIndex = 0;
			this->InputText->Text = L"Input";
			// 
			// OutputText
			// 
			this->OutputText->AutoSize = true;
			this->OutputText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->OutputText->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->OutputText->Location = System::Drawing::Point(3, 356);
			this->OutputText->Name = L"OutputText";
			this->OutputText->Size = System::Drawing::Size(722, 20);
			this->OutputText->TabIndex = 1;
			this->OutputText->Text = L"Output";
			// 
			// Input
			// 
			this->Input->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Input->Location = System::Drawing::Point(3, 173);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(722, 180);
			this->Input->TabIndex = 2;
			this->Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Input_TextChanged);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 5;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				40)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33223F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33223F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33554F)));
			this->tableLayoutPanel4->Controls->Add(this->two, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->label1, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label2, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->label4, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->initialX, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->initialY, 2, 2);
			this->tableLayoutPanel4->Controls->Add(this->X1, 3, 1);
			this->tableLayoutPanel4->Controls->Add(this->Y1, 3, 2);
			this->tableLayoutPanel4->Controls->Add(this->X2, 4, 1);
			this->tableLayoutPanel4->Controls->Add(this->Y2, 4, 2);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(722, 144);
			this->tableLayoutPanel4->TabIndex = 5;
			// 
			// two
			// 
			this->two->AutoSize = true;
			this->two->Font = (gcnew System::Drawing::Font(L"新細明體", 14));
			this->two->Location = System::Drawing::Point(3, 99);
			this->two->Name = L"two";
			this->two->Size = System::Drawing::Size(70, 28);
			this->two->TabIndex = 0;
			this->two->Text = L"X,Y";
			this->two->UseVisualStyleBackColor = true;
			this->two->CheckedChanged += gcnew System::EventHandler(this, &MyForm::two_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 15));
			this->label1->Location = System::Drawing::Point(93, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 15));
			this->label2->Location = System::Drawing::Point(93, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 14));
			this->label3->Location = System::Drawing::Point(133, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"InitialPoint";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 15));
			this->label4->Location = System::Drawing::Point(330, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Interval";
			// 
			// initialX
			// 
			this->initialX->Dock = System::Windows::Forms::DockStyle::Fill;
			this->initialX->Location = System::Drawing::Point(133, 51);
			this->initialX->Multiline = true;
			this->initialX->Name = L"initialX";
			this->initialX->Size = System::Drawing::Size(191, 42);
			this->initialX->TabIndex = 5;
			// 
			// initialY
			// 
			this->initialY->Dock = System::Windows::Forms::DockStyle::Fill;
			this->initialY->Location = System::Drawing::Point(133, 99);
			this->initialY->Multiline = true;
			this->initialY->Name = L"initialY";
			this->initialY->Size = System::Drawing::Size(191, 42);
			this->initialY->TabIndex = 6;
			// 
			// X1
			// 
			this->X1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->X1->Location = System::Drawing::Point(330, 51);
			this->X1->Multiline = true;
			this->X1->Name = L"X1";
			this->X1->Size = System::Drawing::Size(191, 42);
			this->X1->TabIndex = 7;
			// 
			// Y1
			// 
			this->Y1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Y1->Location = System::Drawing::Point(330, 99);
			this->Y1->Multiline = true;
			this->Y1->Name = L"Y1";
			this->Y1->Size = System::Drawing::Size(191, 42);
			this->Y1->TabIndex = 8;
			// 
			// X2
			// 
			this->X2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->X2->Location = System::Drawing::Point(527, 51);
			this->X2->Multiline = true;
			this->X2->Name = L"X2";
			this->X2->Size = System::Drawing::Size(192, 42);
			this->X2->TabIndex = 9;
			// 
			// Y2
			// 
			this->Y2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Y2->Location = System::Drawing::Point(527, 99);
			this->Y2->Multiline = true;
			this->Y2->Name = L"Y2";
			this->Y2->Size = System::Drawing::Size(192, 42);
			this->Y2->TabIndex = 10;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 860);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Optimization";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void loadEquationsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
	}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadEquationData())
	{
		std::vector<std::string> equations = dataManager->GetEquations();
		for (unsigned int i = 0; i < equations.size(); i++)
		{
			Output->Text += "Equation" + i + "  " + gcnew String(equations[i].c_str());
			Output->Text += Environment::NewLine;
		}
//#define DEBUG
#ifdef DEBUG
		std::vector<std::vector<std::string>> postequs = dataManager->GetPostEqs();
		Output->Text += "PostEquation = ";
		for (unsigned int i = 0; i < postequs.size(); ++i)
		{
			for (unsigned int j = 0; j < postequs[i].size(); ++j)
			{
				Output->Text += gcnew String(postequs[i][j].c_str());
			}
			Output->Text += Environment::NewLine;
		}
#endif // DEBUG

//#define DEBUG
#ifdef DEBUG
		Powell powell;
		powell.EquationIndex = 3;
		powell.posteq = dataManager->GetPostEqs();
		Output->Text += powell.FunctionValue(5,0) + Environment::NewLine;
#endif // DEBUG


	}
}
private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	// Get Equations
	std::vector<std::string> equations = dataManager->GetEquations();
	if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
	{
		array<String^> ^userCommand = userInput->Split(' ');
		if (userCommand[0] == "clear")
		{
			Input->Clear();
		}
		else if (userCommand[0] == "Command")
		{
			Output->Text += "Equation Number(ex. 1) + Powell, Newton, Steep, Quasi, Conjugate" + Environment::NewLine;
		}
		else if(userCommand->Length == 2)
		{
			bool HasEqu = false;
			// userCommand[0] = EquationNumber
			std::string temp;
			MarshalString(userCommand[0], temp);
			for (unsigned int i = 0; i < equations.size(); ++i)
			{
				if (atoi(temp.c_str()) == i)
				{
					HasEqu = true;
					// userCommand[1] = Method
					if (userCommand[1] == "Powell")
					{
						Powell powell;
						powell.EquationIndex = i;
						powell.posteq = dataManager->GetPostEqs();
						powell.original = dataManager->GetEquations();
						double xi, yi, xlow, xhi, ylow, yhi, last, alpha;
						std::string temp;
						MarshalString(initialX->Text, temp);
						xi = atoi(temp.c_str());
						MarshalString(X1->Text, temp);
						xlow = atoi(temp.c_str());
						MarshalString(X2->Text, temp);
						xhi = atoi(temp.c_str());
						if (two->Checked)
						{
							MarshalString(initialY->Text, temp);
							yi = atoi(temp.c_str());
							MarshalString(Y1->Text, temp);
							ylow = atoi(temp.c_str());
							MarshalString(Y2->Text, temp);
							yhi = atoi(temp.c_str());
							// THRESOLD
							int thre = 200;
							// 紀錄步驟
							int stepi, stepj;
							stepi = stepj = 1;
							// Initialize
							double base[2][2] = { (1,0),(0,1) };
							last = powell.FunctionValue(xi, yi);
							while (1)
							{
								
								--thre;
								if (!thre)
									break;
							}
						}
						else
						{
							
						}
					}
					else if (userCommand[1] == "Newton")
					{

					}
					else if (userCommand[1] == "Steep")
					{

					}
					else if (userCommand[1] == "Quasi")
					{

					}
					else if (userCommand[1] == "Conjugate")
					{

					}
					break;
				}
			}
			if (!HasEqu)
				Output->Text += "Equation Not Found！！" + Environment::NewLine;
		}
		//判斷找不到指令
		else
		{
			Output->Text += "-Command not found-" + Environment::NewLine;
		}
	}
	else
	{
		//將使用者輸入字串(在Text box中)，依'\n'作切割
		array<String^> ^userCommand = Input->Text->Split('\n');
		//並將最後一行，作為目前使用者輸入指令
		userInput = userCommand[userCommand->Length - 1];
	}
}
private: System::Void two_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	initialY->Enabled = !initialY->Enabled;
	Y1->Enabled = !Y1->Enabled;
	Y2->Enabled = !Y2->Enabled;
}
};
}