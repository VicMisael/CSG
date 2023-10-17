#include "MetallicSpecular.h"
#include "../../utils/utility.h"
#include <glm/geometric.hpp>


ColorVec MetallicSpecular::rho(const Vector3& wo) const
{
	return Constants::BLACK;
}

ColorVec MetallicSpecular::f(const intersectionRec& intersection, const Vector3& wo, const Vector3& wi) const
{
	return Constants::BLACK;
}

sample_f_out MetallicSpecular::sample_f(const intersectionRec& intersection, const Vector3& wo) const
{
	const float ndotwo = dot(intersection.normal, wo);
	const Vector3 wi = -wo + 2.0f * intersection.normal * ndotwo + (fuzz_ * utility::random_in_hemisphere(intersection.normal));
	const float pdf = fabs(dot(intersection.normal, wi));
	return { kr_ * cr,wi,pdf };
}
