#include "Tracer.h"
#include "GLM/ext.hpp"
#include <iostream>

Tracer::Tracer() : m_sphere{glm::vec3(0, 0, -6), 1}
{
     
}

glm::vec3 Tracer::Trace(Ray _ray)
{
    // test for sphere
    if (RaySphereIntersect(_ray, m_sphere).hit)
    {
        std::cout << "anything";
        return glm::vec3(1, 0, 0);   
    }
    else
    {
        return glm::vec3();
    }
}

glm::vec3 Tracer::GetClosestPointToLine(Ray _ray, glm::vec3 _queryPoint)
{
    m_a = m_origin - _ray.m_direction;

    m_closestPoint = m_a + (glm::dot((m_origin - m_a), _ray.m_direction) * _ray.m_direction);

    return m_closestPoint;
}

Intersect Tracer::RaySphereIntersect(Ray _ray, Sphere _sphere)
{
    float dist = glm::distance(_sphere.m_centre, _ray.m_origin);
    Intersect intersect;


    // Ray is inside sphere
    if (dist < _sphere.m_radius)
    {
        std::cout << "RAY INSIDE SPHERE" << std::endl;
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
            std::cout << "no hit" << std::endl;
            intersect.hit = false;
            return intersect;
        }
        // 1 intersect
        else if (dist == _sphere.m_radius)
        {
            std::cout << "ONE hit" << std::endl;
            intersect.hit = true;
            intersect.intersectPoint1 = m_closestPoint;
            intersect.intersectPoint2 = m_closestPoint;
            return intersect;
        }
        // 2 intersects
        else
        {
            std::cout << "TWO hit" << std::endl;
            intersect.hit = true;
            float x = glm::sqrt( glm::pow(_sphere.m_radius, 2) - glm::pow(dist, 2));
            intersect.intersectPoint1 = m_a + ((glm::dot((m_origin - m_a), _ray.m_direction) + x) * _ray.m_direction);
            intersect.intersectPoint2 = m_a + ((glm::dot((m_origin - m_a), _ray.m_direction) - x) * _ray.m_direction);
            return intersect;
        }
    } 
}
