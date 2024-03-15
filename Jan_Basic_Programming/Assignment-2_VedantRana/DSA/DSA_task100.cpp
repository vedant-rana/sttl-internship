#include <iostream>
#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/partition_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Polygon_2<K> Polygon_2;

void triangulatePolygon(const Polygon_2& polygon) {
    std::list<Polygon_2> triangles;
    CGAL::optimal_convex_partition_2(polygon.vertices_begin(), polygon.vertices_end(), std::back_inserter(triangles));

    int triangleIndex = 1;
    for (const auto& triangle : triangles) {
        std::cout << "Triangle " << triangleIndex++ << ": ";
        for (auto vertex = triangle.vertices_begin(); vertex != triangle.vertices_end(); ++vertex) {
            std::cout << "(" << *vertex << ") ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Point_2> points = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    Polygon_2 polygon(points.begin(), points.end());

    triangulatePolygon(polygon);

    return 0;
}
