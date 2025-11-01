#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_9136849521926011583) {
   out_9136849521926011583[0] = delta_x[0] + nom_x[0];
   out_9136849521926011583[1] = delta_x[1] + nom_x[1];
   out_9136849521926011583[2] = delta_x[2] + nom_x[2];
   out_9136849521926011583[3] = delta_x[3] + nom_x[3];
   out_9136849521926011583[4] = delta_x[4] + nom_x[4];
   out_9136849521926011583[5] = delta_x[5] + nom_x[5];
   out_9136849521926011583[6] = delta_x[6] + nom_x[6];
   out_9136849521926011583[7] = delta_x[7] + nom_x[7];
   out_9136849521926011583[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_241616271440707288) {
   out_241616271440707288[0] = -nom_x[0] + true_x[0];
   out_241616271440707288[1] = -nom_x[1] + true_x[1];
   out_241616271440707288[2] = -nom_x[2] + true_x[2];
   out_241616271440707288[3] = -nom_x[3] + true_x[3];
   out_241616271440707288[4] = -nom_x[4] + true_x[4];
   out_241616271440707288[5] = -nom_x[5] + true_x[5];
   out_241616271440707288[6] = -nom_x[6] + true_x[6];
   out_241616271440707288[7] = -nom_x[7] + true_x[7];
   out_241616271440707288[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4195783494232505601) {
   out_4195783494232505601[0] = 1.0;
   out_4195783494232505601[1] = 0.0;
   out_4195783494232505601[2] = 0.0;
   out_4195783494232505601[3] = 0.0;
   out_4195783494232505601[4] = 0.0;
   out_4195783494232505601[5] = 0.0;
   out_4195783494232505601[6] = 0.0;
   out_4195783494232505601[7] = 0.0;
   out_4195783494232505601[8] = 0.0;
   out_4195783494232505601[9] = 0.0;
   out_4195783494232505601[10] = 1.0;
   out_4195783494232505601[11] = 0.0;
   out_4195783494232505601[12] = 0.0;
   out_4195783494232505601[13] = 0.0;
   out_4195783494232505601[14] = 0.0;
   out_4195783494232505601[15] = 0.0;
   out_4195783494232505601[16] = 0.0;
   out_4195783494232505601[17] = 0.0;
   out_4195783494232505601[18] = 0.0;
   out_4195783494232505601[19] = 0.0;
   out_4195783494232505601[20] = 1.0;
   out_4195783494232505601[21] = 0.0;
   out_4195783494232505601[22] = 0.0;
   out_4195783494232505601[23] = 0.0;
   out_4195783494232505601[24] = 0.0;
   out_4195783494232505601[25] = 0.0;
   out_4195783494232505601[26] = 0.0;
   out_4195783494232505601[27] = 0.0;
   out_4195783494232505601[28] = 0.0;
   out_4195783494232505601[29] = 0.0;
   out_4195783494232505601[30] = 1.0;
   out_4195783494232505601[31] = 0.0;
   out_4195783494232505601[32] = 0.0;
   out_4195783494232505601[33] = 0.0;
   out_4195783494232505601[34] = 0.0;
   out_4195783494232505601[35] = 0.0;
   out_4195783494232505601[36] = 0.0;
   out_4195783494232505601[37] = 0.0;
   out_4195783494232505601[38] = 0.0;
   out_4195783494232505601[39] = 0.0;
   out_4195783494232505601[40] = 1.0;
   out_4195783494232505601[41] = 0.0;
   out_4195783494232505601[42] = 0.0;
   out_4195783494232505601[43] = 0.0;
   out_4195783494232505601[44] = 0.0;
   out_4195783494232505601[45] = 0.0;
   out_4195783494232505601[46] = 0.0;
   out_4195783494232505601[47] = 0.0;
   out_4195783494232505601[48] = 0.0;
   out_4195783494232505601[49] = 0.0;
   out_4195783494232505601[50] = 1.0;
   out_4195783494232505601[51] = 0.0;
   out_4195783494232505601[52] = 0.0;
   out_4195783494232505601[53] = 0.0;
   out_4195783494232505601[54] = 0.0;
   out_4195783494232505601[55] = 0.0;
   out_4195783494232505601[56] = 0.0;
   out_4195783494232505601[57] = 0.0;
   out_4195783494232505601[58] = 0.0;
   out_4195783494232505601[59] = 0.0;
   out_4195783494232505601[60] = 1.0;
   out_4195783494232505601[61] = 0.0;
   out_4195783494232505601[62] = 0.0;
   out_4195783494232505601[63] = 0.0;
   out_4195783494232505601[64] = 0.0;
   out_4195783494232505601[65] = 0.0;
   out_4195783494232505601[66] = 0.0;
   out_4195783494232505601[67] = 0.0;
   out_4195783494232505601[68] = 0.0;
   out_4195783494232505601[69] = 0.0;
   out_4195783494232505601[70] = 1.0;
   out_4195783494232505601[71] = 0.0;
   out_4195783494232505601[72] = 0.0;
   out_4195783494232505601[73] = 0.0;
   out_4195783494232505601[74] = 0.0;
   out_4195783494232505601[75] = 0.0;
   out_4195783494232505601[76] = 0.0;
   out_4195783494232505601[77] = 0.0;
   out_4195783494232505601[78] = 0.0;
   out_4195783494232505601[79] = 0.0;
   out_4195783494232505601[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7348746772834708743) {
   out_7348746772834708743[0] = state[0];
   out_7348746772834708743[1] = state[1];
   out_7348746772834708743[2] = state[2];
   out_7348746772834708743[3] = state[3];
   out_7348746772834708743[4] = state[4];
   out_7348746772834708743[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7348746772834708743[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7348746772834708743[7] = state[7];
   out_7348746772834708743[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6888329322770940807) {
   out_6888329322770940807[0] = 1;
   out_6888329322770940807[1] = 0;
   out_6888329322770940807[2] = 0;
   out_6888329322770940807[3] = 0;
   out_6888329322770940807[4] = 0;
   out_6888329322770940807[5] = 0;
   out_6888329322770940807[6] = 0;
   out_6888329322770940807[7] = 0;
   out_6888329322770940807[8] = 0;
   out_6888329322770940807[9] = 0;
   out_6888329322770940807[10] = 1;
   out_6888329322770940807[11] = 0;
   out_6888329322770940807[12] = 0;
   out_6888329322770940807[13] = 0;
   out_6888329322770940807[14] = 0;
   out_6888329322770940807[15] = 0;
   out_6888329322770940807[16] = 0;
   out_6888329322770940807[17] = 0;
   out_6888329322770940807[18] = 0;
   out_6888329322770940807[19] = 0;
   out_6888329322770940807[20] = 1;
   out_6888329322770940807[21] = 0;
   out_6888329322770940807[22] = 0;
   out_6888329322770940807[23] = 0;
   out_6888329322770940807[24] = 0;
   out_6888329322770940807[25] = 0;
   out_6888329322770940807[26] = 0;
   out_6888329322770940807[27] = 0;
   out_6888329322770940807[28] = 0;
   out_6888329322770940807[29] = 0;
   out_6888329322770940807[30] = 1;
   out_6888329322770940807[31] = 0;
   out_6888329322770940807[32] = 0;
   out_6888329322770940807[33] = 0;
   out_6888329322770940807[34] = 0;
   out_6888329322770940807[35] = 0;
   out_6888329322770940807[36] = 0;
   out_6888329322770940807[37] = 0;
   out_6888329322770940807[38] = 0;
   out_6888329322770940807[39] = 0;
   out_6888329322770940807[40] = 1;
   out_6888329322770940807[41] = 0;
   out_6888329322770940807[42] = 0;
   out_6888329322770940807[43] = 0;
   out_6888329322770940807[44] = 0;
   out_6888329322770940807[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6888329322770940807[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6888329322770940807[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6888329322770940807[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6888329322770940807[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6888329322770940807[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6888329322770940807[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6888329322770940807[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6888329322770940807[53] = -9.8100000000000005*dt;
   out_6888329322770940807[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6888329322770940807[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6888329322770940807[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6888329322770940807[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6888329322770940807[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6888329322770940807[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6888329322770940807[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6888329322770940807[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6888329322770940807[62] = 0;
   out_6888329322770940807[63] = 0;
   out_6888329322770940807[64] = 0;
   out_6888329322770940807[65] = 0;
   out_6888329322770940807[66] = 0;
   out_6888329322770940807[67] = 0;
   out_6888329322770940807[68] = 0;
   out_6888329322770940807[69] = 0;
   out_6888329322770940807[70] = 1;
   out_6888329322770940807[71] = 0;
   out_6888329322770940807[72] = 0;
   out_6888329322770940807[73] = 0;
   out_6888329322770940807[74] = 0;
   out_6888329322770940807[75] = 0;
   out_6888329322770940807[76] = 0;
   out_6888329322770940807[77] = 0;
   out_6888329322770940807[78] = 0;
   out_6888329322770940807[79] = 0;
   out_6888329322770940807[80] = 1;
}
void h_25(double *state, double *unused, double *out_5962696603336956321) {
   out_5962696603336956321[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6329622546503186210) {
   out_6329622546503186210[0] = 0;
   out_6329622546503186210[1] = 0;
   out_6329622546503186210[2] = 0;
   out_6329622546503186210[3] = 0;
   out_6329622546503186210[4] = 0;
   out_6329622546503186210[5] = 0;
   out_6329622546503186210[6] = 1;
   out_6329622546503186210[7] = 0;
   out_6329622546503186210[8] = 0;
}
void h_24(double *state, double *unused, double *out_2267212909003243917) {
   out_2267212909003243917[0] = state[4];
   out_2267212909003243917[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2771696947700863074) {
   out_2771696947700863074[0] = 0;
   out_2771696947700863074[1] = 0;
   out_2771696947700863074[2] = 0;
   out_2771696947700863074[3] = 0;
   out_2771696947700863074[4] = 1;
   out_2771696947700863074[5] = 0;
   out_2771696947700863074[6] = 0;
   out_2771696947700863074[7] = 0;
   out_2771696947700863074[8] = 0;
   out_2771696947700863074[9] = 0;
   out_2771696947700863074[10] = 0;
   out_2771696947700863074[11] = 0;
   out_2771696947700863074[12] = 0;
   out_2771696947700863074[13] = 0;
   out_2771696947700863074[14] = 1;
   out_2771696947700863074[15] = 0;
   out_2771696947700863074[16] = 0;
   out_2771696947700863074[17] = 0;
}
void h_30(double *state, double *unused, double *out_6119883271688085466) {
   out_6119883271688085466[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7589425197078757208) {
   out_7589425197078757208[0] = 0;
   out_7589425197078757208[1] = 0;
   out_7589425197078757208[2] = 0;
   out_7589425197078757208[3] = 0;
   out_7589425197078757208[4] = 1;
   out_7589425197078757208[5] = 0;
   out_7589425197078757208[6] = 0;
   out_7589425197078757208[7] = 0;
   out_7589425197078757208[8] = 0;
}
void h_26(double *state, double *unused, double *out_1315260162740615347) {
   out_1315260162740615347[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8375618208332309182) {
   out_8375618208332309182[0] = 0;
   out_8375618208332309182[1] = 0;
   out_8375618208332309182[2] = 0;
   out_8375618208332309182[3] = 0;
   out_8375618208332309182[4] = 0;
   out_8375618208332309182[5] = 0;
   out_8375618208332309182[6] = 0;
   out_8375618208332309182[7] = 1;
   out_8375618208332309182[8] = 0;
}
void h_27(double *state, double *unused, double *out_47065849603093985) {
   out_47065849603093985[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5414661885278332297) {
   out_5414661885278332297[0] = 0;
   out_5414661885278332297[1] = 0;
   out_5414661885278332297[2] = 0;
   out_5414661885278332297[3] = 1;
   out_5414661885278332297[4] = 0;
   out_5414661885278332297[5] = 0;
   out_5414661885278332297[6] = 0;
   out_5414661885278332297[7] = 0;
   out_5414661885278332297[8] = 0;
}
void h_29(double *state, double *unused, double *out_2900660140752390976) {
   out_2900660140752390976[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8099656541393149392) {
   out_8099656541393149392[0] = 0;
   out_8099656541393149392[1] = 1;
   out_8099656541393149392[2] = 0;
   out_8099656541393149392[3] = 0;
   out_8099656541393149392[4] = 0;
   out_8099656541393149392[5] = 0;
   out_8099656541393149392[6] = 0;
   out_8099656541393149392[7] = 0;
   out_8099656541393149392[8] = 0;
}
void h_28(double *state, double *unused, double *out_8503751566026600175) {
   out_8503751566026600175[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3017257524323618818) {
   out_3017257524323618818[0] = 1;
   out_3017257524323618818[1] = 0;
   out_3017257524323618818[2] = 0;
   out_3017257524323618818[3] = 0;
   out_3017257524323618818[4] = 0;
   out_3017257524323618818[5] = 0;
   out_3017257524323618818[6] = 0;
   out_3017257524323618818[7] = 0;
   out_3017257524323618818[8] = 0;
}
void h_31(double *state, double *unused, double *out_6237890665621462210) {
   out_6237890665621462210[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7749410106098957706) {
   out_7749410106098957706[0] = 0;
   out_7749410106098957706[1] = 0;
   out_7749410106098957706[2] = 0;
   out_7749410106098957706[3] = 0;
   out_7749410106098957706[4] = 0;
   out_7749410106098957706[5] = 0;
   out_7749410106098957706[6] = 0;
   out_7749410106098957706[7] = 0;
   out_7749410106098957706[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_9136849521926011583) {
  err_fun(nom_x, delta_x, out_9136849521926011583);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_241616271440707288) {
  inv_err_fun(nom_x, true_x, out_241616271440707288);
}
void car_H_mod_fun(double *state, double *out_4195783494232505601) {
  H_mod_fun(state, out_4195783494232505601);
}
void car_f_fun(double *state, double dt, double *out_7348746772834708743) {
  f_fun(state,  dt, out_7348746772834708743);
}
void car_F_fun(double *state, double dt, double *out_6888329322770940807) {
  F_fun(state,  dt, out_6888329322770940807);
}
void car_h_25(double *state, double *unused, double *out_5962696603336956321) {
  h_25(state, unused, out_5962696603336956321);
}
void car_H_25(double *state, double *unused, double *out_6329622546503186210) {
  H_25(state, unused, out_6329622546503186210);
}
void car_h_24(double *state, double *unused, double *out_2267212909003243917) {
  h_24(state, unused, out_2267212909003243917);
}
void car_H_24(double *state, double *unused, double *out_2771696947700863074) {
  H_24(state, unused, out_2771696947700863074);
}
void car_h_30(double *state, double *unused, double *out_6119883271688085466) {
  h_30(state, unused, out_6119883271688085466);
}
void car_H_30(double *state, double *unused, double *out_7589425197078757208) {
  H_30(state, unused, out_7589425197078757208);
}
void car_h_26(double *state, double *unused, double *out_1315260162740615347) {
  h_26(state, unused, out_1315260162740615347);
}
void car_H_26(double *state, double *unused, double *out_8375618208332309182) {
  H_26(state, unused, out_8375618208332309182);
}
void car_h_27(double *state, double *unused, double *out_47065849603093985) {
  h_27(state, unused, out_47065849603093985);
}
void car_H_27(double *state, double *unused, double *out_5414661885278332297) {
  H_27(state, unused, out_5414661885278332297);
}
void car_h_29(double *state, double *unused, double *out_2900660140752390976) {
  h_29(state, unused, out_2900660140752390976);
}
void car_H_29(double *state, double *unused, double *out_8099656541393149392) {
  H_29(state, unused, out_8099656541393149392);
}
void car_h_28(double *state, double *unused, double *out_8503751566026600175) {
  h_28(state, unused, out_8503751566026600175);
}
void car_H_28(double *state, double *unused, double *out_3017257524323618818) {
  H_28(state, unused, out_3017257524323618818);
}
void car_h_31(double *state, double *unused, double *out_6237890665621462210) {
  h_31(state, unused, out_6237890665621462210);
}
void car_H_31(double *state, double *unused, double *out_7749410106098957706) {
  H_31(state, unused, out_7749410106098957706);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
