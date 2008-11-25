/* File: memory.h
 * $Author$
 * $Date::                            $
 * Descr: definitions of functions for memory allocation and freeing; also includes overflows checks
 *
 * Copyright (C) 2006-2008 University of Amsterdam
 * This file is part of ADDA.
 *
 * ADDA is free software: you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * ADDA is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with ADDA. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef __memory_h
#define __memory_h

#include <stddef.h>   // for size_t
#include "function.h" // for function attributes

#define MBYTE 1048576.0
// for conciseness
#define OTHER_ARGUMENTS const int who,const char *fname,const int line,const char *name

void CheckOverflow(double size,OTHER_ARGUMENTS);
size_t MultOverflow(size_t a,size_t b,OTHER_ARGUMENTS);
// allocate
doublecomplex *complexVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
double **doubleMatrix(size_t rows,size_t cols,OTHER_ARGUMENTS) ATT_MALLOC;
double *doubleVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
double *doubleVector2(size_t nl,size_t nh,OTHER_ARGUMENTS) ATT_MALLOC;
int **intMatrix (size_t nrl,size_t nrh,size_t ncl,size_t nch,OTHER_ARGUMENTS) ATT_MALLOC;
int *intVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
unsigned short *ushortVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
char *charVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
unsigned char *ucharVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
void *voidVector(size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
// reallocate
double *doubleRealloc(double *ptr,const size_t size,OTHER_ARGUMENTS) ATT_MALLOC;
// free
void Free_cVector(doublecomplex *v);
void Free_dMatrix(double **m,size_t rows);
void Free_dVector2(double *v,size_t nl);
void Free_iMatrix(int **m,size_t nrl,size_t nrh,size_t ncl);
void Free_general(void *v);

// macros to use for allocation and reallocation
#define MALLOC_VECTOR(vec,type,size,who) vec=type##Vector(size,who,POSIT,#vec)
#define MALLOC_DVECTOR2(vec,nl,nh,who) vec=doubleVector2(nl,nh,who,POSIT,#vec)
#define MALLOC_DMATRIX(vec,rows,cols,who) vec=doubleMatrix(rows,cols,who,POSIT,#vec)
#define MALLOC_IMATRIX(vec,nrl,nrh,ncl,nch,who) vec=intMatrix(nrl,nrh,ncl,nch,who,POSIT,#vec)
#define REALLOC_DVECTOR(vec,size,who) vec=doubleRealloc(vec,size,who,POSIT,#vec)

#endif //__memory_h