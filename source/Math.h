namespace JPH {

	struct Vector2
	{
		float x;
		float y;
		
		Vector2();
		Vector2(float _x, float _y);
		Vector2 operator-(Vector2& right) const;
		Vector2 operator+(Vector2& right) const;
	};

	struct Vector3
	{
		float x;
		float y;
		float z;
		Vector3();
		Vector3(float _x, float _y, float _z);
		Vector3 operator-(Vector3& right) const;
		Vector3 operator+(Vector3& right) const;
	};

	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4();
		Vector4(float _x, float _y, float _z, float _w);
		Vector4 operator-(Vector4& right) const;
		Vector4 operator+(Vector4& right) const;
	};

	struct Matrix4 {
		float m[4][4];

		Matrix4();

		Matrix4(float _x1, float _x2, float _x3, float _x4,
			float _y1, float _y2, float _y3, float _y4,
			float _z1, float _z2, float _z3, float _z4,
			float _w1, float _w2, float _w3, float _w4);
		Matrix4 operator*(Matrix4& right) const;

	};
}