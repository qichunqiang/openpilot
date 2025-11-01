#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6693988935871502641);
void live_err_fun(double *nom_x, double *delta_x, double *out_2501913548150572982);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6642882679806618776);
void live_H_mod_fun(double *state, double *out_3343747777747245400);
void live_f_fun(double *state, double dt, double *out_4682205214969107414);
void live_F_fun(double *state, double dt, double *out_4631235499101007584);
void live_h_4(double *state, double *unused, double *out_6255229089832981131);
void live_H_4(double *state, double *unused, double *out_6988140207866823461);
void live_h_9(double *state, double *unused, double *out_8439469344227442657);
void live_H_9(double *state, double *unused, double *out_4171384930578280685);
void live_h_10(double *state, double *unused, double *out_6751049804481693894);
void live_H_10(double *state, double *unused, double *out_2329824037372097514);
void live_h_12(double *state, double *unused, double *out_6055697972697186546);
void live_H_12(double *state, double *unused, double *out_6439147457810766360);
void live_h_35(double *state, double *unused, double *out_5662705662350387353);
void live_H_35(double *state, double *unused, double *out_3693584425485752651);
void live_h_32(double *state, double *unused, double *out_260958475431226114);
void live_H_32(double *state, double *unused, double *out_6136103027567521767);
void live_h_13(double *state, double *unused, double *out_5105127733932351968);
void live_H_13(double *state, double *unused, double *out_2472811404085735039);
void live_h_14(double *state, double *unused, double *out_8439469344227442657);
void live_H_14(double *state, double *unused, double *out_4171384930578280685);
void live_h_33(double *state, double *unused, double *out_7675513282673685946);
void live_H_33(double *state, double *unused, double *out_543027420846895047);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}