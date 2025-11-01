#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2440499843507941394);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2064779874113896738);
void car_H_mod_fun(double *state, double *out_8685934565314902148);
void car_f_fun(double *state, double dt, double *out_3569315504279299196);
void car_F_fun(double *state, double dt, double *out_7786780943589601504);
void car_h_25(double *state, double *unused, double *out_2813877564209405637);
void car_H_25(double *state, double *unused, double *out_3263786548504619517);
void car_h_24(double *state, double *unused, double *out_7617080211086229333);
void car_H_24(double *state, double *unused, double *out_5511105859307551377);
void car_h_30(double *state, double *unused, double *out_4264508956838288804);
void car_H_30(double *state, double *unused, double *out_3134447601361379447);
void car_h_26(double *state, double *unused, double *out_848235667189218788);
void car_H_26(double *state, double *unused, double *out_477716770369436707);
void car_h_27(double *state, double *unused, double *out_8197723075071445166);
void car_H_27(double *state, double *unused, double *out_959684289560954536);
void car_h_29(double *state, double *unused, double *out_737164310822556841);
void car_H_29(double *state, double *unused, double *out_753678437308596497);
void car_h_28(double *state, double *unused, double *out_7254213222169782731);
void car_H_28(double *state, double *unused, double *out_5836077454378127071);
void car_h_31(double *state, double *unused, double *out_3956957662140945299);
void car_H_31(double *state, double *unused, double *out_3294432510381579945);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}