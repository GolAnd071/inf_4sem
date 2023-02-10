#include <set>
#include <gmsh.h>

int main(int argc, char **argv)
{
    gmsh::initialize();

    gmsh::model::add("s0t3");

    double lc = 2e-1;
    gmsh::model::geo::addPoint(1, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(1, 0, 1, lc, 2);
    gmsh::model::geo::addPoint(1, 1, 0, lc, 3);
    gmsh::model::geo::addPoint(1, 0, -1, lc, 4);
    gmsh::model::geo::addPoint(1, -1, 0, lc, 5);
    gmsh::model::geo::addPoint(-1, 0, 0, lc, 6);
    gmsh::model::geo::addPoint(-1, 0, 1, lc, 7);
    gmsh::model::geo::addPoint(-1, 1, 0, lc, 8);
    gmsh::model::geo::addPoint(-1, 0, -1, lc, 9);
    gmsh::model::geo::addPoint(-1, -1, 0, lc, 10);


    gmsh::model::geo::addLine(2, 7, 1);
    gmsh::model::geo::addLine(3, 8, 2);
    gmsh::model::geo::addLine(4, 9, 3);
    gmsh::model::geo::addLine(5, 10, 4);
    gmsh::model::geo::addCircleArc(2, 1, 3, 5);
    gmsh::model::geo::addCircleArc(3, 1, 4, 6);
    gmsh::model::geo::addCircleArc(4, 1, 5, 7);
    gmsh::model::geo::addCircleArc(5, 1, 2, 8);
    gmsh::model::geo::addCircleArc(7, 6, 8, 9);
    gmsh::model::geo::addCircleArc(8, 6, 9, 10);
    gmsh::model::geo::addCircleArc(9, 6, 10, 11);
    gmsh::model::geo::addCircleArc(10, 6, 7, 12);


    gmsh::model::geo::addCurveLoop({5, 6, 7, 8}, 1);
    gmsh::model::geo::addPlaneSurface({1}, 1);

    gmsh::model::geo::addCurveLoop({9, 10, 11, 12}, 2);
    gmsh::model::geo::addPlaneSurface({2}, 2);


    gmsh::model::geo::addCurveLoop({5, 2, -9, -1}, 3);
    gmsh::model::geo::addSurfaceFilling({3}, 3);

    gmsh::model::geo::addCurveLoop({6, 3, -10, -2}, 4);
    gmsh::model::geo::addSurfaceFilling({4}, 4);

    gmsh::model::geo::addCurveLoop({7, 4, -11, -3}, 5);
    gmsh::model::geo::addSurfaceFilling({5}, 5);

    gmsh::model::geo::addCurveLoop({8, 1, -12, -4}, 6);
    gmsh::model::geo::addSurfaceFilling({6}, 6);

    gmsh::model::geo::addSurfaceLoop({1, 3, 4, 5, 6, 2}, 1);
    gmsh::model::geo::addVolume({1});

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("s0t3.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}
