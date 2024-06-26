﻿#pragma once
#include "math/Vec2.h"

namespace xmath
{
	namespace intersect
	{
		inline bool Point_Circle(const cocos2d::Vec2& p0,
			const cocos2d::Vec2& p1, float r)
		{
			const auto dx = p0.x - p1.x;
			const auto dy = p0.y - p1.y;
			return dx * dx + dy * dy <= r * r;
		}
		bool Point_AABB(const cocos2d::Vec2& p0, const cocos2d::Vec2& p1, float halfW, float halfH);
		bool Point_OBB(const cocos2d::Vec2& p0, const cocos2d::Vec2& p1, float halfW, float halfH, float rot);
		bool Point_Diamond(const cocos2d::Vec2& p0,
			const cocos2d::Vec2& p1, float a, float b, float rot);
		bool Point_Ellipse(const cocos2d::Vec2& p0,
			const cocos2d::Vec2& p1, float a, float b, float rot);
		bool Point_Triangle(const cocos2d::Vec2& p,
			const cocos2d::Vec2& A, const cocos2d::Vec2& B, const cocos2d::Vec2& C);
		bool Point_Triangle(const cocos2d::Vec2& P,
			const cocos2d::Vec2& E0, const cocos2d::Vec2& E1);
		bool Point_Parallelogram(const cocos2d::Vec2& p0,
			const cocos2d::Vec2& p1, const cocos2d::Vec2& halfDiagA, const cocos2d::Vec2& halfDiagB);


		bool OBB_Circle(const cocos2d::Vec2& p0, float halfW, float halfH, float rot,
			const cocos2d::Vec2& p1, float r);
		bool OBB_OBB(const cocos2d::Vec2& p0, float halfW0, float halfH0, float rot0,
			const cocos2d::Vec2& p1, float halfW1, float halfH1, float rot1);
		bool OBB_Line(const cocos2d::Vec2& p0, float halfW0, float halfH0, float rot0,
			const cocos2d::Vec2& p1, float rot1);
		bool OBB_Triangle(const cocos2d::Vec2& p, float halfW, float halfH, float rot,
			const cocos2d::Vec2& A, const cocos2d::Vec2& B, const cocos2d::Vec2& C);
		bool OBB_Diamond(const cocos2d::Vec2& p0, float halfW, float halfH, float rot0,
			const cocos2d::Vec2& p1, float a, float b, float rot1);
		bool OBB_Ellipse(const cocos2d::Vec2& p0, float halfW, float halfH, float rot0,
			const cocos2d::Vec2& p1, float a, float b, float rot1);

		bool Circle_Ellipse(const cocos2d::Vec2& p0, float r,
			const cocos2d::Vec2& p1, float a, float b, float rot);
		bool Circle_Diamond(const cocos2d::Vec2& p0, float r,
			const cocos2d::Vec2& p1, float a, float b, float rot);
		bool Circle_Triangle(const cocos2d::Vec2& p, float r,
			const cocos2d::Vec2& A, const cocos2d::Vec2& B, const cocos2d::Vec2& C);

		bool Ellipse_Ellipse(const cocos2d::Vec2& p0, float a0, float b0, float rot0,
			const cocos2d::Vec2& p1, float a1, float b1, float rot1);
		bool Ellipse_Diamond(const cocos2d::Vec2& p0, float a0, float b0, float rot0,
			const cocos2d::Vec2& p1, float a1, float b1, float rot1);
		bool Ellipse_Triangle(const cocos2d::Vec2& p, float a, float b, float rot,
			const cocos2d::Vec2& A, const cocos2d::Vec2& B, const cocos2d::Vec2& C);

		bool Segment_Segment(const cocos2d::Vec2& A0, const cocos2d::Vec2& b0,
			const cocos2d::Vec2& A1, const cocos2d::Vec2& B1);
		bool Triangle_Triangle(const cocos2d::Vec2& A0, const cocos2d::Vec2& b0, const cocos2d::Vec2& C0,
			const cocos2d::Vec2& A1, const cocos2d::Vec2& B1, const cocos2d::Vec2& C1);

		bool Parallelogram_Parallelogram(
			const cocos2d::Vec2& p0, const cocos2d::Vec2& halfDiagA0, const cocos2d::Vec2& halfDiagB0,
			const cocos2d::Vec2& p1, const cocos2d::Vec2& halfDiagA1, const cocos2d::Vec2& halfDiagB1);

		bool Diamond_Diamond(const cocos2d::Vec2& p0, float a0, float b0, float rot0,
			const cocos2d::Vec2& p1, float a1, float b1, float rot1);

		bool Diamond_Triangle(const cocos2d::Vec2& p, float a, float b, float rot, 
			const cocos2d::Vec2& A, const cocos2d::Vec2& B, const cocos2d::Vec2& C);

		bool Line_Circle(const cocos2d::Vec2& p0, float r, const cocos2d::Vec2& p1, float rot);
		inline bool AABB_AABB(const cocos2d::Vec2& p0, float halfW0, float halfH0,
			const cocos2d::Vec2& p1, float halfW1, float halfH1)
		{
			return std::max(p0.x - halfW0, p1.x - halfW1) <= std::min(p0.x + halfW0, p1.x + halfW1) &&
				std::max(p0.y - halfH0, p1.y - halfH1) <= std::min(p0.y + halfH0, p1.y + halfH1);
		}
		inline bool AABB_Circle(const cocos2d::Vec2& p0, float halfW, float halfH,
			const cocos2d::Vec2& p1, float r)
		{
			const auto dw = std::max(0.f, std::abs(p0.x - p1.x) - halfW);
			const auto dh = std::max(0.f, std::abs(p0.y - p1.y) - halfH);
			return r * r >= dh * dh + dw * dw;
		}
		inline bool Circle_Circle(const cocos2d::Vec2& p0, float r0,
			const cocos2d::Vec2& p1, float r1)
		{
			const auto d = r0 + r1;
			const auto dx = p0.x - p1.x;
			const auto dy = p0.y - p1.y;
			return dx * dx + dy * dy <= d * d;
		}
	}
}
