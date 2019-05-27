#pragma once
#include <algorithm>
#include "DataManager.h"
#include "DotNetUtilities.h"
#include "Powell.h"
#include "Vector.h"
#include "Matrix.h"
#include "Equation.h"
#define THRESOLD 10E-8
#define THRESOLD2 10E-6
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
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
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
	Output->Clear();
	//從讀取讀取向量資料
	if (dataManager->LoadEquationData())
	{
		std::vector<std::string> equations = dataManager->GetEquations();
		for (unsigned int i = 0; i < equations.size(); i++)
		{
			Output->Text += "Equation" + i + "  " + gcnew String(equations[i].c_str());
			Output->Text += Environment::NewLine;
		}
	}
}
private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	// Get Equations
	std::vector<std::string> equations = dataManager->GetEquations();
	if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
	{
		array<String^> ^userCommand = userInput->Split(' ');
		try {
			if (userCommand[0] == "clear")
			{
				Input->Clear();
				Output->Clear();
				for (unsigned int i = 0; i < equations.size(); i++)
				{
					Output->Text += "Equation" + i + "  " + gcnew String(equations[i].c_str());
					Output->Text += Environment::NewLine;
				}
			}
			else if (userCommand[0] == "Command")
			{
				Output->Text += "Equation Number(ex. 1) + Powell, Newton, Steep, Quasi, Conjugate" + Environment::NewLine;
			}
			else if (userCommand->Length == 2)
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
							double xi, yi, xlow, xhi, ylow, yhi, alpha;
							std::string temp;
							MarshalString(initialX->Text, temp);
							xi = std::stod(temp);
							MarshalString(X1->Text, temp);
							xlow = std::stod(temp);
							MarshalString(X2->Text, temp);
							xhi = std::stod(temp);
							// Limit
							int thre = 200;
							// 紀錄步驟
							int stepi, stepj;
							stepi = stepj = 1;
							if (two->Checked)
							{
								MarshalString(initialY->Text, temp);
								yi = std::stod(temp);
								MarshalString(Y1->Text, temp);
								ylow = std::stod(temp);
								MarshalString(Y2->Text, temp);
								yhi = std::stod(temp);
								// Initialize
								double x1, x2, x3, y1, y2, y3, bx1 = 1, by1 = 0, bx2 = 0, by2 = 1, bx3, by3, com1, com2;
								std::vector<double> golden;
								std::vector<double> Alphas;
								golden.clear(); Alphas.clear();
								while (1)
								{
									// Output
									Output->Text += "j = " + stepj + Environment::NewLine;
									Output->Text += "i = " + stepi + Environment::NewLine;
									Output->Text += "X1 = [ " + xi + " " + yi + "]" + Environment::NewLine;
									if (stepj > 1)
									{
										bx1 = bx2; by1 = by2; bx2 = bx3; by2 = by3;
									}
									// X1 (xi, yi)
									double goldena, goldenc, g[4];
									g[0] = (xhi - xi) / bx1;
									g[1] = (xlow - xi) / bx1;
									g[2] = (yhi - yi) / by1;
									g[3] = (ylow - yi) / by1;
									golden.insert(golden.end(), g, g + 4);
									std::sort(golden.begin(), golden.end());
									std::string alp1, alp2;
									std::ostringstream ss;
									ss << xi;
									alp1 = ss.str();
									ss.str("");
									ss << abs(bx1);
									if (bx1 > 0)
									{
										alp1 += "+a*" + ss.str();
									}
									else
									{
										alp1 += "-a*" + ss.str();
									}
									ss.str("");
									ss << yi;
									alp2 = ss.str();
									ss.str("");
									ss << abs(by1);
									if (by1 > 0)
									{
										alp2 += "+a*" + ss.str();
									}
									else
									{
										alp2 += "-a*" + ss.str();
									}
									powell.GEquation = dataManager->InfixToPost(powell.ChangeEq(alp1, alp2));
									// alpha interval
									goldena = golden[1];
									goldenc = golden[2];
									golden.clear();
									alpha = powell.GoldenSearch(goldena, (goldena + goldenc) / 2, goldenc);
									Alphas.push_back(alpha);
									// X2 (x1, y1)
									x1 = xi + bx1 * alpha;
									y1 = yi + by1 * alpha;
									g[0] = (xhi - x1) / bx2;
									g[1] = (xlow - x1) / bx2;
									g[2] = (yhi - y1) / by2;
									g[3] = (ylow - y1) / by2;
									golden.insert(golden.end(), g, g + 4);
									std::sort(golden.begin(), golden.end());
									ss.str("");
									ss << x1;
									alp1 = ss.str();
									ss.str("");
									ss << abs(bx2);
									if (bx2 > 0)
									{
										alp1 += "+a*" + ss.str();
									}
									else
									{
										alp1 += "-a*" + ss.str();
									}
									ss.str("");
									ss << y1;
									alp2 = ss.str();
									ss.str("");
									ss << abs(by2);
									if (by2 > 0)
									{
										alp2 += "+a*" + ss.str();
									}
									else
									{
										alp2 += "-a*" + ss.str();
									}
									powell.GEquation = dataManager->InfixToPost(powell.ChangeEq(alp1, alp2));
									// alpha interval
									goldena = golden[1];
									goldenc = golden[2];
									golden.clear();
									alpha = powell.GoldenSearch(goldena, (goldena + goldenc) / 2, goldenc);
									Alphas.push_back(alpha);
									// X3 (x2, y2)
									x2 = x1 + by1 * alpha;
									y2 = y1 + by2 * alpha;
									// First Compare
									com1 = powell.FunctionValue(x2, y2, 0);
									bx3 = bx1 * Alphas[0] + bx2 * Alphas[1];
									by3 = by1 * Alphas[0] + by2 * Alphas[1];
									g[0] = (xhi - x2) / bx3;
									g[1] = (xlow - x2) / bx3;
									g[2] = (yhi - y2) / by3;
									g[3] = (ylow - y2) / by3;
									golden.insert(golden.end(), g, g + 4);
									std::sort(golden.begin(), golden.end());
									ss.str("");
									ss << x2;
									alp1 = ss.str();
									ss.str("");
									ss << abs(bx3);
									if (bx3 > 0)
									{
										alp1 += "+a*" + ss.str();
									}
									else
									{
										alp1 += "-a*" + ss.str();
									}
									ss.str("");
									ss << y2;
									alp2 = ss.str();
									ss.str("");
									ss << abs(by3);
									if (by3 > 0)
									{
										alp2 += "+a*" + ss.str();
									}
									else
									{
										alp2 += "-a*" + ss.str();
									}
									powell.GEquation = dataManager->InfixToPost(powell.ChangeEq(alp1, alp2));
									// alpha interval
									goldena = golden[1];
									goldenc = golden[2];
									golden.clear();
									alpha = powell.GoldenSearch(goldena, (goldena + goldenc) / 2, goldenc);
									x3 = x2 + bx3 * alpha;
									y3 = y2 + by3 * alpha;
									// Second Compare
									com2 = powell.FunctionValue(x3, y3, 0);
									xi = x3;
									yi = y3;
									// Output
									Output->Text += "X2 = [ " + x1 + " " + y1 + "]" + Environment::NewLine;
									Output->Text += "i = " + ++stepi + Environment::NewLine;
									Output->Text += "X2 = [ " + x1 + " " + y1 + "]" + Environment::NewLine;
									Output->Text += "X3 = [ " + x2 + " " + y2 + "]" + Environment::NewLine;
									Output->Text += "alpha = " + alpha + Environment::NewLine;
									Output->Text += "S3 = [ " + bx3 + " " + by3 + "]" + Environment::NewLine;
									Output->Text += "X4 = [ " + x3 + " " + y3 + "]" + Environment::NewLine;
									Output->Text += Environment::NewLine;

									Alphas.clear();
									if (abs(com1 - com2) < THRESOLD)
									{
										break;
									}
									--thre;
									if (!thre)
										break;
									stepi = 1;
									++stepj;
								}
								Output->Text += "[x,y] = " + "[ " + x3 + ", " + y3 + " ] " + Environment::NewLine;
								Output->Text += "min = " + com2 + Environment::NewLine;
							}
							else
							{
								// Initialize
								double x1, x2, bx1 = 1, bx2;
								std::vector<double> golden;
								while (1)
								{
									// Output
									Output->Text += "j = " + stepj + Environment::NewLine;
									Output->Text += "i = " + stepi + Environment::NewLine;
									Output->Text += "X1 = [ " + xi + "]" + Environment::NewLine;
									if (stepj != 1)
									{
										bx1 = bx2;
									}
									// X1
									double goldena, goldenc;
									golden.push_back((xhi - xi) / bx1);
									golden.push_back((xlow - xi) / bx1);
									std::sort(golden.begin(), golden.end());
									goldena = golden[0]; goldenc = golden[1];
									golden.clear();
									// Golden String
									std::ostringstream ss;
									std::string alph1, alph2;
									ss << xi;
									alph1 = ss.str();
									ss.str("");
									ss << abs(bx1);
									if (bx1 > 0)
									{
										alph1 += "+a*" + ss.str();
									}
									else
									{
										alph1 += "-a*" + ss.str();
									}
									ss.str("");
									powell.GEquation = dataManager->InfixToPost(powell.ChangeEq(alph1, ""));
									alpha = powell.GoldenSearch(goldena, (goldena + goldenc) / 2, goldenc);
									x1 = xi + alpha * bx1;
									// bx2
									bx2 = alpha * bx1;
									golden.push_back((xhi - x1) / bx1);
									golden.push_back((xlow - x1) / bx1);
									std::sort(golden.begin(), golden.end());
									goldena = golden[0]; goldenc = golden[1];
									golden.clear();
									// Golden String
									ss << x1;
									alph2 = ss.str();
									ss.str("");
									ss << abs(bx2);
									if (bx2 > 0)
									{
										alph2 += "+a*" + ss.str();
									}
									else
									{
										alph2 += "-a*" + ss.str();
									}
									ss.str("");
									powell.GEquation = dataManager->InfixToPost(powell.ChangeEq(alph2, ""));
									alpha = powell.GoldenSearch(goldena, (goldena + goldenc) / 2, goldenc);
									x2 = x1 + alpha * bx2;
									// Output
									Output->Text += "X2 = [ " + x1 + "]" + Environment::NewLine;
									Output->Text += Environment::NewLine;
									Output->Text += "alpha = " + alpha + Environment::NewLine;
									Output->Text += "S2 = [ " + bx2 + "]" + Environment::NewLine;
									Output->Text += "X3 = [ " + x2 + "]" + Environment::NewLine;
									Output->Text += Environment::NewLine;
									if (abs(x1 - x2) < THRESOLD2)
										break;
									xi = x2;
									--thre;
									if (!thre)
										break;
									++stepj;
								}
								Output->Text += "[x] = " + x1 + Environment::NewLine;
								Output->Text += "min = " + powell.FunctionValue(x1, 0, 0) + Environment::NewLine;
							}
						}
						else if (userCommand[1] == "Newton")
						{
							int thre = 200;
							// initial
							Equation equation;
							equation.EquIndex = i;
							equation.original = dataManager->GetEquations();
							equation.postEqu = dataManager->InfixToPost(equation.original[equation.EquIndex]);
							equation.CheckSqrt();
							double xi, yi, x1, y1;
							std::string temp;
							MarshalString(initialX->Text, temp);
							xi = std::stod(temp);
							if (two->Checked)
							{
								// initial
								MarshalString(initialY->Text, temp);
								yi = std::stod(temp);
								Vector gradient;
								Matrix Gradient, hessianInv;
								while (1)
								{
									// Get Gradient
									gradient = equation.gradient(xi, yi, 0, 2);
									Gradient = gradient.ToMatrix();
									// Get Hessian
									equation.getHessian(xi, yi);
									// Output
									Output->Text += "Hessian = [ " + Environment::NewLine;
									Output->Text += equation.hessian.data[0][0] + " , " + equation.hessian.data[0][1] + Environment::NewLine;
									Output->Text += equation.hessian.data[1][0] + " , " + equation.hessian.data[1][1] + Environment::NewLine;
									Output->Text += "]" + Environment::NewLine;
									// xi+1
									// Hessian Inverse
									hessianInv = equation.hessian.inverse();
									// Output
									Output->Text += "Hessian Inverse = [ " + Environment::NewLine;
									Output->Text += hessianInv.data[0][0] + " , " + hessianInv.data[0][1] + Environment::NewLine;
									Output->Text += hessianInv.data[1][0] + " , " + hessianInv.data[1][1] + Environment::NewLine;
									Output->Text += "]" + Environment::NewLine;
									hessianInv = hessianInv * Gradient;
									// Boundary
									double flag1, flag2;
									flag1 = xi - hessianInv.data[0][0];
									flag2 = yi - hessianInv.data[1][0];
									while (equation.FunctionValue(flag1, flag2, 0) != equation.FunctionValue(flag1, flag2, 0))
									{
										hessianInv.data[0][0] *= 0.9;
										hessianInv.data[1][0] *= 0.9;
										flag1 = xi - hessianInv.data[0][0];
										flag2 = yi - hessianInv.data[1][0];
									}
									x1 = xi - hessianInv.data[0][0];
									y1 = yi - hessianInv.data[1][0];
									if (equation.HasSqrt)
									{
										if (x1 < 0)
											x1 = 10E-5;
										if (y1 < 0)
											y1 = 10E-5;
									}
									Output->Text += "x = [ " + x1 + " , " + yi + " ]" + Environment::NewLine;
									// Boundary
									if (abs(x1 - xi) < THRESOLD2 && abs(y1 - yi) < THRESOLD2)
										break;
									--thre;
									if (!thre)
										break;
									xi = x1;
									yi = y1;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x, y] = [ " + x1 + " , " + y1 + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(x1, y1, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
							else
							{
								// initial
								double gradient, hessian, hessianInv;
								Vector Gradient;
								while (1)
								{
									// Get Gradient
									Gradient = equation.gradient(xi, 0, 0, 1);
									gradient = Gradient.data[0];
									// Get Hessian
									hessian = equation.dif_xx(xi, 0, 10E-5);
									// Output
									Output->Text += "Hessian = [ " + Environment::NewLine;
									Output->Text += hessian + Environment::NewLine;
									Output->Text += "]" + Environment::NewLine;
									// Hessian Inverse
									hessianInv = 1 / hessian;
									// Output
									Output->Text += "Hessian Inverse = [ " + Environment::NewLine;
									Output->Text += hessianInv + Environment::NewLine;
									Output->Text += "]" + Environment::NewLine;
									// xi+1
									// Boundary
									double flag = xi - hessianInv * gradient;
									while (equation.FunctionValue(flag, 0, 0) != equation.FunctionValue(flag, 0, 0))
									{
										hessianInv *= 0.9;
										flag = xi - hessianInv * gradient;
									}
									x1 = xi - hessianInv * gradient;
									if (equation.HasSqrt)
									{
										if (x1 < 0)
											x1 = 10E-5;
									}
									Output->Text += "x = [ " + x1 + " ]" + Environment::NewLine;
									// THRESOLD
									if (abs(x1 - xi) < THRESOLD2)
										break;
									--thre;
									if (!thre)
										break;
									xi = x1;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x] = [ " + x1 + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(x1, 0, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
						}
						else if (userCommand[1] == "Steep")
						{
							int thre = 200, stepi = 0;
							// initial
							Equation equation;
							equation.EquIndex = i;
							equation.original = dataManager->GetEquations();
							equation.postEqu = dataManager->InfixToPost(equation.original[equation.EquIndex]);
							equation.CheckSqrt();
							double xi, yi;
							std::string temp;
							MarshalString(initialX->Text, temp);
							xi = std::stod(temp);
							Vector hi, h0, Xi;
							if (two->Checked)
							{
								// Initial
								MarshalString(initialY->Text, temp);
								yi = std::stod(temp);
								Xi.data.push_back(xi); 
								Xi.data.push_back(yi);
								h0 = equation.gradient(xi, yi, 0, 2);
								while (1)
								{
									Output->Text += "i = " + stepi + Environment::NewLine;
									Output->Text += "h = [ " + xi + " , " + yi + " ]" + Environment::NewLine;
									Vector lambda;
									// initial
									if (stepi != 0)
									{
										Xi.data.push_back(xi);
										Xi.data.push_back(yi);
									}
									// hi = -gradient
									hi = equation.gradient(xi, yi, 0, 2);
									for (unsigned int i = 0; i < hi.data.size(); ++i)
										hi.data[i] *= -1;
									// Compute step-size
									equation.getHessian(xi, yi);
									Matrix Hi = hi.ToMatrix();
									// Lambda
									lambda.data.push_back((Hi.trans() * Hi).data[0][0] / (Hi.trans() * equation.hessian * Hi).data[0][0]);
									Output->Text += "lambda = " + lambda.data[0] + Environment::NewLine;
									// f(x, y) = NAN?
									double flag1, flag2;
									flag1 = Xi.data[0] + lambda.data[0] * hi.data[0];
									flag2 = Xi.data[1] + lambda.data[0] * hi.data[1];
									while (equation.FunctionValue(flag1, flag2, 0) != equation.FunctionValue(flag1, flag2, 0))
									{
										lambda.data[0] *= 0.9;
										flag1 = Xi.data[0] + lambda.data[0] * hi.data[0];
										flag2 = Xi.data[1] + lambda.data[0] * hi.data[1];
									}
									// Xi+1
									Xi = Xi + lambda * hi;
									--thre;
									if (!thre)
										break;
									// Next
									xi = Xi.data[0];
									yi = Xi.data[1];
									if (equation.HasSqrt)
									{
										if (xi < 0)
											xi = 10E-5;
										if (yi < 0)
											yi = 10E-5;
									}
									Output->Text += "X = [ " + xi + " , " + yi + " ]" + Environment::NewLine;
									if (stepi != 0 && ((hi.norm() / h0.norm()) < THRESOLD))
										break;
									Xi.data.clear();
									++stepi;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x, y] = [ " + xi + ", " + yi + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(xi, yi, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
							else
							{
								Xi.data.push_back(xi);
								h0 = equation.gradient(xi, 0, 0, 1);
								double Lambda = 0;
								while (1)
								{
									Output->Text += "i = " + stepi + Environment::NewLine;
									Output->Text += "h = [ " + xi + " ]" + Environment::NewLine;
									Vector lambda;
									// initial
									if (stepi != 0)
									{
										Xi.data.push_back(xi);
									}
									// hi = -gradient
									hi = equation.gradient(xi, 0, 0, 1);
									hi.data[0] *= -1;
									// Compute step-size
									double hessian = equation.dif_xx(xi, 0, 10E-5);
									// Lambda
									Lambda = (hi.data[0] * hi.data[0]) / (hi.data[0] * hi.data[0] * hessian);
									lambda.data.push_back(Lambda);
									Output->Text += "lambda = " + Lambda + Environment::NewLine;
									// f(x) == NAN?
									double flag = (Xi + lambda * hi).data[0];
									while (equation.FunctionValue(flag, 0, 0) != equation.FunctionValue(flag, 0, 0))
									{
										lambda.data[0] *= 0.9;
										flag = (Xi + lambda * hi).data[0];
									}
									// Xi+1
									Xi = Xi + lambda * hi;
									--thre;
									if (!thre)
										break;
									// Next
									xi = Xi.data[0];
									if (equation.HasSqrt)
									{
										if (xi < 0)
											xi = 10E-5;
									}
									Output->Text += "X = [ " + xi + " ]" + Environment::NewLine;
									if (stepi != 0 && ((hi.norm() / h0.norm()) < THRESOLD))
										break;
									Xi.data.clear();
									++stepi;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x] = [ " + xi + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(xi, 0, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
						}
						else if (userCommand[1] == "Quasi")
						{
							int thre = 200, stepi = 0;
							// initial
							Equation equation;
							equation.EquIndex = i;
							equation.original = dataManager->GetEquations();
							equation.postEqu = dataManager->InfixToPost(equation.original[equation.EquIndex]);
							equation.CheckSqrt();
							double xi, yi, x1, y1, alpha;
							std::string temp;
							MarshalString(initialX->Text, temp);
							xi = std::stod(temp);
							Vector gradient, gradient_next;
							if (two->Checked)
							{
								Vector d, deltaX, deltaG;
								Matrix F, G, Dx, Dg;
								// initial
								MarshalString(initialY->Text, temp);
								yi = std::stod(temp);
								F = F.identityM(2);
								alpha = 1;
								while (1) 
								{
									if (stepi == 0)
									{
										Output->Text += "Initial Hessian: [" + Environment::NewLine;
										Output->Text += F.data[0][0] + " , " + F.data[0][1] + Environment::NewLine;
										Output->Text += F.data[1][0] + " , " + F.data[1][1] + Environment::NewLine;
										Output->Text += "]" + Environment::NewLine;
									}
									else
									{
										Output->Text += "Hessian: [" + Environment::NewLine;
										Output->Text += F.data[0][0] + " , " + F.data[0][1] + Environment::NewLine;
										Output->Text += F.data[1][0] + " , " + F.data[1][1] + Environment::NewLine;
										Output->Text += "]" + Environment::NewLine;
									}
									// Get Gradient, d
									gradient = equation.gradient(xi, yi, 0, 2);
									if (abs(gradient.data[0]) < THRESOLD2 && abs(gradient.data[1]) < THRESOLD2)
										break;
									// d(k) = -F(k)*g(k)
									d = gradient;
									G = gradient.ToMatrix();
									Matrix temp = F * G;
									d.data[0] = -temp.data[0][0];
									d.data[1] = -temp.data[1][0];
									// xi+1
									x1 = xi + alpha * d.data[0];
									y1 = yi + alpha * d.data[1];
									if (equation.HasSqrt)
									{
										if (x1 < 0)
											x1 = 10E-5;
										if (y1 < 0)
											y1 = 10E-5;
									}
									// Next Gradient
									gradient_next = equation.gradient(x1, y1, 0, 2);
									if (abs(gradient_next.data[0]) < THRESOLD2 && abs(gradient_next.data[1]) < THRESOLD2)
										break;
									// deltaX
									deltaX.data.push_back(alpha * d.data[0]);
									deltaX.data.push_back(alpha * d.data[1]);
									Dx = deltaX.ToMatrix();
									// deltaG
									deltaG = gradient_next - gradient;
									Dg = deltaG.ToMatrix();
									// New F(k+1)
									double tempX, tempG;
									tempX = (Dx.trans()*Dg).data[0][0];
									tempG = (Dg.trans() * F * Dg).data[0][0];
									Dx = Dx * Dx.trans();
									Dg = (F * Dg) * (F * Dg).trans();
									for (unsigned int j = 0; j < 2; ++j)
									{
										for (unsigned int k = 0; k < 2; ++k)
										{
											Dx.data[j][k] /= tempX;
											Dg.data[j][k] /= tempG;
										}
									}
									F = F + Dx - Dg;
									// Output
									if (stepi == 0)
									{
										Output->Text += "Initial Hessian inverse: [" + Environment::NewLine;
										Output->Text += F.data[0][0] + " , " + F.data[0][1] + Environment::NewLine;
										Output->Text += F.data[1][0] + " , " + F.data[1][1] + Environment::NewLine;
										Output->Text += "]" + Environment::NewLine;
									}
									Output->Text += "x = [ " + xi + " , " + yi + " ]" + Environment::NewLine;
									if (abs(xi - x1) < THRESOLD2 && abs(yi - y1) < THRESOLD2)
										break;
									deltaX.data.clear();
									deltaG.data.clear();
									xi = x1;
									yi = y1;
									alpha *= 0.85;
									++stepi;
									--thre;
									if (!thre)
										break;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x, y] = [ " + xi + ", " + yi + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(xi, yi, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
							else
							{
								double d, deltaX, deltaG, F;
								F = 1;
								alpha = 1;
								while (1)
								{
									if (stepi == 0)
									{
										Output->Text += "Initial Hessian: [" + Environment::NewLine;
										Output->Text += F + Environment::NewLine;
										Output->Text += "]" + Environment::NewLine;
									}
									else
									{
										Output->Text += "Initial Hessian Inverse: [" + Environment::NewLine;
										Output->Text += F + Environment::NewLine;
										Output->Text += "]" + Environment::NewLine;
									}
									// Get Gradient, d
									gradient = equation.gradient(xi, 0, 0, 1);
									if (abs(gradient.data[0]) < THRESOLD2)
										break;
									// d(k) = -F(k)*g(k)
									d = gradient.data[0];
									double temp = F * d;
									d = -temp;
									// xi+1
									x1 = xi + alpha * d;
									if (equation.HasSqrt)
									{
										if (x1 < 0)
											x1 = 10E-5;
									}
									// Next Gradient
									gradient_next = equation.gradient(x1, 0, 0, 1);
									if (abs(gradient_next.data[0]) < THRESOLD2)
										break;
									// deltaX
									deltaX = alpha * d;
									// deltaG
									deltaG = gradient_next.data[0] - gradient.data[0];
									// New F(k+1)
									double tempX, tempG;
									tempX = deltaX * deltaG;
									tempG = deltaG * F * deltaG;
									F = F + (deltaX * deltaX) / tempX - (F * deltaG * F * deltaG) / tempG;
									// Output
									if (stepi == 0)
									{
										Output->Text += "Initial Hessian inverse: [" + Environment::NewLine;
										Output->Text += F + Environment::NewLine;
										Output->Text += "]" + Environment::NewLine;
									}
									Output->Text += "x = [ " + xi + " ]" + Environment::NewLine;
									if (abs(xi - x1) < THRESOLD2)
										break;
									xi = x1;
									alpha *= 0.9;
									++stepi;
									--thre;
									if (!thre)
										break;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x] = [ " + xi + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(xi, 0, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
						}
						else if (userCommand[1] == "Conjugate")
						{
							int thre = 200, stepi = 0;
							// Initial
							Equation equation;
							equation.EquIndex = i;
							equation.original = dataManager->GetEquations();
							equation.postEqu = dataManager->InfixToPost(equation.original[equation.EquIndex]);
							equation.CheckSqrt();
							double xi, yi, xlow, xhi, ylow, yhi, alpha, beta, si[2];
							alpha = beta = 0;
							std::string temp;
							MarshalString(initialX->Text, temp);
							xi = std::stod(temp);
							MarshalString(X1->Text, temp);
							xlow = std::stod(temp);
							MarshalString(X2->Text, temp);
							xhi = std::stod(temp);
							if (two->Checked)
							{
								// Initial
								MarshalString(initialY->Text, temp);
								yi = std::stod(temp);
								MarshalString(Y1->Text, temp);
								ylow = std::stod(temp);
								MarshalString(Y2->Text, temp);
								yhi = std::stod(temp);
								Vector gradient, gradient_next, si;
								Matrix G, G_next, Si;
								double x1, y1;
								while (1)
								{
									// Get Gradiant
									gradient = equation.gradient(xi, yi, 0, 2);
									G = gradient.ToMatrix();
									if (stepi == 0)
									{
										if (abs(gradient.data[0]) < THRESOLD2 && abs(gradient.data[1]) < THRESOLD2)
											break;
										si = gradient;
										for (unsigned int j = 0; j < si.data.size(); ++j)
										{
											si.data[j] *= -1;
										}
									}
									Si = si.ToMatrix();
									// Get Hessian
									equation.getHessian(xi, yi);
									// Find Alpha
									alpha = -(G.trans() * Si).data[0][0] / (Si.trans() * equation.hessian * Si).data[0][0];
									// xi+1
									x1 = xi + alpha * si.data[0];
									y1 = yi + alpha * si.data[1];
									// Boundary
									if (x1 < xlow)
										x1 = xlow + 10E-5;
									else if (x1 > xhi)
										x1 = xhi - 10E-5;
									if (y1 < ylow)
										y1 = ylow + 10E-5;
									else if (y1 > yhi)
										y1 = yhi - 10E-5;
									if (equation.HasSqrt)
									{
										if (x1 < 0)
											x1 = 10E-5;
										if (y1 < 0)
											y1 = 10E-5;
									}
									// Find beta
									gradient_next = equation.gradient(x1, y1, 0, 2);
									if (abs(gradient_next.data[0]) < THRESOLD2 && abs(gradient_next.data[1]) < THRESOLD2)
										break;
									G_next = gradient_next.ToMatrix();
									equation.getHessian(x1, y1);
									beta = -(G_next.trans() * Si).data[0][0] / (Si.trans() * equation.hessian * Si).data[0][0];
									// Output
									Output->Text += "i = " + stepi + Environment::NewLine;
									if (stepi != 0)
										Output->Text += "beta = " + beta + Environment::NewLine;
									Output->Text += "Si = [ " + si.data[0] + " , " + si.data[1] + " ]" + Environment::NewLine;
									Output->Text += "alpha = " + alpha + Environment::NewLine;
									Output->Text += "Xi = [ " + x1 + " , " + y1 + " ]" + Environment::NewLine;
									Output->Text += Environment::NewLine;
									// Next_Si
									si.data[0] = -gradient_next.data[0] + beta * si.data[0];
									si.data[1] = -gradient_next.data[1] + beta * si.data[1];
									xi = x1;
									yi = y1;
									++stepi;
									--thre;
									if (!thre)
										break;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x, y] = [ " + xi + ", " + yi + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(xi, yi, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
							else
							{
								Vector gradient, gradient_next, si;
								double x1, hessian, g, g_next, S;
								while (1)
								{
									// Get Gradient
									gradient = equation.gradient(xi, 0, 0, 1);
									g = gradient.data[0];
									if (stepi == 0)
									{
										if (abs(gradient.data[0]) < THRESOLD2)
											break;
										si = gradient;
										si.data[0] *= -1;
									}
									S = si.data[0];
									// Get Hessian
									hessian = equation.dif_xx(xi, 0, 10E-5);
									// Find Alpha
									alpha = -(g * S) / (S * hessian * S);
									// xi+1
									x1 = xi + alpha * S;
									// Boundary
									if (x1 < xlow)
										x1 = xlow + 10E-5;
									else if (x1 > xhi)
										x1 = xhi - 10E-5;
									if (equation.HasSqrt)
									{
										if (x1 < 0)
											x1 = 10E-5;
									}
									// Find beta
									gradient_next = equation.gradient(x1, 0, 0, 1);
									if (abs(gradient_next.data[0]) < THRESOLD)
										break;
									g_next = gradient_next.data[0];
									hessian = equation.dif_xx(x1, 0, 10E-5);
									beta = -(g_next * S) / (S * hessian * S);
									// Output
									Output->Text += "i = " + stepi + Environment::NewLine;
									if (stepi != 0)
										Output->Text += "beta = " + beta + Environment::NewLine;
									Output->Text += "Si = [ " + S + " ]" + Environment::NewLine;
									Output->Text += "alpha = " + alpha + Environment::NewLine;
									Output->Text += "Xi = [ " + x1 + " ]" + Environment::NewLine;
									Output->Text += Environment::NewLine;
									// Next_Si
									si.data[0] = -g_next + beta * si.data[0];
									xi = x1;
									++stepi;
									--thre;
									if (!thre)
										break;
								}
								Output->Text += Environment::NewLine;
								Output->Text += "[x] = [ " + x1 + " ]" + Environment::NewLine;
								Output->Text += "min = " + equation.FunctionValue(x1, 0, 0) + Environment::NewLine;
								Output->Text += Environment::NewLine;
							}
						}
						else
						{
							Output->Text += "There is something Wrong ! You can try 'Command' to see all commands" + Environment::NewLine;
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
		catch(Matrix_Error e)
		{
			switch (e)
			{
			case Matrix_Error::Dimension_Error:
				Output->Text += "Matrix Dimension Error！" + Environment::NewLine;
				break;
			default:
				break;
			}
		}
		catch (vectorError e)
		{
			switch (e)
			{	
			case vectorError::Dimension_Error:
				Output->Text += "Vector Dimension Error！" + Environment::NewLine;
				break;
			default:
				break;
			}
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