#include <iostream>
#include <cmath>
#include <ctime>
#include <cryptopp/integer.h>
#include <cryptopp/ecp.h>
#include <cryptopp/eccrypto.h>

using namespace CryptoPP;


typedef ECP::Point Point;
typedef ECP::Element FieldElement;


Integer lenstras_elliptic_curve_factorization(const Integer& n, int max_iterations = 1000) {
    AutoSeededRandomPool prng;

    EllipticCurve<ECP> curve = ASN1::secp256r1();  
    ECP::Point G = curve.GetSubgroupGenerator();
    Integer order = curve.GetSubgroupOrder();

    for (int i = 0; i < max_iterations; ++i) {
        Integer a = Integer::RandomInteger(order, prng);
        Point b = curve.Multiply(a, G);

        
        for (Integer j = 2; j < n; ++j) {
            b = curve.Add(b, G);
            Integer d = b.x;

            if (1 < d && d < n) {
                return d;
            }
        }
    }

    return 0;  
}

int main() {
    Integer number_to_factorize = 5959;
    Integer result = lenstras_elliptic_curve_factorization(number_to_factorize);

    if (result > 0) {
        std::cout << "The factor of " << number_to_factorize << " is " << result << std::endl;
    } else {
        std::cout << "Factorization failed for " << number_to_factorize << std::endl;
    }

    return 0;
}
