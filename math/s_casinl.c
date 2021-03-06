/* Return arc sine of complex long double value.
   Copyright (C) 1997-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <complex.h>
#include <math.h>
#include <math_private.h>


__complex__ long double
__casinl (__complex__ long double x)
{
  __complex__ long double res;

  if (isnan (__real__ x) || isnan (__imag__ x))
    {
      if (__real__ x == 0.0)
	{
	  res = x;
	}
      else if (isinf (__real__ x) || isinf (__imag__ x))
	{
	  __real__ res = __nanl ("");
	  __imag__ res = __copysignl (HUGE_VALL, __imag__ x);
	}
      else
	{
	  __real__ res = __nanl ("");
	  __imag__ res = __nanl ("");
	}
    }
  else
    {
      __complex__ long double y;

      __real__ y = -__imag__ x;
      __imag__ y = __real__ x;

      y = __casinhl (y);

      __real__ res = __imag__ y;
      __imag__ res = -__real__ y;
    }

  return res;
}
weak_alias (__casinl, casinl)
