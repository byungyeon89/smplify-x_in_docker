//  Copyright John Maddock 2014.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/cstdfloat.hpp>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE( test_main )
{
   //
   // Basic tests that the functions which provide std lib supported are correctly wrapped:
   //
   boost::float128_t tol = std::numeric_limits<boost::float128_t>::epsilon() * 4;
   boost::float128_t pi = BOOST_FLOAT128_C(3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211);


   BOOST_CHECK_EQUAL(std::abs(BOOST_FLOAT128_C(-2.0)), BOOST_FLOAT128_C(2.0));
   BOOST_CHECK_EQUAL(std::abs(BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(2.0));
   BOOST_CHECK_EQUAL(std::fabs(BOOST_FLOAT128_C(-2.0)), BOOST_FLOAT128_C(2.0));
   BOOST_CHECK_EQUAL(std::fabs(BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(2.0));

   BOOST_CHECK_CLOSE_FRACTION(std::acos(BOOST_FLOAT128_C(0.25)), BOOST_FLOAT128_C(1.31811607165281796574566425464604046984639096659071471685355), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::acos(BOOST_FLOAT128_C(-0.25)), BOOST_FLOAT128_C(1.82347658193697527271697912863346241435077843278439110412140), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::acos(BOOST_FLOAT128_C(0.75)), BOOST_FLOAT128_C(0.722734247813415611178377352641333362025218486424440267626754), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::acos(BOOST_FLOAT128_C(-0.75)), BOOST_FLOAT128_C(2.41885840577637762728426603063816952217195091295066555334819), tol);
   BOOST_CHECK_EQUAL(std::acos(BOOST_FLOAT128_C(1.0)), 0);
   BOOST_CHECK_CLOSE_FRACTION(std::acos(BOOST_FLOAT128_C(0.0)), BOOST_FLOAT128_C(1.57079632679489661923132169163975144209858469968755291048747), tol);

   BOOST_CHECK_CLOSE_FRACTION(std::asin(BOOST_FLOAT128_C(0.25)), BOOST_FLOAT128_C(0.25268025514207865348565743699371097225219373309683819363392), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asin(BOOST_FLOAT128_C(-0.25)), BOOST_FLOAT128_C(-0.252680255142078653485657436993710972252193733096838193633924), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asin(BOOST_FLOAT128_C(0.75)), BOOST_FLOAT128_C(0.848062078981481008052944338998418080073366213263112642860718), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asin(BOOST_FLOAT128_C(-0.75)), BOOST_FLOAT128_C(-0.848062078981481008052944338998418080073366213263112642860718), tol);
   BOOST_CHECK_EQUAL(std::asin(BOOST_FLOAT128_C(0.0)), 0);
   BOOST_CHECK_CLOSE_FRACTION(std::asin(BOOST_FLOAT128_C(1.0)), BOOST_FLOAT128_C(1.57079632679489661923132169163975144209858469968755291048747), tol);

   BOOST_CHECK_CLOSE_FRACTION(std::atan(BOOST_FLOAT128_C(0.25)), BOOST_FLOAT128_C(0.244978663126864154172082481211275810914144098381184067127376), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan(BOOST_FLOAT128_C(-0.25)), BOOST_FLOAT128_C(-0.244978663126864154172082481211275810914144098381184067127376), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan(BOOST_FLOAT128_C(1.25)), BOOST_FLOAT128_C(0.896055384571343956174800718029937827024578444846840487366551), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan(BOOST_FLOAT128_C(-1.25)), BOOST_FLOAT128_C(-0.896055384571343956174800718029937827024578444846840487366551), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan(BOOST_FLOAT128_C(10.25)), BOOST_FLOAT128_C(1.47354312854333084551799286825415639734160148773878671550090), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan(BOOST_FLOAT128_C(-10.25)), BOOST_FLOAT128_C(-1.47354312854333084551799286825415639734160148773878671550090), tol);
   BOOST_CHECK_EQUAL(std::atan(BOOST_FLOAT128_C(0.0)), 0);

   BOOST_CHECK_CLOSE_FRACTION(std::atan2(BOOST_FLOAT128_C(0.5), BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(0.244978663126864154172082481211275810914144098381184067127376), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan2(BOOST_FLOAT128_C(-0.5), BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(-0.244978663126864154172082481211275810914144098381184067127376), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan2(BOOST_FLOAT128_C(0.5), BOOST_FLOAT128_C(-2.0)), BOOST_FLOAT128_C(-0.244978663126864154172082481211275810914144098381184067127376) + pi, tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan2(BOOST_FLOAT128_C(-0.5), BOOST_FLOAT128_C(-2.0)), BOOST_FLOAT128_C(0.244978663126864154172082481211275810914144098381184067127376) - pi, tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan2(BOOST_FLOAT128_C(2.0), BOOST_FLOAT128_C(0.0)), pi / 2, tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atan2(BOOST_FLOAT128_C(-2.0), BOOST_FLOAT128_C(0.0)), -pi / 2, tol);
   BOOST_CHECK_EQUAL(std::atan2(BOOST_FLOAT128_C(0.0), BOOST_FLOAT128_C(0.0)), BOOST_FLOAT128_C(0.0));

   BOOST_CHECK_CLOSE_FRACTION(std::sin(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.479425538604203000273287935215571388081803367940600675188617), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sin(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(-0.479425538604203000273287935215571388081803367940600675188617), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sin(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(0.997494986604054430941723371141487322706651425922115821949975), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sin(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(-0.997494986604054430941723371141487322706651425922115821949975), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sin(BOOST_FLOAT128_C(3.5)), BOOST_FLOAT128_C(-0.350783227689619848120368800043635585084981735940583485415755), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sin(BOOST_FLOAT128_C(-3.5)), BOOST_FLOAT128_C(0.350783227689619848120368800043635585084981735940583485415755), tol);
   BOOST_CHECK_EQUAL(std::sin(BOOST_FLOAT128_C(0.0)), 0);

   BOOST_CHECK_CLOSE_FRACTION(std::cos(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.877582561890372716116281582603829651991645197109744052997611), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cos(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(0.877582561890372716116281582603829651991645197109744052997611), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cos(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(0.0707372016677029100881898514342687090850910275633468694226454), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cos(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(0.0707372016677029100881898514342687090850910275633468694226454), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cos(BOOST_FLOAT128_C(3.5)), BOOST_FLOAT128_C(-0.936456687290796337698657626671760463019957765781959251620988), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cos(BOOST_FLOAT128_C(-3.5)), BOOST_FLOAT128_C(-0.936456687290796337698657626671760463019957765781959251620988), tol);
   BOOST_CHECK_EQUAL(std::cos(BOOST_FLOAT128_C(0.0)), 1.0);

   BOOST_CHECK_CLOSE_FRACTION(std::tan(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.546302489843790513255179465780285383297551720179791246164091), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tan(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(-0.546302489843790513255179465780285383297551720179791246164091), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tan(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(14.1014199471717193876460836519877564456595435772358618661233), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tan(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(-14.1014199471717193876460836519877564456595435772358618661233), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tan(BOOST_FLOAT128_C(3.5)), BOOST_FLOAT128_C(0.374585640158594666330512579989147388450882284289259230693023), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tan(BOOST_FLOAT128_C(-3.5)), BOOST_FLOAT128_C(-0.374585640158594666330512579989147388450882284289259230693023), tol);
   BOOST_CHECK_EQUAL(std::tan(BOOST_FLOAT128_C(0.0)), 0.0);

   BOOST_CHECK_CLOSE_FRACTION(std::sinh(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.521095305493747361622425626411491559105928982611480527946094), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sinh(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(-0.521095305493747361622425626411491559105928982611480527946094), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sinh(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(2.12927945509481749683438749467763164883178911950429386401441), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sinh(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(-2.12927945509481749683438749467763164883178911950429386401441), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sinh(BOOST_FLOAT128_C(3.5)), BOOST_FLOAT128_C(16.5426272876349976249567315290124982237000338471151419910948), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::sinh(BOOST_FLOAT128_C(-3.5)), BOOST_FLOAT128_C(-16.5426272876349976249567315290124982237000338471151419910948), tol);
   BOOST_CHECK_EQUAL(std::sinh(BOOST_FLOAT128_C(0.0)), 0);

   BOOST_CHECK_CLOSE_FRACTION(std::cosh(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(1.12762596520638078522622516140267201254784711809866748362899), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cosh(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(1.12762596520638078522622516140267201254784711809866748362899), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cosh(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(2.35240961524324732576766796544164417017396074886537319275824), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cosh(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(2.35240961524324732576766796544164417017396074886537319275824), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cosh(BOOST_FLOAT128_C(3.5)), BOOST_FLOAT128_C(16.5728246710573161256965178213761180687716943793627989977661), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::cosh(BOOST_FLOAT128_C(-3.5)), BOOST_FLOAT128_C(16.5728246710573161256965178213761180687716943793627989977661), tol);
   BOOST_CHECK_EQUAL(std::cosh(BOOST_FLOAT128_C(0.0)), 1.0);

   BOOST_CHECK_CLOSE_FRACTION(std::tanh(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.462117157260009758502318483643672548730289280330113038552732), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tanh(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(-0.462117157260009758502318483643672548730289280330113038552732), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tanh(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(0.905148253644866438242303696456495597227641135158781798564224), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tanh(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(-0.905148253644866438242303696456495597227641135158781798564224), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tanh(BOOST_FLOAT128_C(3.5)), BOOST_FLOAT128_C(0.998177897611198709284273352450611717351703879477362867150362), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::tanh(BOOST_FLOAT128_C(-3.5)), BOOST_FLOAT128_C(-0.998177897611198709284273352450611717351703879477362867150362), tol);
   BOOST_CHECK_EQUAL(std::tanh(BOOST_FLOAT128_C(0.0)), 0.0);

   BOOST_CHECK_CLOSE_FRACTION(std::asinh(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.481211825059603447497758913424368423135184334385660519661018), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asinh(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(-0.481211825059603447497758913424368423135184334385660519661018), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asinh(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(1.19476321728710930411193082851909052353616207515300542927068), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asinh(BOOST_FLOAT128_C(-1.5)), BOOST_FLOAT128_C(-1.19476321728710930411193082851909052353616207515300542927068), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asinh(BOOST_FLOAT128_C(30.5)), BOOST_FLOAT128_C(4.11114250086321582491802557961818852029252495243356752882371), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::asinh(BOOST_FLOAT128_C(-30.5)), BOOST_FLOAT128_C(-4.11114250086321582491802557961818852029252495243356752882371), tol * 40); // extra tolerance required on Mingw-x64 at least
   BOOST_CHECK_EQUAL(std::asinh(BOOST_FLOAT128_C(0.0)), 0);

   BOOST_CHECK_CLOSE_FRACTION(std::acosh(BOOST_FLOAT128_C(1.5)), BOOST_FLOAT128_C(0.962423650119206894995517826848736846270368668771321039322036), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::acosh(BOOST_FLOAT128_C(30.5)), BOOST_FLOAT128_C(4.11060501081175314729512161636335880294693070089674383785623), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::acosh(BOOST_FLOAT128_C(3000.5)), BOOST_FLOAT128_C(8.69968137322099085819002231042463682720224626990472395734493), tol);
   BOOST_CHECK_EQUAL(std::acosh(BOOST_FLOAT128_C(1.0)), 0.0);

   BOOST_CHECK_CLOSE_FRACTION(std::atanh(BOOST_FLOAT128_C(0.5)), BOOST_FLOAT128_C(0.549306144334054845697622618461262852323745278911374725867347), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atanh(BOOST_FLOAT128_C(-0.5)), BOOST_FLOAT128_C(-0.549306144334054845697622618461262852323745278911374725867347), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atanh(BOOST_FLOAT128_C(0.75)), BOOST_FLOAT128_C(0.972955074527656652552676371721589864818542364790930594229695), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atanh(BOOST_FLOAT128_C(-0.75)), BOOST_FLOAT128_C(-0.972955074527656652552676371721589864818542364790930594229695), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atanh(BOOST_FLOAT128_C(0.125)), BOOST_FLOAT128_C(0.125657214140453038842568865200935839828948193031818857504999), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::atanh(BOOST_FLOAT128_C(-0.125)), BOOST_FLOAT128_C(-0.125657214140453038842568865200935839828948193031818857504999), tol);
   BOOST_CHECK_EQUAL(std::atanh(BOOST_FLOAT128_C(0.0)), 0.0);

   BOOST_CHECK_EQUAL(std::ldexp(BOOST_FLOATMAX_C(2.5), 2), 2.5 * 4);
   int i;
   BOOST_CHECK_EQUAL(std::frexp(BOOST_FLOATMAX_C(16.0), &i), BOOST_FLOATMAX_C(0.5));
   BOOST_CHECK_EQUAL(std::floor(BOOST_FLOATMAX_C(2.5)), 2);
   BOOST_CHECK_EQUAL(std::floor(BOOST_FLOATMAX_C(-2.5)), -3);
   BOOST_CHECK_EQUAL(std::ceil(BOOST_FLOATMAX_C(2.5)), 3);
   BOOST_CHECK_EQUAL(std::ceil(BOOST_FLOATMAX_C(-2.5)), -2);
   BOOST_CHECK_EQUAL(std::trunc(BOOST_FLOATMAX_C(2.5)), 2);
   BOOST_CHECK_EQUAL(std::trunc(BOOST_FLOATMAX_C(-2.5)), -2);

   BOOST_CHECK_CLOSE_FRACTION(std::sqrt(BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(1.41421356237309504880168872420969807856967187537694807317668), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::exp(BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(7.38905609893065022723042746057500781318031557055184732408713), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::exp(BOOST_FLOAT128_C(2000.0)), BOOST_FLOAT128_C(3.88118019428436857648232207537185146709138266970427068956343e868), tol * 500);
   BOOST_CHECK_CLOSE_FRACTION(std::exp(BOOST_FLOAT128_C(-2.0)), 1 / BOOST_FLOAT128_C(7.38905609893065022723042746057500781318031557055184732408713), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::exp(BOOST_FLOAT128_C(-2000.0)), 1 / BOOST_FLOAT128_C(3.88118019428436857648232207537185146709138266970427068956343e868), tol * 500);
   BOOST_CHECK_CLOSE_FRACTION(std::pow(BOOST_FLOAT128_C(2.5), BOOST_FLOAT128_C(2.5)), BOOST_FLOAT128_C(9.88211768802618541249654232635224541787360981039130258392970), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::pow(BOOST_FLOAT128_C(2.5), -BOOST_FLOAT128_C(2.5)), 1 / BOOST_FLOAT128_C(9.88211768802618541249654232635224541787360981039130258392970), tol);

   BOOST_CHECK_CLOSE_FRACTION(std::log(BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(0.693147180559945309417232121458176568075500134360255254120680), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::log(BOOST_FLOAT128_C(2000.0)), BOOST_FLOAT128_C(7.60090245954208236147120648551126919087880460024657418222066), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::log10(BOOST_FLOAT128_C(2.0)), BOOST_FLOAT128_C(0.301029995663981195213738894724493026768189881462108541310427), tol);
   BOOST_CHECK_CLOSE_FRACTION(std::log10(BOOST_FLOAT128_C(2000.0)), BOOST_FLOAT128_C(3.30102999566398119521373889472449302676818988146210854131043), tol);

   BOOST_CHECK_EQUAL(std::fmod(BOOST_FLOATMAX_C(20.0), BOOST_FLOATMAX_C(7.0)), BOOST_FLOATMAX_C(6.0));
   BOOST_CHECK_EQUAL(std::fmod(-BOOST_FLOATMAX_C(20.0), BOOST_FLOATMAX_C(7.0)), -BOOST_FLOATMAX_C(6.0));
   BOOST_CHECK_EQUAL(std::fmod(BOOST_FLOATMAX_C(20.0), -BOOST_FLOATMAX_C(7.0)), BOOST_FLOATMAX_C(6.0));
   BOOST_CHECK_EQUAL(std::fmod(-BOOST_FLOATMAX_C(20.0), -BOOST_FLOATMAX_C(7.0)), -BOOST_FLOATMAX_C(6.0));
   //
   // Basic tests of complex number support:
   //
   std::complex<boost::floatmax_t> cm(2.5, 3.5);
   std::complex<double> cd(2.5, 3.5);
   BOOST_CHECK_EQUAL(real(cm), BOOST_FLOATMAX_C(2.5));
   BOOST_CHECK_EQUAL(imag(cm), BOOST_FLOATMAX_C(3.5));
   BOOST_CHECK_CLOSE_FRACTION(abs(cm), std::sqrt(real(cm) * real(cm) + imag(cm) * imag(cm)), tol);
   BOOST_CHECK_CLOSE_FRACTION(arg(cm), std::atan2(imag(cm), real(cm)), tol);
   BOOST_CHECK_EQUAL(norm(cm), norm(cd));
   BOOST_CHECK_EQUAL(conj(cm), std::complex<boost::floatmax_t>(2.5, -3.5));
   BOOST_CHECK_EQUAL(proj(cm), cm);
   if (std::numeric_limits<boost::floatmax_t>::has_infinity)
   {
      boost::floatmax_t m = (std::numeric_limits<boost::floatmax_t>::max)();
      boost::floatmax_t n = (std::numeric_limits<boost::floatmax_t>::quiet_NaN)();
      boost::floatmax_t i = std::numeric_limits<boost::floatmax_t>::infinity();
      std::complex<boost::floatmax_t> ci(i, 0);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(i, 2.5)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(i, -2.5)), std::conj(ci));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-i, 2.5)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-i, -2.5)), std::conj(ci));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(2.5, i)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-2.5, i)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(2.5, -i)), std::conj(ci));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-2.5, -i)), std::conj(ci));
      // If there's a NaN and an infinity, then we treat it as an infinity:
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(i, n)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-i, n)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(n, i)), ci);
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(n, -i)), std::conj(ci));
      // Maximum values should not be detected as infinities:
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(m, 2.5)), std::complex<boost::floatmax_t>(m, 2.5));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(m, -2.5)), std::complex<boost::floatmax_t>(m, -2.5));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-m, 2.5)), std::complex<boost::floatmax_t>(-m, 2.5));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-m, -2.5)), std::complex<boost::floatmax_t>(-m, -2.5));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(2.5, m)), std::complex<boost::floatmax_t>(2.5, m));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-2.5, m)), std::complex<boost::floatmax_t>(-2.5, m));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(2.5, -m)), std::complex<boost::floatmax_t>(2.5, -m));
      BOOST_CHECK_EQUAL(proj(std::complex<boost::floatmax_t>(-2.5, -m)), std::complex<boost::floatmax_t>(-2.5, -m));
   }
   BOOST_CHECK_CLOSE_FRACTION(real(cm), real(std::polar(abs(cm), arg(cm))), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(cm), imag(std::polar(abs(cm), arg(cm))), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(sqrt(cm)), BOOST_FLOATMAX_C(1.84406651636014927478967924702313083926924795108746617689331), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(sqrt(cm)), BOOST_FLOATMAX_C(0.94898962942734874384477674565646902214428238312030745589860), tol);

   BOOST_CHECK_CLOSE_FRACTION(real(sin(cm)), BOOST_FLOATMAX_C(9.9183739147466194779705692590714075536609528502804512321829), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(sin(cm)), BOOST_FLOATMAX_C(-13.2530202358612673933065316490414418905222985108088743924151), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(cos(cm)), BOOST_FLOATMAX_C(-13.2772126767962806757640045050809172681765101364150115572273), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(cos(cm)), BOOST_FLOATMAX_C(-9.9003016219435352532718399415663308886142356901813313808396), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(tan(cm)), BOOST_FLOATMAX_C(-0.001747945781533807475041571346335555146588886236426940282142), 100 * tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(tan(cm)), BOOST_FLOATMAX_C(0.999481272866023968509371163341197364669909311495225118348783), tol);

   BOOST_CHECK_CLOSE_FRACTION(real(asin(cm)), BOOST_FLOATMAX_C(0.60763873377718961061236721540807625716707363115177473522038), 3 * tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(asin(cm)), BOOST_FLOATMAX_C(2.15662466247239925020341473126370983708442367609452933444142), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(acos(cm)), BOOST_FLOATMAX_C(0.96315759301770700861895447623167518493151106853577817526710), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(acos(cm)), BOOST_FLOATMAX_C(-2.15662466247239925020341473126370983708442367609452933444142), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(atan(cm)), BOOST_FLOATMAX_C(1.43164649729234094356720655652341656334194939189977737526797), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(atan(cm)), BOOST_FLOATMAX_C(0.18785402217098027123573761814417062282719376109354553980571), tol);

   BOOST_CHECK_CLOSE_FRACTION(real(exp(cm)), BOOST_FLOATMAX_C(-11.40837793738050755301628098123357473395267691300165885963084), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(exp(cm)), BOOST_FLOATMAX_C(-4.27341455284486523762268047763120025488336663280501044879428), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(log(cm)), BOOST_FLOATMAX_C(1.45888536604213956747543177478663529791228872640369045476212), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(log(cm)), BOOST_FLOATMAX_C(0.95054684081207514789478913546381917504767901030880427426177), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(pow(cm, cm)), BOOST_FLOATMAX_C(0.500085941796692509786065254311643761781309406813392318413211), 3 * tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(pow(cm, cm)), BOOST_FLOATMAX_C(1.2835619023632800631240903890826362708871896445947786884), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(pow(cm, 45)), BOOST_FLOATMAX_C(1.15295630001810518909457669488131135702133178710937500000000e28), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(pow(cm, 45)), BOOST_FLOATMAX_C(-3.03446103291767290317331113291188915967941284179687500000000e28), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(pow(cm, BOOST_FLOATMAX_C(-6.25))), BOOST_FLOATMAX_C(0.0001033088262386741675929555572265687059620746178809486273109638), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(pow(cm, BOOST_FLOATMAX_C(-6.25))), BOOST_FLOATMAX_C(0.000036807924520680371147635577932953977554657684086220380643819), 10*tol);
   BOOST_CHECK_CLOSE_FRACTION(real(pow(BOOST_FLOATMAX_C(23.125), cm)), BOOST_FLOATMAX_C(-6.10574617260000071495777483951769228578270070743952693687), 500*tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(pow(BOOST_FLOATMAX_C(23.125), cm)), BOOST_FLOATMAX_C(-2571.59829653692515304089117319850284971907684832627401081405), tol);

   BOOST_CHECK_CLOSE_FRACTION(real(sinh(cm)), BOOST_FLOATMAX_C(-5.66575444574645085564435171738630834083691435582030649964506), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(sinh(cm)), BOOST_FLOATMAX_C(-2.15110429680352723029881676360397937637837569516923953471257), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(cosh(cm)), BOOST_FLOATMAX_C(-5.74262349163405669737192926384726639311576255718135235998578), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(cosh(cm)), BOOST_FLOATMAX_C(-2.12231025604133800732386371402722087850499093763577091408171), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(tanh(cm)), BOOST_FLOATMAX_C(0.989853240015864535514963496600761619743140454542828561309980), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(tanh(cm)), BOOST_FLOATMAX_C(0.008764045495134631601280624388444235039135499546704045953309), 12 * tol);

   BOOST_CHECK_CLOSE_FRACTION(real(asinh(cm)), BOOST_FLOATMAX_C(2.14787287976856126021628946626513750583054633606189652982666), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(asinh(cm)), BOOST_FLOATMAX_C(0.93760050284009400234857022775555923392488940926800031416598), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(acosh(cm)), BOOST_FLOATMAX_C(2.15662466247239925020341473126370983708442367609452933444142), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(acosh(cm)), BOOST_FLOATMAX_C(0.96315759301770700861895447623167518493151106853577817526710), tol);
   BOOST_CHECK_CLOSE_FRACTION(real(atanh(cm)), BOOST_FLOATMAX_C(0.131131117031038145756858363631111963444914136310244574499277), tol);
   BOOST_CHECK_CLOSE_FRACTION(imag(atanh(cm)), BOOST_FLOATMAX_C(1.380543138238714176079527733234534889849881842858502491699319), 12 * tol);
}



