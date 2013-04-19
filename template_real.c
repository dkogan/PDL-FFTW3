// This is the template used by PP to generate the FFTW routines. This is passed
// into pp_def() in the 'Code' key. Before this file is passed to pp_def, the
// following strings are replaced:
//
// INVERSE      If this is a c2r transform rather than r2c

#ifndef __TEMPLATE_ALREADY_INCLUDED__

/* the Linux kernel does something similar to assert at compile time */
#define static_assert(x) (void)( sizeof( int[ 1 - 2* !(x) ]) )

#define __TEMPLATE_ALREADY_INCLUDED__
#endif


{
  // make sure the PDL data type I'm using matches the FFTW data type
  static_assert( sizeof($GENERIC())*2 == sizeof($TFD(fftwf_,fftw_)complex) );

  $TFD(fftwf_,fftw_)plan plan = INT2PTR( $TFD(fftwf_,fftw_)plan, $COMP(plan));

  if( !INVERSE )
    $TFD(fftwf_,fftw_)execute_dft_r2c( plan,
                                       ($TFD(float,double)*)$P(real),
                                       ($TFD(fftwf_,fftw_)complex*)$P(complex) );
  else
    $TFD(fftwf_,fftw_)execute_dft_c2r( plan,
                                       ($TFD(fftwf_,fftw_)complex*)$P(complex),
                                       ($TFD(float,double)*)$P(real) );
}