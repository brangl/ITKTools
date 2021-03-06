/*=========================================================================
*
* Copyright Marius Staring, Stefan Klein, David Doria. 2011.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0.txt
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*=========================================================================*/
#ifndef __itkFleissKappaStatistic_h_
#define __itkFleissKappaStatistic_h_

#include "itkKappaStatisticBase.h"

namespace itk {
namespace Statistics {

/** \class FleissKappaStatistic
 *
 * \brief This class computes the unweighted kappa statistic for multiple observers.
 *
 * The kappa statistic is a measure for the agreement of observers.
 *
 * n:  the number of observers
 * N:  the number of observations
 * k:  the number of categories
 *
 * The implementation is based on the wikipedia page:
 *
 *   http://en.wikipedia.org/wiki/Fleiss%27_kappa
 *
 * The Fleiss kappa statistic is suitable for two or more observers.
 * It is unweighted.
 *
 * \ingroup Statistics
 *
 */
class ITK_EXPORT FleissKappaStatistic : public KappaStatisticBase
{
public:
  /** Standard class typedefs. */
  typedef FleissKappaStatistic        Self;
  typedef KappaStatisticBase          Superclass;
  typedef SmartPointer< Self >        Pointer;
  typedef SmartPointer< const Self >  ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro( FleissKappaStatistic, KappaStatisticBase );

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Typedefs from the Superclass. */
  typedef Superclass::CategoryType  CategoryType;
  typedef Superclass::SampleType    SampleType;
  typedef Superclass::SamplesType   SamplesType;

  /** The function that computes the kappa statistic value. */
  virtual void ComputeKappaStatisticValue( double & Po, double & Pe,
    double & kappa );

  /** The function that computes the kappa statistic value and standard deviation. */
  virtual void ComputeKappaStatisticValueAndStandardDeviation(
    double & Po, double & Pe, double & kappa, double & std, const bool & compare );

protected:
  FleissKappaStatistic();
  virtual ~FleissKappaStatistic() {};
  void PrintSelf( std::ostream& os, Indent indent ) const;

private:
  FleissKappaStatistic(const Self&); // purposely not implemented
  void operator=(const Self&);       // purposely not implemented

  /** A helper function that calculate the observation matrix,
   * i.e. the n_{ij}.
   */
  void ComputeObservationMatrix( const unsigned int n,
    const unsigned int N, const unsigned int k );

  SamplesType m_ObservationMatrix;

}; // end class FleissKappaStatistic

} // end of namespace Statistics
} // end namespace itk

#endif // end #ifndef __itkFleissKappaStatistic_h_
