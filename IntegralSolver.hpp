#include <utility>
#include <cmath>
#include <vector>
#include <functional>
#include <fstream>
#include <iostream>


namespace IntegralSolver
{
    double Trapezoid(const std::vector<double> &fvec, 
                     const double &dx)
    {
        const std::size_t N = fvec.size();
        const std::size_t N1 = N - 1;

        double ret = 0.5 * fvec[0];
        for (std::size_t i = 1; i < N1; ++i)
        {
            ret += fvec[i];
        }
        ret += 0.5 * fvec[N1];
        ret *= dx;

        return ret;
    }

    double Simpson(const std::vector<double> &fvec, 
                   const double &dx)
    {
        const std::size_t N = fvec.size();
        const std::size_t N1 = N - 1;

        if (N % 2 == 0)
        {
            std::cerr << "# of quadrature points must be an odd number!" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        double ret = fvec[0] + 4.0 * fvec[1];
        for (std::size_t i = 2; i < N1; i += 2)
        {
            ret += 2.0 * fvec[i] + 4.0 * fvec[i + 1];
        }
        ret += fvec[N1];
        ret *= dx / 3.0;

        return ret;
    }

    double Simpson38(const std::vector<double> &fvec, 
                     const double &dx)
    {
        const std::size_t N = fvec.size();
        const std::size_t N1 = N - 1;

        if (N % 3 != 1)
        {
            std::cerr << "# of quadrature points must be a multiple of 3 + 1!" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        double ret = fvec[0] + 3.0 * (fvec[1] + fvec[2]);
        for (std::size_t i = 3; i < N1; i += 3)
        {
            ret += 2.0 * fvec[i] + 3.0 * (fvec[i + 1] + fvec[i + 2]);
        }
        ret += fvec[N1];
        ret *= 3.0 * dx / 8.0;

        return ret;
    }

    double Boole(const std::vector<double> &fvec, 
                 const double &dx)
    {
        const std::size_t N = fvec.size();
        const std::size_t N1 = N - 1;

        if (N % 4 != 1)
        {
            std::cerr << "# of quadrature points must be a multiple of 4 + 1!" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        double ret = 7.0 * fvec[0] + 32.0 * (fvec[1] + fvec[3]) + 12.0 * fvec[2];
        for (std::size_t i = 4; i < N1; i += 4)
        {
            ret += 14.0 * fvec[i] + 32.0 * (fvec[i + 1] + fvec[i + 3]) + 12.0 * fvec[i + 2];
        }
        ret += 7.0 * fvec[N1];
        ret *= dx / 22.5;

        return ret;
    }

}