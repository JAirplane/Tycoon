#pragma once
#include <iostream>
#include "msoftcon.h"
#include <vector>
using namespace std;
class Alphabet
{
public:
	Alphabet() {}
	~Alphabet() {}
	static void DrawTile(int startX, int startY, color foreground = cBLACK, color background = cDARK_CYAN);
	static const vector< vector<bool> > Get_A_Matrix();
	static const vector< vector<bool> > Get_B_Matrix();
	static const vector< vector<bool> > Get_C_Matrix();
	static const vector< vector<bool> > Get_D_Matrix();
	static const vector< vector<bool> > Get_E_Matrix();
	static const vector< vector<bool> > Get_F_Matrix();
	static const vector< vector<bool> > Get_G_Matrix();
	static const vector< vector<bool> > Get_H_Matrix();
	static const vector< vector<bool> > Get_I_Matrix();
	static const vector< vector<bool> > Get_J_Matrix();
	static const vector< vector<bool> > Get_K_Matrix();
	static const vector< vector<bool> > Get_L_Matrix();
	static const vector< vector<bool> > Get_M_Matrix();
	static const vector< vector<bool> > Get_N_Matrix();
	static const vector< vector<bool> > Get_O_Matrix();
	static const vector< vector<bool> > Get_P_Matrix();
	static const vector< vector<bool> > Get_Q_Matrix();
	static const vector< vector<bool> > Get_R_Matrix();
	static const vector< vector<bool> > Get_S_Matrix();
	static const vector< vector<bool> > Get_T_Matrix();
	static const vector< vector<bool> > Get_U_Matrix();
	static const vector< vector<bool> > Get_V_Matrix();
	static const vector< vector<bool> > Get_W_Matrix();
	static const vector< vector<bool> > Get_X_Matrix();
	static const vector< vector<bool> > Get_Y_Matrix();
	static const vector< vector<bool> > Get_Z_Matrix();
	static const vector< vector<bool> > Get_Comma_Matrix();
	static const vector< vector<bool> > Get_Dot_Matrix();
	static const vector< vector<bool> > Get_ExclamationMark_Matrix();
	static const vector< vector<bool> > Get_QuestionMark_Matrix();
	static const vector< vector<bool> > Get_Colon_Matrix();
	static const vector< vector<bool> > Get_Semicolon_Matrix();
	static void DrawLetter(const vector< vector<bool> > letterMatrix, int startX, int startY, color foreground = cBLACK, color background = cDARK_CYAN);
};