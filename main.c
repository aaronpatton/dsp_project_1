 /*
 ============================================================================
 Name        : Signal_variance.c
 Author      : Aaron
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate signal mean and variance
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

double CalcSignalMean(double *sigSrcArr, int sigLength);
double CalcSignalVariance(double *sigSrcArr, double sigMean, int sigLength);

int main(void)
{

	double meanValue = CalcSignalMean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
    double variance = CalcSignalVariance(&InputSignal_f32_1kHz_15kHz[0], meanValue, SIG_LENGTH);
	printf("\n\nVariance = %f\n\n\n", variance);

	return 0;
}

double CalcSignalMean(double *sigSrcArr, int sigLength)
{
	double _mean = 0.0;

	for(int i = 0; i < sigLength; i++)
	{
		_mean = _mean + sigSrcArr[i];
	}

	_mean = _mean/(double)sigLength;

	return _mean;
}

double CalcSignalVariance(double *sigSrcArr, double sigMean, int sigLength)
{
    double _variance = 0.0;

    for(int i = 0; i < sigLength; i++)
    {
        _variance = _variance + pow((sigSrcArr[i] - sigMean),2);

    }

    _variance = _variance/(double)(sigLength-1);

    return _variance;

}
