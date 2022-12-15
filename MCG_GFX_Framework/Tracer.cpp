#include "Tracer.h"
#include "GLM/ext.hpp"
#include <iostream>

Tracer::Tracer() /*: m_sphere{glm::vec3(320, 240, -200), 100}*/
{
     
}

Colour Tracer::Trace(Ray _ray)
{
    for (size_t i = 0; i < m_spheres.size(); i++)
    {
        Intersect intersection = RaySphereIntersect(_ray, m_spheres[i]);
        // test for sphere
        if (intersection.hit)
        {
            return m_spheres[i].ShadePixel(_ray, intersection.intersectPoint1);
        }
        else // return background colour
        {
            //Colour col(glm::vec3(1, 1, 1));
            //return col;
        }
    }

    Colour col(glm::vec3(1, 1, 1));
    return col;
}

glm::vec3 Tracer::GetClosestPointToLine(Ray _ray, glm::vec3 _queryPoint)
{
    m_closestPoint = _ray.m_origin + (glm::dot((_queryPoint - _ray.m_origin), _ray.m_direction) * _ray.m_direction);

    return m_closestPoint;
}


Intersect Tracer::RaySphereIntersect(Ray _ray, Sphere _sphere)
{
    // Check distance between sphere and centre
    float dist = glm::distance(_sphere.m_centre, _ray.m_origin);

    // Instance of intersection
    Intersect intersect;

    // Ray is inside sphere
    if (dist < _sphere.m_radius)
    {
        intersect.hit = false;
        return intersect;
    }
    else
    {
        m_closestPoint = GetClosestPointToLine(_ray, _sphere.m_centre);

        // Distance calculation from closest point to sphere centre
        dist = glm::distance(m_closestPoint, _sphere.m_centre);

        // 0 intersections
        if (dist > _sphere.m_radius)
        {
            intersect.hit = false;
            return intersect;
        }
        // > 1 intersections
        else
        {
            intersect.hit = true;
            float x = glm::sqrt( glm::pow(_sphere.m_radius, 2) - glm::pow(dist, 2));
            intersect.intersectPoint1 = _ray.m_origin + ((glm::dot((m_origin - _ray.m_origin), _ray.m_direction) - x) * _ray.m_direction);
            return intersect;
        }
    } 
}

void Tracer::AddSphere(Sphere sphere)
{
    m_spheres.push_back(sphere);
}


