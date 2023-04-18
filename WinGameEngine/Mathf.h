#pragma once
class Mathf
{
public :

	static float Clamp01(float value) {
		if (value < 0.0f) return 0.0f;
		if (value > 1.f) return 1.f;
	}

	static float Lerp(float a, float b, float t) {
		return a + (b - a) * Clamp01(t);
	}

	static Vec2 Lerp(const Vec2& a, const Vec2& b, float t) {
		t = std::fmaxf(0.0f, std::fminf(1.0f, t));
		float x = a.x + (b.x - a.x) * t;
		float y = a.y + (b.y - a.y) * t;
		return Vec2(x, y);
	}
};

