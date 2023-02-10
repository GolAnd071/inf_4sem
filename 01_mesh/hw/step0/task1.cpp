#include <set>
#include <gmsh.h>

int main(int argc, char **argv)
{
    gmsh::initialize();

    gmsh::model::add("s0t1");

    double lc = 2e-1;
    gmsh::model::geo::addPoint(1, 1, 1, lc, 1);
    gmsh::model::geo::addPoint(-1, 1, 1, lc, 2);
    gmsh::model::geo::addPoint(1, -1, 1, lc, 3);
    gmsh::model::geo::addPoint(1, 1, -1, lc, 4);
    gmsh::model::geo::addPoint(-1, -1, 1, lc, 5);
    gmsh::model::geo::addPoint(-1, 1, -1, lc, 6);
    gmsh::model::geo::addPoint(1, -1, -1, lc, 7);
    gmsh::model::geo::addPoint(-1, -1, -1, lc, 8);

    gmsh::model::geo::addLine(1, 2, 1);
    gmsh::model::geo::addLine(1, 3, 2);
    gmsh::model::geo::addLine(1, 4, 3);
    gmsh::model::geo::addLine(2, 5, 4);
    gmsh::model::geo::addLine(2, 6, 5);
    gmsh::model::geo::addLine(3, 5, 6);
    gmsh::model::geo::addLine(3, 7, 7);
    gmsh::model::geo::addLine(4, 6, 8);
    gmsh::model::geo::addLine(4, 7, 9);
    gmsh::model::geo::addLine(5, 8, 10);
    gmsh::model::geo::addLine(6, 8, 11);
    gmsh::model::geo::addLine(7, 8, 12);

    gmsh::model::geo::addCurveLoop({1, 4, -6, -2}, 1);
    gmsh::model::geo::addPlaneSurface({1}, 1);

    gmsh::model::geo::addCurveLoop({1, 5, -8, -3}, 2);
    gmsh::model::geo::addPlaneSurface({2}, 2);

    gmsh::model::geo::addCurveLoop({2, 7, -9, -3}, 3);
    gmsh::model::geo::addPlaneSurface({3}, 3);

    gmsh::model::geo::addCurveLoop({4, 10, -11, -5}, 4);
    gmsh::model::geo::addPlaneSurface({4}, 4);

    gmsh::model::geo::addCurveLoop({6, 10, -12, -7}, 5);
    gmsh::model::geo::addPlaneSurface({5}, 5);

    gmsh::model::geo::addCurveLoop({8, 11, -12, -9}, 6);
    gmsh::model::geo::addPlaneSurface({6}, 6);

    gmsh::model::geo::addSurfaceLoop({1, 2, 3, 5, 4, 6}, 1);
    gmsh::model::geo::addVolume({1});

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("s0t1.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}
