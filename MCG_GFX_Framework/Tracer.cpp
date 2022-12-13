#include "Tracer.h"
#include "GLM/ext.hpp"
#include <iostream>

Tracer::Tracer() : m_sphere{glm::vec3(320, 240, -200), 100}
{
     
}

Colour Tracer::Trace(Ray _ray)
{

    Intersect intersection = RaySphereIntersect(_ray, m_sphere);
    // test for sphere
    if (intersection.hit)
    {
        //std::cout << "anything";
        return m_sphere.ShadePixel(_ray, intersection.intersectPoint1);
    }
    else // return background colour
    {
        Colour col(glm::vec3(0, 0, 0));
        return col;
    }
}

glm::vec3 Tracer::GetClosestPointToLine(Ray _ray, glm::vec3 _queryPoint)
{
    m_a = _ray.m_origin;

    m_closestPoint = m_a + (glm::dot((_queryPoint - m_a), _ray.m_direction) * _ray.m_direction);

    return m_closestPoint;
}

Intersect Tracer::RaySphereIntersect(Ray _ray, Sphere _sphere)
{
    float dist = glm::distance(_sphere.m_centre, _ray.m_origin);
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

        dist = glm::distance(m_closestPoint, _sphere.m_centre);
        // 0 intersects
        if (dist > _sphere.m_radius)
        {
            intersect.hit = false;
            return intersect;
        }
        // 1 intersect
        else if (dist == _sphere.m_radius)
        {
            intersect.hit = true;
            intersect.intersectPoint1 = m_closestPoint;
            return intersect;
        }
        // 2 intersects
        else
        {
            intersect.hit = true;
            float x = glm::sqrt( glm::pow(_sphere.m_radius, 2) - glm::pow(dist, 2));
            intersect.intersectPoint1 = m_a + ((glm::dot((m_origin - m_a), _ray.m_direction) - x) * _ray.m_direction);
            return intersect;
        }
    } 
}
