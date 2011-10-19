/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __EXT_GMAGICK_H__
#define __EXT_GMAGICK_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/base/base_includes.h>
#include <util/exception.h>
#include <string>

struct _PixelWand;
typedef struct _PixelWand PixelWand;

struct _MagickWand;
typedef struct _MagickWand MagickWand;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

extern const int q_Gmagick_FILTER_UNDEFINED;
extern const int q_Gmagick_COMPOSITE_DEFAULT;
extern const int q_Gmagick_COMPOSITE_UNDEFINED;
extern const int q_Gmagick_COMPOSITE_NO;
extern const int q_Gmagick_COMPOSITE_ADD;
extern const int q_Gmagick_COMPOSITE_ATOP;
extern const int q_Gmagick_COMPOSITE_BUMPMAP;
extern const int q_Gmagick_COMPOSITE_CLEAR;
extern const int q_Gmagick_COMPOSITE_COLORIZE;
extern const int q_Gmagick_COMPOSITE_COPYBLACK;
extern const int q_Gmagick_COMPOSITE_COPYBLUE;
extern const int q_Gmagick_COMPOSITE_COPY;
extern const int q_Gmagick_COMPOSITE_COPYCYAN;
extern const int q_Gmagick_COMPOSITE_COPYGREEN;
extern const int q_Gmagick_COMPOSITE_COPYMAGENTA;
extern const int q_Gmagick_COMPOSITE_COPYOPACITY;
extern const int q_Gmagick_COMPOSITE_COPYRED;
extern const int q_Gmagick_COMPOSITE_COPYYELLOW;
extern const int q_Gmagick_COMPOSITE_DARKEN;
extern const int q_Gmagick_COMPOSITE_DIFFERENCE;
extern const int q_Gmagick_COMPOSITE_DISPLACE;
extern const int q_Gmagick_COMPOSITE_DISSOLVE;
extern const int q_Gmagick_COMPOSITE_HUE;
extern const int q_Gmagick_COMPOSITE_IN;
extern const int q_Gmagick_COMPOSITE_LIGHTEN;
extern const int q_Gmagick_COMPOSITE_LUMINIZE;
extern const int q_Gmagick_COMPOSITE_MINUS;
extern const int q_Gmagick_COMPOSITE_MODULATE;
extern const int q_Gmagick_COMPOSITE_MULTIPLY;
extern const int q_Gmagick_COMPOSITE_OUT;
extern const int q_Gmagick_COMPOSITE_OVER;
extern const int q_Gmagick_COMPOSITE_OVERLAY;
extern const int q_Gmagick_COMPOSITE_PLUS;
extern const int q_Gmagick_COMPOSITE_REPLACE;
extern const int q_Gmagick_COMPOSITE_SATURATE;
extern const int q_Gmagick_COMPOSITE_SCREEN;
extern const int q_Gmagick_COMPOSITE_SUBTRACT;
extern const int q_Gmagick_COMPOSITE_THRESHOLD;
extern const int q_Gmagick_COMPOSITE_XOR;
extern const int q_Gmagick_MONTAGEMODE_FRAME;
extern const int q_Gmagick_MONTAGEMODE_UNFRAME;
extern const int q_Gmagick_MONTAGEMODE_CONCATENATE;
extern const int q_Gmagick_STYLE_NORMAL;
extern const int q_Gmagick_STYLE_ITALIC;
extern const int q_Gmagick_STYLE_OBLIQUE;
extern const int q_Gmagick_STYLE_ANY;
extern const int q_Gmagick_FILTER_UNDEFINED;
extern const int q_Gmagick_FILTER_POINT;
extern const int q_Gmagick_FILTER_BOX;
extern const int q_Gmagick_FILTER_TRIANGLE;
extern const int q_Gmagick_FILTER_HERMITE;
extern const int q_Gmagick_FILTER_HANNING;
extern const int q_Gmagick_FILTER_HAMMING;
extern const int q_Gmagick_FILTER_BLACKMAN;
extern const int q_Gmagick_FILTER_GAUSSIAN;
extern const int q_Gmagick_FILTER_QUADRATIC;
extern const int q_Gmagick_FILTER_CUBIC;
extern const int q_Gmagick_FILTER_CATROM;
extern const int q_Gmagick_FILTER_MITCHELL;
extern const int q_Gmagick_FILTER_LANCZOS;
extern const int q_Gmagick_FILTER_BESSEL;
extern const int q_Gmagick_FILTER_SINC;
extern const int q_Gmagick_IMGTYPE_UNDEFINED;
extern const int q_Gmagick_IMGTYPE_BILEVEL;
extern const int q_Gmagick_IMGTYPE_GRAYSCALE;
extern const int q_Gmagick_IMGTYPE_GRAYSCALEMATTE;
extern const int q_Gmagick_IMGTYPE_PALETTE;
extern const int q_Gmagick_IMGTYPE_PALETTEMATTE;
extern const int q_Gmagick_IMGTYPE_TRUECOLOR;
extern const int q_Gmagick_IMGTYPE_TRUECOLORMATTE;
extern const int q_Gmagick_IMGTYPE_COLORSEPARATION;
extern const int q_Gmagick_IMGTYPE_COLORSEPARATIONMATTE;
extern const int q_Gmagick_IMGTYPE_OPTIMIZE;
extern const int q_Gmagick_RESOLUTION_UNDEFINED;
extern const int q_Gmagick_RESOLUTION_PIXELSPERINCH;
extern const int q_Gmagick_RESOLUTION_PIXELSPERCENTIMETER;
extern const int q_Gmagick_COMPRESSION_UNDEFINED;
extern const int q_Gmagick_COMPRESSION_NO;
extern const int q_Gmagick_COMPRESSION_BZIP;
extern const int q_Gmagick_COMPRESSION_FAX;
extern const int q_Gmagick_COMPRESSION_GROUP4;
extern const int q_Gmagick_COMPRESSION_JPEG;
extern const int q_Gmagick_COMPRESSION_LOSSLESSJPEG;
extern const int q_Gmagick_COMPRESSION_LZW;
extern const int q_Gmagick_COMPRESSION_RLE;
extern const int q_Gmagick_COMPRESSION_ZIP;
extern const int q_Gmagick_PAINT_POINT;
extern const int q_Gmagick_PAINT_REPLACE;
extern const int q_Gmagick_PAINT_FLOODFILL;
extern const int q_Gmagick_PAINT_FILLTOBORDER;
extern const int q_Gmagick_PAINT_RESET;
extern const int q_Gmagick_GRAVITY_NORTHWEST;
extern const int q_Gmagick_GRAVITY_NORTH;
extern const int q_Gmagick_GRAVITY_NORTHEAST;
extern const int q_Gmagick_GRAVITY_WEST;
extern const int q_Gmagick_GRAVITY_CENTER;
extern const int q_Gmagick_GRAVITY_EAST;
extern const int q_Gmagick_GRAVITY_SOUTHWEST;
extern const int q_Gmagick_GRAVITY_SOUTH;
extern const int q_Gmagick_GRAVITY_SOUTHEAST;
extern const int q_Gmagick_STRETCH_NORMAL;
extern const int q_Gmagick_STRETCH_ULTRACONDENSED;
extern const int q_Gmagick_STRETCH_CONDENSED;
extern const int q_Gmagick_STRETCH_SEMICONDENSED;
extern const int q_Gmagick_STRETCH_SEMIEXPANDED;
extern const int q_Gmagick_STRETCH_EXPANDED;
extern const int q_Gmagick_STRETCH_EXTRAEXPANDED;
extern const int q_Gmagick_STRETCH_ULTRAEXPANDED;
extern const int q_Gmagick_STRETCH_ANY;
extern const int q_Gmagick_ALIGN_UNDEFINED;
extern const int q_Gmagick_ALIGN_LEFT;
extern const int q_Gmagick_ALIGN_CENTER;
extern const int q_Gmagick_ALIGN_RIGHT;
extern const int q_Gmagick_DECORATION_NO;
extern const int q_Gmagick_DECORATION_UNDERLINE;
extern const int q_Gmagick_DECORATION_OVERLINE;
extern const int q_Gmagick_DECORATION_LINETROUGH;
extern const int q_Gmagick_NOISE_UNIFORM;
extern const int q_Gmagick_NOISE_GAUSSIAN;
extern const int q_Gmagick_NOISE_MULTIPLICATIVEGAUSSIAN;
extern const int q_Gmagick_NOISE_IMPULSE;
extern const int q_Gmagick_NOISE_LAPLACIAN;
extern const int q_Gmagick_NOISE_POISSON;
extern const int q_Gmagick_CHANNEL_UNDEFINED;
extern const int q_Gmagick_CHANNEL_RED;
extern const int q_Gmagick_CHANNEL_GRAY;
extern const int q_Gmagick_CHANNEL_CYAN;
extern const int q_Gmagick_CHANNEL_GREEN;
extern const int q_Gmagick_CHANNEL_MAGENTA;
extern const int q_Gmagick_CHANNEL_BLUE;
extern const int q_Gmagick_CHANNEL_YELLOW;
extern const int q_Gmagick_CHANNEL_OPACITY;
extern const int q_Gmagick_CHANNEL_MATTE;
extern const int q_Gmagick_CHANNEL_BLACK;
extern const int q_Gmagick_CHANNEL_INDEX;
extern const int q_Gmagick_CHANNEL_ALL;
extern const int q_Gmagick_METRIC_UNDEFINED;
extern const int q_Gmagick_METRIC_MEANABSOLUTEERROR;
extern const int q_Gmagick_METRIC_MEANSQUAREERROR;
extern const int q_Gmagick_METRIC_PEAKABSOLUTEERROR;
extern const int q_Gmagick_METRIC_PEAKSIGNALTONOISERATIO;
extern const int q_Gmagick_METRIC_ROOTMEANSQUAREDERROR;
extern const int q_Gmagick_PIXEL_CHAR;
extern const int q_Gmagick_PIXEL_DOUBLE;
extern const int q_Gmagick_PIXEL_FLOAT;
extern const int q_Gmagick_PIXEL_INTEGER;
extern const int q_Gmagick_PIXEL_LONG;
extern const int q_Gmagick_PIXEL_SHORT;
extern const int q_Gmagick_COLORSPACE_UNDEFINED;
extern const int q_Gmagick_COLORSPACE_RGB;
extern const int q_Gmagick_COLORSPACE_GRAY;
extern const int q_Gmagick_COLORSPACE_TRANSPARENT;
extern const int q_Gmagick_COLORSPACE_OHTA;
extern const int q_Gmagick_COLORSPACE_LAB;
extern const int q_Gmagick_COLORSPACE_XYZ;
extern const int q_Gmagick_COLORSPACE_YCBCR;
extern const int q_Gmagick_COLORSPACE_YCC;
extern const int q_Gmagick_COLORSPACE_YIQ;
extern const int q_Gmagick_COLORSPACE_YPBPR;
extern const int q_Gmagick_COLORSPACE_YUV;
extern const int q_Gmagick_COLORSPACE_CMYK;
extern const int q_Gmagick_COLORSPACE_SRGB;
extern const int q_Gmagick_COLORSPACE_HSL;
extern const int q_Gmagick_COLORSPACE_HWB;
extern const int q_Gmagick_VIRTUALPIXELMETHOD_UNDEFINED;
extern const int q_Gmagick_VIRTUALPIXELMETHOD_CONSTANT;
extern const int q_Gmagick_VIRTUALPIXELMETHOD_EDGE;
extern const int q_Gmagick_VIRTUALPIXELMETHOD_MIRROR;
extern const int q_Gmagick_VIRTUALPIXELMETHOD_TILE;
extern const int q_Gmagick_PREVIEW_UNDEFINED;
extern const int q_Gmagick_PREVIEW_ROTATE;
extern const int q_Gmagick_PREVIEW_SHEAR;
extern const int q_Gmagick_PREVIEW_ROLL;
extern const int q_Gmagick_PREVIEW_HUE;
extern const int q_Gmagick_PREVIEW_SATURATION;
extern const int q_Gmagick_PREVIEW_BRIGHTNESS;
extern const int q_Gmagick_PREVIEW_GAMMA;
extern const int q_Gmagick_PREVIEW_SPIFF;
extern const int q_Gmagick_PREVIEW_DULL;
extern const int q_Gmagick_PREVIEW_GRAYSCALE;
extern const int q_Gmagick_PREVIEW_QUANTIZE;
extern const int q_Gmagick_PREVIEW_DESPECKLE;
extern const int q_Gmagick_PREVIEW_REDUCENOISE;
extern const int q_Gmagick_PREVIEW_ADDNOISE;
extern const int q_Gmagick_PREVIEW_SHARPEN;
extern const int q_Gmagick_PREVIEW_BLUR;
extern const int q_Gmagick_PREVIEW_THRESHOLD;
extern const int q_Gmagick_PREVIEW_EDGEDETECT;
extern const int q_Gmagick_PREVIEW_SPREAD;
extern const int q_Gmagick_PREVIEW_SOLARIZE;
extern const int q_Gmagick_PREVIEW_SHADE;
extern const int q_Gmagick_PREVIEW_RAISE;
extern const int q_Gmagick_PREVIEW_SEGMENT;
extern const int q_Gmagick_PREVIEW_SWIRL;
extern const int q_Gmagick_PREVIEW_IMPLODE;
extern const int q_Gmagick_PREVIEW_WAVE;
extern const int q_Gmagick_PREVIEW_OILPAINT;
extern const int q_Gmagick_PREVIEW_CHARCOALDRAWING;
extern const int q_Gmagick_PREVIEW_JPEG;
extern const int q_Gmagick_RENDERINGINTENT_UNDEFINED;
extern const int q_Gmagick_RENDERINGINTENT_SATURATION;
extern const int q_Gmagick_RENDERINGINTENT_PERCEPTUAL;
extern const int q_Gmagick_RENDERINGINTENT_ABSOLUTE;
extern const int q_Gmagick_RENDERINGINTENT_RELATIVE;
extern const int q_Gmagick_INTERLACE_UNDEFINED;
extern const int q_Gmagick_INTERLACE_NO;
extern const int q_Gmagick_INTERLACE_LINE;
extern const int q_Gmagick_INTERLACE_PLANE;
extern const int q_Gmagick_INTERLACE_PARTITION;
extern const int q_Gmagick_FILLRULE_UNDEFINED;
extern const int q_Gmagick_FILLRULE_EVENODD;
extern const int q_Gmagick_FILLRULE_NONZERO;
extern const int q_Gmagick_PATHUNITS_USERSPACE;
extern const int q_Gmagick_PATHUNITS_USERSPACEONUSE;
extern const int q_Gmagick_PATHUNITS_OBJECTBOUNDINGBOX;
extern const int q_Gmagick_LINECAP_UNDEFINED;
extern const int q_Gmagick_LINECAP_BUTT;
extern const int q_Gmagick_LINECAP_ROUND;
extern const int q_Gmagick_LINECAP_SQUARE;
extern const int q_Gmagick_LINEJOIN_UNDEFINED;
extern const int q_Gmagick_LINEJOIN_MITER;
extern const int q_Gmagick_LINEJOIN_ROUND;
extern const int q_Gmagick_LINEJOIN_BEVEL;
extern const int q_Gmagick_RESOURCETYPE_UNDEFINED;
extern const int q_Gmagick_RESOURCETYPE_AREA;
extern const int q_Gmagick_RESOURCETYPE_DISK;
extern const int q_Gmagick_RESOURCETYPE_FILE;
extern const int q_Gmagick_RESOURCETYPE_MAP;
extern const int q_Gmagick_RESOURCETYPE_MEMORY;
extern const int q_Gmagick_DISPOSE_UNDEFINED;
extern const int q_Gmagick_DISPOSE_NONE;
extern const int q_Gmagick_DISPOSE_BACKGROUND;
extern const int q_Gmagick_DISPOSE_PREVIOUS;

///////////////////////////////////////////////////////////////////////////////
// class GmagickPixel

FORWARD_DECLARE_CLASS_BUILTIN(GmagickPixel);
class c_GmagickPixel : public ExtObjectData {
 public:
  DECLARE_CLASS(GmagickPixel, GmagickPixel, ObjectData)

  // need to implement
  public: c_GmagickPixel(const ObjectStaticCallbacks *cb);
  public: ~c_GmagickPixel();
  public: void t___construct(CStrRef color = null_string);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);
  public: PixelWand * get_PixelWand();

  // implemented by HPHP
  public: c_GmagickPixel *create(String color = null_string);
  public: void dynConstruct(CArrRef Params);
  public: void getConstructor(MethodCallPackage &mcp);
 private:
  PixelWand *pixel_wand;
};

///////////////////////////////////////////////////////////////////////////////
// class Gmagick

FORWARD_DECLARE_CLASS_BUILTIN(Gmagick);
class c_Gmagick : public ExtObjectData {
 public:
  DECLARE_CLASS(Gmagick, Gmagick, ObjectData)

  // need to implement
  public: c_Gmagick(const ObjectStaticCallbacks *cb);
  public: ~c_Gmagick();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);
  public: void t_destroy();
  DECLARE_METHOD_INVOKE_HELPERS(destroy);
  public: String t_getcopyright();
  DECLARE_METHOD_INVOKE_HELPERS(getcopyright);
  public: Object t_readimageblob(CStrRef blob, CStrRef filename);
  DECLARE_METHOD_INVOKE_HELPERS(readimageblob);
  public: String t_getimageblob();
  DECLARE_METHOD_INVOKE_HELPERS(getimageblob);
  public: String t_getimagefilename();
  DECLARE_METHOD_INVOKE_HELPERS(getimagefilename);
  public: int64 t_getimagetype();
  DECLARE_METHOD_INVOKE_HELPERS(getimagetype);
  public: String t_getimageformat();
  DECLARE_METHOD_INVOKE_HELPERS(getimageformat);
  public: int64 t_getimagecolorspace();
  DECLARE_METHOD_INVOKE_HELPERS(getimagecolorspace);
  public: String t_getimageprofile(CStrRef profile);
  DECLARE_METHOD_INVOKE_HELPERS(getimageprofile);
  public: Object t_profileimage(CStrRef name, CStrRef profile);
  DECLARE_METHOD_INVOKE_HELPERS(profileimage);
  public: Object t_setcompressionquality(int64 quality);
  DECLARE_METHOD_INVOKE_HELPERS(setcompressionquality);
  public: Object t_readimage(CStrRef filename);
  DECLARE_METHOD_INVOKE_HELPERS(readimage);
  public: int64 t_getimagewidth();
  DECLARE_METHOD_INVOKE_HELPERS(getimagewidth);
  public: int64 t_getimageheight();
  DECLARE_METHOD_INVOKE_HELPERS(getimageheight);
  public: Object t_resizeimage(int64 columns, int64 rows, int64 filter_type, double blur, bool fit = false);
  DECLARE_METHOD_INVOKE_HELPERS(resizeimage);
  public: Object t_rotateimage(CObjRef background, double degrees);
  DECLARE_METHOD_INVOKE_HELPERS(rotateimage);
  public: Object t_setimageformat(CStrRef format);
  DECLARE_METHOD_INVOKE_HELPERS(setimageformat);
  public: Object t_cropimage(int64 width, int64 height, int64 x, int64 y);
  DECLARE_METHOD_INVOKE_HELPERS(cropimage);
  public: Object t_writeimage(CStrRef filename, bool all_frames = false);
  DECLARE_METHOD_INVOKE_HELPERS(writeimage);
  public: Object t_borderimage(CObjRef bordercolor, int64 width, int64 height);
  DECLARE_METHOD_INVOKE_HELPERS(borderimage);

  // implemented by HPHP
  public: c_Gmagick *create();
  public: void dynConstruct(CArrRef Params);
  public: void getConstructor(MethodCallPackage &mcp);
 private:
  void checkResult(int result);
  void checkNotEmpty(); 
  void checkHasFormat();
  void throwException(const char * magick_message, int magick_severity);
  bool adjust_dimensions(bool bestfit, long desired_width, long desired_height, long *new_width, long *new_height);
  MagickWand *magick_wand;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXT_GMAGICK_H__
