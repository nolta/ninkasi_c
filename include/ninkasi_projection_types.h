
#ifndef NINKASI_PROJECTION_TYPES_H
#define NINKASI_PROJECTION_TYPES_H

#include <ninkasi_defs.h>

typedef enum {
  NK_RECT,
  NK_CEA

} nkProjectionType;


typedef struct {
  nkProjectionType proj_type;
  
  actData radelt;  //maps to cdelt1
  actData decdelt; //maps to cdelt2

  int rapix; //maps to crpix1
  int decpix; //maps to crpix2
  actData pv;  //maps to pv2_1

  
} nkProjection;

#endif