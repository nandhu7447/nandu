#include<iostream>
#include<cmath>
//#include <gtest/gtest.h>
using namespace std;
class Circular{
private :
    float centerLongitude;
    float centerLatitude;
    float radiusKm;

public :
    void SetLocation(float lon,float lat,float r)
    {
        centerLongitude = lon;
        centerLatitude = lat;
        radiusKm = r; //radius in KM
    }
    //Haversine formula 
    bool isInside(float currentLat, float currentLon) const {
        // Calculate distance between center and current point using Haversine formula
        float dLat = (currentLat - centerLatitude) * M_PI / 180.0;
        float dLon = (currentLon - centerLongitude) * M_PI / 180.0;
        float a = sin(dLat / 2) * sin(dLat / 2) +
                  cos(centerLatitude * M_PI / 180.0) * cos(currentLat * M_PI / 180.0) *
                  sin(dLon / 2) * sin(dLon / 2);
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));
        float distance = 6371 * c; // Radius of the Earth in km

        // Check if the distance is less than the radius
        return distance <= radiusKm;
    }
};
