#include <set>
#include <gmsh.h>
#include <vector>

int addTorus(const double r1, const double r2, const double ms, const int tag = -1)
{
    int c1 = gmsh::model::geo::addPoint(r1, 0, 0, ms);
    int c2 = gmsh::model::geo::addPoint(0, r1, 0, ms);
    int c3 = gmsh::model::geo::addPoint(-r1, 0, 0, ms);
    int c4 = gmsh::model::geo::addPoint(0, -r1, 0, ms);

    int o1 = gmsh::model::geo::addPoint(0, 0, 0, ms);
    int o2 = gmsh::model::geo::addPoint(0, 0, r2, ms);
    int o3 = gmsh::model::geo::addPoint(0, 0, 0, ms);
    int o4 = gmsh::model::geo::addPoint(0, 0, -r2, ms);


    int p11 = gmsh::model::geo::addPoint(r1 + r2, 0, 0, ms);
    int p12 = gmsh::model::geo::addPoint(r1, 0, r2, ms);
    int p13 = gmsh::model::geo::addPoint(r1 - r2, 0, 0, ms);
    int p14 = gmsh::model::geo::addPoint(r1, 0, -r2, ms);

    int p21 = gmsh::model::geo::addPoint(0, r1 + r2, 0, ms);
    int p22 = gmsh::model::geo::addPoint(0, r1, r2, ms);
    int p23 = gmsh::model::geo::addPoint(0, r1 - r2, 0, ms);
    int p24 = gmsh::model::geo::addPoint(0, r1, -r2, ms);

    int p31 = gmsh::model::geo::addPoint(-r1 - r2, 0, 0, ms);
    int p32 = gmsh::model::geo::addPoint(-r1, 0, r2, ms);
    int p33 = gmsh::model::geo::addPoint(-r1 + r2, 0, 0, ms);
    int p34 = gmsh::model::geo::addPoint(-r1, 0, -r2, ms);

    int p41 = gmsh::model::geo::addPoint(0, -r1 - r2, 0, ms);
    int p42 = gmsh::model::geo::addPoint(0, -r1, r2, ms);
    int p43 = gmsh::model::geo::addPoint(0, -r1 + r2, 0, ms);
    int p44 = gmsh::model::geo::addPoint(0, -r1, -r2, ms);


    int l11 = gmsh::model::geo::addCircleArc(p11, c1, p12);
    int l12 = gmsh::model::geo::addCircleArc(p12, c1, p13);
    int l13 = gmsh::model::geo::addCircleArc(p13, c1, p14);
    int l14 = gmsh::model::geo::addCircleArc(p14, c1, p11);

    int l21 = gmsh::model::geo::addCircleArc(p21, c2, p22);
    int l22 = gmsh::model::geo::addCircleArc(p22, c2, p23);
    int l23 = gmsh::model::geo::addCircleArc(p23, c2, p24);
    int l24 = gmsh::model::geo::addCircleArc(p24, c2, p21);

    int l31 = gmsh::model::geo::addCircleArc(p31, c3, p32);
    int l32 = gmsh::model::geo::addCircleArc(p32, c3, p33);
    int l33 = gmsh::model::geo::addCircleArc(p33, c3, p34);
    int l34 = gmsh::model::geo::addCircleArc(p34, c3, p31);

    int l41 = gmsh::model::geo::addCircleArc(p41, c4, p42);
    int l42 = gmsh::model::geo::addCircleArc(p42, c4, p43);
    int l43 = gmsh::model::geo::addCircleArc(p43, c4, p44);
    int l44 = gmsh::model::geo::addCircleArc(p44, c4, p41);


    int a11 = gmsh::model::geo::addCircleArc(p11, o1, p21);
    int a12 = gmsh::model::geo::addCircleArc(p21, o1, p31);
    int a13 = gmsh::model::geo::addCircleArc(p31, o1, p41);
    int a14 = gmsh::model::geo::addCircleArc(p41, o1, p11);

    int a21 = gmsh::model::geo::addCircleArc(p12, o2, p22);
    int a22 = gmsh::model::geo::addCircleArc(p22, o2, p32);
    int a23 = gmsh::model::geo::addCircleArc(p32, o2, p42);
    int a24 = gmsh::model::geo::addCircleArc(p42, o2, p12);

    int a31 = gmsh::model::geo::addCircleArc(p13, o3, p23);
    int a32 = gmsh::model::geo::addCircleArc(p23, o3, p33);
    int a33 = gmsh::model::geo::addCircleArc(p33, o3, p43);
    int a34 = gmsh::model::geo::addCircleArc(p43, o3, p13);

    int a41 = gmsh::model::geo::addCircleArc(p14, o4, p24);
    int a42 = gmsh::model::geo::addCircleArc(p24, o4, p34);
    int a43 = gmsh::model::geo::addCircleArc(p34, o4, p44);
    int a44 = gmsh::model::geo::addCircleArc(p44, o4, p14);


    std::vector<std::pair<int, int>> ot;

    gmsh::model::geo::revolve({{1, l11}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s11 = ot[1].second;

    gmsh::model::geo::revolve({{1, l12}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s12 = ot[1].second;

    gmsh::model::geo::revolve({{1, l13}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s13 = ot[1].second;

    gmsh::model::geo::revolve({{1, l14}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s14 = ot[1].second;

    gmsh::model::geo::revolve({{1, l21}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s21 = ot[1].second;

    gmsh::model::geo::revolve({{1, l22}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s22 = ot[1].second;

    gmsh::model::geo::revolve({{1, l23}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s23 = ot[1].second;

    gmsh::model::geo::revolve({{1, l24}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s24 = ot[1].second;

    gmsh::model::geo::revolve({{1, l31}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s31 = ot[1].second;

    gmsh::model::geo::revolve({{1, l32}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s32 = ot[1].second;

    gmsh::model::geo::revolve({{1, l33}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s33 = ot[1].second;

    gmsh::model::geo::revolve({{1, l34}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s34 = ot[1].second;

    gmsh::model::geo::revolve({{1, l41}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s41 = ot[1].second;

    gmsh::model::geo::revolve({{1, l42}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s42 = ot[1].second;

    gmsh::model::geo::revolve({{1, l43}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s43 = ot[1].second;

    gmsh::model::geo::revolve({{1, l44}}, 0, 0, 0, 0, 0, 1, M_PI / 2, ot, {});
    int s44 = ot[1].second;


    int ret = gmsh::model::geo::addSurfaceLoop({s11, s12, s13, s14, s24, s21, s22, s23, s33, s34, s31, s32, s42, s43, s44, s41}, tag);

    return ret;
}

int main(int argc, char **argv)
{
    gmsh::initialize();

    gmsh::model::add("s1");

    double lc = 2e-1;
    addTorus(2, 1, lc, 1);
    addTorus(2, 0.5, lc, 2);

    gmsh::model::geo::addVolume({1, -2}, 1);

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("s1.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}
