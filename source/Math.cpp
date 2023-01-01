#include "Math.h"

JPH::Vector3::Vector3()
{
}

JPH::Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

JPH::Vector3 JPH::Vector3::operator-(Vector3& right) const
{
	Vector3 out;
	out.x = this->x - right.x;
	out.y = this->y - right.y;
	out.z = this->z - right.z;
	return out;
}

JPH::Vector3 JPH::Vector3::operator+(Vector3& right) const
{
	Vector3 out;
	out.x = this->x + right.x;
	out.y = this->y + right.y;
	out.z = this->z + right.z;
	return out;
}

JPH::Vector2::Vector2()
{
}

JPH::Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

JPH::Vector2 JPH::Vector2::operator-(Vector2& right) const
{
	Vector2 out;
	out.x = this->x - right.x;
	out.y = this->y - right.y;
	return out;
}

JPH::Vector2 JPH::Vector2::operator+(Vector2& right) const
{
	Vector2 out;
	out.x = this->x + right.x;
	out.y = this->y + right.y;
	return out;
}

JPH::Vector4::Vector4()
{
	
}

JPH::Vector4::Vector4(float _x, float _y, float _z, float _w) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

JPH::Vector4 JPH::Vector4::operator-(Vector4& right) const
{
	Vector4 out;
	out.x = this->x - right.x;
	out.y = this->y - right.y;
	out.z = this->z - right.z;
	out.w = this->w - right.w;
	return out;
}

JPH::Vector4 JPH::Vector4::operator+(Vector4& right) const
{
	Vector4 out;
	out.x = this->x + right.x;
	out.y = this->y + right.y;
	out.z = this->z + right.z;
	out.w = this->w + right.w;
	return out;
}

JPH::Matrix4::Matrix4() 
{

}

JPH::Matrix4::Matrix4(float _x1, float _x2, float _x3, float _x4, float _y1, float _y2, float _y3, float _y4, float _z1, float _z2, float _z3, float _z4, float _w1, float _w2, float _w3, float _w4) {

	m[0][0] = _x1;
	m[0][1] = _x2;
	m[0][2] = _x3;
	m[0][3] = _x4;

	m[1][0] = _y1;
	m[1][1] = _y2;
	m[1][2] = _y3;
	m[1][3] = _y4;

	m[2][0] = _z1;
	m[2][1] = _z2;
	m[2][2] = _z3;
	m[2][3] = _z4;

	m[3][0] = _w1;
	m[3][1] = _w2;
	m[3][2] = _w3;
	m[3][3] = _w4;

}

JPH::Matrix4 JPH::Matrix4::operator*(Matrix4& right) const {
	Matrix4 out;
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < 4; j++) {
			out.m[i][j] = m[i][0] * right.m[0][j] +
				m[i][1] * right.m[1][j] +
				m[i][2] * right.m[2][j] +
				m[i][3] * right.m[3][j];
		}
	}
	return out;
}
