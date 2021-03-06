/*
 * GL2PS, an OpenGL to PostScript Printing Library
 * Copyright (C) 1999-2006 Christophe Geuzaine <geuz@geuz.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of either:
 *
 * a) the GNU Library General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your
 * option) any later version; or
 *
 * b) the GL2PS License as published by Christophe Geuzaine, either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See either
 * the GNU Library General Public License or the GL2PS License for
 * more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library in the file named "COPYING.LGPL";
 * if not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 *
 * You should have received a copy of the GL2PS License with this
 * library in the file named "COPYING.GL2PS"; if not, I will be glad
 * to provide one.
 *
 * For the latest info about gl2ps, see http://www.geuz.org/gl2ps/.
 * Please report all bugs and problems to <gl2ps@geuz.org>.
 */

#ifndef __GL2PS_H__
#define __GL2PS_H__

#include <stdio.h>
#include <stdlib.h>

/* Define GL2PSDLL at compile time to build a Windows DLL */

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  if defined(_MSC_VER)
#    pragma warning(disable:4115)
#  endif
#  include <windows.h>
#  if defined(GL2PSDLL)
#    if defined(GL2PSDLL_EXPORTS)
#      define GL2PSDLL_API __declspec(dllexport)
#    else
#      define GL2PSDLL_API __declspec(dllimport)
#    endif
#  else
#    define GL2PSDLL_API
#  endif
#else
#  define GL2PSDLL_API
#endif

/*G.Barrand : begin :*/
typedef unsigned int   gl2ps_uint;
typedef unsigned short gl2ps_ushort;
#define gl2ps_GLint    int
#define gl2ps_GLfloat  float
#define gl2ps_GLenum   gl2ps_uint
#define gl2ps_GLshort  short
#define gl2ps_GLushort gl2ps_ushort
#define gl2ps_GLsizei  int
#define GL2PS_GL_RGBA  0x1908
/*G.Barrand : end.*/

/* Support for compressed PostScript/PDF/SVG and for embedded PNG
   images in SVG */

/*G.Barrand : begin :*/
#if defined(HAVE_ZLIB) || defined(HAVE_LIBZ)
#  define GL2PS_HAVE_ZLIB
#  if defined(HAVE_LIBPNG) || defined(HAVE_PNG)
#    define GL2PS_HAVE_LIBPNG
#  endif
#endif
/*G.Barrand : end.*/

/* Version number */

#define GL2PS_MAJOR_VERSION 1
#define GL2PS_MINOR_VERSION 3
#define GL2PS_PATCH_VERSION 2
#define GL2PS_EXTRA_VERSION ""

#define GL2PS_VERSION (GL2PS_MAJOR_VERSION + \
                       0.01 * GL2PS_MINOR_VERSION + \
                       0.0001 * GL2PS_PATCH_VERSION)

#define GL2PS_COPYRIGHT "(C) 1999-2006 Christophe Geuzaine (geuz@geuz.org)"

/* Output file formats (the values and the ordering are important!) */

#define GL2PS_PS  0
#define GL2PS_EPS 1
#define GL2PS_TEX 2
#define GL2PS_PDF 3
#define GL2PS_SVG 4
#define GL2PS_PGF 5

/* Sorting algorithms */

#define GL2PS_NO_SORT     1
#define GL2PS_SIMPLE_SORT 2
#define GL2PS_BSP_SORT    3

/* Message levels and error codes */

#define GL2PS_SUCCESS       0
#define GL2PS_INFO          1
#define GL2PS_WARNING       2
#define GL2PS_ERROR         3
#define GL2PS_NO_FEEDBACK   4
#define GL2PS_OVERFLOW      5
#define GL2PS_UNINITIALIZED 6

/* Options for gl2psBeginPage */

#define GL2PS_NONE                 0
#define GL2PS_DRAW_BACKGROUND      (1<<0)
#define GL2PS_SIMPLE_LINE_OFFSET   (1<<1)
#define GL2PS_SILENT               (1<<2)
#define GL2PS_BEST_ROOT            (1<<3)
#define GL2PS_OCCLUSION_CULL       (1<<4)
#define GL2PS_NO_TEXT              (1<<5)
#define GL2PS_LANDSCAPE            (1<<6)
#define GL2PS_NO_PS3_SHADING       (1<<7)
#define GL2PS_NO_PIXMAP            (1<<8)
#define GL2PS_USE_CURRENT_VIEWPORT (1<<9)
#define GL2PS_COMPRESS             (1<<10)
#define GL2PS_NO_BLENDING          (1<<11)
#define GL2PS_TIGHT_BOUNDING_BOX   (1<<12)

/* Arguments for gl2psEnable/gl2psDisable */

#define GL2PS_POLYGON_OFFSET_FILL 1
#define GL2PS_POLYGON_BOUNDARY    2
#define GL2PS_LINE_STIPPLE        3
#define GL2PS_BLEND               4

/* Text alignment (o=raster position; default mode is BL):
   +---+ +---+ +---+ +---+ +---+ +---+ +-o-+ o---+ +---o 
   | o | o   | |   o |   | |   | |   | |   | |   | |   | 
   +---+ +---+ +---+ +-o-+ o---+ +---o +---+ +---+ +---+ 
    C     CL    CR    B     BL    BR    T     TL    TR */

#define GL2PS_TEXT_C  1
#define GL2PS_TEXT_CL 2
#define GL2PS_TEXT_CR 3
#define GL2PS_TEXT_B  4
#define GL2PS_TEXT_BL 5
#define GL2PS_TEXT_BR 6
#define GL2PS_TEXT_T  7
#define GL2PS_TEXT_TL 8
#define GL2PS_TEXT_TR 9

typedef gl2ps_GLfloat GL2PSrgba[4];

#if defined(__cplusplus)
extern "C" {
#endif

GL2PSDLL_API gl2ps_GLint gl2psBeginPage(const char *title, const char *producer, 
                                  gl2ps_GLint viewport[4], gl2ps_GLint format, gl2ps_GLint sort,
                                  gl2ps_GLint options, gl2ps_GLint colormode,
                                  gl2ps_GLint colorsize, GL2PSrgba *colormap, 
                                  gl2ps_GLint nr, gl2ps_GLint ng, gl2ps_GLint nb, gl2ps_GLint buffersize,
                                  FILE *stream, const char *filename);
GL2PSDLL_API gl2ps_GLint gl2psEndPage(void);
GL2PSDLL_API gl2ps_GLint gl2psSetOptions(gl2ps_GLint options);
GL2PSDLL_API gl2ps_GLint gl2psBeginViewport(gl2ps_GLint viewport[4]);
GL2PSDLL_API gl2ps_GLint gl2psEndViewport(void);
GL2PSDLL_API gl2ps_GLint gl2psText(const char *str, const char *fontname, 
                             gl2ps_GLshort fontsize);
GL2PSDLL_API gl2ps_GLint gl2psTextOpt(const char *str, const char *fontname, 
                                gl2ps_GLshort fontsize, gl2ps_GLint align, gl2ps_GLfloat angle);
GL2PSDLL_API gl2ps_GLint gl2psSpecial(gl2ps_GLint format, const char *str);
GL2PSDLL_API gl2ps_GLint gl2psDrawPixels(gl2ps_GLsizei width, gl2ps_GLsizei height,
                                   gl2ps_GLint xorig, gl2ps_GLint yorig,
                                   gl2ps_GLenum format, gl2ps_GLenum type, const void *pixels);
GL2PSDLL_API gl2ps_GLint gl2psEnable(gl2ps_GLint mode);
GL2PSDLL_API gl2ps_GLint gl2psDisable(gl2ps_GLint mode);
GL2PSDLL_API gl2ps_GLint gl2psPointSize(gl2ps_GLfloat value);
GL2PSDLL_API gl2ps_GLint gl2psLineWidth(gl2ps_GLfloat value);
GL2PSDLL_API gl2ps_GLint gl2psBlendFunc(gl2ps_GLenum sfactor, gl2ps_GLenum dfactor);

/* undocumented */
GL2PSDLL_API gl2ps_GLint gl2psDrawImageMap(gl2ps_GLsizei width, gl2ps_GLsizei height,
                                     const gl2ps_GLfloat position[3],
                                     const unsigned char *imagemap);
GL2PSDLL_API const char *gl2psGetFileExtension(gl2ps_GLint format);
GL2PSDLL_API const char *gl2psGetFormatDescription(gl2ps_GLint format);

/*G.Barrand*/
GL2PSDLL_API gl2ps_GLint gl2psGetOptions(gl2ps_GLint* options);
GL2PSDLL_API gl2ps_GLint gl2psSetBackgroundColor(float r,float g,float b);

#if defined(__cplusplus)
}
#endif

/*G.Barrand : begin :*/
typedef unsigned char  gl2ps_GLboolean;

typedef struct {
  gl2ps_GLboolean (*m_glIsEnabled)      (gl2ps_GLenum);
  void            (*m_glBegin)          (gl2ps_GLenum);
  void            (*m_glEnd)            ();
  void            (*m_glGetFloatv)      (gl2ps_GLenum,gl2ps_GLfloat*);
  void            (*m_glVertex3f)       (gl2ps_GLfloat,gl2ps_GLfloat,gl2ps_GLfloat);
  void            (*m_glGetBooleanv)    (gl2ps_GLenum,gl2ps_GLboolean*);
  void            (*m_glGetIntegerv)    (gl2ps_GLenum,gl2ps_GLint*);
  gl2ps_GLint     (*m_glRenderMode)     (gl2ps_GLenum);
  void            (*m_glFeedbackBuffer) (gl2ps_GLsizei,gl2ps_GLenum,gl2ps_GLfloat*);
  void            (*m_glPassThrough)    (gl2ps_GLfloat);
} gl2ps_gl_funcs_t;

#if defined(__cplusplus)
extern "C" {
#endif
GL2PSDLL_API void gl2ps_set_gl_funcs(gl2ps_gl_funcs_t*);
GL2PSDLL_API void gl2ps_reset_gl_funcs();
#if defined(__cplusplus)
}
#endif
/*G.Barrand : end.*/
  
#endif /* __GL2PS_H__ */
