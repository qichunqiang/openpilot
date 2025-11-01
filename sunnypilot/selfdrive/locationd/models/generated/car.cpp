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
void err_fun(double *nom_x, double *delta_x, double *out_2440499843507941394) {
   out_2440499843507941394[0] = delta_x[0] + nom_x[0];
   out_2440499843507941394[1] = delta_x[1] + nom_x[1];
   out_2440499843507941394[2] = delta_x[2] + nom_x[2];
   out_2440499843507941394[3] = delta_x[3] + nom_x[3];
   out_2440499843507941394[4] = delta_x[4] + nom_x[4];
   out_2440499843507941394[5] = delta_x[5] + nom_x[5];
   out_2440499843507941394[6] = delta_x[6] + nom_x[6];
   out_2440499843507941394[7] = delta_x[7] + nom_x[7];
   out_2440499843507941394[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2064779874113896738) {
   out_2064779874113896738[0] = -nom_x[0] + true_x[0];
   out_2064779874113896738[1] = -nom_x[1] + true_x[1];
   out_2064779874113896738[2] = -nom_x[2] + true_x[2];
   out_2064779874113896738[3] = -nom_x[3] + true_x[3];
   out_2064779874113896738[4] = -nom_x[4] + true_x[4];
   out_2064779874113896738[5] = -nom_x[5] + true_x[5];
   out_2064779874113896738[6] = -nom_x[6] + true_x[6];
   out_2064779874113896738[7] = -nom_x[7] + true_x[7];
   out_2064779874113896738[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8685934565314902148) {
   out_8685934565314902148[0] = 1.0;
   out_8685934565314902148[1] = 0.0;
   out_8685934565314902148[2] = 0.0;
   out_8685934565314902148[3] = 0.0;
   out_8685934565314902148[4] = 0.0;
   out_8685934565314902148[5] = 0.0;
   out_8685934565314902148[6] = 0.0;
   out_8685934565314902148[7] = 0.0;
   out_8685934565314902148[8] = 0.0;
   out_8685934565314902148[9] = 0.0;
   out_8685934565314902148[10] = 1.0;
   out_8685934565314902148[11] = 0.0;
   out_8685934565314902148[12] = 0.0;
   out_8685934565314902148[13] = 0.0;
   out_8685934565314902148[14] = 0.0;
   out_8685934565314902148[15] = 0.0;
   out_8685934565314902148[16] = 0.0;
   out_8685934565314902148[17] = 0.0;
   out_8685934565314902148[18] = 0.0;
   out_8685934565314902148[19] = 0.0;
   out_8685934565314902148[20] = 1.0;
   out_8685934565314902148[21] = 0.0;
   out_8685934565314902148[22] = 0.0;
   out_8685934565314902148[23] = 0.0;
   out_8685934565314902148[24] = 0.0;
   out_8685934565314902148[25] = 0.0;
   out_8685934565314902148[26] = 0.0;
   out_8685934565314902148[27] = 0.0;
   out_8685934565314902148[28] = 0.0;
   out_8685934565314902148[29] = 0.0;
   out_8685934565314902148[30] = 1.0;
   out_8685934565314902148[31] = 0.0;
   out_8685934565314902148[32] = 0.0;
   out_8685934565314902148[33] = 0.0;
   out_8685934565314902148[34] = 0.0;
   out_8685934565314902148[35] = 0.0;
   out_8685934565314902148[36] = 0.0;
   out_8685934565314902148[37] = 0.0;
   out_8685934565314902148[38] = 0.0;
   out_8685934565314902148[39] = 0.0;
   out_8685934565314902148[40] = 1.0;
   out_8685934565314902148[41] = 0.0;
   out_8685934565314902148[42] = 0.0;
   out_8685934565314902148[43] = 0.0;
   out_8685934565314902148[44] = 0.0;
   out_8685934565314902148[45] = 0.0;
   out_8685934565314902148[46] = 0.0;
   out_8685934565314902148[47] = 0.0;
   out_8685934565314902148[48] = 0.0;
   out_8685934565314902148[49] = 0.0;
   out_8685934565314902148[50] = 1.0;
   out_8685934565314902148[51] = 0.0;
   out_8685934565314902148[52] = 0.0;
   out_8685934565314902148[53] = 0.0;
   out_8685934565314902148[54] = 0.0;
   out_8685934565314902148[55] = 0.0;
   out_8685934565314902148[56] = 0.0;
   out_8685934565314902148[57] = 0.0;
   out_8685934565314902148[58] = 0.0;
   out_8685934565314902148[59] = 0.0;
   out_8685934565314902148[60] = 1.0;
   out_8685934565314902148[61] = 0.0;
   out_8685934565314902148[62] = 0.0;
   out_8685934565314902148[63] = 0.0;
   out_8685934565314902148[64] = 0.0;
   out_8685934565314902148[65] = 0.0;
   out_8685934565314902148[66] = 0.0;
   out_8685934565314902148[67] = 0.0;
   out_8685934565314902148[68] = 0.0;
   out_8685934565314902148[69] = 0.0;
   out_8685934565314902148[70] = 1.0;
   out_8685934565314902148[71] = 0.0;
   out_8685934565314902148[72] = 0.0;
   out_8685934565314902148[73] = 0.0;
   out_8685934565314902148[74] = 0.0;
   out_8685934565314902148[75] = 0.0;
   out_8685934565314902148[76] = 0.0;
   out_8685934565314902148[77] = 0.0;
   out_8685934565314902148[78] = 0.0;
   out_8685934565314902148[79] = 0.0;
   out_8685934565314902148[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3569315504279299196) {
   out_3569315504279299196[0] = state[0];
   out_3569315504279299196[1] = state[1];
   out_3569315504279299196[2] = state[2];
   out_3569315504279299196[3] = state[3];
   out_3569315504279299196[4] = state[4];
   out_3569315504279299196[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3569315504279299196[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3569315504279299196[7] = state[7];
   out_3569315504279299196[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7786780943589601504) {
   out_7786780943589601504[0] = 1;
   out_7786780943589601504[1] = 0;
   out_7786780943589601504[2] = 0;
   out_7786780943589601504[3] = 0;
   out_7786780943589601504[4] = 0;
   out_7786780943589601504[5] = 0;
   out_7786780943589601504[6] = 0;
   out_7786780943589601504[7] = 0;
   out_7786780943589601504[8] = 0;
   out_7786780943589601504[9] = 0;
   out_7786780943589601504[10] = 1;
   out_7786780943589601504[11] = 0;
   out_7786780943589601504[12] = 0;
   out_7786780943589601504[13] = 0;
   out_7786780943589601504[14] = 0;
   out_7786780943589601504[15] = 0;
   out_7786780943589601504[16] = 0;
   out_7786780943589601504[17] = 0;
   out_7786780943589601504[18] = 0;
   out_7786780943589601504[19] = 0;
   out_7786780943589601504[20] = 1;
   out_7786780943589601504[21] = 0;
   out_7786780943589601504[22] = 0;
   out_7786780943589601504[23] = 0;
   out_7786780943589601504[24] = 0;
   out_7786780943589601504[25] = 0;
   out_7786780943589601504[26] = 0;
   out_7786780943589601504[27] = 0;
   out_7786780943589601504[28] = 0;
   out_7786780943589601504[29] = 0;
   out_7786780943589601504[30] = 1;
   out_7786780943589601504[31] = 0;
   out_7786780943589601504[32] = 0;
   out_7786780943589601504[33] = 0;
   out_7786780943589601504[34] = 0;
   out_7786780943589601504[35] = 0;
   out_7786780943589601504[36] = 0;
   out_7786780943589601504[37] = 0;
   out_7786780943589601504[38] = 0;
   out_7786780943589601504[39] = 0;
   out_7786780943589601504[40] = 1;
   out_7786780943589601504[41] = 0;
   out_7786780943589601504[42] = 0;
   out_7786780943589601504[43] = 0;
   out_7786780943589601504[44] = 0;
   out_7786780943589601504[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7786780943589601504[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7786780943589601504[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7786780943589601504[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7786780943589601504[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7786780943589601504[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7786780943589601504[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7786780943589601504[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7786780943589601504[53] = -9.8100000000000005*dt;
   out_7786780943589601504[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7786780943589601504[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7786780943589601504[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7786780943589601504[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7786780943589601504[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7786780943589601504[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7786780943589601504[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7786780943589601504[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7786780943589601504[62] = 0;
   out_7786780943589601504[63] = 0;
   out_7786780943589601504[64] = 0;
   out_7786780943589601504[65] = 0;
   out_7786780943589601504[66] = 0;
   out_7786780943589601504[67] = 0;
   out_7786780943589601504[68] = 0;
   out_7786780943589601504[69] = 0;
   out_7786780943589601504[70] = 1;
   out_7786780943589601504[71] = 0;
   out_7786780943589601504[72] = 0;
   out_7786780943589601504[73] = 0;
   out_7786780943589601504[74] = 0;
   out_7786780943589601504[75] = 0;
   out_7786780943589601504[76] = 0;
   out_7786780943589601504[77] = 0;
   out_7786780943589601504[78] = 0;
   out_7786780943589601504[79] = 0;
   out_7786780943589601504[80] = 1;
}
void h_25(double *state, double *unused, double *out_2813877564209405637) {
   out_2813877564209405637[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3263786548504619517) {
   out_3263786548504619517[0] = 0;
   out_3263786548504619517[1] = 0;
   out_3263786548504619517[2] = 0;
   out_3263786548504619517[3] = 0;
   out_3263786548504619517[4] = 0;
   out_3263786548504619517[5] = 0;
   out_3263786548504619517[6] = 1;
   out_3263786548504619517[7] = 0;
   out_3263786548504619517[8] = 0;
}
void h_24(double *state, double *unused, double *out_7617080211086229333) {
   out_7617080211086229333[0] = state[4];
   out_7617080211086229333[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5511105859307551377) {
   out_5511105859307551377[0] = 0;
   out_5511105859307551377[1] = 0;
   out_5511105859307551377[2] = 0;
   out_5511105859307551377[3] = 0;
   out_5511105859307551377[4] = 1;
   out_5511105859307551377[5] = 0;
   out_5511105859307551377[6] = 0;
   out_5511105859307551377[7] = 0;
   out_5511105859307551377[8] = 0;
   out_5511105859307551377[9] = 0;
   out_5511105859307551377[10] = 0;
   out_5511105859307551377[11] = 0;
   out_5511105859307551377[12] = 0;
   out_5511105859307551377[13] = 0;
   out_5511105859307551377[14] = 1;
   out_5511105859307551377[15] = 0;
   out_5511105859307551377[16] = 0;
   out_5511105859307551377[17] = 0;
}
void h_30(double *state, double *unused, double *out_4264508956838288804) {
   out_4264508956838288804[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3134447601361379447) {
   out_3134447601361379447[0] = 0;
   out_3134447601361379447[1] = 0;
   out_3134447601361379447[2] = 0;
   out_3134447601361379447[3] = 0;
   out_3134447601361379447[4] = 1;
   out_3134447601361379447[5] = 0;
   out_3134447601361379447[6] = 0;
   out_3134447601361379447[7] = 0;
   out_3134447601361379447[8] = 0;
}
void h_26(double *state, double *unused, double *out_848235667189218788) {
   out_848235667189218788[0] = state[7];
}
void H_26(double *state, double *unused, double *out_477716770369436707) {
   out_477716770369436707[0] = 0;
   out_477716770369436707[1] = 0;
   out_477716770369436707[2] = 0;
   out_477716770369436707[3] = 0;
   out_477716770369436707[4] = 0;
   out_477716770369436707[5] = 0;
   out_477716770369436707[6] = 0;
   out_477716770369436707[7] = 1;
   out_477716770369436707[8] = 0;
}
void h_27(double *state, double *unused, double *out_8197723075071445166) {
   out_8197723075071445166[0] = state[3];
}
void H_27(double *state, double *unused, double *out_959684289560954536) {
   out_959684289560954536[0] = 0;
   out_959684289560954536[1] = 0;
   out_959684289560954536[2] = 0;
   out_959684289560954536[3] = 1;
   out_959684289560954536[4] = 0;
   out_959684289560954536[5] = 0;
   out_959684289560954536[6] = 0;
   out_959684289560954536[7] = 0;
   out_959684289560954536[8] = 0;
}
void h_29(double *state, double *unused, double *out_737164310822556841) {
   out_737164310822556841[0] = state[1];
}
void H_29(double *state, double *unused, double *out_753678437308596497) {
   out_753678437308596497[0] = 0;
   out_753678437308596497[1] = 1;
   out_753678437308596497[2] = 0;
   out_753678437308596497[3] = 0;
   out_753678437308596497[4] = 0;
   out_753678437308596497[5] = 0;
   out_753678437308596497[6] = 0;
   out_753678437308596497[7] = 0;
   out_753678437308596497[8] = 0;
}
void h_28(double *state, double *unused, double *out_7254213222169782731) {
   out_7254213222169782731[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5836077454378127071) {
   out_5836077454378127071[0] = 1;
   out_5836077454378127071[1] = 0;
   out_5836077454378127071[2] = 0;
   out_5836077454378127071[3] = 0;
   out_5836077454378127071[4] = 0;
   out_5836077454378127071[5] = 0;
   out_5836077454378127071[6] = 0;
   out_5836077454378127071[7] = 0;
   out_5836077454378127071[8] = 0;
}
void h_31(double *state, double *unused, double *out_3956957662140945299) {
   out_3956957662140945299[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3294432510381579945) {
   out_3294432510381579945[0] = 0;
   out_3294432510381579945[1] = 0;
   out_3294432510381579945[2] = 0;
   out_3294432510381579945[3] = 0;
   out_3294432510381579945[4] = 0;
   out_3294432510381579945[5] = 0;
   out_3294432510381579945[6] = 0;
   out_3294432510381579945[7] = 0;
   out_3294432510381579945[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_2440499843507941394) {
  err_fun(nom_x, delta_x, out_2440499843507941394);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2064779874113896738) {
  inv_err_fun(nom_x, true_x, out_2064779874113896738);
}
void car_H_mod_fun(double *state, double *out_8685934565314902148) {
  H_mod_fun(state, out_8685934565314902148);
}
void car_f_fun(double *state, double dt, double *out_3569315504279299196) {
  f_fun(state,  dt, out_3569315504279299196);
}
void car_F_fun(double *state, double dt, double *out_7786780943589601504) {
  F_fun(state,  dt, out_7786780943589601504);
}
void car_h_25(double *state, double *unused, double *out_2813877564209405637) {
  h_25(state, unused, out_2813877564209405637);
}
void car_H_25(double *state, double *unused, double *out_3263786548504619517) {
  H_25(state, unused, out_3263786548504619517);
}
void car_h_24(double *state, double *unused, double *out_7617080211086229333) {
  h_24(state, unused, out_7617080211086229333);
}
void car_H_24(double *state, double *unused, double *out_5511105859307551377) {
  H_24(state, unused, out_5511105859307551377);
}
void car_h_30(double *state, double *unused, double *out_4264508956838288804) {
  h_30(state, unused, out_4264508956838288804);
}
void car_H_30(double *state, double *unused, double *out_3134447601361379447) {
  H_30(state, unused, out_3134447601361379447);
}
void car_h_26(double *state, double *unused, double *out_848235667189218788) {
  h_26(state, unused, out_848235667189218788);
}
void car_H_26(double *state, double *unused, double *out_477716770369436707) {
  H_26(state, unused, out_477716770369436707);
}
void car_h_27(double *state, double *unused, double *out_8197723075071445166) {
  h_27(state, unused, out_8197723075071445166);
}
void car_H_27(double *state, double *unused, double *out_959684289560954536) {
  H_27(state, unused, out_959684289560954536);
}
void car_h_29(double *state, double *unused, double *out_737164310822556841) {
  h_29(state, unused, out_737164310822556841);
}
void car_H_29(double *state, double *unused, double *out_753678437308596497) {
  H_29(state, unused, out_753678437308596497);
}
void car_h_28(double *state, double *unused, double *out_7254213222169782731) {
  h_28(state, unused, out_7254213222169782731);
}
void car_H_28(double *state, double *unused, double *out_5836077454378127071) {
  H_28(state, unused, out_5836077454378127071);
}
void car_h_31(double *state, double *unused, double *out_3956957662140945299) {
  h_31(state, unused, out_3956957662140945299);
}
void car_H_31(double *state, double *unused, double *out_3294432510381579945) {
  H_31(state, unused, out_3294432510381579945);
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
