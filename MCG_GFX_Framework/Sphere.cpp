#include "Sphere.h"


Sphere::Sphere()
{
    m_centre = glm::vec3(0);
    m_radius = 1;
    m_sphereColour = Colour(glm::vec3(1.0f, 0.0f, 1.0f));
}

Sphere::Sphere(glm::vec3 _centre, int _radius, Colour col)
{
    m_centre = _centre;
    m_radius = _radius;
}

Colour Sphere::ShadePixel(Ray _ray, glm::vec3 _intersection)
{
    Camera cam;

    glm::vec3 lightDir(1, 0, 1);

    //diffuse shading
    float diffuse = glm::max(glm::dot(lightDir, GetSphereNormal(_intersection, cam)), 0.0f);


    glm::vec3 half = (glm::normalize(glm::vec3(0) + lightDir)); //view dir + light dir
    float spec = glm::pow(glm::max(glm::dot(GetSphereNormal(_intersection, cam), half), 0.0f), 5.0f);

    Colour col = Colour(glm::vec3(1.0f, 0.0f, 0.0f) * (diffuse + spec));
    return col;
}

glm::vec3 Sphere::GetSphereNormal(glm::vec3 samplePoint, Camera cam)
{
    //glm::vec3 originToCentre = glm::vec3(m_centre.x - cam.m_position.x, m_centre.y - cam.m_position.y, m_centre.z - cam.m_position.z);
    //glm::vec3 originToIntersection = glm::vec3(cam.m_position.x - samplePoint.x, cam.m_position.y - samplePoint.y, cam.m_position.z - samplePoint.z);


    glm::vec3 sphereNormal = glm::normalize(samplePoint - m_centre);

    return sphereNormal;
}