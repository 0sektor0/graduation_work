//
// File: CalcShewhart_data.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 20-Mar-2018 12:35:48
//

// Include Files
#include "rt_nonfinite.h"
#include "CalcShewhart.h"
#include "EppsPallyCriterion.h"
#include "GetSample.h"
#include "GiriCriterion.h"
#include "HegazyGreenCriterion.h"
#include "MakeMultipleNNPredicions.h"
#include "ShapiroWeakCriterion.h"
#include "SimulateNarxNetwork.h"
#include "CalcShewhart_data.h"

// Variable Definitions
const double dv0[50] = { 0.061118274114390067, 0.45245729087246855,
  0.06499820776456669, -0.77623308042818207, -0.18375679513183668,
  0.35575413907207259, -0.0310540317018684, -0.37954870166977434,
  0.74836593250336136, 0.80988420411757134, 0.829849704904656,
  -0.17884640298788379, 0.10205876785931219, 0.61855950507032731,
  0.79873441213675378, 0.44635436329409817, -0.70233273371579374,
  0.17579939418324625, -0.92172594699906729, -0.14680215324128654,
  0.37370421384758468, 0.80476647981130878, 0.60539502572113679,
  -0.052556936312140611, 0.46134689481393693, -0.16275726759675654,
  0.83740650216391566, 0.82084738939122637, 0.63475361457385315,
  -0.19175535558190129, -0.15875173421608405, -0.40976660375266277,
  0.54300672037422426, 0.59196247108706868, 0.78759242653206218,
  0.23238495186979111, 0.046342999217160077, -0.53515672416150284,
  0.7182607164819621, -0.058057948077309747, -0.78490825315753976,
  0.73545036441467238, 0.49148973155308195, 0.56947784560221326,
  -0.448655589351279, 0.56026273558967632, 0.1531253928657019,
  -0.50444865429346775, -0.22617740060867175, -0.45708782008073551 };

const double dv1[10] = { 0.227912320265216, 0.3562975104828735,
  0.0016997302229618191, -0.10321879935706216, 0.011173329077173059,
  -1.3330986659522588, 1.0280049070402815, -0.6329336615435307,
  -0.29979747055028638, 0.37390326576799848 };

const double dv2[10] = { -1.3922910334749807, -1.2243227026298271,
  -1.1616434113591667, 0.67333631182990639, 0.16568973433063081,
  -0.21123017491985102, 0.26311886693415992, -0.87640070521585856,
  1.4094979073865546, 1.7429300475993963 };

const double dv3[50] = { 0.48007240060049333, -0.32655555053651469,
  0.80575443384963608, 0.58544393706798292, -0.31021171446756912,
  -0.057709205351858105, 0.3517819352048539, 0.33339735350153493,
  0.09647395799162406, 0.24100105249987525, -0.50577944426525867,
  -0.026470156442869153, 0.38235123028352996, 0.660296017327714,
  0.36176753800464767, -1.2496335893106432, 0.28351044798211489,
  -0.26664420612800932, -0.22380988865279541, -0.79424037432398786,
  0.74243581436767869, -0.262809117620158, -0.7014282632380836,
  -0.26797218750834256, -0.31053007116776843, 0.13455419846262481,
  0.025107752649021688, -0.26429502651768755, -0.28684262815962386,
  0.097792315813590019, 0.34981797347828991, 0.83503738209305189,
  0.40021028762755889, -0.19389039268654384, 0.610735377099027,
  -0.88581854010554228, -1.0292477683266568, -0.7205548457000418,
  -0.72864634459582378, -0.33734056504732179, -0.54753566571526457,
  -0.823614236843807, -0.023251768225536495, -0.72563051376941334,
  -0.73806147067274319, 0.41872332846062688, 0.57982720873662252,
  0.87255553506833861, 0.0779340548878843, 1.1722430098942052 };

//
// File trailer for CalcShewhart_data.cpp
//
// [EOF]
//