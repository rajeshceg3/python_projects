#include <iostream>
#include <vector>
#include <dlib/clustering.h>
#include <dlib/rand.h>
using std::vector;
using namespace dlib;

int main()
{
    std::vector<matrix<double,2,1>> data_points;
    std::vector<matrix<double,2,1>> initial_centers = {{1,1},{2,3}};
    matrix<double,2,1> sample;
    const int count = 10;
	
    for (int i = 0; i < count; ++i)
    {
        sample(0) = 1.0 + (((double) std::rand() / RAND_MAX) - 0.5);
        sample(1) = 1.0 + (((double) std::rand() / RAND_MAX) - 0.5);
        data_points.push_back(sample);
    }

    for (int i = 0; i < count; ++i)
    {
        sample(0) = 2 + (((double) std::rand() / RAND_MAX) - 0.5);
        sample(1) = 3 + (((double) std::rand() / RAND_MAX) - 0.5);
        data_points.push_back(sample);
    }

    pick_initial_centers(2, initial_centers, data_points);
    find_clusters_using_kmeans(data_points,initial_centers, 10);

    for (const auto& slice : initial_centers) 
        std::cout << "Cluster x: " << slice(0) << " , y: " << slice(1) << "\n";

}
