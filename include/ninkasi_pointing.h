#ifndef NINKASI_POINTING_H
#define NINKASI_POINTING_H
#ifndef MAKEFILE_HAND
#include "config.h"
#endif
#include "ninkasi.h"
#include "ninkasi_mathutils.h"

#define NINKASI_DO_RADEC 1
#define NINKASI_DO_TWOGAMMA 2


typedef struct {
  actData *ra;
  actData *dec;
  actData *alt;
  actData *az;
  actData *tod_alt;
  actData *tod_az;

  actData *az_coarse;
  actData *alt_coarse;
  actData *ra_coarse;
  actData *dec_coarse;
  actData *time_coarse;

#ifdef ACTPOL
  actData *sin2gamma;
  actData *cos2gamma;
  actData *sin2gamma_coarse;
  actData *cos2gamma_coarse;
#endif

  PointingFit *pointing_fit; 
} PointingFitScratch;

/*--------------------------------------------------------------------------------*/

void destroy_pointing_fit_raw(PointingFit *fit);
void destroy_pointing_fit(mbTOD *tod);
void assign_tod_ra_dec(mbTOD *tod);
void set_tod_pointing_tiled(mbTOD *tod, actData *azvec, int naz, actData *altvec, int nalt, actData **ra_mat, actData **dec_mat, actData *ra_clock, actData *dec_clock, int nclock);

void cut_mispointed_detectors(mbTOD *tod);
mbPointingOffset *nkReadPointingOffset(const char *filename);
void find_tod_radec_lims(mbTOD *tod);

void set_tod_starting_altaz_ctime(mbTOD *tod, actData alt, actData az, double ctime);


void get_radec_from_altaz_fit_tiled(const TiledPointingFit *tile, actData *alt, actData *az, actData *ctime, actData *ra, actData *dec, int npoint);
void get_radec_from_altaz_exact_1det(const mbTOD *tod,int det,    PointingFitScratch *scratch);
void get_radec_from_altaz_fit_1det(const mbTOD *tod,int det, PointingFitScratch *scratch);
void get_radec_from_altaz_fit_1det_coarse(const mbTOD *tod, int det, PointingFitScratch *scratch);
void get_radec_from_altaz_fit_1det_coarse_exact(const mbTOD *tod, int det, PointingFitScratch *scratch);
actData find_max_pointing_err(const mbTOD *tod);

void destroy_pointing_fit_scratch(PointingFitScratch *scratch);
PointingFitScratch *allocate_pointing_fit_scratch(const mbTOD *tod);
mbPointingOffset *nkPointingOffsetAlloc(int nrow,int ncol,int fitType);

void destroy_pointing_offset(mbPointingOffset *pt);
int *find_az_turnarounds(mbTOD *tod, int *nturn);
void find_pointing_pivots(mbTOD *tod, actData tol);
void shift_tod_pointing(mbTOD *tod, actData ra_shift, actData dec_shift);
int act_observed_altaz_to_mean_radec( const Site *site, double freq_GHz,
        int n, const double ctime[], const actData alt[], const actData az[],
				      actData ra[], actData dec[] );
#ifdef ACTPOL
ACTpolPointingFit *initialize_actpol_pointing(mbTOD *tod, actData *dx, actData *dy, actData *angle, actData freq,int dpiv);
ACTpolPointingFit *update_actpol_pointing(mbTOD *tod, actData *dx, actData *dy, actData *angle, actData freq,int dpiv);
void precalc_actpol_pointing_exact(mbTOD *tod,int op_flag);
void precalc_actpol_pointing(mbTOD *tod);
void precalc_actpol_pointing_free(mbTOD *tod);
void find_tod_radec_lims_actpol_pointing_exact(mbTOD *tod,actData rawrap);
void get_radec_one_det_actpol(mbTOD *tod,int det,PointingFitScratch *scratch);
void get_radec_from_altaz_actpol_c(double *az, double *el, double *tvec, double *dx, double *dy, double *theta, double *ra, double *dec, int nhorns, int nt);


#endif

#endif

