AC_INIT([randcam], [1.0], [oliver@von-und-fuer-lau.de])
AC_COPYRIGHT([Copyright (c) 2008 Oliver Lau])

AM_INIT_AUTOMAKE([randcam], [1.0], [oliver@von-und-fuer-lau.de])
AM_CONFIG_HEADER([config.h])

AC_PROG_CXX
AC_PROG_INSTALL
AC_LANG_CPLUSPLUS

AC_CHECK_LIB([cv], [cvSub])
AC_CHECK_LIB([highgui], [main])

AC_ARG_ENABLE([debug],
              [AS_HELP_STRING([--enable-debug],[build debug version without optimization [no]])],
              [debug=$enableval],
              [debug=no])

AC_MSG_CHECKING([whether to build debug version (no optimization)])
if test x"$debug" = "xyes"; then
    AC_MSG_RESULT([yes])
    if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
        CPPFLAGS="-DDEBUG -D_DEBUG $CPPFLAGS"
        DEFAULT_CXXFLAGS="-ggdb -O0 $DEFAULT_CXXFLAGS"
    fi
else
    AC_MSG_RESULT([no])
    AC_MSG_NOTICE( TARGET=$target )
    case $target in
    i*86-apple-*)
        if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
            DEFAULT_CXXFLAGS="-g -march=prescott -ffast-math -fomit-frame-pointer $DEFAULT_CXXFLAGS"
        fi
        ;;
    i686-*-*)
        if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
          DEFAULT_CXXFLAGS="-g -march=i686 -ffast-math -fomit-frame-pointer $DEFAULT_CXXFLAGS"
        fi
        ;;
    amd64-*-* | x86_64-*-*)
        if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
          DEFAULT_CXXFLAGS="-g $DEFAULT_CXXFLAGS"
        fi
        ;;
    powerpc-*-*)
        if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
            DEFAULT_CXXFLAGS="-g -mcpu=G3 -mtune=G5 -fomit-frame-pointer $DEFAULT_CXXFLAGS"
        fi
        ;;
    *-*-*)
        if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
            DEFAULT_CXXFLAGS="-fomit-frame-pointer $DEFAULT_CXXFLAGS"
        fi
        ;;
    esac
    CPPFLAGS="-DNDEBUG $CPPFLAGS"
    DEFAULT_CXXFLAGS="-O3 $DEFAULT_CXXFLAGS"
fi


AC_ARG_ENABLE([gui],
              [AS_HELP_STRING([--enable-gui],[enable OpenCV GUI])],
              [have_opencv_gui=no],
              [have_opencv_gui=yes])
if test x"$have_opencv_gui" = "xyes"; then
    AC_DEFINE([HAVE_OPENCV_GUI], [1], [Define to 1 if you have OpenCV GUI support enabled.])
fi


AC_ARG_ENABLE([sse2],
              [AS_HELP_STRING([--enable-sse2],[enable SSE2 intrinsics [yes]])],
              [sse2=$enableval],
              [sse2=yes])

if test x"$sse2" = "xyes"; then
  if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
    case $target in
    i*86-apple-* | i686-*-* | amd64-*-* | x86_64-*-*)
      DEFAULT_CXXFLAGS=" -msse2 $DEFAULT_CXXFLAGS"
        ;;
    *-*-*)
        ;;
    esac
  fi
fi



have_openmp=no

AC_MSG_CHECKING(for OpenMP support)
AC_LINK_IFELSE([
AC_LANG_PROGRAM([[
#include <omp.h>
void f(int* a, int* b, int n) {
  int i;
  #pragma parallel for
  for(i = 0; i < n; i++)
     a[i] += b[i];
}
]])],
[have_openmp=yes],
[have_openmp=no])

AC_MSG_RESULT($have_openmp)

AC_ARG_ENABLE([openmp],
              [AS_HELP_STRING([--enable-openmp],[enable OpenMP threading [automatic]])],
              [openmp=$enableval],
              [openmp=$have_openmp])

if test x"$openmp" = "xyes"; then
 if test x"$ac_cv_c_compiler_gnu" = "xyes"; then
    DEFAULT_CXXFLAGS=" -fopenmp $DEFAULT_CXXFLAGS"
    AC_CHECK_LIB(gomp,omp_get_num_threads)
 fi
fi


AM_SANITY_CHECK
AC_OUTPUT(Makefile)
