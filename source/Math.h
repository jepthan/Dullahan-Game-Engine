namespace JPH {

	struct Vector2
	{
		float x;
		float y;
		
		Vector2();
		Vector2(float _x, float _y);
	};

	struct Vector3
	{
		float x;
		float y;
		float z;
		Vector3();
		Vector3(float _x, float _y, float _z);
	};

	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;
		Vector3();
		Vector3(float _x, float _y, float _z, float _w);
	};

	struct Matrix4f {
		float m[4][4];

		Matrix4f();

		Matrix4f(float _x1, float _x2, float _x3, float _x4,
			float _y1, float _y2, float _y3, float _y4,
			float _z1, float _z2, float _z3, float _z4,
			float _w1, float _w2, float _w3, float _w4);
		Matrix4f operator*(Matrix4f& right) const;

	};
}