#include "Alphabet.h"
void Alphabet::DrawTile(int startX, int startY, color foreground, color background)
{
	set_color(foreground, background);
	set_cursor_pos(startX, startY);
	cout << " ";
	set_color(cBLACK, cBLACK);
}
const vector< vector<bool> > Alphabet::Get_A_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> secondRow{ 0, 1, 1, 1, 1, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_B_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_C_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_D_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 0, 0 };
	vector<bool> secondRow{ 1, 1, 0, 1, 1, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 1, 1, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_E_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_F_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 0 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_G_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 0, 1, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 1 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_H_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_I_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> thirdRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fourthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fifthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> sixthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_J_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> secondRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_K_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 1, 1, 0 };
	vector<bool> thirdRow{ 1, 1, 1, 1, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 1, 0, 0, 0 };
	vector<bool> fifthRow{ 1, 1, 1, 1, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 1, 1, 0 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_L_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_M_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 1, 0, 1, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 1, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_N_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 1, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 1, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 1, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_O_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_P_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Q_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 1, 0, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 0, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_R_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 1, 1, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 1, 1, 0 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_S_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> fourthRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_T_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> thirdRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fourthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fifthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> sixthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> seventhRow{ 0, 0, 1, 1, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_U_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> fifthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_V_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 1, 1, 0, 1, 1, 0 };
	vector<bool> fourthRow{ 0, 1, 1, 0, 1, 1, 0 };
	vector<bool> fifthRow{ 0, 1, 1, 0, 1, 1, 0 };
	vector<bool> sixthRow{ 0, 0, 1, 1, 1, 0, 0 };
	vector<bool> seventhRow{ 0, 0, 1, 1, 1, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_W_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0 };
	vector<bool> fourthRow{ 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0 };
	vector<bool> fifthRow{ 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0 };
	vector<bool> sixthRow{ 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 ,0 };
	vector<bool> seventhRow{ 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 ,0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_X_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 1, 1, 1, 1, 0 };
	vector<bool> fourthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fifthRow{ 0, 1, 1, 1, 1, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> seventhRow{ 1, 1, 0, 0, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Y_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 1, 1, 1, 1, 0 };
	vector<bool> fourthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fifthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> sixthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> seventhRow{ 0, 0, 1, 1, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Z_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 0, 0, 1, 1, 0 };
	vector<bool> fourthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> fifthRow{ 0, 1, 1, 0, 0, 0 };
	vector<bool> sixthRow{ 1, 1, 0, 0, 0, 0 };
	vector<bool> seventhRow{ 1, 1, 1, 1, 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Comma_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1 };
	vector<bool> secondRow{ 1, 1 };
	vector<bool> thirdRow{ 0, 1 };
	vector<bool> fourthRow{ 1, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Dot_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1 };
	vector<bool> secondRow{ 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_ExclamationMark_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1 };
	vector<bool> secondRow{ 1, 1 };
	vector<bool> thirdRow{ 1, 1 };
	vector<bool> fourthRow{ 1, 1 };
	vector<bool> fifthRow{ 0, 0 };
	vector<bool> sixthRow{ 1, 1 };
	vector<bool> seventhRow{ 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_QuestionMark_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1, 1, 1, 1, 1 };
	vector<bool> secondRow{ 1, 1, 0, 0, 1, 1 };
	vector<bool> thirdRow{ 0, 0, 0, 0, 1, 1 };
	vector<bool> fourthRow{ 0, 0, 1, 1, 1, 1 };
	vector<bool> fifthRow{ 0, 0, 0, 0, 0, 0 };
	vector<bool> sixthRow{ 0, 0, 1, 1, 0, 0 };
	vector<bool> seventhRow{ 0, 0, 1, 1, 0, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Colon_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1 };
	vector<bool> secondRow{ 1, 1 };
	vector<bool> thirdRow{ 0, 0 };
	vector<bool> fourthRow{ 0, 0 };
	vector<bool> fifthRow{ 0, 0 };
	vector<bool> sixthRow{ 1, 1 };
	vector<bool> seventhRow{ 1, 1 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
const vector< vector<bool> > Alphabet::Get_Semicolon_Matrix()
{
	vector< vector<bool> > rootVector;
	vector<bool> firstRow{ 1, 1 };
	vector<bool> secondRow{ 1, 1 };
	vector<bool> thirdRow{ 0, 0 };
	vector<bool> fourthRow{ 1, 1 };
	vector<bool> fifthRow{ 1, 1 };
	vector<bool> sixthRow{ 0, 1 };
	vector<bool> seventhRow{ 1, 0 };
	rootVector.push_back(firstRow);
	rootVector.push_back(secondRow);
	rootVector.push_back(thirdRow);
	rootVector.push_back(fourthRow);
	rootVector.push_back(fifthRow);
	rootVector.push_back(sixthRow);
	rootVector.push_back(seventhRow);
	return rootVector;
}
void Alphabet::DrawLetter(const vector< vector<bool> > letterMatrix, int startX, int startY, color foreground, color background)
{
	vector< vector<bool> >::const_iterator rootIter;
	int row = startX;
	int column = startY;
	int letterWidth = (*letterMatrix.begin()).size();
	for (rootIter = letterMatrix.begin(); rootIter != letterMatrix.end(); rootIter++, column++)
	{
		vector<bool>::const_iterator internalIter;
		for (internalIter = (*rootIter).begin(); internalIter != (*rootIter).end(); internalIter++, row++)
		{
			if ((*internalIter) == true)
			{
				Alphabet::DrawTile(row, column, foreground, background);
			}
		}
		row = startX;
	}
	set_cursor_pos(startX + letterWidth + 1, startY);
}