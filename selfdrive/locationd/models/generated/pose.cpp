#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4357576219374353734) {
   out_4357576219374353734[0] = delta_x[0] + nom_x[0];
   out_4357576219374353734[1] = delta_x[1] + nom_x[1];
   out_4357576219374353734[2] = delta_x[2] + nom_x[2];
   out_4357576219374353734[3] = delta_x[3] + nom_x[3];
   out_4357576219374353734[4] = delta_x[4] + nom_x[4];
   out_4357576219374353734[5] = delta_x[5] + nom_x[5];
   out_4357576219374353734[6] = delta_x[6] + nom_x[6];
   out_4357576219374353734[7] = delta_x[7] + nom_x[7];
   out_4357576219374353734[8] = delta_x[8] + nom_x[8];
   out_4357576219374353734[9] = delta_x[9] + nom_x[9];
   out_4357576219374353734[10] = delta_x[10] + nom_x[10];
   out_4357576219374353734[11] = delta_x[11] + nom_x[11];
   out_4357576219374353734[12] = delta_x[12] + nom_x[12];
   out_4357576219374353734[13] = delta_x[13] + nom_x[13];
   out_4357576219374353734[14] = delta_x[14] + nom_x[14];
   out_4357576219374353734[15] = delta_x[15] + nom_x[15];
   out_4357576219374353734[16] = delta_x[16] + nom_x[16];
   out_4357576219374353734[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2661115432814277835) {
   out_2661115432814277835[0] = -nom_x[0] + true_x[0];
   out_2661115432814277835[1] = -nom_x[1] + true_x[1];
   out_2661115432814277835[2] = -nom_x[2] + true_x[2];
   out_2661115432814277835[3] = -nom_x[3] + true_x[3];
   out_2661115432814277835[4] = -nom_x[4] + true_x[4];
   out_2661115432814277835[5] = -nom_x[5] + true_x[5];
   out_2661115432814277835[6] = -nom_x[6] + true_x[6];
   out_2661115432814277835[7] = -nom_x[7] + true_x[7];
   out_2661115432814277835[8] = -nom_x[8] + true_x[8];
   out_2661115432814277835[9] = -nom_x[9] + true_x[9];
   out_2661115432814277835[10] = -nom_x[10] + true_x[10];
   out_2661115432814277835[11] = -nom_x[11] + true_x[11];
   out_2661115432814277835[12] = -nom_x[12] + true_x[12];
   out_2661115432814277835[13] = -nom_x[13] + true_x[13];
   out_2661115432814277835[14] = -nom_x[14] + true_x[14];
   out_2661115432814277835[15] = -nom_x[15] + true_x[15];
   out_2661115432814277835[16] = -nom_x[16] + true_x[16];
   out_2661115432814277835[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1505681434595544592) {
   out_1505681434595544592[0] = 1.0;
   out_1505681434595544592[1] = 0.0;
   out_1505681434595544592[2] = 0.0;
   out_1505681434595544592[3] = 0.0;
   out_1505681434595544592[4] = 0.0;
   out_1505681434595544592[5] = 0.0;
   out_1505681434595544592[6] = 0.0;
   out_1505681434595544592[7] = 0.0;
   out_1505681434595544592[8] = 0.0;
   out_1505681434595544592[9] = 0.0;
   out_1505681434595544592[10] = 0.0;
   out_1505681434595544592[11] = 0.0;
   out_1505681434595544592[12] = 0.0;
   out_1505681434595544592[13] = 0.0;
   out_1505681434595544592[14] = 0.0;
   out_1505681434595544592[15] = 0.0;
   out_1505681434595544592[16] = 0.0;
   out_1505681434595544592[17] = 0.0;
   out_1505681434595544592[18] = 0.0;
   out_1505681434595544592[19] = 1.0;
   out_1505681434595544592[20] = 0.0;
   out_1505681434595544592[21] = 0.0;
   out_1505681434595544592[22] = 0.0;
   out_1505681434595544592[23] = 0.0;
   out_1505681434595544592[24] = 0.0;
   out_1505681434595544592[25] = 0.0;
   out_1505681434595544592[26] = 0.0;
   out_1505681434595544592[27] = 0.0;
   out_1505681434595544592[28] = 0.0;
   out_1505681434595544592[29] = 0.0;
   out_1505681434595544592[30] = 0.0;
   out_1505681434595544592[31] = 0.0;
   out_1505681434595544592[32] = 0.0;
   out_1505681434595544592[33] = 0.0;
   out_1505681434595544592[34] = 0.0;
   out_1505681434595544592[35] = 0.0;
   out_1505681434595544592[36] = 0.0;
   out_1505681434595544592[37] = 0.0;
   out_1505681434595544592[38] = 1.0;
   out_1505681434595544592[39] = 0.0;
   out_1505681434595544592[40] = 0.0;
   out_1505681434595544592[41] = 0.0;
   out_1505681434595544592[42] = 0.0;
   out_1505681434595544592[43] = 0.0;
   out_1505681434595544592[44] = 0.0;
   out_1505681434595544592[45] = 0.0;
   out_1505681434595544592[46] = 0.0;
   out_1505681434595544592[47] = 0.0;
   out_1505681434595544592[48] = 0.0;
   out_1505681434595544592[49] = 0.0;
   out_1505681434595544592[50] = 0.0;
   out_1505681434595544592[51] = 0.0;
   out_1505681434595544592[52] = 0.0;
   out_1505681434595544592[53] = 0.0;
   out_1505681434595544592[54] = 0.0;
   out_1505681434595544592[55] = 0.0;
   out_1505681434595544592[56] = 0.0;
   out_1505681434595544592[57] = 1.0;
   out_1505681434595544592[58] = 0.0;
   out_1505681434595544592[59] = 0.0;
   out_1505681434595544592[60] = 0.0;
   out_1505681434595544592[61] = 0.0;
   out_1505681434595544592[62] = 0.0;
   out_1505681434595544592[63] = 0.0;
   out_1505681434595544592[64] = 0.0;
   out_1505681434595544592[65] = 0.0;
   out_1505681434595544592[66] = 0.0;
   out_1505681434595544592[67] = 0.0;
   out_1505681434595544592[68] = 0.0;
   out_1505681434595544592[69] = 0.0;
   out_1505681434595544592[70] = 0.0;
   out_1505681434595544592[71] = 0.0;
   out_1505681434595544592[72] = 0.0;
   out_1505681434595544592[73] = 0.0;
   out_1505681434595544592[74] = 0.0;
   out_1505681434595544592[75] = 0.0;
   out_1505681434595544592[76] = 1.0;
   out_1505681434595544592[77] = 0.0;
   out_1505681434595544592[78] = 0.0;
   out_1505681434595544592[79] = 0.0;
   out_1505681434595544592[80] = 0.0;
   out_1505681434595544592[81] = 0.0;
   out_1505681434595544592[82] = 0.0;
   out_1505681434595544592[83] = 0.0;
   out_1505681434595544592[84] = 0.0;
   out_1505681434595544592[85] = 0.0;
   out_1505681434595544592[86] = 0.0;
   out_1505681434595544592[87] = 0.0;
   out_1505681434595544592[88] = 0.0;
   out_1505681434595544592[89] = 0.0;
   out_1505681434595544592[90] = 0.0;
   out_1505681434595544592[91] = 0.0;
   out_1505681434595544592[92] = 0.0;
   out_1505681434595544592[93] = 0.0;
   out_1505681434595544592[94] = 0.0;
   out_1505681434595544592[95] = 1.0;
   out_1505681434595544592[96] = 0.0;
   out_1505681434595544592[97] = 0.0;
   out_1505681434595544592[98] = 0.0;
   out_1505681434595544592[99] = 0.0;
   out_1505681434595544592[100] = 0.0;
   out_1505681434595544592[101] = 0.0;
   out_1505681434595544592[102] = 0.0;
   out_1505681434595544592[103] = 0.0;
   out_1505681434595544592[104] = 0.0;
   out_1505681434595544592[105] = 0.0;
   out_1505681434595544592[106] = 0.0;
   out_1505681434595544592[107] = 0.0;
   out_1505681434595544592[108] = 0.0;
   out_1505681434595544592[109] = 0.0;
   out_1505681434595544592[110] = 0.0;
   out_1505681434595544592[111] = 0.0;
   out_1505681434595544592[112] = 0.0;
   out_1505681434595544592[113] = 0.0;
   out_1505681434595544592[114] = 1.0;
   out_1505681434595544592[115] = 0.0;
   out_1505681434595544592[116] = 0.0;
   out_1505681434595544592[117] = 0.0;
   out_1505681434595544592[118] = 0.0;
   out_1505681434595544592[119] = 0.0;
   out_1505681434595544592[120] = 0.0;
   out_1505681434595544592[121] = 0.0;
   out_1505681434595544592[122] = 0.0;
   out_1505681434595544592[123] = 0.0;
   out_1505681434595544592[124] = 0.0;
   out_1505681434595544592[125] = 0.0;
   out_1505681434595544592[126] = 0.0;
   out_1505681434595544592[127] = 0.0;
   out_1505681434595544592[128] = 0.0;
   out_1505681434595544592[129] = 0.0;
   out_1505681434595544592[130] = 0.0;
   out_1505681434595544592[131] = 0.0;
   out_1505681434595544592[132] = 0.0;
   out_1505681434595544592[133] = 1.0;
   out_1505681434595544592[134] = 0.0;
   out_1505681434595544592[135] = 0.0;
   out_1505681434595544592[136] = 0.0;
   out_1505681434595544592[137] = 0.0;
   out_1505681434595544592[138] = 0.0;
   out_1505681434595544592[139] = 0.0;
   out_1505681434595544592[140] = 0.0;
   out_1505681434595544592[141] = 0.0;
   out_1505681434595544592[142] = 0.0;
   out_1505681434595544592[143] = 0.0;
   out_1505681434595544592[144] = 0.0;
   out_1505681434595544592[145] = 0.0;
   out_1505681434595544592[146] = 0.0;
   out_1505681434595544592[147] = 0.0;
   out_1505681434595544592[148] = 0.0;
   out_1505681434595544592[149] = 0.0;
   out_1505681434595544592[150] = 0.0;
   out_1505681434595544592[151] = 0.0;
   out_1505681434595544592[152] = 1.0;
   out_1505681434595544592[153] = 0.0;
   out_1505681434595544592[154] = 0.0;
   out_1505681434595544592[155] = 0.0;
   out_1505681434595544592[156] = 0.0;
   out_1505681434595544592[157] = 0.0;
   out_1505681434595544592[158] = 0.0;
   out_1505681434595544592[159] = 0.0;
   out_1505681434595544592[160] = 0.0;
   out_1505681434595544592[161] = 0.0;
   out_1505681434595544592[162] = 0.0;
   out_1505681434595544592[163] = 0.0;
   out_1505681434595544592[164] = 0.0;
   out_1505681434595544592[165] = 0.0;
   out_1505681434595544592[166] = 0.0;
   out_1505681434595544592[167] = 0.0;
   out_1505681434595544592[168] = 0.0;
   out_1505681434595544592[169] = 0.0;
   out_1505681434595544592[170] = 0.0;
   out_1505681434595544592[171] = 1.0;
   out_1505681434595544592[172] = 0.0;
   out_1505681434595544592[173] = 0.0;
   out_1505681434595544592[174] = 0.0;
   out_1505681434595544592[175] = 0.0;
   out_1505681434595544592[176] = 0.0;
   out_1505681434595544592[177] = 0.0;
   out_1505681434595544592[178] = 0.0;
   out_1505681434595544592[179] = 0.0;
   out_1505681434595544592[180] = 0.0;
   out_1505681434595544592[181] = 0.0;
   out_1505681434595544592[182] = 0.0;
   out_1505681434595544592[183] = 0.0;
   out_1505681434595544592[184] = 0.0;
   out_1505681434595544592[185] = 0.0;
   out_1505681434595544592[186] = 0.0;
   out_1505681434595544592[187] = 0.0;
   out_1505681434595544592[188] = 0.0;
   out_1505681434595544592[189] = 0.0;
   out_1505681434595544592[190] = 1.0;
   out_1505681434595544592[191] = 0.0;
   out_1505681434595544592[192] = 0.0;
   out_1505681434595544592[193] = 0.0;
   out_1505681434595544592[194] = 0.0;
   out_1505681434595544592[195] = 0.0;
   out_1505681434595544592[196] = 0.0;
   out_1505681434595544592[197] = 0.0;
   out_1505681434595544592[198] = 0.0;
   out_1505681434595544592[199] = 0.0;
   out_1505681434595544592[200] = 0.0;
   out_1505681434595544592[201] = 0.0;
   out_1505681434595544592[202] = 0.0;
   out_1505681434595544592[203] = 0.0;
   out_1505681434595544592[204] = 0.0;
   out_1505681434595544592[205] = 0.0;
   out_1505681434595544592[206] = 0.0;
   out_1505681434595544592[207] = 0.0;
   out_1505681434595544592[208] = 0.0;
   out_1505681434595544592[209] = 1.0;
   out_1505681434595544592[210] = 0.0;
   out_1505681434595544592[211] = 0.0;
   out_1505681434595544592[212] = 0.0;
   out_1505681434595544592[213] = 0.0;
   out_1505681434595544592[214] = 0.0;
   out_1505681434595544592[215] = 0.0;
   out_1505681434595544592[216] = 0.0;
   out_1505681434595544592[217] = 0.0;
   out_1505681434595544592[218] = 0.0;
   out_1505681434595544592[219] = 0.0;
   out_1505681434595544592[220] = 0.0;
   out_1505681434595544592[221] = 0.0;
   out_1505681434595544592[222] = 0.0;
   out_1505681434595544592[223] = 0.0;
   out_1505681434595544592[224] = 0.0;
   out_1505681434595544592[225] = 0.0;
   out_1505681434595544592[226] = 0.0;
   out_1505681434595544592[227] = 0.0;
   out_1505681434595544592[228] = 1.0;
   out_1505681434595544592[229] = 0.0;
   out_1505681434595544592[230] = 0.0;
   out_1505681434595544592[231] = 0.0;
   out_1505681434595544592[232] = 0.0;
   out_1505681434595544592[233] = 0.0;
   out_1505681434595544592[234] = 0.0;
   out_1505681434595544592[235] = 0.0;
   out_1505681434595544592[236] = 0.0;
   out_1505681434595544592[237] = 0.0;
   out_1505681434595544592[238] = 0.0;
   out_1505681434595544592[239] = 0.0;
   out_1505681434595544592[240] = 0.0;
   out_1505681434595544592[241] = 0.0;
   out_1505681434595544592[242] = 0.0;
   out_1505681434595544592[243] = 0.0;
   out_1505681434595544592[244] = 0.0;
   out_1505681434595544592[245] = 0.0;
   out_1505681434595544592[246] = 0.0;
   out_1505681434595544592[247] = 1.0;
   out_1505681434595544592[248] = 0.0;
   out_1505681434595544592[249] = 0.0;
   out_1505681434595544592[250] = 0.0;
   out_1505681434595544592[251] = 0.0;
   out_1505681434595544592[252] = 0.0;
   out_1505681434595544592[253] = 0.0;
   out_1505681434595544592[254] = 0.0;
   out_1505681434595544592[255] = 0.0;
   out_1505681434595544592[256] = 0.0;
   out_1505681434595544592[257] = 0.0;
   out_1505681434595544592[258] = 0.0;
   out_1505681434595544592[259] = 0.0;
   out_1505681434595544592[260] = 0.0;
   out_1505681434595544592[261] = 0.0;
   out_1505681434595544592[262] = 0.0;
   out_1505681434595544592[263] = 0.0;
   out_1505681434595544592[264] = 0.0;
   out_1505681434595544592[265] = 0.0;
   out_1505681434595544592[266] = 1.0;
   out_1505681434595544592[267] = 0.0;
   out_1505681434595544592[268] = 0.0;
   out_1505681434595544592[269] = 0.0;
   out_1505681434595544592[270] = 0.0;
   out_1505681434595544592[271] = 0.0;
   out_1505681434595544592[272] = 0.0;
   out_1505681434595544592[273] = 0.0;
   out_1505681434595544592[274] = 0.0;
   out_1505681434595544592[275] = 0.0;
   out_1505681434595544592[276] = 0.0;
   out_1505681434595544592[277] = 0.0;
   out_1505681434595544592[278] = 0.0;
   out_1505681434595544592[279] = 0.0;
   out_1505681434595544592[280] = 0.0;
   out_1505681434595544592[281] = 0.0;
   out_1505681434595544592[282] = 0.0;
   out_1505681434595544592[283] = 0.0;
   out_1505681434595544592[284] = 0.0;
   out_1505681434595544592[285] = 1.0;
   out_1505681434595544592[286] = 0.0;
   out_1505681434595544592[287] = 0.0;
   out_1505681434595544592[288] = 0.0;
   out_1505681434595544592[289] = 0.0;
   out_1505681434595544592[290] = 0.0;
   out_1505681434595544592[291] = 0.0;
   out_1505681434595544592[292] = 0.0;
   out_1505681434595544592[293] = 0.0;
   out_1505681434595544592[294] = 0.0;
   out_1505681434595544592[295] = 0.0;
   out_1505681434595544592[296] = 0.0;
   out_1505681434595544592[297] = 0.0;
   out_1505681434595544592[298] = 0.0;
   out_1505681434595544592[299] = 0.0;
   out_1505681434595544592[300] = 0.0;
   out_1505681434595544592[301] = 0.0;
   out_1505681434595544592[302] = 0.0;
   out_1505681434595544592[303] = 0.0;
   out_1505681434595544592[304] = 1.0;
   out_1505681434595544592[305] = 0.0;
   out_1505681434595544592[306] = 0.0;
   out_1505681434595544592[307] = 0.0;
   out_1505681434595544592[308] = 0.0;
   out_1505681434595544592[309] = 0.0;
   out_1505681434595544592[310] = 0.0;
   out_1505681434595544592[311] = 0.0;
   out_1505681434595544592[312] = 0.0;
   out_1505681434595544592[313] = 0.0;
   out_1505681434595544592[314] = 0.0;
   out_1505681434595544592[315] = 0.0;
   out_1505681434595544592[316] = 0.0;
   out_1505681434595544592[317] = 0.0;
   out_1505681434595544592[318] = 0.0;
   out_1505681434595544592[319] = 0.0;
   out_1505681434595544592[320] = 0.0;
   out_1505681434595544592[321] = 0.0;
   out_1505681434595544592[322] = 0.0;
   out_1505681434595544592[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5250663778640377101) {
   out_5250663778640377101[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5250663778640377101[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5250663778640377101[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5250663778640377101[3] = dt*state[12] + state[3];
   out_5250663778640377101[4] = dt*state[13] + state[4];
   out_5250663778640377101[5] = dt*state[14] + state[5];
   out_5250663778640377101[6] = state[6];
   out_5250663778640377101[7] = state[7];
   out_5250663778640377101[8] = state[8];
   out_5250663778640377101[9] = state[9];
   out_5250663778640377101[10] = state[10];
   out_5250663778640377101[11] = state[11];
   out_5250663778640377101[12] = state[12];
   out_5250663778640377101[13] = state[13];
   out_5250663778640377101[14] = state[14];
   out_5250663778640377101[15] = state[15];
   out_5250663778640377101[16] = state[16];
   out_5250663778640377101[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5179985648983440931) {
   out_5179985648983440931[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5179985648983440931[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5179985648983440931[2] = 0;
   out_5179985648983440931[3] = 0;
   out_5179985648983440931[4] = 0;
   out_5179985648983440931[5] = 0;
   out_5179985648983440931[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5179985648983440931[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5179985648983440931[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5179985648983440931[9] = 0;
   out_5179985648983440931[10] = 0;
   out_5179985648983440931[11] = 0;
   out_5179985648983440931[12] = 0;
   out_5179985648983440931[13] = 0;
   out_5179985648983440931[14] = 0;
   out_5179985648983440931[15] = 0;
   out_5179985648983440931[16] = 0;
   out_5179985648983440931[17] = 0;
   out_5179985648983440931[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5179985648983440931[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5179985648983440931[20] = 0;
   out_5179985648983440931[21] = 0;
   out_5179985648983440931[22] = 0;
   out_5179985648983440931[23] = 0;
   out_5179985648983440931[24] = 0;
   out_5179985648983440931[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5179985648983440931[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5179985648983440931[27] = 0;
   out_5179985648983440931[28] = 0;
   out_5179985648983440931[29] = 0;
   out_5179985648983440931[30] = 0;
   out_5179985648983440931[31] = 0;
   out_5179985648983440931[32] = 0;
   out_5179985648983440931[33] = 0;
   out_5179985648983440931[34] = 0;
   out_5179985648983440931[35] = 0;
   out_5179985648983440931[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5179985648983440931[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5179985648983440931[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5179985648983440931[39] = 0;
   out_5179985648983440931[40] = 0;
   out_5179985648983440931[41] = 0;
   out_5179985648983440931[42] = 0;
   out_5179985648983440931[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5179985648983440931[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5179985648983440931[45] = 0;
   out_5179985648983440931[46] = 0;
   out_5179985648983440931[47] = 0;
   out_5179985648983440931[48] = 0;
   out_5179985648983440931[49] = 0;
   out_5179985648983440931[50] = 0;
   out_5179985648983440931[51] = 0;
   out_5179985648983440931[52] = 0;
   out_5179985648983440931[53] = 0;
   out_5179985648983440931[54] = 0;
   out_5179985648983440931[55] = 0;
   out_5179985648983440931[56] = 0;
   out_5179985648983440931[57] = 1;
   out_5179985648983440931[58] = 0;
   out_5179985648983440931[59] = 0;
   out_5179985648983440931[60] = 0;
   out_5179985648983440931[61] = 0;
   out_5179985648983440931[62] = 0;
   out_5179985648983440931[63] = 0;
   out_5179985648983440931[64] = 0;
   out_5179985648983440931[65] = 0;
   out_5179985648983440931[66] = dt;
   out_5179985648983440931[67] = 0;
   out_5179985648983440931[68] = 0;
   out_5179985648983440931[69] = 0;
   out_5179985648983440931[70] = 0;
   out_5179985648983440931[71] = 0;
   out_5179985648983440931[72] = 0;
   out_5179985648983440931[73] = 0;
   out_5179985648983440931[74] = 0;
   out_5179985648983440931[75] = 0;
   out_5179985648983440931[76] = 1;
   out_5179985648983440931[77] = 0;
   out_5179985648983440931[78] = 0;
   out_5179985648983440931[79] = 0;
   out_5179985648983440931[80] = 0;
   out_5179985648983440931[81] = 0;
   out_5179985648983440931[82] = 0;
   out_5179985648983440931[83] = 0;
   out_5179985648983440931[84] = 0;
   out_5179985648983440931[85] = dt;
   out_5179985648983440931[86] = 0;
   out_5179985648983440931[87] = 0;
   out_5179985648983440931[88] = 0;
   out_5179985648983440931[89] = 0;
   out_5179985648983440931[90] = 0;
   out_5179985648983440931[91] = 0;
   out_5179985648983440931[92] = 0;
   out_5179985648983440931[93] = 0;
   out_5179985648983440931[94] = 0;
   out_5179985648983440931[95] = 1;
   out_5179985648983440931[96] = 0;
   out_5179985648983440931[97] = 0;
   out_5179985648983440931[98] = 0;
   out_5179985648983440931[99] = 0;
   out_5179985648983440931[100] = 0;
   out_5179985648983440931[101] = 0;
   out_5179985648983440931[102] = 0;
   out_5179985648983440931[103] = 0;
   out_5179985648983440931[104] = dt;
   out_5179985648983440931[105] = 0;
   out_5179985648983440931[106] = 0;
   out_5179985648983440931[107] = 0;
   out_5179985648983440931[108] = 0;
   out_5179985648983440931[109] = 0;
   out_5179985648983440931[110] = 0;
   out_5179985648983440931[111] = 0;
   out_5179985648983440931[112] = 0;
   out_5179985648983440931[113] = 0;
   out_5179985648983440931[114] = 1;
   out_5179985648983440931[115] = 0;
   out_5179985648983440931[116] = 0;
   out_5179985648983440931[117] = 0;
   out_5179985648983440931[118] = 0;
   out_5179985648983440931[119] = 0;
   out_5179985648983440931[120] = 0;
   out_5179985648983440931[121] = 0;
   out_5179985648983440931[122] = 0;
   out_5179985648983440931[123] = 0;
   out_5179985648983440931[124] = 0;
   out_5179985648983440931[125] = 0;
   out_5179985648983440931[126] = 0;
   out_5179985648983440931[127] = 0;
   out_5179985648983440931[128] = 0;
   out_5179985648983440931[129] = 0;
   out_5179985648983440931[130] = 0;
   out_5179985648983440931[131] = 0;
   out_5179985648983440931[132] = 0;
   out_5179985648983440931[133] = 1;
   out_5179985648983440931[134] = 0;
   out_5179985648983440931[135] = 0;
   out_5179985648983440931[136] = 0;
   out_5179985648983440931[137] = 0;
   out_5179985648983440931[138] = 0;
   out_5179985648983440931[139] = 0;
   out_5179985648983440931[140] = 0;
   out_5179985648983440931[141] = 0;
   out_5179985648983440931[142] = 0;
   out_5179985648983440931[143] = 0;
   out_5179985648983440931[144] = 0;
   out_5179985648983440931[145] = 0;
   out_5179985648983440931[146] = 0;
   out_5179985648983440931[147] = 0;
   out_5179985648983440931[148] = 0;
   out_5179985648983440931[149] = 0;
   out_5179985648983440931[150] = 0;
   out_5179985648983440931[151] = 0;
   out_5179985648983440931[152] = 1;
   out_5179985648983440931[153] = 0;
   out_5179985648983440931[154] = 0;
   out_5179985648983440931[155] = 0;
   out_5179985648983440931[156] = 0;
   out_5179985648983440931[157] = 0;
   out_5179985648983440931[158] = 0;
   out_5179985648983440931[159] = 0;
   out_5179985648983440931[160] = 0;
   out_5179985648983440931[161] = 0;
   out_5179985648983440931[162] = 0;
   out_5179985648983440931[163] = 0;
   out_5179985648983440931[164] = 0;
   out_5179985648983440931[165] = 0;
   out_5179985648983440931[166] = 0;
   out_5179985648983440931[167] = 0;
   out_5179985648983440931[168] = 0;
   out_5179985648983440931[169] = 0;
   out_5179985648983440931[170] = 0;
   out_5179985648983440931[171] = 1;
   out_5179985648983440931[172] = 0;
   out_5179985648983440931[173] = 0;
   out_5179985648983440931[174] = 0;
   out_5179985648983440931[175] = 0;
   out_5179985648983440931[176] = 0;
   out_5179985648983440931[177] = 0;
   out_5179985648983440931[178] = 0;
   out_5179985648983440931[179] = 0;
   out_5179985648983440931[180] = 0;
   out_5179985648983440931[181] = 0;
   out_5179985648983440931[182] = 0;
   out_5179985648983440931[183] = 0;
   out_5179985648983440931[184] = 0;
   out_5179985648983440931[185] = 0;
   out_5179985648983440931[186] = 0;
   out_5179985648983440931[187] = 0;
   out_5179985648983440931[188] = 0;
   out_5179985648983440931[189] = 0;
   out_5179985648983440931[190] = 1;
   out_5179985648983440931[191] = 0;
   out_5179985648983440931[192] = 0;
   out_5179985648983440931[193] = 0;
   out_5179985648983440931[194] = 0;
   out_5179985648983440931[195] = 0;
   out_5179985648983440931[196] = 0;
   out_5179985648983440931[197] = 0;
   out_5179985648983440931[198] = 0;
   out_5179985648983440931[199] = 0;
   out_5179985648983440931[200] = 0;
   out_5179985648983440931[201] = 0;
   out_5179985648983440931[202] = 0;
   out_5179985648983440931[203] = 0;
   out_5179985648983440931[204] = 0;
   out_5179985648983440931[205] = 0;
   out_5179985648983440931[206] = 0;
   out_5179985648983440931[207] = 0;
   out_5179985648983440931[208] = 0;
   out_5179985648983440931[209] = 1;
   out_5179985648983440931[210] = 0;
   out_5179985648983440931[211] = 0;
   out_5179985648983440931[212] = 0;
   out_5179985648983440931[213] = 0;
   out_5179985648983440931[214] = 0;
   out_5179985648983440931[215] = 0;
   out_5179985648983440931[216] = 0;
   out_5179985648983440931[217] = 0;
   out_5179985648983440931[218] = 0;
   out_5179985648983440931[219] = 0;
   out_5179985648983440931[220] = 0;
   out_5179985648983440931[221] = 0;
   out_5179985648983440931[222] = 0;
   out_5179985648983440931[223] = 0;
   out_5179985648983440931[224] = 0;
   out_5179985648983440931[225] = 0;
   out_5179985648983440931[226] = 0;
   out_5179985648983440931[227] = 0;
   out_5179985648983440931[228] = 1;
   out_5179985648983440931[229] = 0;
   out_5179985648983440931[230] = 0;
   out_5179985648983440931[231] = 0;
   out_5179985648983440931[232] = 0;
   out_5179985648983440931[233] = 0;
   out_5179985648983440931[234] = 0;
   out_5179985648983440931[235] = 0;
   out_5179985648983440931[236] = 0;
   out_5179985648983440931[237] = 0;
   out_5179985648983440931[238] = 0;
   out_5179985648983440931[239] = 0;
   out_5179985648983440931[240] = 0;
   out_5179985648983440931[241] = 0;
   out_5179985648983440931[242] = 0;
   out_5179985648983440931[243] = 0;
   out_5179985648983440931[244] = 0;
   out_5179985648983440931[245] = 0;
   out_5179985648983440931[246] = 0;
   out_5179985648983440931[247] = 1;
   out_5179985648983440931[248] = 0;
   out_5179985648983440931[249] = 0;
   out_5179985648983440931[250] = 0;
   out_5179985648983440931[251] = 0;
   out_5179985648983440931[252] = 0;
   out_5179985648983440931[253] = 0;
   out_5179985648983440931[254] = 0;
   out_5179985648983440931[255] = 0;
   out_5179985648983440931[256] = 0;
   out_5179985648983440931[257] = 0;
   out_5179985648983440931[258] = 0;
   out_5179985648983440931[259] = 0;
   out_5179985648983440931[260] = 0;
   out_5179985648983440931[261] = 0;
   out_5179985648983440931[262] = 0;
   out_5179985648983440931[263] = 0;
   out_5179985648983440931[264] = 0;
   out_5179985648983440931[265] = 0;
   out_5179985648983440931[266] = 1;
   out_5179985648983440931[267] = 0;
   out_5179985648983440931[268] = 0;
   out_5179985648983440931[269] = 0;
   out_5179985648983440931[270] = 0;
   out_5179985648983440931[271] = 0;
   out_5179985648983440931[272] = 0;
   out_5179985648983440931[273] = 0;
   out_5179985648983440931[274] = 0;
   out_5179985648983440931[275] = 0;
   out_5179985648983440931[276] = 0;
   out_5179985648983440931[277] = 0;
   out_5179985648983440931[278] = 0;
   out_5179985648983440931[279] = 0;
   out_5179985648983440931[280] = 0;
   out_5179985648983440931[281] = 0;
   out_5179985648983440931[282] = 0;
   out_5179985648983440931[283] = 0;
   out_5179985648983440931[284] = 0;
   out_5179985648983440931[285] = 1;
   out_5179985648983440931[286] = 0;
   out_5179985648983440931[287] = 0;
   out_5179985648983440931[288] = 0;
   out_5179985648983440931[289] = 0;
   out_5179985648983440931[290] = 0;
   out_5179985648983440931[291] = 0;
   out_5179985648983440931[292] = 0;
   out_5179985648983440931[293] = 0;
   out_5179985648983440931[294] = 0;
   out_5179985648983440931[295] = 0;
   out_5179985648983440931[296] = 0;
   out_5179985648983440931[297] = 0;
   out_5179985648983440931[298] = 0;
   out_5179985648983440931[299] = 0;
   out_5179985648983440931[300] = 0;
   out_5179985648983440931[301] = 0;
   out_5179985648983440931[302] = 0;
   out_5179985648983440931[303] = 0;
   out_5179985648983440931[304] = 1;
   out_5179985648983440931[305] = 0;
   out_5179985648983440931[306] = 0;
   out_5179985648983440931[307] = 0;
   out_5179985648983440931[308] = 0;
   out_5179985648983440931[309] = 0;
   out_5179985648983440931[310] = 0;
   out_5179985648983440931[311] = 0;
   out_5179985648983440931[312] = 0;
   out_5179985648983440931[313] = 0;
   out_5179985648983440931[314] = 0;
   out_5179985648983440931[315] = 0;
   out_5179985648983440931[316] = 0;
   out_5179985648983440931[317] = 0;
   out_5179985648983440931[318] = 0;
   out_5179985648983440931[319] = 0;
   out_5179985648983440931[320] = 0;
   out_5179985648983440931[321] = 0;
   out_5179985648983440931[322] = 0;
   out_5179985648983440931[323] = 1;
}
void h_4(double *state, double *unused, double *out_7888032330331071963) {
   out_7888032330331071963[0] = state[6] + state[9];
   out_7888032330331071963[1] = state[7] + state[10];
   out_7888032330331071963[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2197503021392499830) {
   out_2197503021392499830[0] = 0;
   out_2197503021392499830[1] = 0;
   out_2197503021392499830[2] = 0;
   out_2197503021392499830[3] = 0;
   out_2197503021392499830[4] = 0;
   out_2197503021392499830[5] = 0;
   out_2197503021392499830[6] = 1;
   out_2197503021392499830[7] = 0;
   out_2197503021392499830[8] = 0;
   out_2197503021392499830[9] = 1;
   out_2197503021392499830[10] = 0;
   out_2197503021392499830[11] = 0;
   out_2197503021392499830[12] = 0;
   out_2197503021392499830[13] = 0;
   out_2197503021392499830[14] = 0;
   out_2197503021392499830[15] = 0;
   out_2197503021392499830[16] = 0;
   out_2197503021392499830[17] = 0;
   out_2197503021392499830[18] = 0;
   out_2197503021392499830[19] = 0;
   out_2197503021392499830[20] = 0;
   out_2197503021392499830[21] = 0;
   out_2197503021392499830[22] = 0;
   out_2197503021392499830[23] = 0;
   out_2197503021392499830[24] = 0;
   out_2197503021392499830[25] = 1;
   out_2197503021392499830[26] = 0;
   out_2197503021392499830[27] = 0;
   out_2197503021392499830[28] = 1;
   out_2197503021392499830[29] = 0;
   out_2197503021392499830[30] = 0;
   out_2197503021392499830[31] = 0;
   out_2197503021392499830[32] = 0;
   out_2197503021392499830[33] = 0;
   out_2197503021392499830[34] = 0;
   out_2197503021392499830[35] = 0;
   out_2197503021392499830[36] = 0;
   out_2197503021392499830[37] = 0;
   out_2197503021392499830[38] = 0;
   out_2197503021392499830[39] = 0;
   out_2197503021392499830[40] = 0;
   out_2197503021392499830[41] = 0;
   out_2197503021392499830[42] = 0;
   out_2197503021392499830[43] = 0;
   out_2197503021392499830[44] = 1;
   out_2197503021392499830[45] = 0;
   out_2197503021392499830[46] = 0;
   out_2197503021392499830[47] = 1;
   out_2197503021392499830[48] = 0;
   out_2197503021392499830[49] = 0;
   out_2197503021392499830[50] = 0;
   out_2197503021392499830[51] = 0;
   out_2197503021392499830[52] = 0;
   out_2197503021392499830[53] = 0;
}
void h_10(double *state, double *unused, double *out_8793784065757772837) {
   out_8793784065757772837[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8793784065757772837[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8793784065757772837[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2875840076825351679) {
   out_2875840076825351679[0] = 0;
   out_2875840076825351679[1] = 9.8100000000000005*cos(state[1]);
   out_2875840076825351679[2] = 0;
   out_2875840076825351679[3] = 0;
   out_2875840076825351679[4] = -state[8];
   out_2875840076825351679[5] = state[7];
   out_2875840076825351679[6] = 0;
   out_2875840076825351679[7] = state[5];
   out_2875840076825351679[8] = -state[4];
   out_2875840076825351679[9] = 0;
   out_2875840076825351679[10] = 0;
   out_2875840076825351679[11] = 0;
   out_2875840076825351679[12] = 1;
   out_2875840076825351679[13] = 0;
   out_2875840076825351679[14] = 0;
   out_2875840076825351679[15] = 1;
   out_2875840076825351679[16] = 0;
   out_2875840076825351679[17] = 0;
   out_2875840076825351679[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2875840076825351679[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2875840076825351679[20] = 0;
   out_2875840076825351679[21] = state[8];
   out_2875840076825351679[22] = 0;
   out_2875840076825351679[23] = -state[6];
   out_2875840076825351679[24] = -state[5];
   out_2875840076825351679[25] = 0;
   out_2875840076825351679[26] = state[3];
   out_2875840076825351679[27] = 0;
   out_2875840076825351679[28] = 0;
   out_2875840076825351679[29] = 0;
   out_2875840076825351679[30] = 0;
   out_2875840076825351679[31] = 1;
   out_2875840076825351679[32] = 0;
   out_2875840076825351679[33] = 0;
   out_2875840076825351679[34] = 1;
   out_2875840076825351679[35] = 0;
   out_2875840076825351679[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2875840076825351679[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2875840076825351679[38] = 0;
   out_2875840076825351679[39] = -state[7];
   out_2875840076825351679[40] = state[6];
   out_2875840076825351679[41] = 0;
   out_2875840076825351679[42] = state[4];
   out_2875840076825351679[43] = -state[3];
   out_2875840076825351679[44] = 0;
   out_2875840076825351679[45] = 0;
   out_2875840076825351679[46] = 0;
   out_2875840076825351679[47] = 0;
   out_2875840076825351679[48] = 0;
   out_2875840076825351679[49] = 0;
   out_2875840076825351679[50] = 1;
   out_2875840076825351679[51] = 0;
   out_2875840076825351679[52] = 0;
   out_2875840076825351679[53] = 1;
}
void h_13(double *state, double *unused, double *out_7313132045476290120) {
   out_7313132045476290120[0] = state[3];
   out_7313132045476290120[1] = state[4];
   out_7313132045476290120[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1014770803939832971) {
   out_1014770803939832971[0] = 0;
   out_1014770803939832971[1] = 0;
   out_1014770803939832971[2] = 0;
   out_1014770803939832971[3] = 1;
   out_1014770803939832971[4] = 0;
   out_1014770803939832971[5] = 0;
   out_1014770803939832971[6] = 0;
   out_1014770803939832971[7] = 0;
   out_1014770803939832971[8] = 0;
   out_1014770803939832971[9] = 0;
   out_1014770803939832971[10] = 0;
   out_1014770803939832971[11] = 0;
   out_1014770803939832971[12] = 0;
   out_1014770803939832971[13] = 0;
   out_1014770803939832971[14] = 0;
   out_1014770803939832971[15] = 0;
   out_1014770803939832971[16] = 0;
   out_1014770803939832971[17] = 0;
   out_1014770803939832971[18] = 0;
   out_1014770803939832971[19] = 0;
   out_1014770803939832971[20] = 0;
   out_1014770803939832971[21] = 0;
   out_1014770803939832971[22] = 1;
   out_1014770803939832971[23] = 0;
   out_1014770803939832971[24] = 0;
   out_1014770803939832971[25] = 0;
   out_1014770803939832971[26] = 0;
   out_1014770803939832971[27] = 0;
   out_1014770803939832971[28] = 0;
   out_1014770803939832971[29] = 0;
   out_1014770803939832971[30] = 0;
   out_1014770803939832971[31] = 0;
   out_1014770803939832971[32] = 0;
   out_1014770803939832971[33] = 0;
   out_1014770803939832971[34] = 0;
   out_1014770803939832971[35] = 0;
   out_1014770803939832971[36] = 0;
   out_1014770803939832971[37] = 0;
   out_1014770803939832971[38] = 0;
   out_1014770803939832971[39] = 0;
   out_1014770803939832971[40] = 0;
   out_1014770803939832971[41] = 1;
   out_1014770803939832971[42] = 0;
   out_1014770803939832971[43] = 0;
   out_1014770803939832971[44] = 0;
   out_1014770803939832971[45] = 0;
   out_1014770803939832971[46] = 0;
   out_1014770803939832971[47] = 0;
   out_1014770803939832971[48] = 0;
   out_1014770803939832971[49] = 0;
   out_1014770803939832971[50] = 0;
   out_1014770803939832971[51] = 0;
   out_1014770803939832971[52] = 0;
   out_1014770803939832971[53] = 0;
}
void h_14(double *state, double *unused, double *out_7899393187456188913) {
   out_7899393187456188913[0] = state[6];
   out_7899393187456188913[1] = state[7];
   out_7899393187456188913[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1765737834946984699) {
   out_1765737834946984699[0] = 0;
   out_1765737834946984699[1] = 0;
   out_1765737834946984699[2] = 0;
   out_1765737834946984699[3] = 0;
   out_1765737834946984699[4] = 0;
   out_1765737834946984699[5] = 0;
   out_1765737834946984699[6] = 1;
   out_1765737834946984699[7] = 0;
   out_1765737834946984699[8] = 0;
   out_1765737834946984699[9] = 0;
   out_1765737834946984699[10] = 0;
   out_1765737834946984699[11] = 0;
   out_1765737834946984699[12] = 0;
   out_1765737834946984699[13] = 0;
   out_1765737834946984699[14] = 0;
   out_1765737834946984699[15] = 0;
   out_1765737834946984699[16] = 0;
   out_1765737834946984699[17] = 0;
   out_1765737834946984699[18] = 0;
   out_1765737834946984699[19] = 0;
   out_1765737834946984699[20] = 0;
   out_1765737834946984699[21] = 0;
   out_1765737834946984699[22] = 0;
   out_1765737834946984699[23] = 0;
   out_1765737834946984699[24] = 0;
   out_1765737834946984699[25] = 1;
   out_1765737834946984699[26] = 0;
   out_1765737834946984699[27] = 0;
   out_1765737834946984699[28] = 0;
   out_1765737834946984699[29] = 0;
   out_1765737834946984699[30] = 0;
   out_1765737834946984699[31] = 0;
   out_1765737834946984699[32] = 0;
   out_1765737834946984699[33] = 0;
   out_1765737834946984699[34] = 0;
   out_1765737834946984699[35] = 0;
   out_1765737834946984699[36] = 0;
   out_1765737834946984699[37] = 0;
   out_1765737834946984699[38] = 0;
   out_1765737834946984699[39] = 0;
   out_1765737834946984699[40] = 0;
   out_1765737834946984699[41] = 0;
   out_1765737834946984699[42] = 0;
   out_1765737834946984699[43] = 0;
   out_1765737834946984699[44] = 1;
   out_1765737834946984699[45] = 0;
   out_1765737834946984699[46] = 0;
   out_1765737834946984699[47] = 0;
   out_1765737834946984699[48] = 0;
   out_1765737834946984699[49] = 0;
   out_1765737834946984699[50] = 0;
   out_1765737834946984699[51] = 0;
   out_1765737834946984699[52] = 0;
   out_1765737834946984699[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_4357576219374353734) {
  err_fun(nom_x, delta_x, out_4357576219374353734);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2661115432814277835) {
  inv_err_fun(nom_x, true_x, out_2661115432814277835);
}
void pose_H_mod_fun(double *state, double *out_1505681434595544592) {
  H_mod_fun(state, out_1505681434595544592);
}
void pose_f_fun(double *state, double dt, double *out_5250663778640377101) {
  f_fun(state,  dt, out_5250663778640377101);
}
void pose_F_fun(double *state, double dt, double *out_5179985648983440931) {
  F_fun(state,  dt, out_5179985648983440931);
}
void pose_h_4(double *state, double *unused, double *out_7888032330331071963) {
  h_4(state, unused, out_7888032330331071963);
}
void pose_H_4(double *state, double *unused, double *out_2197503021392499830) {
  H_4(state, unused, out_2197503021392499830);
}
void pose_h_10(double *state, double *unused, double *out_8793784065757772837) {
  h_10(state, unused, out_8793784065757772837);
}
void pose_H_10(double *state, double *unused, double *out_2875840076825351679) {
  H_10(state, unused, out_2875840076825351679);
}
void pose_h_13(double *state, double *unused, double *out_7313132045476290120) {
  h_13(state, unused, out_7313132045476290120);
}
void pose_H_13(double *state, double *unused, double *out_1014770803939832971) {
  H_13(state, unused, out_1014770803939832971);
}
void pose_h_14(double *state, double *unused, double *out_7899393187456188913) {
  h_14(state, unused, out_7899393187456188913);
}
void pose_H_14(double *state, double *unused, double *out_1765737834946984699) {
  H_14(state, unused, out_1765737834946984699);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
